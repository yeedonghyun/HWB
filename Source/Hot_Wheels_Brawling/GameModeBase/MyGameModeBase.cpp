#include "MyGameModeBase.h"
#include "Blueprint/Userwidget.h"
#include "TimerManager.h"
#include "Hot_Wheels_Brawling/Widget/MainMenuWidget.h"

bool AMyGameModeBase::bFirstStart = true;


void AMyGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    // ���콺 Ŀ�� ǥ��
    APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
    if (PlayerController)
    {
        PlayerController->bShowMouseCursor = true;
        PlayerController->bEnableClickEvents = true;
        PlayerController->bEnableMouseOverEvents = true;
    }

    // �ε� ���� ���� �� �߰�
    if (TSubclassOf<UUserWidget> TitleWidgetClass = LoadClass<UUserWidget>(nullptr, TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/TreadMill/BluePrints/Widget/BP_TitleWidget.BP_TitleWidget_C'")))
    {
        TitleWidget = CreateWidget<UUserWidget>(GetWorld(), TitleWidgetClass);
        if (TitleWidget)
        {
            TitleWidget->AddToViewport();
        }

        // 3�� �ڿ� Ÿ��Ʋ ȭ���� �����ϰ� ���� �޴��� ���� Ÿ�̸� ����
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
    // Ÿ��Ʋ ���� ����
    if (TitleWidget)
    {
        TitleWidget->RemoveFromViewport();
        TitleWidget = nullptr;
    }

    // ���� �޴� ���� ���� �� �߰�
    if (TSubclassOf<UUserWidget> MainMenuWidgetClass = LoadClass<UUserWidget>(nullptr, TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/TreadMill/BluePrints/Widget/BP_MainPage.BP_MainPage_C'")))
    {
        MainMenuWidget = CreateWidget<UUserWidget>(GetWorld(), MainMenuWidgetClass);
        if (MainMenuWidget)
        {
            MainMenuWidget->AddToViewport();
        }
    }
}
