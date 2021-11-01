// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tavern.generated.h"

class UGlobalInformation;
class APiratePlayerController;
class UWeaponComponent;
class APirate;
UCLASS()
class PROCEDURALCONTENT_API ATavern : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATavern();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "RECRUITING")
	void AddCrewmember();


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WEAPONS")
		TArray<UWeaponComponent*> WeaponsAvailable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WEAPONS")
		TArray<UStaticMesh*> WeaponMeshes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CLOTHING")
	TArray<UStaticMesh*> HatMeshes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "DATA")
	class UDataTable* NamesToChoose;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DATA")
	TArray<FString> PossibleNames;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DATA")
	TArray<FString> PossibleLastNames;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "DATA")
	class UGlobalInformation* GI;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "RECRUITING")
	TArray<APirate*> AvailablePirates;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RECRUITING")
	APirate* ShowcasePirate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "RECRUITING")
	int chosenIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI", meta = (AllowPrivateAccess = "true"))
	APiratePlayerController* PlayerController;

	UFUNCTION(BlueprintCallable, Category="RECRUITING")
	void GenerateShowcasePirate();



	
};
