// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFAdminUpdateUserPublisherData.h"

UPFAdminUpdateUserPublisherData::UPFAdminUpdateUserPublisherData(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FUpdateUserPublisherDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminUpdateUserPublisherData* UPFAdminUpdateUserPublisherData::UpdateUserPublisherData(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId, const FString& InData, const TArray<FString>& InKeysToRemove)
{
	UPFAdminUpdateUserPublisherData* Proxy = NewObject<UPFAdminUpdateUserPublisherData>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	
	Proxy->Request.KeysToRemove = InKeysToRemove;
	
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminUpdateUserPublisherData::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->UpdateUserPublisherData(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPAdminUpdateUserDataResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminUpdateUserPublisherData::OnSuccessCallback(const PlayFab::AdminModels::FUpdateUserDataResult& Result)
{
	FBPAdminUpdateUserDataResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFAdminUpdateUserPublisherData::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPAdminUpdateUserDataResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
