// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileShooterComponent.h"

#include "ProjectileActor.h"

// Sets default values for this component's properties
UProjectileShooterComponent::UProjectileShooterComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UProjectileShooterComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UProjectileShooterComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}



void UProjectileShooterComponent::Shoot()
{
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Cyan, TEXT("Shoot pressed"));
	}

	if (bulletClass) {

		auto owner = GetOwner();

		FActorSpawnParameters spawnParams;
		spawnParams.bNoFail = true;
		spawnParams.Owner = owner; // The bullet owner is our owner actually
		// spawnParams.Instigator = GetOwner(); How is it not an APawn?
		spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		FTransform transform;
		transform.SetLocation(owner->GetActorLocation() + owner->GetActorForwardVector() * 10 + owner->GetActorRightVector() * 5.0f);
		transform.SetRotation(owner->GetActorRotation().Quaternion());
		transform.SetScale3D(FVector(1.0f));

		GetWorld()->SpawnActor<AProjectileActor>(bulletClass, transform, spawnParams);

	}
}
