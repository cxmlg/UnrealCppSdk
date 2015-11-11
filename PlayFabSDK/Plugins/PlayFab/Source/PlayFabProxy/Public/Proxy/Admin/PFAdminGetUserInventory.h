// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminGetUserInventory.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFAdminGetUserInventory : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPAdminGetUserInventoryResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPAdminGetUserInventoryResultDelegate OnFailure;
	
	// Retrieves the specified user's current inventory of virtual goods
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Admin|Player Item Management")
	static UPFAdminGetUserInventory* GetUserInventory(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InPlayFabId);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::AdminModels::FGetUserInventoryRequest Request;

	PlayFab::UPlayFabAdminAPI::FGetUserInventoryDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::AdminModels::FGetUserInventoryResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
