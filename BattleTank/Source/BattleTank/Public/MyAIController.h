// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Public/Tank.h"
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API AMyAIController : public AAIController
{
	GENERATED_BODY()
	
	void BeginPlay() override;

	ATank* GetControlledTank() const;
	
	ATank* GetPlayerTank() const;
};
