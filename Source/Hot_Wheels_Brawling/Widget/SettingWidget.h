// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "SettingWidget.generated.h"

/**
 * 
 */
UCLASS()
class HOT_WHEELS_BRAWLING_API USettingWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

private:
	UPROPERTY(meta = (BindWidget))
	UButton* SettingGoBack;

	UPROPERTY(meta = (BindWidget))
	UButton* KeySettingsButton;

	UPROPERTY(meta = (BindWidget))
	UButton* MakersButton;

	UFUNCTION()
	void SettingGoBackClicked();

	UFUNCTION()
	void KeySettingsButtonClicked();

	UFUNCTION()
	void MakersButtonClicked();
};
