// Fill out your copyright notice in the Description page of Project Settings.

#include "SettingObject/SettingObject.h"
#include "GameFramework/GameUserSettings.h"

bool USettingObject::StartUp()
{
	if (!UGameUserSettings::GetGameUserSettings())
	{
		return false;
	}
	UGameUserSettings::GetGameUserSettings()->LoadSettings(true);
	UGameUserSettings::GetGameUserSettings()->ValidateSettings();
	return true;
}

FIntPoint USettingObject::GetScreenResolution() const
{
	return UGameUserSettings::GetGameUserSettings()->GetScreenResolution();
}

void USettingObject::SetScreenResolution(int32 Width, int32 Hight)
{
	UGameUserSettings::GetGameUserSettings()->SetScreenResolution(FIntPoint(Width, Hight));
}

int32 USettingObject::GetFullScreenMode() const
{
	return UGameUserSettings::GetGameUserSettings()->GetFullscreenMode();
}

void USettingObject::SetFullScreenMode(int32 FullScreenMode)
{
	UGameUserSettings::GetGameUserSettings()->SetFullscreenMode(EWindowMode::ConvertIntToWindowMode(FullScreenMode));
}

bool USettingObject::GetVSyncEnabled() const
{
	return UGameUserSettings::GetGameUserSettings()->IsVSyncEnabled();
}

void USettingObject::SetVSyncEnabled(bool bEnabled)
{
	UGameUserSettings::GetGameUserSettings()->SetVSyncEnabled(bEnabled);
}

float USettingObject::GetFrameRateLimit() const
{
	return UGameUserSettings::GetGameUserSettings()->GetFrameRateLimit();
}

void USettingObject::SetFrameRateLimit(float FrameRateLimit)
{
	UGameUserSettings::GetGameUserSettings()->SetFrameRateLimit(FrameRateLimit);
}

int32 USettingObject::GetTextureQuality() const
{
	return UGameUserSettings::GetGameUserSettings()->GetTextureQuality();
}

void USettingObject::SetTextureQuality(int32 Quality)
{
	UGameUserSettings::GetGameUserSettings()->SetTextureQuality(Quality);
}

int32 USettingObject::GetFoliageQuality() const
{
	return UGameUserSettings::GetGameUserSettings()->GetFoliageQuality();
}

void USettingObject::SetFoliageQuality(int32 Quality)
{
	UGameUserSettings::GetGameUserSettings()->SetFoliageQuality(Quality);
}

void USettingObject::ApplySettings(bool bCheckForCommandLineOverrides)
{
	UGameUserSettings::GetGameUserSettings()->ApplySettings(bCheckForCommandLineOverrides);
}

int32 USettingObject::GetViewDistanceQuality() const
{
	return UGameUserSettings::GetGameUserSettings()->GetViewDistanceQuality();
}

void USettingObject::SetViewDistanceQuality(int32 Value)
{
	UGameUserSettings::GetGameUserSettings()->SetViewDistanceQuality(Value);
}

int32 USettingObject::GetShadowQuality() const
{
	return UGameUserSettings::GetGameUserSettings()->GetShadowQuality();
}

void USettingObject::SetShadowQuality(int32 Value)
{
	UGameUserSettings::GetGameUserSettings()->SetShadowQuality(Value);
}

int32 USettingObject::GetAntiAliasingQuality() const
{
	return UGameUserSettings::GetGameUserSettings()->GetAntiAliasingQuality();
}

void USettingObject::SetAntiAliasingQuality(int32 Value)
{
	UGameUserSettings::GetGameUserSettings()->SetAntiAliasingQuality(Value);
}

int32 USettingObject::GetVisualEffectQuality() const
{
	return UGameUserSettings::GetGameUserSettings()->GetVisualEffectQuality();
}

void USettingObject::SetVisualEffectQuality(int32 Value)
{
	UGameUserSettings::GetGameUserSettings()->SetVisualEffectQuality(Value);
}

int32 USettingObject::GetPostProcessingQuality() const
{
	return UGameUserSettings::GetGameUserSettings()->GetPostProcessingQuality();
}

void USettingObject::SetPostProcessingQuality(int32 Value)
{
	UGameUserSettings::GetGameUserSettings()->SetPostProcessingQuality(Value);
}