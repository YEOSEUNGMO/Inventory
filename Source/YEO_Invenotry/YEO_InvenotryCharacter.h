// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Engine/DataTable.h"
#include "YEO_InvenotryCharacter.generated.h"

//UENUM(BlueprintType)
//enum EItemTypes
//{
//	Item_None	UMETA(DisplayName = "None"),
//	Item_Useable	UMETA(DisplayName = "Useable"),
//	Item_Equpment	UMETA(DisplayName = "Equpment")
//};
//
//USTRUCT(BlueprintType)
//struct FIteamDatas
//{
//	GENERATED_USTRUCT_BODY()
//
//public:
//	FIteamDatas()
//		: Name(TEXT("")), Texture(nullptr), Type(EItemTypes::Item_None), Count(0)
//	{};
//	//virtual void Clear();
//	//virtual void Use(AYEO_InvenotryCharacter* player);
//
//public:
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//		FName Name;
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//		UTexture2D* Texture;
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//		TEnumAsByte<EItemTypes> Type;
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//		int Count;
//};

USTRUCT(BlueprintType)
struct FCraftingInfo : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ComponentID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ProductID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bDestroyItemA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bDestroyItemB;
};

USTRUCT(BlueprintType)
struct FInventoryItem : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:

	FInventoryItem()
	{
		Name = FText::FromString("Item");
		Action = FText::FromString("Use");
		Description = FText::FromString("Please enter a descrpition for this item");
		Value = 10;
	}
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ItemID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class APickup> ItemPickup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Action;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Thumbnail;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCraftingInfo> ItemCombinations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanBeUsed;

	bool operator==(const FInventoryItem& Item) const
	{
		if (ItemID == Item.ItemID)
			return true;
		else
			return false;
	}
};
UCLASS(config=Game)
class AYEO_InvenotryCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	AYEO_InvenotryCharacter();

	virtual void Tick(float DeltaTime) override;

	bool bIsPickingUp = false;
	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;


protected:

	void CheckForInteractables();

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface
	void BeginPickUp();
	void EndPickUp();
	void ShowInventory();


public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

