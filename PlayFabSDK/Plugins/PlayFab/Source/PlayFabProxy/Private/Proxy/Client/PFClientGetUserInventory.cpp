// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFClientGetUserInventory.h"

UPFClientGetUserInventory::UPFClientGetUserInventory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetUserInventoryDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientGetUserInventory* UPFClientGetUserInventory::GetUserInventory(UObject* WorldContextObject, class APlayerController* PlayerController )
{
	UPFClientGetUserInventory* Proxy = NewObject<UPFClientGetUserInventory>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientGetUserInventory::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->GetUserInventory(SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientGetUserInventoryResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientGetUserInventory::OnSuccessCallback(const PlayFab::ClientModels::FGetUserInventoryResult& Result)
{
	FBPClientGetUserInventoryResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientGetUserInventory::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientGetUserInventoryResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
