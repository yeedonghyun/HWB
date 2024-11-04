// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "KeySettingsWidget.generated.h"

/**
 * 
 */
UCLASS()
class HOT_WHEELS_BRAWLING_API UKeySettingsWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

private:
	UPROPERTY(meta = (BindWidget))
	UButton* KeyToSettings;

	UFUNCTION()
	void KeyToSettingsClicked();
};
