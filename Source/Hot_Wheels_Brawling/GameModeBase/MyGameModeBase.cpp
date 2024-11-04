#include "MyGameModeBase.h"
#include "Blueprint/Userwidget.h"
#include "TimerManager.h"
#include "Hot_Wheels_Brawling/Widget/MainMenuWidget.h"

bool AMyGameModeBase::bFirstStart = true;


void AMyGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    // 마우스 커서 표시
    APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
    if (PlayerController)
    {
        PlayerController->bShowMouseCursor = true;
        PlayerController->bEnableClickEvents = true;
        PlayerController->bEnableMouseOverEvents = true;
    }

    // 로딩 위젯 생성 및 추가
    if (TSubclassOf<UUserWidget> TitleWidgetClass = LoadClass<UUserWidget>(nullptr, TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/TreadMill/BluePrints/Widget/BP_TitleWidget.BP_TitleWidget_C'")))
    {
        TitleWidget = CreateWidget<UUserWidget>(GetWorld(), TitleWidgetClass);
        if (TitleWidget)
        {
            TitleWidget->AddToViewport();
        }

        // 3초 뒤에 타이틀 화면을 제거하고 메인 메뉴를 띄우는 타이머 설정
        if (bFirstStart) {
            GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AMyGameModeBase::ShowMainMenu, 3.0f, false);
            bFirstStart = false;
        }
        else {
            ShowMainMenu();
        }
    }
}

void AMyGameModeBase::ShowMainMenu()
{
    // 타이틀 위젯 제거
    if (TitleWidget)
    {
        TitleWidget->RemoveFromViewport();
        TitleWidget = nullptr;
    }

    // 메인 메뉴 위젯 생성 및 추가
    if (TSubclassOf<UUserWidget> MainMenuWidgetClass = LoadClass<UUserWidget>(nullptr, TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/TreadMill/BluePrints/Widget/BP_MainPage.BP_MainPage_C'")))
    {
        MainMenuWidget = CreateWidget<UUserWidget>(GetWorld(), MainMenuWidgetClass);
        if (MainMenuWidget)
        {
            MainMenuWidget->AddToViewport();
        }
    }
}
