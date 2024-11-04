// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Hot_Wheels_Brawling/Widget/ScoreWidget.h"
#include "GameFramework/GameModeBase.h"
#include "SecondGameModeBase.generated.h"

UCLASS()
class HOT_WHEELS_BRAWLING_API ASecondGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASecondGameModeBase();

	virtual void BeginPlay() override;

	UScoreWidget* ScoreWidget;

protected:
	TSubclassOf<UUserWidget> MainHUDWidgetClass;
};