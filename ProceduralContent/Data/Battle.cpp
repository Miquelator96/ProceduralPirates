// Fill out your copyright notice in the Description page of Project Settings.


#include "Battle.h"
#include "Kismet/GameplayStatics.h" 
#include "ProceduralContent/Characters/Pirate.h"
#include "ProceduralContent/Weapons/WeaponComponent.h"
#include "ProceduralContent/Weapons/RangedWeapon.h"
#include "ProceduralContent/Weapons/MeleeWeapon.h"
#include "ProceduralContent/Data/GlobalInformation.h"
#include "ProceduralContent/ShipLevel/PositionInShip.h"
#include "Math/UnrealMathUtility.h" 
#include "Engine/DataTable.h" 
#include "Misc/OutputDeviceNull.h"


// Sets default values
ABattle::ABattle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Load possible names
	static ConstructorHelpers::FObjectFinder<UDataTable> PossibleNamesDataObject(TEXT("DataTable'/Game/Data/PossibleNames.PossibleNames'"));
	if (PossibleNamesDataObject.Succeeded()) NamesToChoose = PossibleNamesDataObject.Object;
	
}

//void ABattle::SetupInputComponent()
//{
	// Always call this.
	//Super::SetupInputComponent();

	// This is initialized on startup, you can go straight to binding
//	InputComponent->BindAction("Jump", IE_Pressed, this, &AUnrealisticPlayerController::Jump);
//}

// Called when the game starts or when spawned
void ABattle::BeginPlay()
{
	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	GI = GetWorld()->GetGameInstance<UGlobalInformation>();
	GenerateTeams();

	Super::BeginPlay();
}


// Called every frame
void ABattle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABattle::GenerateTeams()
{
	TArray<class AActor*> positions;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "PositionTeam0", positions);



	
	for (AActor* position : positions)
	{
		int posNum = Cast<APositionInShip>(position)->PirateAssigned;

		if (posNum >= 0) piratesTeam0.Add(GeneratePirate(0, position->GetTransform(),posNum));
		position->Destroy();
	}

	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "PositionTeam1", positions);
	for (AActor* position : positions)
	{
		//piratesTeam1.Add(GeneratePirate(1, position->GetTransform(), ));
		position->Destroy();
	}

}

APirate* ABattle::GeneratePirate(int team, FTransform position, int whichPirate)
{

	UWorld* const World = GetWorld();
	if (World)
	{

		UGlobalInformation* gi = GetWorld()->GetGameInstance<UGlobalInformation>();

		APirate* pirate = World->SpawnActor<APirate>(PiratesSubclass,position);
		pirate->team = team;
		
		UWeaponComponent* chosenWeapon = nullptr;

		//If the position is of the player's team, load info from tavern and load weapon
		if (team == 0) {
			pirate->infoPirate = gi->infos[whichPirate];
			//UE_LOG(LogTemp, Warning, TEXT("Output: %s"), *gi->infos[whichPirate].NamePerson);
			chosenWeapon = *GI->WeaponsAvailable.Find(pirate->infoPirate.EquippedWeapon);

		}

		//If enemy, choose random weapon
		else {
			chosenWeapon = *GI->WeaponsAvailable.Find(GI->WeaponNames[rand() % GI->WeaponNames.Num()]);
			pirate->infoPirate.EquippedHat = GI->HatNames[rand() % GI->HatNames.Num()];
		}
		pirate->EquippedHat->SetStaticMesh(*GI->HatMeshes.Find(pirate->infoPirate.EquippedHat));
		pirate->EquipWeapon(chosenWeapon, GI->WeaponMeshes[chosenWeapon->meshIndex]);
		FOutputDeviceNull ar;
		pirate->CallFunctionByNameWithArguments(TEXT("UpdateTeam"), ar, NULL, true);
		
		return pirate;
	}
	
	return nullptr;
}


