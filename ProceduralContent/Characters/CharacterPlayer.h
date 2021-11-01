// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "ProceduralContent/Controllers/PiratePlayerController.h"
#include "CharacterPlayer.generated.h"

class APirate;
class APiratePlayerController;
UCLASS()
class PROCEDURALCONTENT_API ACharacterPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void VerticalRot(float amount);
	void VerticalMove(float Value);
	void HorizontalMove(float Value);
	void HorizontalRot(float Value);

//	void HandleClick(FHitResult HitResult);
	void RaycastFromCursor();


	UPROPERTY()
	UCameraComponent* cam;
	UPROPERTY()
	float YawRotation = 0;
	UPROPERTY()
	float PitchRotation = 0;

	UPROPERTY()
	APiratePlayerController* playerController;


};
