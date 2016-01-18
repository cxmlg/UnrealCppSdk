// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFClientGetCloudScriptUrl.h"

UPFClientGetCloudScriptUrl::UPFClientGetCloudScriptUrl(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetCloudScriptUrlDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientGetCloudScriptUrl* UPFClientGetCloudScriptUrl::GetCloudScriptUrl(UObject* WorldContextObject, class APlayerController* PlayerController , const int32& InVersion, const bool& InTesting)
{
	UPFClientGetCloudScriptUrl* Proxy = NewObject<UPFClientGetCloudScriptUrl>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.Version = InVersion;
	Proxy->Request.Testing = InTesting;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientGetCloudScriptUrl::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->GetCloudScriptUrl(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientGetCloudScriptUrlResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientGetCloudScriptUrl::OnSuccessCallback(const PlayFab::ClientModels::FGetCloudScriptUrlResult& Result)
{
	FBPClientGetCloudScriptUrlResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientGetCloudScriptUrl::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientGetCloudScriptUrlResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}