// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFAdminGetUserInternalData.h"

UPFAdminGetUserInternalData::UPFAdminGetUserInternalData(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FGetUserInternalDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminGetUserInternalData* UPFAdminGetUserInternalData::GetUserInternalData(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId, const TArray<FString>& InKeys, const int32& InIfChangedFromDataVersion)
{
	UPFAdminGetUserInternalData* Proxy = NewObject<UPFAdminGetUserInternalData>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	Proxy->Request.Keys = InKeys;
	Proxy->Request.IfChangedFromDataVersion = InIfChangedFromDataVersion;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminGetUserInternalData::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->GetUserInternalData(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPAdminGetUserDataResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminGetUserInternalData::OnSuccessCallback(const PlayFab::AdminModels::FGetUserDataResult& Result)
{
	FBPAdminGetUserDataResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFAdminGetUserInternalData::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPAdminGetUserDataResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
