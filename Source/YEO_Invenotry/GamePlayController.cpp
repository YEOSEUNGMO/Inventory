// Fill out your copyright notice in the Description page of Project Settings.

#include "YEO_Invenotry.h"
#include "GamePlayController.h"
#include "GamePlayGameMode.h"
#include "Interactable.h"
void AGamePlayController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Use", IE_Pressed, this, &AGamePlayController::Interact);
}

void AGamePlayController::Interact()
{
	if (CurrentInteractable)
	{
		CurrentInteractable->Interact(this);
	}
}

void AGamePlayController::AddItemToInventoryByID(FName ID)
{
	AGamePlayGameMode* GameMode = Cast<AGamePlayGameMode>(GetWorld()->GetAuthGameMode());
	UDataTable* ItemTable = GameMode->GetItemDB();

	FInventoryItem* ItemToAdd = ItemTable->FindRow<FInventoryItem>(ID, "");

	if (ItemToAdd)
	{
		Inventory.Add(*ItemToAdd);
	}

}