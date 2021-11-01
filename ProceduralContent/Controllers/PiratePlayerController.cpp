// Fill out your copyright notice in the Description page of Project Settings.


#include "PiratePlayerController.h"
#include "Blueprint/UserWidget.h" 
#include "Blueprint/WidgetTree.h" 
#include "Components/TextBlock.h" 
#include "ProceduralContent/Characters/Pirate.h"

void APiratePlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    InputComponent->BindAction("ChangeSelectMode", IE_Pressed, this, &APiratePlayerController::ToggleMouse);
}

void APiratePlayerController::ToggleMouse()
{
    ShowingMouse = !ShowingMouse;
    bShowMouseCursor = ShowingMouse;
    bEnableClickEvents = ShowingMouse;
    bEnableMouseOverEvents = ShowingMouse;
}


void APiratePlayerController::UpdateWidget(FString what, FName field)
{
    UTextBlock* Name = (UTextBlock*)(PirateInformationWidget->WidgetTree->FindWidget(field));
    if (Name) Name->SetText(FText::FromString(what));
}
