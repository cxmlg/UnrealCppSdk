// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientLoginWithFacebook.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFClientLoginWithFacebook : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPClientLoginResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPClientLoginResultDelegate OnFailure;
	
	// Signs the user in using a Facebook access token, returning a session identifier that can subsequently be used for API calls which require an authenticated user
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Client|Authentication")
	static UPFClientLoginWithFacebook* LoginWithFacebook(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InTitleId, const FString& InAccessToken, const bool& InCreateAccount);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ClientModels::FLoginWithFacebookRequest Request;

	PlayFab::UPlayFabClientAPI::FLoginWithFacebookDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ClientModels::FLoginResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};