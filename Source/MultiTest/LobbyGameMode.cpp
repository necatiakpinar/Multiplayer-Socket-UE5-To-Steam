// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"

#include "GameFramework/GameStateBase.h"
#include "GameFramework/PlayerState.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	if (GameState)
	{
		int32 NumberOffPlayers = GameState.Get()->PlayerArray.Num();

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1,15.0f,FColor::Yellow,
				FString(TEXT("Number of players : %d "), NumberOffPlayers));

			APlayerState* PlayerState = NewPlayer->GetPlayerState<APlayerState>();
			if (PlayerState)
			{
				FString PlayerName = PlayerState->GetPlayerName();
				GEngine->AddOnScreenDebugMessage(-1,15.0f,FColor::Cyan,
				FString::Printf(TEXT("%s has joined the game"), *PlayerName)
				);
			}
			
		}
	}
}

void ALobbyGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
	
	APlayerState* PlayerState = Exiting->GetPlayerState<APlayerState>();
	if (PlayerState)
	{
		int32 NumberOffPlayers = GameState.Get()->PlayerArray.Num();
		GEngine->AddOnScreenDebugMessage(-1,15.0f,FColor::Yellow,
				FString(TEXT("Number of players : %d "), NumberOffPlayers - 1));
		
		FString PlayerName = PlayerState->GetPlayerName();
		GEngine->AddOnScreenDebugMessage(-1,15.0f,FColor::Cyan,
		FString::Printf(TEXT("%s has exited the game"), *PlayerName)
		);
	}
}
