// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultiTestGameMode.h"
#include "MultiTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMultiTestGameMode::AMultiTestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
