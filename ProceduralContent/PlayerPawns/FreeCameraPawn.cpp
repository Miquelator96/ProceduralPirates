// Fill out your copyright notice in the Description page of Project Settings.


#include "FreeCameraPawn.h"
#include "Blueprint/UserWidget.h" 
#include "Blueprint/WidgetTree.h" 
#include "Components/TextBlock.h" 

void AFreeCameraPawn::UpdateWidget(FString what, FName field)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Name: %s"), *what));

	UTextBlock* Name = (UTextBlock*)(PirateInformationWidget->WidgetTree->FindWidget(field));
	if (Name) Name->SetText(FText::FromString(what));
}
