// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "TopdownGameState.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWN2D_API ATopdownGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	ATopdownGameState();

	unsigned int HitTargets = 0;
	bool hasLevelChanged = false;

};
