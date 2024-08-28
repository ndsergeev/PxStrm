// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PxStrmGameMode.generated.h"

UCLASS(minimalapi)
class APxStrmGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APxStrmGameMode();
	void BeginPlay();
	void ApplyColorToStaticMeshes(const FLinearColor& Color);
};



