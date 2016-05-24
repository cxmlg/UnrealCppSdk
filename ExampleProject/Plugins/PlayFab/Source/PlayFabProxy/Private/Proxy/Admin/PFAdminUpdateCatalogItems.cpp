// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFAdminUpdateCatalogItems.h"

UPFAdminUpdateCatalogItems::UPFAdminUpdateCatalogItems(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FUpdateCatalogItemsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminUpdateCatalogItems* UPFAdminUpdateCatalogItems::UpdateCatalogItems(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InCatalogVersion, const TArray<FBPAdminCatalogItem>& InCatalog)
{
	UPFAdminUpdateCatalogItems* Proxy = NewObject<UPFAdminUpdateCatalogItems>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.CatalogVersion = InCatalogVersion;
	for (const FBPAdminCatalogItem& elem : InCatalog)
    {
        Proxy->Request.Catalog.Add(elem.Data);
    }

	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminUpdateCatalogItems::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->UpdateCatalogItems(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminUpdateCatalogItems::OnSuccessCallback(const PlayFab::AdminModels::FUpdateCatalogItemsResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFAdminUpdateCatalogItems::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}
