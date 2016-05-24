// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFAdminUpdateUserReadOnlyData.h"

UPFAdminUpdateUserReadOnlyData::UPFAdminUpdateUserReadOnlyData(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FUpdateUserReadOnlyDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminUpdateUserReadOnlyData* UPFAdminUpdateUserReadOnlyData::UpdateUserReadOnlyData(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId, const FString& InData, const TArray<FString>& InKeysToRemove)
{
	UPFAdminUpdateUserReadOnlyData* Proxy = NewObject<UPFAdminUpdateUserReadOnlyData>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	
	Proxy->Request.KeysToRemove = InKeysToRemove;
	
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminUpdateUserReadOnlyData::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->UpdateUserReadOnlyData(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPAdminUpdateUserDataResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminUpdateUserReadOnlyData::OnSuccessCallback(const PlayFab::AdminModels::FUpdateUserDataResult& Result)
{
	FBPAdminUpdateUserDataResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFAdminUpdateUserReadOnlyData::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPAdminUpdateUserDataResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
