// Fill out your copyright notice in the Description page of Project Settings.


#include "Target.h"

#include <Components/StaticMeshComponent.h>

// Sets default values
ATarget::ATarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>("Static mesh");

	SetRootComponent(staticMesh);

	moveScale = 200.f;
}

// Called when the game starts or when spawned
void ATarget::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector moveDirection = FMath::VRand();
	moveDirection.Z = 0.0f;
	moveDirection.Normalize();

	FVector moveDelta = moveDirection * moveScale * DeltaTime;

	AddActorWorldOffset(moveDelta, true);
}

