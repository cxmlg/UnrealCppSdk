// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFServerUpdateUserInventoryItemCustomData.h"

UPFServerUpdateUserInventoryItemCustomData::UPFServerUpdateUserInventoryItemCustomData(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabServerAPI::FUpdateUserInventoryItemCustomDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFServerUpdateUserInventoryItemCustomData* UPFServerUpdateUserInventoryItemCustomData::UpdateUserInventoryItemCustomData(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId, const FString& InCharacterId, const FString& InItemInstanceId, const FString& InData, const TArray<FString>& InKeysToRemove)
{
	UPFServerUpdateUserInventoryItemCustomData* Proxy = NewObject<UPFServerUpdateUserInventoryItemCustomData>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	Proxy->Request.CharacterId = InCharacterId;
	Proxy->Request.ItemInstanceId = InItemInstanceId;
	
	Proxy->Request.KeysToRemove = InKeysToRemove;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFServerUpdateUserInventoryItemCustomData::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

	bool CallResult = false;

	if(ServerAPI.IsValid())
	{	
		CallResult = ServerAPI->UpdateUserInventoryItemCustomData(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFServerUpdateUserInventoryItemCustomData::OnSuccessCallback(const PlayFab::ServerModels::FEmptyResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFServerUpdateUserInventoryItemCustomData::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}
