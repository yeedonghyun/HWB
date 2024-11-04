#include "FirstScenePlayerController.h"
#include "Kismet/GameplayStatics.h"


void AFirstScenePlayerController::BeginPlay()
{
    Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AFirstScenePlayerController::PossessPawn, 0.01f, false);

}

void AFirstScenePlayerController::PossessPawn()
{
    TArray<AActor*> FoundPawns;
    UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("Player1Tag"), FoundPawns);
    if (FoundPawns.Num() > 0)
    {
        player1 = Cast<AC_CH_CarBase>(FoundPawns[0]);
        player1->meshindex = 0;
        player1->GetMesh()->SetSkeletalMesh(MeshManager.GetCharactersMesh(player1->meshindex, true));
        player1->bFalled = false;
    }
    else {
        UE_LOG(LogTemp, Warning, TEXT("Player1 Pawn not found!"));
    }

    FoundPawns.Empty();
    UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("Player2Tag"), FoundPawns);
    if (FoundPawns.Num() > 0)
    {
        player2 = Cast<AC_CH_CarBase_SecondPlayer>(FoundPawns[0]); 
        player2->meshindex = 0;
        player2->GetMesh()->SetSkeletalMesh(MeshManager.GetCharactersMesh(player2->meshindex, false));
        player2->bFalled = false;
    }
    else {
        UE_LOG(LogTemp, Warning, TEXT("Player2 Pawn not found!"));
    }

    if (player1 && player2) {
        GetWorldTimerManager().ClearTimer(TimerHandle);
    }
}

void AFirstScenePlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    InputComponent->BindAction(FName("LeftSkin_1"), EInputEvent::IE_Pressed, this, &AFirstScenePlayerController::Player1LeftMesh);
    InputComponent->BindAction(FName("RightSkin_1"), EInputEvent::IE_Pressed, this, &AFirstScenePlayerController::Player1RightMesh);
    InputComponent->BindAction(FName("LeftSkin_2"), EInputEvent::IE_Pressed, this, &AFirstScenePlayerController::Player2LeftMesh);
    InputComponent->BindAction(FName("RightSkin_2"), EInputEvent::IE_Pressed, this, &AFirstScenePlayerController::Player2RightMesh);
}

void AFirstScenePlayerController::Player1LeftMesh()
{
    if (player1) {
        player1->meshindex--;
        if (player1->meshindex < 0) {
            player1->meshindex = MeshManager.GetCharactersMeshCount(true) - 1;
        }

        player1->GetMesh()->SetSkeletalMesh(MeshManager.GetCharactersMesh(player1->meshindex, true));
    }
}

void AFirstScenePlayerController::Player1RightMesh()
{
    if (player1) {
        player1->meshindex++;
        if (player1->meshindex >= MeshManager.GetCharactersMeshCount(true)){
            player1->meshindex = 0;
        }

        player1->GetMesh()->SetSkeletalMesh(MeshManager.GetCharactersMesh(player1->meshindex, true));
    }
}

void AFirstScenePlayerController::Player2LeftMesh()
{
    if (player2) {
        player2->meshindex--;
        if (player2->meshindex < 0) {
            player2->meshindex = MeshManager.GetCharactersMeshCount(false) - 1;
        }

        player2->GetMesh()->SetSkeletalMesh(MeshManager.GetCharactersMesh(player2->meshindex, false));
    }
}

void AFirstScenePlayerController::Player2RightMesh()
{
    if (player2) {
        player2->meshindex++;
        if (player2->meshindex >= MeshManager.GetCharactersMeshCount(false)) {
            player2->meshindex = 0;
        }

        player2->GetMesh()->SetSkeletalMesh(MeshManager.GetCharactersMesh(player2->meshindex, false));
    }
}
