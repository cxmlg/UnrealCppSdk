// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFClientUpdateUserPublisherData.h"

UPFClientUpdateUserPublisherData::UPFClientUpdateUserPublisherData(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FUpdateUserPublisherDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientUpdateUserPublisherData* UPFClientUpdateUserPublisherData::UpdateUserPublisherData(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InData, const TArray<FString>& InKeysToRemove)
{
	UPFClientUpdateUserPublisherData* Proxy = NewObject<UPFClientUpdateUserPublisherData>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	
	Proxy->Request.KeysToRemove = InKeysToRemove;
	
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientUpdateUserPublisherData::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->UpdateUserPublisherData(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientUpdateUserDataResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientUpdateUserPublisherData::OnSuccessCallback(const PlayFab::ClientModels::FUpdateUserDataResult& Result)
{
	FBPClientUpdateUserDataResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientUpdateUserPublisherData::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientUpdateUserDataResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
