// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFClientGetPhotonAuthenticationToken.h"

UPFClientGetPhotonAuthenticationToken::UPFClientGetPhotonAuthenticationToken(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetPhotonAuthenticationTokenDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientGetPhotonAuthenticationToken* UPFClientGetPhotonAuthenticationToken::GetPhotonAuthenticationToken(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPhotonApplicationId)
{
	UPFClientGetPhotonAuthenticationToken* Proxy = NewObject<UPFClientGetPhotonAuthenticationToken>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PhotonApplicationId = InPhotonApplicationId;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientGetPhotonAuthenticationToken::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->GetPhotonAuthenticationToken(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientGetPhotonAuthenticationTokenResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientGetPhotonAuthenticationToken::OnSuccessCallback(const PlayFab::ClientModels::FGetPhotonAuthenticationTokenResult& Result)
{
	FBPClientGetPhotonAuthenticationTokenResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientGetPhotonAuthenticationToken::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientGetPhotonAuthenticationTokenResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}