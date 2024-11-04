#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "../MeshManager.h"
#include "C_CH_CarBase_SecondPlayer.generated.h"

UCLASS()
class HOT_WHEELS_BRAWLING_API AC_CH_CarBase_SecondPlayer : public AWheeledVehiclePawn
{
	GENERATED_BODY()

public:
	AC_CH_CarBase_SecondPlayer(); 

	MeshManager MeshManager;
	//Movement functions
	void MoveForward(float value);
	void MoveBackward(float value);
	void MoveRL(float value);
	void BrakePressed();
	void BrakeReleased();

	//Look
	void LookUpDown(float value);
	void LookRL(float value);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UAudioComponent* EngineSoundC;

	//end movement functions
	static int meshindex;
	static bool bFalled;

private:

	float BoostProgress;

protected:
	virtual void Tick(float DeltaSeconds) override;

};
