// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientLoginWithIOSDeviceID.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFClientLoginWithIOSDeviceID : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPClientLoginResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPClientLoginResultDelegate OnFailure;
	
	// Signs the user in using the vendor-specific iOS device identifier, returning a session identifier that can subsequently be used for API calls which require an authenticated user
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Client|Authentication")
	static UPFClientLoginWithIOSDeviceID* LoginWithIOSDeviceID(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InTitleId, const FString& InDeviceId, const FString& InOS, const FString& InDeviceModel, const bool& InCreateAccount);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ClientModels::FLoginWithIOSDeviceIDRequest Request;

	PlayFab::UPlayFabClientAPI::FLoginWithIOSDeviceIDDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ClientModels::FLoginResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
