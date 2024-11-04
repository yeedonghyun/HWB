// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "LoadingWidget.generated.h"

/**
 * 
 */
UCLASS()
class HOT_WHEELS_BRAWLING_API ULoadingWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void HideLoaidngWidget();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loading")
	TArray<FString> LoadingMessages;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* LoadingTextBlock;

	UFUNCTION(BlueprintCallable, Category = "Loading")
	void SetRandomLoadingMessage();

protected:
	virtual void NativeConstruct() override;

};
