// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "../MeshManager.h"
#include "C_CH_CarBase.generated.h"

UCLASS()
class HOT_WHEELS_BRAWLING_API AC_CH_CarBase : public AWheeledVehiclePawn
{
	GENERATED_BODY()

public:
	AC_CH_CarBase();

	MeshManager MeshManager;
	//UPROPERTY(BlueprintReadWrite, EditAnywhere)
	//class USpringArmComponent* SpringArmC;
	//UPROPERTY(BlueprintReadWrite, EditAnywhere)
	//class UCameraComponent* CameraC;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UAudioComponent* EngineSoundC;


	//Movement functions
	void MoveForward(float value);
	void MoveBackward(float value);
	void MoveRL(float value);
	void BrakePressed();
	void BrakeReleased();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UScoreWidget* MyScoreWidget;

	// 1 또는 2로 플레이어 인덱스를 구분하기 위한 변수
	int32 PlayerIndex;

	//Look
	void LookUpDown(float value);
	void LookRL(float value);

	//end movement functions

	static int meshindex;
	static bool bFalled;


protected:
	virtual void Tick(float DeltaSeconds) override;

	float BoostProgress;

};
