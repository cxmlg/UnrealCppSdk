// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFAdminUpdateStoreItems.h"

UPFAdminUpdateStoreItems::UPFAdminUpdateStoreItems(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FUpdateStoreItemsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminUpdateStoreItems* UPFAdminUpdateStoreItems::UpdateStoreItems(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InCatalogVersion, const FString& InStoreId, const FBPAdminStoreMarketingModel& InMarketingData, const TArray<FBPAdminStoreItem>& InStore)
{
	UPFAdminUpdateStoreItems* Proxy = NewObject<UPFAdminUpdateStoreItems>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.CatalogVersion = InCatalogVersion;
	Proxy->Request.StoreId = InStoreId;
	*Proxy->Request.MarketingData = InMarketingData.Data;
	for (const FBPAdminStoreItem& elem : InStore)
    {
        Proxy->Request.Store.Add(elem.Data);
    }

	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminUpdateStoreItems::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->UpdateStoreItems(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminUpdateStoreItems::OnSuccessCallback(const PlayFab::AdminModels::FUpdateStoreItemsResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFAdminUpdateStoreItems::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}
