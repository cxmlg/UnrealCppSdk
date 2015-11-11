// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFServerUpdateUserReadOnlyData.h"

UPFServerUpdateUserReadOnlyData::UPFServerUpdateUserReadOnlyData(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabServerAPI::FUpdateUserReadOnlyDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFServerUpdateUserReadOnlyData* UPFServerUpdateUserReadOnlyData::UpdateUserReadOnlyData(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId, const FString& InData, const TArray<FString>& InKeysToRemove)
{
	UPFServerUpdateUserReadOnlyData* Proxy = NewObject<UPFServerUpdateUserReadOnlyData>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	
	Proxy->Request.KeysToRemove = InKeysToRemove;
	
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFServerUpdateUserReadOnlyData::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

	bool CallResult = false;

	if(ServerAPI.IsValid())
	{	
		CallResult = ServerAPI->UpdateUserReadOnlyData(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPServerUpdateUserDataResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFServerUpdateUserReadOnlyData::OnSuccessCallback(const PlayFab::ServerModels::FUpdateUserDataResult& Result)
{
	FBPServerUpdateUserDataResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFServerUpdateUserReadOnlyData::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPServerUpdateUserDataResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
