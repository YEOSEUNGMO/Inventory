// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "Components/BoxComponent.h"
#include "Engine/StaticMesh.h"
#include "Engine.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	TBox->SetGenerateOverlapEvents(true);
	TBox->OnComponentBeginOverlap.AddDynamic(this, &AItem::TriggerEnter);
	TBox->OnComponentEndOverlap.AddDynamic(this, &AItem::TriggerEnd);

	RootComponent = TBox;

	SM_TBox = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Box Mesh"));
	SM_TBox->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AItem::Pickup()
{
	PlayerController->Inventory.Add(*ItemName);
	GEngine->AddOnScreenDebugMessage(1, 3.0f, FColor::Green, TEXT("Pick Up!!"));
	Destroy();
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerController != nullptr)
	{
		if (PlayerController->bIsPickingUp && bItemIsWithInRange)
		{
			Pickup();
		}
	}

}

void AItem::GetPlayer(AActor* player)
{
	PlayerController = Cast<AYEO_InvenotryCharacter>(player);
}

void AItem::TriggerEnter(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	bItemIsWithInRange = true;
	GEngine->AddOnScreenDebugMessage(1, 3.0f, FColor::Green, FString::Printf(TEXT("Press F to pickup %s"), *ItemName));
	GetPlayer(OtherActor);
}

void AItem::TriggerEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	bItemIsWithInRange = false;
}
