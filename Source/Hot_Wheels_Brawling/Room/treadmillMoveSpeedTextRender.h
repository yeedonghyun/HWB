// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TextRenderActor.h"
#include "Components/TextRenderComponent.h"
#include "treadmillMoveSpeedTextRender.generated.h"

UCLASS()
class HOT_WHEELS_BRAWLING_API AtreadmillMoveSpeedTextRender : public AActor
{
	GENERATED_BODY()

public:
	AtreadmillMoveSpeedTextRender();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	float floorSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	float floorMaxSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	float speedIncreasePerSec;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	int limitText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	FColor textColor;

private:
	UPROPERTY(VisibleAnywhere)
	UTextRenderComponent* floorMaxSpeedTextRenderComp;
};