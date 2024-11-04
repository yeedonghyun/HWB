#include "MultiPlayerController.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "../Widget/GameOverWidget.h"
#include "Hot_Wheels_Brawling/GameModeBase/SecondGameModeBase.h"
#include "Kismet/GameplayStatics.h"

void AMultiPlayerController::BeginPlay()
{
    Super::BeginPlay();

    bGameOverTriggered = false;
    bPlayer1GameOver = false;
    bPlayer2GameOver = false;

    ASecondGameModeBase* GameMode = Cast<ASecondGameModeBase>(GetWorld()->GetAuthGameMode());
    if (GameMode)
    {
        PlayerScoreWidget = GameMode->ScoreWidget;
    }

    GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AMultiPlayerController::PossessPawn, 0.01f, false);
}

void AMultiPlayerController::PossessPawn()
{
    TArray<AActor*> FoundPawns;
    UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("Player1Tag"), FoundPawns);
    if (FoundPawns.Num() > 0)
    {
        player1 = Cast<AC_CH_CarBase>(FoundPawns[0]);
        player1->GetMesh()->SetSkeletalMesh(player1->MeshManager.GetCharactersMesh(player1->meshindex, true));
    }
    else {
        UE_LOG(LogTemp, Warning, TEXT("Player1 Pawn not found!"));
    }

    FoundPawns.Empty();
    UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("Player1View"), FoundPawns);
    if (FoundPawns.Num() > 0)
    {
        AC_CH_CarBase* Player1View = Cast<AC_CH_CarBase>(FoundPawns[0]);
        Player1View->GetMesh()->SetSkeletalMesh(player1->MeshManager.GetCharactersMesh(player1->meshindex, true));
    }
    

    FoundPawns.Empty();
    UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("Player2Tag"), FoundPawns);
    if (FoundPawns.Num() > 0)
    {
        player2 = Cast<AC_CH_CarBase_SecondPlayer>(FoundPawns[0]);
        player2->GetMesh()->SetSkeletalMesh(player2->MeshManager.GetCharactersMesh(player2->meshindex, false));
    }
    else {
        UE_LOG(LogTemp, Warning, TEXT("Player2 Pawn not found!"));
    }

    FoundPawns.Empty();
    UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("Player2View"), FoundPawns);
    if (FoundPawns.Num() > 0)
    {
        AC_CH_CarBase_SecondPlayer* Player2View = Cast<AC_CH_CarBase_SecondPlayer>(FoundPawns[0]);
        Player2View->GetMesh()->SetSkeletalMesh(player2->MeshManager.GetCharactersMesh(player2->meshindex, false));
    }

    if (player1 && player2) {
        GetWorldTimerManager().ClearTimer(TimerHandle);
    }
}

void AMultiPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    InputComponent->BindAxis(FName("MoveForward_1"), this, &AMultiPlayerController::MoveForward_player1);
    InputComponent->BindAxis(FName("MoveBackward_1"), this, &AMultiPlayerController::MoveBackward_player1);
    InputComponent->BindAxis(FName("MoveLR_1"), this, &AMultiPlayerController::MoveRL_player1);
    InputComponent->BindAction(FName("Brake_1"), EInputEvent::IE_Pressed, this, &AMultiPlayerController::BrakePressed_player1);
    InputComponent->BindAction(FName("Brake_1"), EInputEvent::IE_Released, this, &AMultiPlayerController::BrakeReleased_player1);

    InputComponent->BindAxis(FName("MoveForward_2"), this, &AMultiPlayerController::MoveForward_player2);
    InputComponent->BindAxis(FName("MoveBackward_2"), this, &AMultiPlayerController::MoveBackward_player2);
    InputComponent->BindAxis(FName("MoveLR_2"), this, &AMultiPlayerController::MoveRL_player2);
    InputComponent->BindAction(FName("Brake_2"), EInputEvent::IE_Pressed, this, &AMultiPlayerController::BrakePressed_player2);
    InputComponent->BindAction(FName("Brake_2"), EInputEvent::IE_Released, this, &AMultiPlayerController::BrakeReleased_player2);

    /*InputComponent->BindAction("Booster", EInputEvent::IE_Pressed, this, &AMultiPlayerController::OnShiftPressed);
    InputComponent->BindAction("Booster_2", EInputEvent::IE_Pressed, this, &AMultiPlayerController::OnShiftPressedPlayer2);*/
}

void AMultiPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if ((!bPlayer1GameOver && !bPlayer2GameOver) && (!player1->bFalled && player2->bFalled) || (player1->bFalled && !player2->bFalled) )
    {
        bPlayer1GameOver = player1->bFalled;
        bPlayer2GameOver = player2->bFalled;
    }

    if ((player1->bFalled && player2->bFalled) && !bGameOverTriggered)
    {
        GameOverEvent();
        bGameOverTriggered = true;
    }
}

void AMultiPlayerController::GameOverEvent()
{
    if (TSubclassOf<UUserWidget> GameOverWidgetClass = LoadClass<UUserWidget>(nullptr, TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/TreadMill/BluePrints/Widget/BP_GameOverWidget.BP_GameOverWidget_C'")))
    {
        UUserWidget* GameOverWidget = CreateWidget<UUserWidget>(GetWorld(), GameOverWidgetClass);
        if (GameOverWidget)
        {
            GameOverWidget->AddToViewport();

            UGameOverWidget* CastedGameOverWidget = Cast<UGameOverWidget>(GameOverWidget);
            if (CastedGameOverWidget && CastedGameOverWidget->FadeOutScreenAnimation)
            {
                CastedGameOverWidget->SetGameOverMessage(bPlayer1GameOver);
                CastedGameOverWidget->PlayFadeOutAnimation();
            }
        }
    }

    FTimerHandle LocalTimerHandle;
    GetWorld()->GetTimerManager().SetTimer(LocalTimerHandle, [this]()
        {
            UGameplayStatics::OpenLevel(this, FName("FirstLoading"));
        }, 5.0f, false);
}


void AMultiPlayerController::MoveForward_player1(float value)
{
    if (player1)
    {
        player1->MoveForward(value);
    }
}

void AMultiPlayerController::MoveBackward_player1(float value)
{
    if (player1)
    {
        player1->MoveBackward(value);
    }
}

void AMultiPlayerController::MoveRL_player1(float value)
{
    if (player1)
    {
        player1->MoveRL(value);
    }
}

void AMultiPlayerController::BrakePressed_player1()
{
    if (player1)
    {
        player1->BrakePressed();
    }
}

void AMultiPlayerController::BrakeReleased_player1()
{
    if (player1)
    {
        player1->BrakeReleased();
    }
}

void AMultiPlayerController::MoveForward_player2(float value)
{
    if (player2)
    {
        player2->MoveForward(value);
    }
}

void AMultiPlayerController::MoveBackward_player2(float value)
{
    if (player2)
    {
        player2->MoveBackward(value);
    }
}

void AMultiPlayerController::MoveRL_player2(float value)
{
    if (player2)
    {
        player2->MoveRL(value);
    }
}

void AMultiPlayerController::BrakePressed_player2()
{
    if (player2)
    {
        player2->BrakePressed();
    }
}

void AMultiPlayerController::BrakeReleased_player2()
{
    if (player2)
    {
        player2->BrakeReleased();
    }
}