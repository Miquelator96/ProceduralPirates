// Fill out your copyright notice in the Description page of Project Settings.


#include "Tavern.h"
#include "Kismet/GameplayStatics.h" 
#include "ProceduralContent/Weapons/WeaponComponent.h"
#include "ProceduralContent/Weapons/RangedWeapon.h"
#include "ProceduralContent/Weapons/MeleeWeapon.h"
#include "ProceduralContent/Controllers/PiratePlayerController.h"
#include "Math/UnrealMathUtility.h" 
#include "Blueprint/UserWidget.h" 
#include "Blueprint/WidgetTree.h" 
#include "Engine/DataTable.h" 
#include "ProceduralContent/Data/GlobalInformation.h"
#include "ProceduralContent/Characters/Pirate.h"
#include "ProceduralContent/Components/StatsBattle.h"

// Sets default values
ATavern::ATavern()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATavern::BeginPlay()
{
	Super::BeginPlay();

	GI = GetWorld()->GetGameInstance<UGlobalInformation>();
	PlayerController = Cast<APiratePlayerController>(GetWorld()->GetFirstPlayerController());	
}

// Called every frame
void ATavern::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ATavern::GenerateShowcasePirate()
{
	UWorld* const World = GetWorld();
	if (World)
	{
		ShowcasePirate->team = 0;

		ShowcasePirate->infoPirate.FacialHair = rand() % GI->FacialMeshes.Num();
		ShowcasePirate->FacialHairMesh->SetStaticMesh(*GI->FacialMeshes.Find(ShowcasePirate->infoPirate.FacialHair));

		ShowcasePirate->infoPirate.EquippedWeapon = GI->WeaponNames[rand() % GI->WeaponNames.Num()];
		UWeaponComponent* chosenWeapon = *GI->WeaponsAvailable.Find(ShowcasePirate->infoPirate.EquippedWeapon);
		ShowcasePirate->EquipWeapon(chosenWeapon, GI->WeaponMeshes[chosenWeapon->meshIndex]);

		ShowcasePirate->infoPirate.EquippedHat = GI->HatNames[rand() % GI->HatNames.Num()];
		ShowcasePirate->EquippedHat->SetStaticMesh(*GI->HatMeshes.Find(ShowcasePirate->infoPirate.EquippedHat));

		ShowcasePirate->InitializeInfo();

		if (PossibleNames.Num() > 0)	ShowcasePirate->infoPirate.NamePerson = PossibleNames[rand() % PossibleNames.Num()];
		ShowcasePirate->infoPirate.NamePerson.Append(" ");
		if (PossibleLastNames.Num() > 0) ShowcasePirate->infoPirate.NamePerson.Append(PossibleLastNames[rand() % PossibleLastNames.Num()]);


	}
}

void ATavern::AddCrewmember()
{
	GI->Crew.Add(ShowcasePirate);

	GI->CurrentCrew++;
}



