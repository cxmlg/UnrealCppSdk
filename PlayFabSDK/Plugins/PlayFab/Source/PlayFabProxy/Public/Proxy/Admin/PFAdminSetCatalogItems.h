// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminSetCatalogItems.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFAdminSetCatalogItems : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnSuccess; 

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnFailure; 
	
	// Creates the catalog configuration of all virtual goods for the specified catalog version
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Admin|Title-Wide Data Management")
	static UPFAdminSetCatalogItems* SetCatalogItems(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InCatalogVersion, const TArray<FBPAdminCatalogItem>& InCatalog);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::AdminModels::FUpdateCatalogItemsRequest Request;

	PlayFab::UPlayFabAdminAPI::FSetCatalogItemsDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::AdminModels::FUpdateCatalogItemsResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
