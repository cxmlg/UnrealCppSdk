// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientGetUserPublisherData.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFClientGetUserPublisherData : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPClientGetUserDataResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPClientGetUserDataResultDelegate OnFailure;
	
	// Retrieves the publisher-specific custom data for the user which is readable and writable by the client
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Client|Player Data Management")
	static UPFClientGetUserPublisherData* GetUserPublisherData(UObject* WorldContextObject, class APlayerController* PlayerController, const TArray<FString>& InKeys, const FString& InPlayFabId, const int32& InIfChangedFromDataVersion);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ClientModels::FGetUserDataRequest Request;

	PlayFab::UPlayFabClientAPI::FGetUserPublisherDataDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ClientModels::FGetUserDataResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};