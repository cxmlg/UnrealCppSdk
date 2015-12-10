// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFClientLoginWithPSN.h"

UPFClientLoginWithPSN::UPFClientLoginWithPSN(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FLoginWithPSNDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientLoginWithPSN* UPFClientLoginWithPSN::LoginWithPSN(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InTitleId, const FString& InAuthCode, const FString& InRedirectUri, const int32& InIssuerId, const bool& InCreateAccount)
{
	UPFClientLoginWithPSN* Proxy = NewObject<UPFClientLoginWithPSN>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.TitleId = InTitleId;
	Proxy->Request.AuthCode = InAuthCode;
	Proxy->Request.RedirectUri = InRedirectUri;
	Proxy->Request.IssuerId = InIssuerId;
	Proxy->Request.CreateAccount = InCreateAccount;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientLoginWithPSN::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->LoginWithPSN(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientLoginResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientLoginWithPSN::OnSuccessCallback(const PlayFab::ClientModels::FLoginResult& Result)
{
	FBPClientLoginResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientLoginWithPSN::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientLoginResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
