// Fill out your copyright notice in the Description page of Project Settings.




#include "Menu/GameUserSettingMenuStyle1.h"
#include "Components/ComboBoxString.h"
#include "Components/CheckBox.h"
#include "GameFramework/GameUserSettings.h"
#include "Kismet/KismetSystemLibrary.h"


void UGameUserSettingMenuStyle1::NativeConstruct()
{
	UGameUserSettings::GetGameUserSettings()->LoadSettings(true);
	UGameUserSettings::GetGameUserSettings()->ValidateSettings();

	InitializeResolutionComboBox();
	InitializeWindowModeComboBox();
	InitializeFrameRateLimitComboBox();

	UUserWidget::NativeConstruct();
}

void UGameUserSettingMenuStyle1::NativeDestruct()
{
	UUserWidget::NativeDestruct();
}

void UGameUserSettingMenuStyle1::InitializeResolutionComboBox()
{
	if (!this->GetResolutionComboBox())
	{
		return;
	}

	this->GetResolutionComboBox()->ClearOptions();

	// Get GameUserSetting
	UGameUserSettings* GameUserSetting = UGameUserSettings::GetGameUserSettings();

	// Get supported resolutions
	TArray<FIntPoint> SupportedResolutions;
	UKismetSystemLibrary::GetSupportedFullscreenResolutions(SupportedResolutions);

	// Add Supported resolution to combobox options
	for (const FIntPoint& Resolution : SupportedResolutions)
	{
		FString OptionStr = FString::FromInt(Resolution.X) + "x" + FString::FromInt(Resolution.Y);
		this->GetResolutionComboBox()->AddOption(OptionStr);
	}

	// set current resolution to combobox's selected option
	FIntPoint CurrentGameResolution = GameUserSetting->GetScreenResolution();
	FString SelectedOptionStr = FString::FromInt(CurrentGameResolution.X) + "x" + FString::FromInt(CurrentGameResolution.Y);
	this->GetResolutionComboBox()->SetSelectedOption(SelectedOptionStr);

	// bind callback event
	this->GetResolutionComboBox()->OnSelectionChanged.AddDynamic(this, &UGameUserSettingMenuStyle1::OnResolutionComboBoxChanged);
}

void UGameUserSettingMenuStyle1::OnResolutionComboBoxChanged(FString SelectedItem, ESelectInfo::Type SelectionType)
{
	if (SelectionType == ESelectInfo::Type::Direct)
	{
		return;
	}

	FString LeftStr;
	FString RightStr;
	if (!SelectedItem.Split("x", &LeftStr, &RightStr))
	{
		return;
	}

	UGameUserSettings::GetGameUserSettings()->SetScreenResolution(FIntPoint(FCString::Atoi(*LeftStr), FCString::Atoi(*RightStr)));
}

void UGameUserSettingMenuStyle1::InitializeWindowModeComboBox()
{
	if (!this->GetWindowModeComboBox())
	{
		return;
	}

	this->GetWindowModeComboBox()->ClearOptions();

	// Get GameUserSetting
	UGameUserSettings* GameUserSetting = UGameUserSettings::GetGameUserSettings();


	this->GetWindowModeComboBox()->AddOption(WindowModeDisplayText[(int32)EWindowMode::Type::Fullscreen]);
	this->GetWindowModeComboBox()->AddOption(WindowModeDisplayText[(int32)EWindowMode::Type::WindowedFullscreen]);
	this->GetWindowModeComboBox()->AddOption(WindowModeDisplayText[(int32)EWindowMode::Type::Windowed]);


	this->GetWindowModeComboBox()->SetSelectedOption(WindowModeDisplayText[GameUserSetting->GetFullscreenMode()]);

	// bind callback event
	this->GetWindowModeComboBox()->OnSelectionChanged.AddDynamic(this, &UGameUserSettingMenuStyle1::OnWindowModeComboBoxChanged);
}

void UGameUserSettingMenuStyle1::OnWindowModeComboBoxChanged(FString SelectedItem, ESelectInfo::Type SelectionType)
{
	if (SelectionType == ESelectInfo::Type::Direct)
	{
		return;
	}

	UGameUserSettings::GetGameUserSettings()->SetFullscreenMode(EWindowMode::ConvertIntToWindowMode(*WindowModeDisplayText.FindKey(SelectedItem)));
}

void UGameUserSettingMenuStyle1::InitializeFrameRateLimitComboBox()
{
	if (!this->GetFrameRateLimitComboBox())
	{
		return;
	}

	this->GetFrameRateLimitComboBox()->ClearOptions();

	// Get GameUserSetting
	UGameUserSettings* GameUserSetting = UGameUserSettings::GetGameUserSettings();

	TArray<int32> Keys;
	FrameRateLimitDisplayText.GetKeys(Keys);

	for (const int32& Key : Keys)
	{
		this->GetFrameRateLimitComboBox()->AddOption(FrameRateLimitDisplayText[Key]);
	}

	this->GetFrameRateLimitComboBox()->SetSelectedOption(FrameRateLimitDisplayText[FMath::RoundToInt(GameUserSetting->GetFrameRateLimit())]);

	// bind callback event
	this->GetFrameRateLimitComboBox()->OnSelectionChanged.AddDynamic(this, &UGameUserSettingMenuStyle1::OnFrameRateLimitComboBoxChanged);
}

void UGameUserSettingMenuStyle1::OnFrameRateLimitComboBoxChanged(FString SelectedItem, ESelectInfo::Type SelectionType)
{
	if (SelectionType == ESelectInfo::Type::Direct)
	{
		return;
	}
	UGameUserSettings::GetGameUserSettings()->SetFrameRateLimit(*FrameRateLimitDisplayText.FindKey(SelectedItem) * 1.f);
}

void UGameUserSettingMenuStyle1::InitializeVSyncCheckBox()
{
	if (!this->GetVSyncBox())
	{
		return;
	}

	this->GetVSyncBox()->SetIsChecked(UGameUserSettings::GetGameUserSettings()->IsVSyncEnabled());
	this->GetVSyncBox()->OnCheckStateChanged.AddDynamic(this, &UGameUserSettingMenuStyle1::OnVSyncCheckBoxStateChanged);
}

void UGameUserSettingMenuStyle1::OnVSyncCheckBoxStateChanged(bool bIsChecked)
{
	UGameUserSettings::GetGameUserSettings()->SetVSyncEnabled(bIsChecked);
}

void UGameUserSettingMenuStyle1::ApplySettings(bool bCheckForCommandLineOverrides)
{
	UGameUserSettings::GetGameUserSettings()->ApplySettings(bCheckForCommandLineOverrides);
}


