// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFAdminGetCloudScriptVersions.h"

UPFAdminGetCloudScriptVersions::UPFAdminGetCloudScriptVersions(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FGetCloudScriptVersionsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminGetCloudScriptVersions* UPFAdminGetCloudScriptVersions::GetCloudScriptVersions(UObject* WorldContextObject, class APlayerController* PlayerController )
{
	UPFAdminGetCloudScriptVersions* Proxy = NewObject<UPFAdminGetCloudScriptVersions>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminGetCloudScriptVersions::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->GetCloudScriptVersions(SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPAdminGetCloudScriptVersionsResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminGetCloudScriptVersions::OnSuccessCallback(const PlayFab::AdminModels::FGetCloudScriptVersionsResult& Result)
{
	FBPAdminGetCloudScriptVersionsResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFAdminGetCloudScriptVersions::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPAdminGetCloudScriptVersionsResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
