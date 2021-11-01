// Fill out your copyright notice in the Description page of Project Settings.
#include "PirateAIController.h"

#include "ProceduralContent/Characters/Pirate.h"
#include "Kismet/GameplayStatics.h"
#include "PirateAIController.h"



void APirateAIController::BeginPlay()
{
	Super::BeginPlay();
	/*SetFocus(PlayerPawn);
	MoveToActor(PlayerPawn, 100);*/

	//ControlledPirate = Cast<APirate>(GetPawn());
	//ControlledPirate->SetAIController(this);
}

void APirateAIController::SetControlledPirate(APirate* _ControlledPirate)
{
	
	ControlledPirate = _ControlledPirate;
}
