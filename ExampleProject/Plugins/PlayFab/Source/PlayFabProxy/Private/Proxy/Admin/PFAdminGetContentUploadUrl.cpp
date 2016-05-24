// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFAdminGetContentUploadUrl.h"

UPFAdminGetContentUploadUrl::UPFAdminGetContentUploadUrl(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FGetContentUploadUrlDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminGetContentUploadUrl* UPFAdminGetContentUploadUrl::GetContentUploadUrl(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InKey, const FString& InContentType)
{
	UPFAdminGetContentUploadUrl* Proxy = NewObject<UPFAdminGetContentUploadUrl>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.Key = InKey;
	Proxy->Request.ContentType = InContentType;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminGetContentUploadUrl::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->GetContentUploadUrl(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPAdminGetContentUploadUrlResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminGetContentUploadUrl::OnSuccessCallback(const PlayFab::AdminModels::FGetContentUploadUrlResult& Result)
{
	FBPAdminGetContentUploadUrlResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFAdminGetContentUploadUrl::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPAdminGetContentUploadUrlResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
