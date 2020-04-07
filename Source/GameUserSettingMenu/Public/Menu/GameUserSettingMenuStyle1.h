// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameUserSettingMenuStyle1.generated.h"

class UComboBoxString;
class UCheckBox;

/**
 * 
 */
UCLASS()
class GAMEUSERSETTINGMENU_API UGameUserSettingMenuStyle1 : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

protected:

	/**
	 * Resolution ComboBox Getter, please override it in your blueprint to give a return pointer
	 */
	UFUNCTION(BlueprintImplementableEvent, meta = (BlueprintProtected = true), Category = "GameUserSettingMenu|Getters")
		UComboBoxString* GetResolutionComboBox();

	void InitializeResolutionComboBox();

	UFUNCTION()
		void OnResolutionComboBoxChanged(FString SelectedItem, ESelectInfo::Type SelectionType);


	/**
	 * Window Mode ComboBox Getter, please override it in your blueprint to give a return pointer
	 */
	UFUNCTION(BlueprintImplementableEvent, meta = (BlueprintProtected = true), Category = "GameUserSettingMenu|Getters")
		UComboBoxString* GetWindowModeComboBox();

	void InitializeWindowModeComboBox();

	UFUNCTION()
		void OnWindowModeComboBoxChanged(FString SelectedItem, ESelectInfo::Type SelectionType);

	/**
	 * Game window fullscreen mode display string
	 *	key 0 = Fullscreen
	 *	key 1 = Windowed fullscreen
	 *	key 2 = Windowed
	 */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "GameUserSettingMenu|Preset")
		TMap<int32, FString> WindowModeDisplayText
	{
		TPairInitializer<const int32&, const FString&>(0, "FullScreen"),
		TPairInitializer<const int32&, const FString&>(1, "WindowedFullscreen"),
		TPairInitializer<const int32&, const FString&>(2, "Windowed"),
	};



	/**
	 * Frame Rate Limit ComboBox Getter, please override it in your blueprint to give a return pointer
	 */
	UFUNCTION(BlueprintImplementableEvent, meta = (BlueprintProtected = true), Category = "GameUserSettingMenu|Getters")
		UComboBoxString* GetFrameRateLimitComboBox();

	// Frame Rate Limit combobox initializer
	void InitializeFrameRateLimitComboBox();

	UFUNCTION()
		void OnFrameRateLimitComboBoxChanged(FString SelectedItem, ESelectInfo::Type SelectionType);

	/**
	 * Frame rate limit display string
	 *	key 0  = Unlimited
	 *	key 30 = 30fps limited
	 *	key 60 = 60fps limited
	 *  etc...
	 */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "GameUserSettingMenu|Preset")
		TMap<int32, FString> FrameRateLimitDisplayText
	{
		TPairInitializer<const int32&, const FString&>(0,   "Unlimited"),
		TPairInitializer<const int32&, const FString&>(30,  "30"),
		TPairInitializer<const int32&, const FString&>(60,  "60"),
		TPairInitializer<const int32&, const FString&>(90,  "90"),
		TPairInitializer<const int32&, const FString&>(120, "120"),
	};



	/**
	 * VSync CheckBox Getter, please override it in your blueprint to give a return pointer
	 */
	UFUNCTION(BlueprintImplementableEvent, meta = (BlueprintProtected = true), Category = "GameUserSettingMenu|Getters")
		UCheckBox* GetVSyncBox();

	// Frame Rate Limit combobox initializer
	void InitializeVSyncCheckBox();

	UFUNCTION()
		void OnVSyncCheckBoxStateChanged(bool bIsChecked);

public:

	UFUNCTION(BlueprintCallable)
		void ApplySettings(bool bCheckForCommandLineOverrides);


protected:

	class USettingObject* SettingObj = nullptr;
};
