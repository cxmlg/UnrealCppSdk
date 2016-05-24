// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFServerGetUserInternalData.h"

UPFServerGetUserInternalData::UPFServerGetUserInternalData(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabServerAPI::FGetUserInternalDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFServerGetUserInternalData* UPFServerGetUserInternalData::GetUserInternalData(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId, const TArray<FString>& InKeys, const int32& InIfChangedFromDataVersion)
{
	UPFServerGetUserInternalData* Proxy = NewObject<UPFServerGetUserInternalData>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	Proxy->Request.Keys = InKeys;
	Proxy->Request.IfChangedFromDataVersion = InIfChangedFromDataVersion;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFServerGetUserInternalData::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

	bool CallResult = false;

	if(ServerAPI.IsValid())
	{	
		CallResult = ServerAPI->GetUserInternalData(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPServerGetUserDataResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFServerGetUserInternalData::OnSuccessCallback(const PlayFab::ServerModels::FGetUserDataResult& Result)
{
	FBPServerGetUserDataResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFServerGetUserInternalData::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPServerGetUserDataResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
