// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SettingObject.generated.h"

/**
 * 
 */
UCLASS()
class GAMEUSERSETTINGMENU_API USettingObject : public UObject
{

    GENERATED_BODY()


public:

    bool      StartUp();
	void      ApplySettings(bool bCheckForCommandLineOverrides);

    FIntPoint GetScreenResolution() const;
    void      SetScreenResolution(int32 Width, int32 Hight);

    int32     GetFullScreenMode() const;
    void      SetFullScreenMode(int32 FullScreenMode);

    bool      GetVSyncEnabled() const;
    void      SetVSyncEnabled(bool bEnabled);

    float     GetFrameRateLimit() const;
    void      SetFrameRateLimit(float FrameRateLimit);

    int32     GetTextureQuality() const;
    void      SetTextureQuality(int32 Quality);

    int32     GetFoliageQuality() const;
    void      SetFoliageQuality(int32 Quality);

    int32     GetViewDistanceQuality() const;
	void      SetViewDistanceQuality(int32 Value);

	int32     GetShadowQuality() const;
	void      SetShadowQuality(int32 Value);

	int32     GetAntiAliasingQuality() const;
	void      SetAntiAliasingQuality(int32 Value);

	int32     GetVisualEffectQuality() const;
	void      SetVisualEffectQuality(int32 Value);

	int32     GetPostProcessingQuality() const;
	void      SetPostProcessingQuality(int32 Value);
};
