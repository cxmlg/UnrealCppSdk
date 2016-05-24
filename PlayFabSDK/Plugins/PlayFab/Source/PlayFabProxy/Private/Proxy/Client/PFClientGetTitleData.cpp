// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFClientGetTitleData.h"

UPFClientGetTitleData::UPFClientGetTitleData(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetTitleDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientGetTitleData* UPFClientGetTitleData::GetTitleData(UObject* WorldContextObject, class APlayerController* PlayerController , const TArray<FString>& InKeys)
{
	UPFClientGetTitleData* Proxy = NewObject<UPFClientGetTitleData>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.Keys = InKeys;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientGetTitleData::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->GetTitleData(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientGetTitleDataResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientGetTitleData::OnSuccessCallback(const PlayFab::ClientModels::FGetTitleDataResult& Result)
{
	FBPClientGetTitleDataResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientGetTitleData::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientGetTitleDataResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
