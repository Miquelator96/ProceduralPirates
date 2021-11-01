// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROCEDURALCONTENT_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DATA", meta = (AllowPrivateAccess = "true"))
		FName WeaponName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DATA", meta = (AllowPrivateAccess = "true"))
		float accuracy;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DATA", meta = (AllowPrivateAccess = "true"))
		int damage;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DATA", meta = (AllowPrivateAccess = "true"))
		int meshIndex;
	


	
};