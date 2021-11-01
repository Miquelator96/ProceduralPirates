// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PiratePlayerController.generated.h"

/**
 * 
 */
class APirate;
class UUserWidget;
UCLASS()
class PROCEDURALCONTENT_API APiratePlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void SetupInputComponent() override;

	void ToggleMouse();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI", meta = (AllowPrivateAccess = "true"))
	UUserWidget* PirateInformationWidget;

	void UpdateWidget(FString what, FName field);


	UPROPERTY(EditAnywhere, BlueprintReadWrite)

	bool ShowingMouse = false;

	UPROPERTY()
	APirate* SelectedPirate;
};
