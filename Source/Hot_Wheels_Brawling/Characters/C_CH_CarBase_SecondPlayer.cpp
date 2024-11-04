#pragma once

#include "C_CH_CarBase_SecondPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "ChaosWheeledVehicleMovementComponent.h"
#include "ChaosVehicleMovementComponent.h"
#include "Components/AudioComponent.h" 

int AC_CH_CarBase_SecondPlayer::meshindex = 0;
bool AC_CH_CarBase_SecondPlayer::bFalled = false;

AC_CH_CarBase_SecondPlayer::AC_CH_CarBase_SecondPlayer()
{
	//SpringArmC = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	//SpringArmC->SetupAttachment(RootComponent);
	//SpringArmC->TargetArmLength = 600;
	//SpringArmC->SetRelativeLocation(FVector(0, 0, 140));
	//SpringArmC->SetRelativeRotation(FRotator(-10, 0, 0));
	//SpringArmC->bUsePawnControlRotation = true;
	//CameraC = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	//CameraC->SetupAttachment(SpringArmC);

	EngineSoundC = CreateDefaultSubobject<UAudioComponent>(TEXT("Engine Sound"));
	EngineSoundC->SetupAttachment(GetMesh());
}

void AC_CH_CarBase_SecondPlayer::Tick(float DeltaSeconds)
{
	UChaosWheeledVehicleMovementComponent* vehicleComponent = Cast<UChaosWheeledVehicleMovementComponent>(GetVehicleMovementComponent());
	if (!vehicleComponent)
	{
		return;
	}
	EngineSoundC->SetFloatParameter(FName("RPM"), vehicleComponent->GetEngineRotationSpeed());
}

void AC_CH_CarBase_SecondPlayer::MoveForward(float value)
{
	GetVehicleMovementComponent()->SetThrottleInput(value);

	/*UE_LOG(LogTemp, Warning, TEXT("ASDF"));*/
}

void AC_CH_CarBase_SecondPlayer::MoveBackward(float value)
{
	GetVehicleMovementComponent()->SetBrakeInput(value);
}

void AC_CH_CarBase_SecondPlayer::MoveRL(float value)
{
	GetVehicleMovementComponent()->SetSteeringInput(value);
}

void AC_CH_CarBase_SecondPlayer::BrakePressed()
{
	GetVehicleMovementComponent()->SetHandbrakeInput(true);
}

void AC_CH_CarBase_SecondPlayer::BrakeReleased()
{
	GetVehicleMovementComponent()->SetHandbrakeInput(false);
}

void AC_CH_CarBase_SecondPlayer::LookUpDown(float value)
{
	AddControllerPitchInput(value * -1);
}

void AC_CH_CarBase_SecondPlayer::LookRL(float value)
{
	AddControllerYawInput(value);
}



