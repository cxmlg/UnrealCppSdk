// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminGetUserInternalData.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFAdminGetUserInternalData : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPAdminGetUserDataResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPAdminGetUserDataResultDelegate OnFailure;
	
	// Retrieves the title-specific custom data for the user which cannot be accessed by the client
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Admin|Player Data Management")
	static UPFAdminGetUserInternalData* GetUserInternalData(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InPlayFabId, const TArray<FString>& InKeys, const int32& InIfChangedFromDataVersion);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::AdminModels::FGetUserDataRequest Request;

	PlayFab::UPlayFabAdminAPI::FGetUserInternalDataDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::AdminModels::FGetUserDataResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
