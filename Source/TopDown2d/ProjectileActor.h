// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileActor.generated.h"

// We SHOULD really rename this class
UCLASS()
class TOPDOWN2D_API AProjectileActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called everytime an object has been hit
	UFUNCTION()
	void OnActorHitCallback(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	class UProjectileMovementComponent* projectileMovement;

private:
	UPROPERTY(EditAnywhere, Category = "Components")
	class UStaticMeshComponent* staticMesh;

	UPROPERTY(EditAnywhere, Category = "Settings");
	uint32 bouncesBeforeDestroy;

};
