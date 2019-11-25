// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable.h"

// Sets default values
AInteractable::AInteractable()
{
	Name = "Name not set";
	Action = "Iteract";

}

// Called when the game starts or when spawned
void AInteractable::BeginPlay()
{
	Super::BeginPlay();
	
}
//
//// Called every frame
//void AInteractable::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

