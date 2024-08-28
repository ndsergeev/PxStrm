#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Materials/MaterialInstanceConstant.h"
#include "MaterialManager.generated.h"

UCLASS()
class PXSTRM_API AMaterialManager : public AActor
{
	GENERATED_BODY()

public:
	AMaterialManager();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, Category = "MaterialManager")
	TArray<AActor*> ManagedMeshes;

	UPROPERTY(EditAnywhere, Category = "MaterialManager")
	UMaterialInstanceConstant* MaterialInstance;

	UFUNCTION(BlueprintCallable, Category = "Materials")
	void ChangeMaterials(const FLinearColor& NewColor);
};
