// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "MyAIController.h"


void AMyAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ThisTank = GetControlledTank();
	auto TargetTank = GetPlayerTank();
	if (ThisTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("An AI is playing as %s"), *ThisTank->GetName())
		if (TargetTank)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s is targeting %s"), *ThisTank->GetName(), *TargetTank->GetName())
		}
	}
}

ATank* AMyAIController::GetControlledTank() const
{
	if (GetPawn())
	{
		return Cast<ATank>(GetPawn());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to find AI Pawn"))
	}
	return nullptr;
}

ATank* AMyAIController::GetPlayerTank() const
{
	auto Player = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (Player)
	{
		return Player;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to Target Player Pawn"))
	}
	return nullptr;
}
