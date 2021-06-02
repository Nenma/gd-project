// Fill out your copyright notice in the Description page of Project Settings.


#include "MagicChair.h"
#include "ProjectileShooterComponent.h"

// Sets default values for this component's properties
UMagicChair::UMagicChair()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UMagicChair::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMagicChair::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	if (t < 1.0f) {
		auto newPosition = FMath::Lerp(StartPosition, EndPosition, t);
		GetOwner()->SetActorLocation(newPosition);

		t += DeltaTime * Speed;
	}
}

void UMagicChair::DoMagic(ACharacter* character)
{
	auto* projectileShooter = character->FindComponentByClass<UProjectileShooterComponent>();
	if (projectileShooter) {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Cyan,
											 TEXT("Hello! I am the magic chair and I will give you the magic super power of shooting smaller chairs!"));
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Cyan,
											 TEXT("But in order to advance in your adventure, you will have to touch me!"));
		}
		
		StartPosition = GetOwner()->GetActorLocation();
		EndPosition = StartPosition;
		EndPosition.Z += HeightToAdd;

		t = 0.0f;
	}

}

void UMagicChair::Dissapear() {

	if (t >= 1.0f) {
		GetOwner()->Destroy();

		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Cyan, TEXT("Congratulations! You can proceed with your adventure! Have a manea:"));
			
			// Will be used for another level
			/*GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Cyan, TEXT("Ce daca n - am bani si nu sunt bogat"));
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Cyan, TEXT("Dar traiesc la maxim si imi fac de cap"));
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Cyan, TEXT("Nu am nici masina, nu am nici piscina"));
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Cyan, TEXT("Dar cand fac un sprit o tin cate o luan"));*/

			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("Buna dimineata viata mea"));
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("Te astept la o cafea"));
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("Buna dimineata soarele meu"));
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("Frumos e zambetul tau"));
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("Buna dimineata viata mea"));
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("Te astept la o cafea"));
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("Buna dimineata soarele meu"));
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("Frumos e zambetul tau"));
		}
	}

}
