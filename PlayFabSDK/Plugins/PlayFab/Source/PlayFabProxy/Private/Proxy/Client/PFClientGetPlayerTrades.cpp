// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFClientGetPlayerTrades.h"

UPFClientGetPlayerTrades::UPFClientGetPlayerTrades(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetPlayerTradesDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientGetPlayerTrades* UPFClientGetPlayerTrades::GetPlayerTrades(UObject* WorldContextObject, class APlayerController* PlayerController )
{
	UPFClientGetPlayerTrades* Proxy = NewObject<UPFClientGetPlayerTrades>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientGetPlayerTrades::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->GetPlayerTrades(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientGetPlayerTradesResponse BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientGetPlayerTrades::OnSuccessCallback(const PlayFab::ClientModels::FGetPlayerTradesResponse& Result)
{
	FBPClientGetPlayerTradesResponse BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientGetPlayerTrades::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientGetPlayerTradesResponse BPResult;
 	OnFailure.Broadcast(BPResult);	
}
