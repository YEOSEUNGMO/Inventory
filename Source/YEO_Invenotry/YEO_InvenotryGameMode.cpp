// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "YEO_InvenotryGameMode.h"
#include "YEO_InvenotryCharacter.h"
#include "UObject/ConstructorHelpers.h"

AYEO_InvenotryGameMode::AYEO_InvenotryGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
