// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TopdownGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWN2D_API ATopdownGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATopdownGameMode();

	void OnTargetHit();

private:
	UPROPERTY(EditAnywhere, Category = "Game rules")
	unsigned int TargetsForWin;

};
