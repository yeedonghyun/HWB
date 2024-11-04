#include "WaitingRoomWidget.h"
#include "Hot_Wheels_Brawling/Widget/LoadingWidget.h"
#include "Kismet/GameplayStatics.h"

void UWaitingRoomWidget::NativeConstruct()
{
	Super::NativeConstruct();

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UWaitingRoomWidget::PossessPawn, 0.01f, false);

	if (Play)
	{
		Play->OnClicked.AddDynamic(this, &UWaitingRoomWidget::PlayClicked);
	}

	if (BackToMenu)
	{
		BackToMenu->OnClicked.AddDynamic(this, &UWaitingRoomWidget::BackToMenuClicked);
	}

	if (player1Left)
	{
		player1Left->OnClicked.AddDynamic(this, &UWaitingRoomWidget::SelectPlayer1LeftSkin);
	}

	if (player1Right)
	{
		player1Right->OnClicked.AddDynamic(this, &UWaitingRoomWidget::SelectPlayer1RightSkin);
	}

	if (player2Left)
	{
		player2Left->OnClicked.AddDynamic(this, &UWaitingRoomWidget::SelectPlayer2LeftSkin);
	}

	if (player2Right)
	{
		player2Right->OnClicked.AddDynamic(this, &UWaitingRoomWidget::SelectPlayer2RightSkin);
	}
}

void UWaitingRoomWidget::PossessPawn()
{
	if (player1 && player2) {
		return;
	}

	TArray<AActor*> FoundPawns;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("Player1Tag"), FoundPawns);
	if (FoundPawns.Num() > 0)
	{
		player1 = Cast<AC_CH_CarBase>(FoundPawns[0]);
		player1->GetMesh()->SetSkeletalMesh(MeshManager.GetCharactersMesh(player1->meshindex, true));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player1 Pawn not found!"));
	}

	FoundPawns.Empty();
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("Player2Tag"), FoundPawns);
	if (FoundPawns.Num() > 0)
	{
		player2 = Cast<AC_CH_CarBase_SecondPlayer>(FoundPawns[0]);
		player1->GetMesh()->SetSkeletalMesh(MeshManager.GetCharactersMesh(player1->meshindex, true));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player2 Pawn not found!"));
	}
}

void UWaitingRoomWidget::PlayClicked()
{
	this->RemoveFromParent();

	if (TSubclassOf<UUserWidget> LoadingWidgetClass = LoadClass<UUserWidget>(nullptr, TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/TreadMill/BluePrints/Widget/BP_LoadingPage.BP_LoadingPage_C'")))
	{
		UUserWidget* CreatedWidget = CreateWidget<UUserWidget>(GetWorld(), LoadingWidgetClass);
		ULoadingWidget* LoadingWidget = Cast<ULoadingWidget>(CreatedWidget);
		if (LoadingWidget)
		{
			LoadingWidget->AddToViewport();
			LoadingWidget->SetRandomLoadingMessage();

			FTimerHandle LocalTimerHandle;
			GetWorld()->GetTimerManager().SetTimer(LocalTimerHandle, [this, LoadingWidget]()
				{

					UGameplayStatics::OpenLevel(this, FName("SecondPlay"));
				}, 3.0f, false);
		}
	}
}

void UWaitingRoomWidget::BackToMenuClicked()
{
	if (TSubclassOf<UUserWidget> BackToMenuClickedClass = LoadClass<UUserWidget>(nullptr, TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/TreadMill/BluePrints/Widget/BP_MainPage.BP_MainPage_C'")))
	{
		UUserWidget* BackToMenuWidget = CreateWidget<UUserWidget>(GetWorld(), BackToMenuClickedClass);
		if (BackToMenuWidget)
		{
			BackToMenuWidget->AddToViewport();
		}
	}
}
void UWaitingRoomWidget::SelectPlayer1LeftSkin()
{
	if (player1) {
		player1->meshindex--;
		if (player1->meshindex < 0) {
			player1->meshindex = MeshManager.GetCharactersMeshCount(true) - 1;
		}

		player1->GetMesh()->SetSkeletalMesh(MeshManager.GetCharactersMesh(player1->meshindex, true));
	}
}

void UWaitingRoomWidget::SelectPlayer1RightSkin()
{
	if (player1) {
		player1->meshindex++;
		if (player1->meshindex >= MeshManager.GetCharactersMeshCount(true)) {
			player1->meshindex = 0;
		}

		player1->GetMesh()->SetSkeletalMesh(MeshManager.GetCharactersMesh(player1->meshindex, true));
	}
}

void UWaitingRoomWidget::SelectPlayer2LeftSkin()
{
	if (player2) {
		player2->meshindex--;
		if (player2->meshindex < 0) {
			player2->meshindex = MeshManager.GetCharactersMeshCount(false) - 1;
		}

		player2->GetMesh()->SetSkeletalMesh(MeshManager.GetCharactersMesh(player2->meshindex, false));
	}
}

void UWaitingRoomWidget::SelectPlayer2RightSkin()
{
	if (player2) {
		player2->meshindex++;
		if (player2->meshindex >= MeshManager.GetCharactersMeshCount(false)) {
			player2->meshindex = 0;
		}

		player2->GetMesh()->SetSkeletalMesh(MeshManager.GetCharactersMesh(player2->meshindex, false));
	}
}