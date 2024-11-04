#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "MainMenuWidget.generated.h"

/**
 *
 */
UCLASS()
class HOT_WHEELS_BRAWLING_API UMainMenuWidget : public UUserWidget
{
    GENERATED_BODY()

protected:
    virtual void NativeConstruct() override;

private:
    UPROPERTY(meta = (BindWidget))
    UButton* PlayButton;

    UPROPERTY(meta = (BindWidget))
    UButton* LockerButton;

    UPROPERTY(meta = (BindWidget))
    UButton* SettingsButton;

    UPROPERTY(meta = (BindWidget))
    UButton* ExitGameButton;

    UPROPERTY(meta = (BindWidget))
    UImage* PlayButtonHoverImage;

    UPROPERTY(meta = (BindWidget))
    UImage* LockerButtonsHoverImage;

    UPROPERTY(meta = (BindWidget))
    UImage* SettingsButtonsHoverImage;

    UPROPERTY(meta = (BindWidget))
    UImage* ExitButtonsHoverImage;

    UFUNCTION()
    void OnPlayButtonClicked();

    UFUNCTION()
    void OnLockerButtonClicked();

    UFUNCTION()
    void OnSettingsButtonClicked();

    UFUNCTION()
    void OnExitGameButtonClicked();

    UFUNCTION()
    void OnPlayButtonHovered();

    UFUNCTION()
    void OnPlayButtonUnhovered();

    UFUNCTION()
    void OnLockerButtonHovered();

    UFUNCTION()
    void OnLockerButtonUnhovered();

    UFUNCTION()
    void OnSettingsButtonHovered();

    UFUNCTION()
    void OnSettingsButtonUnhovered();

    UFUNCTION()
    void OnExitButtonHovered();

    UFUNCTION()
    void OnExitButtonUnhovered();
};
