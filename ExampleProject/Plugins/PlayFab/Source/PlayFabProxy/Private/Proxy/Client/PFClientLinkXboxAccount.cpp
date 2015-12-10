// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFClientLinkXboxAccount.h"

UPFClientLinkXboxAccount::UPFClientLinkXboxAccount(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FLinkXboxAccountDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientLinkXboxAccount* UPFClientLinkXboxAccount::LinkXboxAccount(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InXboxToken)
{
	UPFClientLinkXboxAccount* Proxy = NewObject<UPFClientLinkXboxAccount>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.XboxToken = InXboxToken;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientLinkXboxAccount::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->LinkXboxAccount(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientLinkXboxAccount::OnSuccessCallback(const PlayFab::ClientModels::FLinkXboxAccountResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFClientLinkXboxAccount::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}
