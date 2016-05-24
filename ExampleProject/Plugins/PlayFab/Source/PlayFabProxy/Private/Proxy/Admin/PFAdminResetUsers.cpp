// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFAdminResetUsers.h"

UPFAdminResetUsers::UPFAdminResetUsers(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FResetUsersDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminResetUsers* UPFAdminResetUsers::ResetUsers(UObject* WorldContextObject, class APlayerController* PlayerController , const TArray<FBPAdminUserCredentials>& InUsers)
{
	UPFAdminResetUsers* Proxy = NewObject<UPFAdminResetUsers>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	for (const FBPAdminUserCredentials& elem : InUsers)
    {
        Proxy->Request.Users.Add(elem.Data);
    }

	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminResetUsers::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->ResetUsers(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminResetUsers::OnSuccessCallback(const PlayFab::AdminModels::FBlankResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFAdminResetUsers::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}
