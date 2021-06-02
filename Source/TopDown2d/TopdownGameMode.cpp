// Fill out your copyright notice in the Description page of Project Settings.


#include "TopdownGameMode.h"
#include "TopdownGameState.h"

ATopdownGameMode::ATopdownGameMode() {

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TP_Character"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	TargetsForWin = 5;

}

void ATopdownGameMode::OnTargetHit() {
	if (ATopdownGameState* GS = Cast<ATopdownGameState>(GameState)) {
		GS->HitTargets++;
		if (GS->HitTargets >= TargetsForWin) {

			if (GEngine) {
				GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("Asa sunt zilele mele"));
				GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("Una buna, zece rele"));
				GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("Nu da Doamne cineva"));
				GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("Sa ma scape de lumea rea"));
				GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("Asa sunt zilele mele"));
				GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("Una buna, zece rele"));
				GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("Nu da Doamne cineva"));
				GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("Sa ma scape de lumea rea"));
			}

		} else {

			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString::Printf(TEXT("You scored a point. You now have %d points"), GS->HitTargets));

		}
	}

}
