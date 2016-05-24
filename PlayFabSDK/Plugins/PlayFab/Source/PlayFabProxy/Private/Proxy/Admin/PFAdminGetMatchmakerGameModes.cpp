// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFAdminGetMatchmakerGameModes.h"

UPFAdminGetMatchmakerGameModes::UPFAdminGetMatchmakerGameModes(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FGetMatchmakerGameModesDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminGetMatchmakerGameModes* UPFAdminGetMatchmakerGameModes::GetMatchmakerGameModes(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InBuildVersion)
{
	UPFAdminGetMatchmakerGameModes* Proxy = NewObject<UPFAdminGetMatchmakerGameModes>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.BuildVersion = InBuildVersion;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminGetMatchmakerGameModes::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->GetMatchmakerGameModes(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPAdminGetMatchmakerGameModesResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminGetMatchmakerGameModes::OnSuccessCallback(const PlayFab::AdminModels::FGetMatchmakerGameModesResult& Result)
{
	FBPAdminGetMatchmakerGameModesResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFAdminGetMatchmakerGameModes::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPAdminGetMatchmakerGameModesResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
