// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/GameMode.h"
#include "MainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class RUNNER_API AMainGameMode : public AGameMode
{
	GENERATED_BODY()

public:
		virtual void BeginPlay() override;
		virtual void Tick(float DeltaSeconds) override;
		void OnCollide();
		UPROPERTY(EditAnywhere,Category="Spawning")
		TSubclassOf<class AGameBlockController> GroundBlock;
		UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class AGameBlockController> HazardBlock1;
		UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class AGameBlockController> HazardBlock2;
		float FARTHEST_DISTANCE = 2000.0f;
		float PointScenarioBlocks = -10.0f;
		float PointHazardBlocks = 1000.0f;
		UFUNCTION(BlueprintCallable, Category = "UMG Game")
			void ChangeMenuWidget(TSubclassOf<UUserWidget> StartingWidgetClass);
		UPROPERTY(EditAnywhere, Category = "Health")
		int Health = 100;
protected:
		UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="UMG Name")
			TSubclassOf<UUserWidget> NewWidgetClass;
		UPROPERTY()
			UUserWidget* CurrentWidget;

	
	
};
