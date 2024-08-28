// Copyright Epic Games, Inc. All Rights Reserved.

#include "PxStrmGameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/World.h"
#include "EngineUtils.h"

#include "MaterialManager.h"

APxStrmGameMode::APxStrmGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(
		TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void APxStrmGameMode::BeginPlay()
{
	Super::BeginPlay();

	FLinearColor NewColor;
	if (FString ColorParam; FParse::Value(FCommandLine::Get(), TEXT("COLOR="), ColorParam))
	{
		switch (FCString::Atoi(*ColorParam))
		{
		case 1:
			NewColor = FLinearColor::Red;
			break;
		case 2:
			NewColor = FLinearColor::Green;
			break;
		case 3:
			NewColor = FLinearColor::Blue;
			break;
		case 4:
			NewColor = FLinearColor(FMath::FRand(), FMath::FRand(), FMath::FRand(), 1.0f);
			break;
		default:
			NewColor = FLinearColor::Black;
			break;
		}
	}
	else
	{
		NewColor = FLinearColor::Black;
	}

	UE_LOG(LogTemp, Log, TEXT("PICKED COLOR: %s"), *NewColor.ToString());
	
	ApplyColorToStaticMeshes(NewColor);
}

void APxStrmGameMode::ApplyColorToStaticMeshes(const FLinearColor& Color)
{
	for (TActorIterator<AMaterialManager> It(GetWorld()); It;)
	{
		AMaterialManager* MaterialManager = *It;
		if (MaterialManager != nullptr)
		{
			UE_LOG(LogTemp, Log, TEXT("TRYING TO CHANGE MATERIAL: %s"), *MaterialManager->GetName());
                
			MaterialManager->ChangeMaterials(Color);
		}
	
		break;
	}
}
