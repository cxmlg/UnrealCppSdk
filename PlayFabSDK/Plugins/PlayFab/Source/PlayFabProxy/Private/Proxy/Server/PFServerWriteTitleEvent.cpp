// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFServerWriteTitleEvent.h"

UPFServerWriteTitleEvent::UPFServerWriteTitleEvent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabServerAPI::FWriteTitleEventDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFServerWriteTitleEvent* UPFServerWriteTitleEvent::WriteTitleEvent(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InEventName, const FDateTime& InTimestamp)
{
	UPFServerWriteTitleEvent* Proxy = NewObject<UPFServerWriteTitleEvent>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.EventName = InEventName;
	
	
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFServerWriteTitleEvent::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

	bool CallResult = false;

	if(ServerAPI.IsValid())
	{	
		CallResult = ServerAPI->WriteTitleEvent(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPServerWriteEventResponse BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFServerWriteTitleEvent::OnSuccessCallback(const PlayFab::ServerModels::FWriteEventResponse& Result)
{
	FBPServerWriteEventResponse BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFServerWriteTitleEvent::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPServerWriteEventResponse BPResult;
 	OnFailure.Broadcast(BPResult);	
}
