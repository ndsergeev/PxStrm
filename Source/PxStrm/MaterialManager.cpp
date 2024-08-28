#include "MaterialManager.h"
#include "Materials/MaterialInstanceConstant.h"


AMaterialManager::AMaterialManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AMaterialManager::BeginPlay()
{
	Super::BeginPlay();
}

void AMaterialManager::ChangeMaterials(const FLinearColor& NewColor)
{
	if (MaterialInstance == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Material instance is not set."));
		return;
	}

	UMaterialInstanceDynamic* MaterialInstanceDynamic = UMaterialInstanceDynamic::Create(MaterialInstance, this);
	if (!MaterialInstanceDynamic)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to create a dynamic material instance."));
		return;
	}

	MaterialInstanceDynamic->SetVectorParameterValue(FName("Color"), NewColor);

	for (AActor* Actor : ManagedMeshes)
	{
		if (!Actor)
		{
			continue;
		}

		TArray<UStaticMeshComponent*> Components;
		Actor->GetComponents<UStaticMeshComponent>(Components);

		for (UStaticMeshComponent* StaticMeshComponent : Components)
		{
			if (StaticMeshComponent)
			{
				StaticMeshComponent->SetMaterial(0, MaterialInstanceDynamic);
				UE_LOG(LogTemp, Log, TEXT("Applied new material to: %s"), *Actor->GetName());
			}
		}
	}
}
