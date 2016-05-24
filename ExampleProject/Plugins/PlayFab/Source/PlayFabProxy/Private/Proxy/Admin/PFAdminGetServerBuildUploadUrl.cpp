// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFAdminGetServerBuildUploadUrl.h"

UPFAdminGetServerBuildUploadUrl::UPFAdminGetServerBuildUploadUrl(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FGetServerBuildUploadUrlDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminGetServerBuildUploadUrl* UPFAdminGetServerBuildUploadUrl::GetServerBuildUploadUrl(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InBuildId)
{
	UPFAdminGetServerBuildUploadUrl* Proxy = NewObject<UPFAdminGetServerBuildUploadUrl>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.BuildId = InBuildId;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminGetServerBuildUploadUrl::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->GetServerBuildUploadUrl(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPAdminGetServerBuildUploadURLResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminGetServerBuildUploadUrl::OnSuccessCallback(const PlayFab::AdminModels::FGetServerBuildUploadURLResult& Result)
{
	FBPAdminGetServerBuildUploadURLResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFAdminGetServerBuildUploadUrl::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPAdminGetServerBuildUploadURLResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
