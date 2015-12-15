// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFAdminIncrementPlayerStatisticVersion.h"

UPFAdminIncrementPlayerStatisticVersion::UPFAdminIncrementPlayerStatisticVersion(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FIncrementPlayerStatisticVersionDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminIncrementPlayerStatisticVersion* UPFAdminIncrementPlayerStatisticVersion::IncrementPlayerStatisticVersion(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InStatisticName)
{
	UPFAdminIncrementPlayerStatisticVersion* Proxy = NewObject<UPFAdminIncrementPlayerStatisticVersion>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.StatisticName = InStatisticName;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminIncrementPlayerStatisticVersion::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->IncrementPlayerStatisticVersion(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPAdminIncrementPlayerStatisticVersionResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminIncrementPlayerStatisticVersion::OnSuccessCallback(const PlayFab::AdminModels::FIncrementPlayerStatisticVersionResult& Result)
{
	FBPAdminIncrementPlayerStatisticVersionResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFAdminIncrementPlayerStatisticVersion::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPAdminIncrementPlayerStatisticVersionResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
