#include "StatsBattle.h"
#include <iostream>
// Fill out your copyright notice in the Description page of Project Settings.


#include "StatsBattle.h"

// Sets default values for this component's properties
UStatsBattle::UStatsBattle()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


	// ...
}

void UStatsBattle::InitializeStats()
{
	Health = FMath::RandRange(50, 70);

	Melee = FMath::RandRange(40, 60);
	Firearms = FMath::RandRange(30, 50);
	Artillery = FMath::RandRange(20, 30);
	Sailing = FMath::RandRange(30, 50);
	Speed = FMath::RandRange(60, 80);
	Fierceness = FMath::RandRange(40, 60);
	MeleeDefense = FMath::RandRange(20, 40);
	Roguery = FMath::RandRange(0, 10);

	Dodge = FMath::RandRange(0, 10);

}


// Called when the game starts
void UStatsBattle::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UStatsBattle::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

