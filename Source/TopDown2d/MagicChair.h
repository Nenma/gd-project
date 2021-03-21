// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Character.h"
#include "MagicChair.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOPDOWN2D_API UMagicChair : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMagicChair();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UFUNCTION(BlueprintCallable)
	void DoMagic(ACharacter* character);
	
	UFUNCTION(BlueprintCallable)
	void Dissapear();

private:

	UPROPERTY(EditAnywhere, Category = "Info")
	float HeightToAdd = 1000.f;

	UPROPERTY(EditAnywhere, Category = "Info")
	float Speed = 30.f;

	float t = 1.0f;

	FVector StartPosition;
	FVector EndPosition;
};
