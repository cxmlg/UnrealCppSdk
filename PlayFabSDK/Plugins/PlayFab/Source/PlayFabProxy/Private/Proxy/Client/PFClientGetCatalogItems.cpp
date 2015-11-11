// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFClientGetCatalogItems.h"

UPFClientGetCatalogItems::UPFClientGetCatalogItems(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetCatalogItemsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientGetCatalogItems* UPFClientGetCatalogItems::GetCatalogItems(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InCatalogVersion)
{
	UPFClientGetCatalogItems* Proxy = NewObject<UPFClientGetCatalogItems>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.CatalogVersion = InCatalogVersion;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientGetCatalogItems::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->GetCatalogItems(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientGetCatalogItemsResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientGetCatalogItems::OnSuccessCallback(const PlayFab::ClientModels::FGetCatalogItemsResult& Result)
{
	FBPClientGetCatalogItemsResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientGetCatalogItems::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientGetCatalogItemsResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
