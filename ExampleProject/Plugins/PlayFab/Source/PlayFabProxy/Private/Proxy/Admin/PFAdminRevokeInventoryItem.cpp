// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFAdminRevokeInventoryItem.h"

UPFAdminRevokeInventoryItem::UPFAdminRevokeInventoryItem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FRevokeInventoryItemDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminRevokeInventoryItem* UPFAdminRevokeInventoryItem::RevokeInventoryItem(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId, const FString& InCharacterId, const FString& InItemInstanceId)
{
	UPFAdminRevokeInventoryItem* Proxy = NewObject<UPFAdminRevokeInventoryItem>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	Proxy->Request.CharacterId = InCharacterId;
	Proxy->Request.ItemInstanceId = InItemInstanceId;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminRevokeInventoryItem::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->RevokeInventoryItem(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminRevokeInventoryItem::OnSuccessCallback(const PlayFab::AdminModels::FRevokeInventoryResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFAdminRevokeInventoryItem::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}
