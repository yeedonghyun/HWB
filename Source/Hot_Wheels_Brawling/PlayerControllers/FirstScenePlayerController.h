#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "../Characters/C_CH_CarBase.h"
#include "../Characters/C_CH_CarBase_SecondPlayer.h"
#include "../MeshManager.h"
#include "FirstScenePlayerController.generated.h"


UCLASS()
class HOT_WHEELS_BRAWLING_API AFirstScenePlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void SetupInputComponent() override;
	void BeginPlay();
	void PossessPawn();

	AC_CH_CarBase* player1;
	AC_CH_CarBase_SecondPlayer* player2;

	FTimerHandle TimerHandle;

public:
	void Player1LeftMesh();
	void Player1RightMesh();
	void Player2LeftMesh();
	void Player2RightMesh();

	MeshManager MeshManager;
};