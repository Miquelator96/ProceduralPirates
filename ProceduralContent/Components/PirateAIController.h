// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "PirateAIController.generated.h"

/**
 * 
 */
class APirate;
UCLASS()
class PROCEDURALCONTENT_API APirateAIController : public AAIController
{
	GENERATED_BODY()

	virtual void BeginPlay();

private:
	APirate* ControlledPirate;
	
public:
	void SetControlledPirate(APirate* _ControlledPirate);
};
