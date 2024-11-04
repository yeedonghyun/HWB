// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "../Characters/C_CH_CarBase.h"
#include "../Characters/C_CH_CarBase_SecondPlayer.h"
#include "../MeshManager.h"
#include "WaitingRoomWidget.generated.h"

/**
 *
 */
UCLASS()
class HOT_WHEELS_BRAWLING_API UWaitingRoomWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

private:

	UPROPERTY(meta = (BindWidget))
	UButton* Play;

	UPROPERTY(meta = (BindWidget))
	UButton* BackToMenu;

	UPROPERTY(meta = (BindWidget))
	UButton* player1Left;

	UPROPERTY(meta = (BindWidget))
	UButton* player1Right;

	UPROPERTY(meta = (BindWidget))
	UButton* player2Left;

	UPROPERTY(meta = (BindWidget))
	UButton* player2Right;

	UFUNCTION()
	void PlayClicked();

	UFUNCTION()
	void BackToMenuClicked();

	UFUNCTION()
	void SelectPlayer1LeftSkin();

	UFUNCTION()
	void SelectPlayer1RightSkin();

	UFUNCTION()
	void SelectPlayer2LeftSkin();

	UFUNCTION()
	void SelectPlayer2RightSkin();

	MeshManager MeshManager;

	AC_CH_CarBase* player1;
	AC_CH_CarBase_SecondPlayer* player2;

	void PossessPawn();

	FTimerHandle TimerHandle;

};
