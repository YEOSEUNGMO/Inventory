// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YEO_InvenotryCharacter.h"
#include "Item.generated.h"

UCLASS()
class YEO_INVENOTRY_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UShapeComponent* TBox;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* SM_TBox;

	AYEO_InvenotryCharacter* PlayerController;

	UPROPERTY(EditAnywhere)
		FString ItemName = FString(TEXT(""));

	void Pickup();

	void GetPlayer(AActor* player);

	bool bItemIsWithInRange = false;

	UFUNCTION()
		void TriggerEnter(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void TriggerEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
