// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponComponent.h"
#include "MeleeWeapon.generated.h"

/**
 * 
 */
UCLASS()
class PROCEDURALCONTENT_API UMeleeWeapon : public UWeaponComponent
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DATA", meta = (AllowPrivateAccess = "true"))
	float attackSpeed;
};
