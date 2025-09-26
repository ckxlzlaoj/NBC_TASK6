// Copyright Epic Games, Inc. All Rights Reserved.

#include "JumpMapGameMode.h"
#include "JumpMapCharacter.h"
#include "UObject/ConstructorHelpers.h"

AJumpMapGameMode::AJumpMapGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
