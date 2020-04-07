// Fill out your copyright notice in the Description page of Project Settings.




#include "Menu/GameUserSettingMenuStyle1.h"
#include "Components/ComboBoxString.h"
#include "Components/CheckBox.h"
#include "Kismet/KismetSystemLibrary.h"
#include "SettingObject/SettingObject.h"


void UGameUserSettingMenuStyle1::NativeConstruct()
{
	
	this->SettingObj = NewObject<USettingObject>(this, "SettingObj");
	if (this->SettingObj)
	{
		this->SettingObj->StartUp();
	}

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
	if (!this->GetResolutionComboBox() || !this->SettingObj)
	{
		return;
	}

	this->GetResolutionComboBox()->ClearOptions();


	// Get supported resolutions
	TArray<FIntPoint> SupportedResolutions;
	this->SettingObj->GetSupportedFullscreenResolutions(SupportedResolutions);

	// Add Supported resolution to combobox options
	// i.e "1920x1080"
	for (const FIntPoint& Resolution : SupportedResolutions)
	{
		FString OptionStr = FString::FromInt(Resolution.X) + "x" + FString::FromInt(Resolution.Y);
		this->GetResolutionComboBox()->AddOption(OptionStr);
	}

	// set current resolution to combobox's selected option
	FIntPoint CurrentGameResolution = this->SettingObj->GetScreenResolution();
	FString SelectedOptionStr = FString::FromInt(CurrentGameResolution.X) + "x" + FString::FromInt(CurrentGameResolution.Y);
	this->GetResolutionComboBox()->SetSelectedOption(SelectedOptionStr);

	// bind callback event
	this->GetResolutionComboBox()->OnSelectionChanged.AddDynamic(this, &UGameUserSettingMenuStyle1::OnResolutionComboBoxChanged);
}

void UGameUserSettingMenuStyle1::OnResolutionComboBoxChanged(FString SelectedItem, ESelectInfo::Type SelectionType)
{
	if (SelectionType == ESelectInfo::Type::Direct || !this->SettingObj)
	{
		return;
	}

	FString LeftStr;
	FString RightStr;
	if (!SelectedItem.Split("x", &LeftStr, &RightStr))
	{
		return;
	}
	this->SettingObj->SetScreenResolution(FCString::Atoi(*LeftStr), FCString::Atoi(*RightStr));
	
}

void UGameUserSettingMenuStyle1::InitializeWindowModeComboBox()
{
	if (!this->GetWindowModeComboBox() || !this->SettingObj)
	{
		return;
	}

	
	this->GetWindowModeComboBox()->ClearOptions();

	this->GetWindowModeComboBox()->AddOption(WindowModeDisplayText[(int32)EWindowMode::Type::Fullscreen]);
	this->GetWindowModeComboBox()->AddOption(WindowModeDisplayText[(int32)EWindowMode::Type::WindowedFullscreen]);
	this->GetWindowModeComboBox()->AddOption(WindowModeDisplayText[(int32)EWindowMode::Type::Windowed]);

	// set selected option
	this->GetWindowModeComboBox()->SetSelectedOption(WindowModeDisplayText[this->SettingObj->GetFullScreenMode()]);

	// bind callback event
	this->GetWindowModeComboBox()->OnSelectionChanged.AddDynamic(this, &UGameUserSettingMenuStyle1::OnWindowModeComboBoxChanged);
}

void UGameUserSettingMenuStyle1::OnWindowModeComboBoxChanged(FString SelectedItem, ESelectInfo::Type SelectionType)
{
	if (SelectionType == ESelectInfo::Type::Direct || !this->SettingObj)
	{
		return;
	}

	this->SettingObj->SetFullscreenMode(*WindowModeDisplayText.FindKey(SelectedItem));
}

void UGameUserSettingMenuStyle1::InitializeFrameRateLimitComboBox()
{
	if (!this->GetFrameRateLimitComboBox() || !this->SettingObj)
	{
		return;
	}

	this->GetFrameRateLimitComboBox()->ClearOptions();

	TArray<int32> Keys;
	FrameRateLimitDisplayText.GetKeys(Keys);

	for (const int32& Key : Keys)
	{
		this->GetFrameRateLimitComboBox()->AddOption(FrameRateLimitDisplayText[Key]);
	}

	this->GetFrameRateLimitComboBox()->SetSelectedOption(FrameRateLimitDisplayText[FMath::RoundToInt(this->SettingObj->GetFrameRateLimit())]);

	// bind callback event
	this->GetFrameRateLimitComboBox()->OnSelectionChanged.AddDynamic(this, &UGameUserSettingMenuStyle1::OnFrameRateLimitComboBoxChanged);
}

void UGameUserSettingMenuStyle1::OnFrameRateLimitComboBoxChanged(FString SelectedItem, ESelectInfo::Type SelectionType)
{
	if (SelectionType == ESelectInfo::Type::Direct || !this->SettingObj)
	{
		return;
	}
	this->SettingObj->SetFrameRateLimit(*FrameRateLimitDisplayText.FindKey(SelectedItem) * 1.f);
}

void UGameUserSettingMenuStyle1::InitializeVSyncCheckBox()
{
	if (!this->GetVSyncBox() || !this->SettingObj)
	{
		return;
	}

	this->GetVSyncBox()->SetIsChecked(this->SettingObj->IsVSyncEnabled());
	this->GetVSyncBox()->OnCheckStateChanged.AddDynamic(this, &UGameUserSettingMenuStyle1::OnVSyncCheckBoxStateChanged);
}

void UGameUserSettingMenuStyle1::OnVSyncCheckBoxStateChanged(bool bIsChecked)
{
	if (!this->SettingObj)
	{
		return;
	}
	this->SettingObj->SetVSyncEnabled(bIsChecked);
}

void UGameUserSettingMenuStyle1::ApplySettings(bool bCheckForCommandLineOverrides)
{
	if (!this->SettingObj)
	{
		return;
	}
	this->SettingObj->ApplySettings(bCheckForCommandLineOverrides);
}


