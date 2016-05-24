// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFServerRedeemMatchmakerTicket.h"

UPFServerRedeemMatchmakerTicket::UPFServerRedeemMatchmakerTicket(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabServerAPI::FRedeemMatchmakerTicketDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFServerRedeemMatchmakerTicket* UPFServerRedeemMatchmakerTicket::RedeemMatchmakerTicket(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InTicket, const FString& InLobbyId)
{
	UPFServerRedeemMatchmakerTicket* Proxy = NewObject<UPFServerRedeemMatchmakerTicket>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.Ticket = InTicket;
	Proxy->Request.LobbyId = InLobbyId;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFServerRedeemMatchmakerTicket::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

	bool CallResult = false;

	if(ServerAPI.IsValid())
	{	
		CallResult = ServerAPI->RedeemMatchmakerTicket(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPServerRedeemMatchmakerTicketResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFServerRedeemMatchmakerTicket::OnSuccessCallback(const PlayFab::ServerModels::FRedeemMatchmakerTicketResult& Result)
{
	FBPServerRedeemMatchmakerTicketResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFServerRedeemMatchmakerTicket::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPServerRedeemMatchmakerTicketResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
