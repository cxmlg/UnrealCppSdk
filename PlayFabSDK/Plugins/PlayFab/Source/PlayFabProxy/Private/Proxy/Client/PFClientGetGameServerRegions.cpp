// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFClientGetGameServerRegions.h"

UPFClientGetGameServerRegions::UPFClientGetGameServerRegions(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetGameServerRegionsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientGetGameServerRegions* UPFClientGetGameServerRegions::GetGameServerRegions(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InBuildVersion, const FString& InTitleId)
{
	UPFClientGetGameServerRegions* Proxy = NewObject<UPFClientGetGameServerRegions>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.BuildVersion = InBuildVersion;
	Proxy->Request.TitleId = InTitleId;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientGetGameServerRegions::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->GetGameServerRegions(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientGameServerRegionsResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientGetGameServerRegions::OnSuccessCallback(const PlayFab::ClientModels::FGameServerRegionsResult& Result)
{
	FBPClientGameServerRegionsResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientGetGameServerRegions::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientGameServerRegionsResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
