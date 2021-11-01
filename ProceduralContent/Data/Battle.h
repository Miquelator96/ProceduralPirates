// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Battle.generated.h"

class UGlobalInformation;
class UWeaponComponent;
class APirate;
class APositionInShip;
UCLASS()
class PROCEDURALCONTENT_API ABattle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABattle();
	//virtual void SetupInputComponent() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	APirate* GeneratePirate(int team, FTransform position, int whichPirate);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "OTHER")
	TSubclassOf<APirate> PiratesSubclass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PIRATES")
	TArray<APirate*> piratesTeam0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PIRATES")
	TArray<APirate*> piratesTeam1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "DATA")
	class UDataTable* NamesToChoose;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "DATA")
	class UGlobalInformation* GI;

private: 
	void GenerateTeams();



};
