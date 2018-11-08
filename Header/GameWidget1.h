// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Blueprint/UserWidget.h"
#include "GameWidget1.generated.h"

/**
 * 
 */
UCLASS()
class RUNNER_API UGameWidget1 : public UUserWidget
{
	GENERATED_BODY()
public:
		void Load();
		void SetScore(int Score,int Health);
		void OnCollide(int Score,int Health);
		void OnGameOver(int Score, int Health);
		UPROPERTY()
		UTextBlock* ScoreText;
	
	
	
};
