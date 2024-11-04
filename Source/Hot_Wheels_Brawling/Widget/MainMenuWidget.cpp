#include "MainMenuWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Image.h"

void UMainMenuWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (PlayButton)
    {
        PlayButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnPlayButtonClicked);
        PlayButton->OnHovered.AddDynamic(this, &UMainMenuWidget::OnPlayButtonHovered);
        PlayButton->OnUnhovered.AddDynamic(this, &UMainMenuWidget::OnPlayButtonUnhovered);
    }

    if (LockerButton)
    {
        LockerButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnLockerButtonClicked);
        LockerButton->OnHovered.AddDynamic(this, &UMainMenuWidget::OnLockerButtonHovered);
        LockerButton->OnUnhovered.AddDynamic(this, &UMainMenuWidget::OnLockerButtonUnhovered);
    }

    if (SettingsButton)
    {
        SettingsButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnSettingsButtonClicked);
        SettingsButton->OnHovered.AddDynamic(this, &UMainMenuWidget::OnSettingsButtonHovered);
        SettingsButton->OnUnhovered.AddDynamic(this, &UMainMenuWidget::OnSettingsButtonUnhovered);
    }

    if (ExitGameButton)
    {
        ExitGameButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnExitGameButtonClicked);
        ExitGameButton->OnHovered.AddDynamic(this, &UMainMenuWidget::OnExitButtonHovered);
        ExitGameButton->OnUnhovered.AddDynamic(this, &UMainMenuWidget::OnExitButtonUnhovered);
    }

    // 모든 이미지 숨김 처리
    if (PlayButtonHoverImage)
    {
        PlayButtonHoverImage->SetVisibility(ESlateVisibility::Hidden);
    }
    if (LockerButtonsHoverImage)
    {
        LockerButtonsHoverImage->SetVisibility(ESlateVisibility::Hidden);
    }
    if (SettingsButtonsHoverImage)
    {
        SettingsButtonsHoverImage->SetVisibility(ESlateVisibility::Hidden);
    }
    if (ExitButtonsHoverImage)
    {
        ExitButtonsHoverImage->SetVisibility(ESlateVisibility::Hidden);
    }
}

void UMainMenuWidget::OnPlayButtonClicked()
{

    this->RemoveFromParent();

    if (TSubclassOf<UUserWidget> WaitingRoomWidgetClass = LoadClass<UUserWidget>(nullptr, TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/TreadMill/BluePrints/Widget/BP_WaitingRoom.BP_WaitingRoom_C'")))
    {
        UUserWidget* WaitingRoomWidget = CreateWidget<UUserWidget>(GetWorld(), WaitingRoomWidgetClass);
        if (WaitingRoomWidget)
        {
            WaitingRoomWidget->AddToViewport();
        }
    }
}

void UMainMenuWidget::OnLockerButtonClicked()
{
    // 보관함 버튼 클릭 처리
}

void UMainMenuWidget::OnSettingsButtonClicked()
{
    if (TSubclassOf<UUserWidget> SettingWidgetClass = LoadClass<UUserWidget>(nullptr, TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/TreadMill/BluePrints/Widget/BP_SettingWidget.BP_SettingWidget_C'")))
    {
        UUserWidget* SettingsWidget = CreateWidget<UUserWidget>(GetWorld(), SettingWidgetClass);
        if (SettingsWidget)
        {
            SettingsWidget->AddToViewport();
        }
    }
}

void UMainMenuWidget::OnExitGameButtonClicked()
{
    UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
}

void UMainMenuWidget::OnPlayButtonHovered()
{
    if (PlayButtonHoverImage)
    {
        PlayButtonHoverImage->SetVisibility(ESlateVisibility::Visible);
    }
}

void UMainMenuWidget::OnPlayButtonUnhovered()
{
    if (PlayButtonHoverImage)
    {
        PlayButtonHoverImage->SetVisibility(ESlateVisibility::Hidden);
    }
}

void UMainMenuWidget::OnLockerButtonHovered()
{
    if (LockerButtonsHoverImage)
    {
        LockerButtonsHoverImage->SetVisibility(ESlateVisibility::Visible);
    }
}

void UMainMenuWidget::OnLockerButtonUnhovered()
{
    if (LockerButtonsHoverImage)
    {
        LockerButtonsHoverImage->SetVisibility(ESlateVisibility::Hidden);
    }
}

void UMainMenuWidget::OnSettingsButtonHovered()
{
    if (SettingsButtonsHoverImage)
    {
        SettingsButtonsHoverImage->SetVisibility(ESlateVisibility::Visible);
    }
}

void UMainMenuWidget::OnSettingsButtonUnhovered()
{
    if (SettingsButtonsHoverImage)
    {
        SettingsButtonsHoverImage->SetVisibility(ESlateVisibility::Hidden);
    }
}

void UMainMenuWidget::OnExitButtonHovered()
{
    if (ExitButtonsHoverImage)
    {
        ExitButtonsHoverImage->SetVisibility(ESlateVisibility::Visible);
    }
}

void UMainMenuWidget::OnExitButtonUnhovered()
{
    if (ExitButtonsHoverImage)
    {
        ExitButtonsHoverImage->SetVisibility(ESlateVisibility::Hidden);
    }
}
