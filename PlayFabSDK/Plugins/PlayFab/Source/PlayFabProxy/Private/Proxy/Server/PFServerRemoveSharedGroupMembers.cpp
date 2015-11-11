// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFServerRemoveSharedGroupMembers.h"

UPFServerRemoveSharedGroupMembers::UPFServerRemoveSharedGroupMembers(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabServerAPI::FRemoveSharedGroupMembersDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFServerRemoveSharedGroupMembers* UPFServerRemoveSharedGroupMembers::RemoveSharedGroupMembers(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InSharedGroupId, const TArray<FString>& InPlayFabIds)
{
	UPFServerRemoveSharedGroupMembers* Proxy = NewObject<UPFServerRemoveSharedGroupMembers>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.SharedGroupId = InSharedGroupId;
	Proxy->Request.PlayFabIds = InPlayFabIds;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFServerRemoveSharedGroupMembers::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

	bool CallResult = false;

	if(ServerAPI.IsValid())
	{	
		CallResult = ServerAPI->RemoveSharedGroupMembers(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFServerRemoveSharedGroupMembers::OnSuccessCallback(const PlayFab::ServerModels::FRemoveSharedGroupMembersResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFServerRemoveSharedGroupMembers::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}
