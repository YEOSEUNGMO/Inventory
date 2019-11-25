// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "YEO_InvenotryCharacter.h"
#include "GamePlayController.generated.h"

/**
 * 
 */
UCLASS()
class YEO_INVENOTRY_API AGamePlayController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Utils")
	void AddItemToInventoryByID(FName ID);

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	class AInteractable* CurrentInteractable;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		TArray<FInventoryItem> Inventory;

protected:
	void Interact();

	virtual void SetupInputComponent() override;
};
