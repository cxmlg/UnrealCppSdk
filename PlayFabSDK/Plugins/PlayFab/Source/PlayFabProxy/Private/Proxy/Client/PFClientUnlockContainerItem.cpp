// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFClientUnlockContainerItem.h"

UPFClientUnlockContainerItem::UPFClientUnlockContainerItem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FUnlockContainerItemDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientUnlockContainerItem* UPFClientUnlockContainerItem::UnlockContainerItem(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InContainerItemId, const FString& InCatalogVersion, const FString& InCharacterId)
{
	UPFClientUnlockContainerItem* Proxy = NewObject<UPFClientUnlockContainerItem>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.ContainerItemId = InContainerItemId;
	Proxy->Request.CatalogVersion = InCatalogVersion;
	Proxy->Request.CharacterId = InCharacterId;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientUnlockContainerItem::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->UnlockContainerItem(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientUnlockContainerItemResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientUnlockContainerItem::OnSuccessCallback(const PlayFab::ClientModels::FUnlockContainerItemResult& Result)
{
	FBPClientUnlockContainerItemResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientUnlockContainerItem::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientUnlockContainerItemResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
