// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileActor.h"

#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

#include "Target.h"
#include "TopdownGameMode.h"

// Sets default values
AProjectileActor::AProjectileActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bouncesBeforeDestroy = INT_MAX;

	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>("Static mesh");

	projectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>("Projectile movement");
	projectileMovement->InitialSpeed = 2000.f;
	projectileMovement->MaxSpeed = 2000.f;
	projectileMovement->bShouldBounce = true;

	SetRootComponent(staticMesh);

	OnActorHit.AddDynamic(this, &AProjectileActor::OnActorHitCallback);
}

// Called when the game starts or when spawned
void AProjectileActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectileActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectileActor::OnActorHitCallback(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	if (AProjectileActor* projectile = Cast<AProjectileActor>(SelfActor)) {
		projectile->bouncesBeforeDestroy -= 1;

		if (ATarget* target = Cast<ATarget>(OtherActor)) {
			if (ATopdownGameMode* gameMode = Cast<ATopdownGameMode>(GetWorld()->GetAuthGameMode())) {
				gameMode->OnTargetHit();
			}
			target->Destroy();
		}

		if (projectile->bouncesBeforeDestroy == 0) {
			Destroy();
		}
	}
}

