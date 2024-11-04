// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "MakersWidget.generated.h"

/**
 * 
 */
UCLASS()
class HOT_WHEELS_BRAWLING_API UMakersWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

private:
	UPROPERTY(meta = (BindWidget))
	UButton* MakersToSettings;

	UFUNCTION()
	void MakersToSettingsClicked();
};
