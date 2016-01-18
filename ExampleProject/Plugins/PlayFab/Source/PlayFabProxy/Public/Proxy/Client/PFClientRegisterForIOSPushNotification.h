// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientRegisterForIOSPushNotification.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFClientRegisterForIOSPushNotification : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnSuccess; 

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnFailure; 
	
	// Registers the iOS device to receive push notifications
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Client|IOS-Specific APIs")
	static UPFClientRegisterForIOSPushNotification* RegisterForIOSPushNotification(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InDeviceToken, const bool& InSendPushNotificationConfirmation, const FString& InConfirmationMessage);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ClientModels::FRegisterForIOSPushNotificationRequest Request;

	PlayFab::UPlayFabClientAPI::FRegisterForIOSPushNotificationDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ClientModels::FRegisterForIOSPushNotificationResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};