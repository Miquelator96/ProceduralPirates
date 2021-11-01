// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Pirate.generated.h"

class AFreeCameraPawn;
class UWeaponComponent;
class APirateAIController;

USTRUCT(BlueprintType)
struct FInfoPerson
{
	GENERATED_BODY()

public:
		UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "BASE")
		int PositionInShip;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "BASE", meta = (AllowPrivateAccess = "true"))
		FString NamePerson;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "BASE", meta = (AllowPrivateAccess = "true"))
		int FacialHair;
		int Level;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "BATTLE STATS")
		int Health = 0;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "BATTLE STATS")
		int Melee = 0;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "BATTLE STATS")
		int Firearms = 0;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "BATTLE STATS")
		int Fierceness = 0;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "BATTLE STATS")
		int Dodge = 0;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "BATTLE STATS")
		int MeleeDefense = 0;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "BATTLE STATS")
		int Artillery = 0;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "BATTLE STATS")
		int Sailing = 0;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "BATTLE STATS")
		int Speed = 0;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "BATTLE STATS")
		int Roguery = 0;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "EQUIPMENT")
		FName EquippedWeapon = "Sword";
		UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "EQUIPMENT")
		FName EquippedHat = "BlackHat";

		FInfoPerson() {

	}

};

UCLASS()
class PROCEDURALCONTENT_API APirate : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APirate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FInfoPerson infoPirate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PIRATE DATA", meta = (AllowPrivateAccess = "true"))
	int team;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PIRATE DATA", meta = (AllowPrivateAccess = "true"))
	UMeshComponent* Body;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXPERIENCE", meta = (AllowPrivateAccess = "true"))
	int level = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXPERIENCE", meta = (AllowPrivateAccess = "true"))
	int experience = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXPERIENCE", meta = (AllowPrivateAccess = "true"))
	int experienceToNextLevel = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NAVIGATION", meta = (AllowPrivateAccess = "true"))
	APirateAIController* PirateController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EQUIPMENT", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* EquippedWeaponMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EQUIPMENT", meta = (AllowPrivateAccess = "true"))
	UActorComponent* EquippedWeapon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EQUIPMENT", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* EquippedHat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BODY", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* FacialHairMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OTHER", meta = (AllowPrivateAccess = "true"))
	AFreeCameraPawn* PlayerPawn;

	void EquipWeapon(UWeaponComponent* weapon, UStaticMesh* mesh);
	void SetTeam(int team_);

	// declare overlap begin function
	UFUNCTION()
	void OnBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void InitializeInfo() {
		infoPirate.Level = 1;
		infoPirate.Health = FMath::RandRange(50, 70);
		infoPirate.Melee = FMath::RandRange(40, 60);
		infoPirate.Firearms = FMath::RandRange(30, 50);
		infoPirate.Artillery = FMath::RandRange(20, 30);
		infoPirate.Sailing = FMath::RandRange(30, 50);
		infoPirate.Speed = FMath::RandRange(60, 80);
		infoPirate.Fierceness = FMath::RandRange(40, 60);
		infoPirate.MeleeDefense = FMath::RandRange(20, 40);
		infoPirate.Roguery = FMath::RandRange(0, 10);
		infoPirate.Dodge = FMath::RandRange(0, 10);
	}

};
