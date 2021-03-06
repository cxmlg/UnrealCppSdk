// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerGetContentDownloadUrl.generated.h"

UCLASS(MinimalAPI)
class UPFServerGetContentDownloadUrl : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPServerGetContentDownloadUrlResultDelegate OnSuccess;

    // This API retrieves a pre-signed URL for accessing a content file for the title. A subsequent HTTP GET to the returned URL will attempt to download the content. A HEAD query to the returned URL will attempt to retrieve the metadata of the content. Note that a successful result does not guarantee the existence of this content - if it has not been uploaded, the query to retrieve the data will fail. See this post for more information: https://community.playfab.com/hc/en-us/community/posts/205469488-How-to-upload-files-to-PlayFab-s-Content-Service. Also, please be aware that the Content service is specifically PlayFab's CDN offering, for which standard CDN rates apply.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Server|Content")
        static UPFServerGetContentDownloadUrl* GetContentDownloadUrl(class APlayerController* PlayerController, const FBPServerGetContentDownloadUrlRequest& InGetContentDownloadUrlRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPServerGetContentDownloadUrlRequest Request;
    PlayFab::UPlayFabServerAPI::FGetContentDownloadUrlDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ServerModels::FGetContentDownloadUrlResult& Result);
};
