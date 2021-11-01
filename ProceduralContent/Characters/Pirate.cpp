// Fill out your copyright notice in the Description page of Project Settings.


#include "Pirate.h"
#include "ProceduralContent/Components/StatsBattle.h"
#include "ProceduralContent/PlayerPawns/FreeCameraPawn.h"
#include "Kismet/GameplayStatics.h"
#include "ProceduralContent/Components/PirateAIController.h"
#include "ProceduralContent/Weapons/WeaponComponent.h"



// Sets default values
APirate::APirate()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	EquippedWeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("WeaponComp"));
	EquippedWeaponMesh->SetupAttachment(RootComponent);

	EquippedHat = CreateDefaultSubobject<UStaticMeshComponent>(FName("Hat"));
	EquippedHat->SetupAttachment(RootComponent);

	FacialHairMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("FacialHair"));
	FacialHairMesh->SetupAttachment(RootComponent);

	Body = CreateDefaultSubobject<UStaticMeshComponent>(FName("Body"));
	Body->SetupAttachment(RootComponent);
	Body->OnComponentBeginOverlap.AddDynamic(this, &APirate::OnBeginOverlap);

	//BattleStats = CreateDefaultSubobjects<BattleStats>();

}

// Called when the game starts or when spawned
void APirate::BeginPlay()
{
	InitializeInfo();
	PlayerPawn = Cast <AFreeCameraPawn> (UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	/*PirateStats = FindComponentByClass<UStatsBattle>();

	if (PirateStats) {
		PirateStats->InitializeStats();
	}*/

	PirateController = GetWorld()->SpawnActor<APirateAIController>(AIControllerClass, GetActorLocation(), GetActorRotation());
	PirateController->Possess(this);
	//PirateController->MoveToLocation(FVector(1700, 2060, 0));
	/*
	TArray<UStaticMeshComponent*> Components;
	GetOwner()->GetComponents<UStaticMeshComponent>(Components);
	UE_LOG(LogTemp, Warning, TEXT("Size =, %d"), Components.Num());
	*/


	Super::BeginPlay();
}

// Called every frame
void APirate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APirate::SetTeam(int _team) {
	team = _team;
}

// Called to bind functionality to input
void APirate::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APirate::EquipWeapon(UWeaponComponent* weapon, UStaticMesh* mesh)
{
	EquippedWeapon = weapon;
	EquippedWeaponMesh->SetStaticMesh(mesh);
	infoPirate.EquippedWeapon = weapon->WeaponName;
}

void APirate::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	PlayerPawn->UpdateWidget(infoPirate.NamePerson, "Name");
	
}





