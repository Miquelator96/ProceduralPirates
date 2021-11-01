// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ProceduralContent/Characters/Pirate.h"
#include "GlobalInformation.generated.h"

/**
 * 
 */


class UWeaponComponent;
class APirate;
UCLASS()
class PROCEDURALCONTENT_API UGlobalInformation : public UGameInstance
{
	GENERATED_BODY()



public:
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<APirate*> Crew;
	
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int MaxCrew = 10;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FInfoPerson> infos;


		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		int CurrentCrew = 0;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BODY")
		TMap<int, UStaticMesh*> FacialMeshes;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "WEAPONS")
		TMap<FName, UWeaponComponent*> WeaponsAvailable;

		UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WEAPONS")
		TArray<UStaticMesh*> WeaponMeshes;

		UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WEAPONS")
		TArray<FName> WeaponNames;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CLOTHING")
		TMap<FName, UStaticMesh*> HatMeshes;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CLOTHING")
		TArray<FName> HatNames;




		virtual void Init() override;

		void SetupWeapon(FName name, float _accuracy, int damage, int _index);
		void SetupRangedWeapon(FName name, float _accuracy, int damage, int _index, float rechargeTime, int range, int ammunition);
		void SetupMeleeWeapon(FName name, float _accuracy, int damage, int _index, float attackSpeed);
};
