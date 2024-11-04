// Fill out your copyright notice in the Description page of Project Settings.


#include "FixedCamera.h"

AFixedCamera::AFixedCamera()
{
    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
    RootComponent = CameraComponent;
}
