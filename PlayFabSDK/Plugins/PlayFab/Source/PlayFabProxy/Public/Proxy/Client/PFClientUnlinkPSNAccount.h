// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientUnlinkPSNAccount.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFClientUnlinkPSNAccount : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnSuccess; 

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnFailure; 
	
	// Unlinks the related PSN account from the user's PlayFab account
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Client|Account Management")
	static UPFClientUnlinkPSNAccount* UnlinkPSNAccount(UObject* WorldContextObject, class APlayerController* PlayerController);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	

	PlayFab::UPlayFabClientAPI::FUnlinkPSNAccountDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ClientModels::FUnlinkPSNAccountResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
