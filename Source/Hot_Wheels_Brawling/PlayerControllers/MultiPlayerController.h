#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "../Characters/C_CH_CarBase.h"
#include "../Characters/C_CH_CarBase_SecondPlayer.h"
#include "Hot_Wheels_Brawling/Widget/ScoreWidget.h"
#include "MultiPlayerController.generated.h"

UCLASS()
class HOT_WHEELS_BRAWLING_API AMultiPlayerController : public APlayerController
{
    GENERATED_BODY()

protected:
    void BeginPlay();
    void PossessPawn();

    AC_CH_CarBase* player1;
    AC_CH_CarBase_SecondPlayer* player2;

    FTimerHandle TimerHandle;

protected:
    virtual void SetupInputComponent() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    UScoreWidget* PlayerScoreWidget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UScoreWidget> PlayerScoreWidgetClass;

public:
    void MoveForward_player1(float value);
    void MoveBackward_player1(float value);
    void MoveRL_player1(float value);
    void BrakePressed_player1();
    void BrakeReleased_player1();

    void MoveForward_player2(float value);
    void MoveBackward_player2(float value);
    void MoveRL_player2(float value);
    void BrakePressed_player2();
    void BrakeReleased_player2();

    virtual void Tick(float DeltaTime) override;

    /*UFUNCTION()
    void OnShiftPressed();

    UFUNCTION()
    void OnShiftPressedPlayer2();*/

private:
    bool bGameOverTriggered;
    bool bPlayer1GameOver;
    bool bPlayer2GameOver;

    void GameOverEvent();
};