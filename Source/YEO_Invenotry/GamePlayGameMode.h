// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GamePlayGameMode.generated.h"

/**
 * 
 */
UCLASS()
class YEO_INVENOTRY_API AGamePlayGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	class UDataTable* GetItemDB() const { return ItemDB; }
protected:
	UPROPERTY(EditDefaultsOnly)
		class UDataTable* ItemDB;
};
