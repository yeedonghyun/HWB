#include "Hot_Wheels_Brawling/Characters/C_CH_CarBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "ChaosWheeledVehicleMovementComponent.h"
#include "Hot_Wheels_Brawling/Widget/ScoreWidget.h"
#include "Components/AudioComponent.h" 

int AC_CH_CarBase::meshindex = 0;
bool AC_CH_CarBase::bFalled = false;

AC_CH_CarBase::AC_CH_CarBase()
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

void AC_CH_CarBase::Tick(float DeltaSeconds)
{
	UChaosWheeledVehicleMovementComponent* vehicleComponent = Cast<UChaosWheeledVehicleMovementComponent>(GetVehicleMovementComponent());
	if (!vehicleComponent)
	{
		return;
	}
	EngineSoundC->SetFloatParameter(FName("RPM"), vehicleComponent->GetEngineRotationSpeed());
}

void AC_CH_CarBase::MoveForward(float value)
{
	GetVehicleMovementComponent()->SetThrottleInput(value);

	/*UE_LOG(LogTemp, Warning, TEXT("ASDF"));*/
}

void AC_CH_CarBase::MoveBackward(float value)
{
	GetVehicleMovementComponent()->SetBrakeInput(value);
}

void AC_CH_CarBase::MoveRL(float value)
{
	GetVehicleMovementComponent()->SetSteeringInput(value);
}

void AC_CH_CarBase::BrakePressed()
{
	GetVehicleMovementComponent()->SetHandbrakeInput(true);
}

void AC_CH_CarBase::BrakeReleased()
{
	GetVehicleMovementComponent()->SetHandbrakeInput(false);
}

void AC_CH_CarBase::LookUpDown(float value)
{
	AddControllerPitchInput(value * -1);
}

void AC_CH_CarBase::LookRL(float value)
{
	AddControllerYawInput(value);
}
