// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponComponent.h"
#include "RangedWeapon.generated.h"

/**
 * 
 */
UCLASS()
class PROCEDURALCONTENT_API URangedWeapon : public UWeaponComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DATA", meta = (AllowPrivateAccess = "true"))
	float rechageTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DATA", meta = (AllowPrivateAccess = "true"))
	int range;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DATA", meta = (AllowPrivateAccess = "true"))
	int ammunition;

};
