// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Misc/ConfigCacheIni.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameSettingsManager.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class TESTING_API UGameSettingsManager : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FileIniManager")
	void SaveGraphicsConfig(int32 DisplayMode, bool VerticalSync, int32 VisualQuality);

	UFUNCTION(BlueprintCallable, Category = "FileIniManager")
	void LoadGraphicsConfig(int32& DisplayMode, bool& VerticalSync, int32& VisualQuality);

	UFUNCTION(BlueprintCallable, Category = "FileIniManager")
	void InitConfigDefault();

	UGameSettingsManager();

private:

	FString DocPath;

	
};
