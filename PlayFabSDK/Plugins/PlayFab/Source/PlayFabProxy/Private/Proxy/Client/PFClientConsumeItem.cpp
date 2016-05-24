// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFClientConsumeItem.h"

UPFClientConsumeItem::UPFClientConsumeItem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FConsumeItemDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientConsumeItem* UPFClientConsumeItem::ConsumeItem(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InItemInstanceId, const int32& InConsumeCount, const FString& InCharacterId)
{
	UPFClientConsumeItem* Proxy = NewObject<UPFClientConsumeItem>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.ItemInstanceId = InItemInstanceId;
	Proxy->Request.ConsumeCount = InConsumeCount;
	Proxy->Request.CharacterId = InCharacterId;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientConsumeItem::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->ConsumeItem(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientConsumeItemResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientConsumeItem::OnSuccessCallback(const PlayFab::ClientModels::FConsumeItemResult& Result)
{
	FBPClientConsumeItemResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientConsumeItem::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientConsumeItemResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
