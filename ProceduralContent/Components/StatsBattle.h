// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StatsBattle.generated.h"




UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROCEDURALCONTENT_API UStatsBattle : public UActorComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "COMBAT", meta = (AllowPrivateAccess = "true"))
		int Health = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "COMBAT", meta = (AllowPrivateAccess = "true"))
		int Melee = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "COMBAT", meta = (AllowPrivateAccess = "true"))
		int Firearms = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "COMBAT", meta = (AllowPrivateAccess = "true"))
		int Fierceness = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "COMBAT", meta = (AllowPrivateAccess = "true"))
		int Dodge = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "COMBAT", meta = (AllowPrivateAccess = "true"))
		int MeleeDefense = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "INTERACT", meta = (AllowPrivateAccess = "true"))
		int Artillery = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "INTERACT", meta = (AllowPrivateAccess = "true"))
		int Sailing = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOVEMENT", meta = (AllowPrivateAccess = "true"))
		int Speed = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOVEMENT", meta = (AllowPrivateAccess = "true"))
		int Roguery = 0;


public:
	// Sets default values for this component's properties
	UStatsBattle();

	void InitializeStats();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;





};