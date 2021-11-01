// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpectatorPawn.h"
#include "FreeCameraPawn.generated.h"

/**
 * 
 */
class UUserWidget;
UCLASS()
class PROCEDURALCONTENT_API AFreeCameraPawn : public ASpectatorPawn
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI", meta = (AllowPrivateAccess = "true"))
	UUserWidget* PirateInformationWidget;
	
	void UpdateWidget(FString what, FName field);
};
