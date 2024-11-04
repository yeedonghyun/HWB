// Fill out your copyright notice in the Description page of Project Settings.


#include "C_WheelFront.h"

UC_WheelFront::UC_WheelFront()
{
	AxleType = EAxleType::Front;
	bAffectedByEngine = true;
	bAffectedBySteering = true;
	MaxSteerAngle = 45;
}