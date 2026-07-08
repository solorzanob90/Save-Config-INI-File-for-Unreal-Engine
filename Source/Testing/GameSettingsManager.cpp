// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSettingsManager.h"
#include "HAL/PlatformFilemanager.h"



UGameSettingsManager::UGameSettingsManager()
{
	FString path = FPlatformProcess::UserDir();
	DocPath = path + TEXT("YourAmazingGame/MyGameConfig.ini");
}

void UGameSettingsManager::SaveGraphicsConfig(int32 DisplayMode, bool VerticalSync, int32 VisualQuality)
{
	GConfig->SetInt(TEXT("Graphics"),TEXT("DisplayMode"), DisplayMode,DocPath);
	GConfig->SetBool(TEXT("Graphics"), TEXT("VerticalSync"), VerticalSync, DocPath);
	GConfig->SetInt(TEXT("Graphics"), TEXT("VisualQuality"), VisualQuality, DocPath);

	GConfig->Flush(false, DocPath);

}

void UGameSettingsManager::LoadGraphicsConfig(int32& DisplayMode, bool& VerticalSync, int32& VisualQuality)
{
	GConfig->GetInt(TEXT("Graphics"), TEXT("DisplayMode"), DisplayMode, DocPath);
	GConfig->GetBool(TEXT("Graphics"), TEXT("VerticalSync"), VerticalSync, DocPath);
	GConfig->GetInt(TEXT("Graphics"), TEXT("VisualQuality"), VisualQuality, DocPath);

}

void UGameSettingsManager::InitConfigDefault()
{
	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*DocPath)) {

		int32 DefaultDisplayMode = 0; bool DefaultVerticalSync = true; int32 DefaultVisualQuality = 1;

		GConfig->SetInt(TEXT("Graphics"),TEXT("DisplayMode"),DefaultDisplayMode,DocPath);
		GConfig->SetBool(TEXT("Graphics"), TEXT("VerticalSync"), DefaultVerticalSync, DocPath);
		GConfig->SetInt(TEXT("Graphics"),TEXT("VisualQuality"), DefaultVisualQuality,DocPath);

		GConfig->Flush(false,DocPath);

	}

	int32 dm, vq;
	bool vs;
	LoadGraphicsConfig(dm,vs,vq);
}


