#include "SecondGameModeBase.h"
#include "Blueprint/Userwidget.h"
#include "../Characters/C_CH_CarBase.h"
#include "../Characters/C_CH_CarBase_SecondPlayer.h"
#include "Kismet/GameplayStatics.h"

#include "Engine/World.h"

ASecondGameModeBase::ASecondGameModeBase()
{
	static ConstructorHelpers::FClassFinder<UScoreWidget> ScoreHUDWidgetAsset(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/TreadMill/BluePrints/Widget/BP_Score4Widget.BP_Score4Widget_C'"));

	if (ScoreHUDWidgetAsset.Succeeded())
		MainHUDWidgetClass = ScoreHUDWidgetAsset.Class;
}

void ASecondGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(MainHUDWidgetClass))
	{
		ScoreWidget = Cast<UScoreWidget>(CreateWidget(GetWorld(), MainHUDWidgetClass));

		if (IsValid(ScoreWidget))
		{
			ScoreWidget->AddToViewport();
		}
	}
}
