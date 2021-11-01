// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterPlayer.h"
#include "GameFramework/Pawn.h" 
#include "ProceduralContent/Characters/Pirate.h"



#pragma region startFunctions
// Sets default values
ACharacterPlayer::ACharacterPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	bUseControllerRotationYaw = false;

	cam = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	cam->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void ACharacterPlayer::BeginPlay()
{
	playerController = Cast <APiratePlayerController> (GetController());

	Super::BeginPlay();
	
}

void ACharacterPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &ACharacterPlayer::VerticalMove);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACharacterPlayer::HorizontalMove);
	PlayerInputComponent->BindAxis("HorizontalRotation", this, &ACharacterPlayer::HorizontalRot);
	PlayerInputComponent->BindAxis("VerticalRotation", this, &ACharacterPlayer::VerticalRot);
	PlayerInputComponent->BindAction("Select", IE_Pressed, this, &ACharacterPlayer::RaycastFromCursor);


}

#pragma endregion


// Called every frame
void ACharacterPlayer::Tick(float DeltaTime)
{
	SetActorRotation(FRotator(PitchRotation, YawRotation, 0 ));

	Super::Tick(DeltaTime);
}


#pragma region basicControls
void ACharacterPlayer::VerticalRot(float amount) {
	if (amount && !playerController->ShowingMouse) PitchRotation += amount;
}

void ACharacterPlayer::HorizontalRot(float amount) {
	if (amount && !playerController->ShowingMouse) YawRotation += amount;
}

void ACharacterPlayer::VerticalMove(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

void ACharacterPlayer::HorizontalMove(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}
#pragma endregion

#pragma region selectNPC
 
/*
void ACharacterPlayer::HandleClick(FHitResult HitResult)
{
	FString NameClass = HitResult.Actor->GetClass()->GetName();

	if (NameClass.Equals("BP_Pirate_C")) {
		FOutputDeviceNull ar;

		AActor* TargetActor = HitResult.GetActor();



		if (SelectedActor == nullptr)
		{


			SelectedActor = TargetActor;

			APirate* TargetPirate = Cast<APirate>(HitResult.Actor);
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Seleccionat"));

			TargetPirate->CallFunctionByNameWithArguments(TEXT("ChangeStatus 2"), ar, NULL, true);


		}
		else {
			if (SelectedActor == TargetActor) {

				SelectedActor = nullptr;
				APirate* TargetPirate = Cast<APirate>(HitResult.Actor);
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Deseleccionat"));
				TargetPirate->CallFunctionByNameWithArguments(TEXT("ChangeStatus 0"), ar, NULL, true);

			}
		}


		/*
		else {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Moving"));
			APirate* TargetPirate = Cast<APirate>(HitResult.Actor);
			FOutputDeviceNull ar2;
			FVector vector = HitResult.Location;
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, vector.ToString());
			if (AIC) {
				AIC->MoveToLocation(HitResult.Location);
			}
			else {
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Controller Null"));
			}
		}
		
	}
	else {
		if (SelectedActor) {
			APirate* SelectedPirate = Cast<APirate>(SelectedActor);
			SelectedPirate->AIC->MoveToLocation(HitResult.Location);
		}






	}

}
*/
void ACharacterPlayer::RaycastFromCursor()
{
	APlayerController* pc = GetWorld()->GetFirstPlayerController();
	float LocationX;
	float LocationY;

	if (pc != nullptr) {

		pc->GetMousePosition(LocationX, LocationY);
		FVector2D MousePosition(LocationX, LocationY);
		FHitResult HitResult;
		const bool bTraceComplex = false;

		if (pc->GetHitResultAtScreenPosition(MousePosition, ECC_Visibility, bTraceComplex, HitResult)) {
			if (HitResult.GetActor() != nullptr) {

				AActor* TargetActor = HitResult.GetActor();
				APirate* auxPirate = Cast<APirate>(HitResult.Actor);
				if (auxPirate) {

					playerController->SelectedPirate =auxPirate;
					playerController->UpdateWidget(auxPirate->infoPirate.NamePerson, "Name");
					//	UE_LOG(LogTemp, Warning, TEXT("Output: %s"), *auxPirate->infoPirate.NamePerson);
				}
				//HandleClick(HitResult);
			}
		}

	}


}
#pragma endregion