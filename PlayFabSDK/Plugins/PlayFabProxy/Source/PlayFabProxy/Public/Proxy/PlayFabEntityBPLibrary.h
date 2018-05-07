// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Core/PlayFabEntityAPI.h"
#include "Core/PlayFabEntityDataModels.h"
#include "PlayFabEntityBPDataModels.h"
#include "PlayFabEntityBPLibrary.generated.h"

UCLASS(MinimalAPI)
class UPFEntityProxyLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    
    // AbortFileUploadsRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityAbortFileUploadsRequest MakeBPEntityAbortFileUploadsRequest(
            FBPEntityEntityKey InEntity
            , TArray<FString> InFileNames
            , int32 InProfileVersion
        );

    // AbortFileUploadsResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityAbortFileUploadsResponse(
            const FBPEntityAbortFileUploadsResponse& In
            , FBPEntityEntityKey& OutEntity
            , int32& OutProfileVersion
);

    // AcceptGroupApplicationRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityAcceptGroupApplicationRequest MakeBPEntityAcceptGroupApplicationRequest(
            FBPEntityEntityKey InEntity
            , FBPEntityEntityKey InGroup
        );

    // AcceptGroupInvitationRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityAcceptGroupInvitationRequest MakeBPEntityAcceptGroupInvitationRequest(
            FBPEntityEntityKey InEntity
            , FBPEntityEntityKey InGroup
        );

    // AddMembersRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityAddMembersRequest MakeBPEntityAddMembersRequest(
            FBPEntityEntityKey InGroup
            , TArray<FBPEntityEntityKey> InMembers
            , FString InRoleId
        );

    // ApplyToGroupRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityApplyToGroupRequest MakeBPEntityApplyToGroupRequest(
            bool InAutoAcceptOutstandingInvite
            , FBPEntityEntityKey InEntity
            , FBPEntityEntityKey InGroup
        );

    // ApplyToGroupResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityApplyToGroupResponse(
            const FBPEntityApplyToGroupResponse& In
            , FBPEntityEntityWithLineage& OutEntity
            , FDateTime& OutExpires
            , FBPEntityEntityKey& OutGroup
);

    // BlockEntityRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityBlockEntityRequest MakeBPEntityBlockEntityRequest(
            FBPEntityEntityKey InEntity
            , FBPEntityEntityKey InGroup
        );

    // ChangeMemberRoleRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityChangeMemberRoleRequest MakeBPEntityChangeMemberRoleRequest(
            FString InDestinationRoleId
            , FBPEntityEntityKey InGroup
            , TArray<FBPEntityEntityKey> InMembers
            , FString InOriginRoleId
        );

    // CreateGroupRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityCreateGroupRequest MakeBPEntityCreateGroupRequest(
            FBPEntityEntityKey InEntity
            , FString InGroupName
        );

    // CreateGroupResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityCreateGroupResponse(
            const FBPEntityCreateGroupResponse& In
            , FString& OutAdminRoleId
            , FDateTime& OutCreated
            , FBPEntityEntityKey& OutGroup
            , FString& OutGroupName
            , FString& OutMemberRoleId
            , int32& OutProfileVersion
            , TMap<FString, FString>& OutRoles
);

    // CreateGroupRoleRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityCreateGroupRoleRequest MakeBPEntityCreateGroupRoleRequest(
            FBPEntityEntityKey InGroup
            , FString InRoleId
            , FString InRoleName
        );

    // CreateGroupRoleResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityCreateGroupRoleResponse(
            const FBPEntityCreateGroupRoleResponse& In
            , int32& OutProfileVersion
            , FString& OutRoleId
            , FString& OutRoleName
);

    // DeleteFilesRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityDeleteFilesRequest MakeBPEntityDeleteFilesRequest(
            FBPEntityEntityKey InEntity
            , TArray<FString> InFileNames
            , int32 InProfileVersion
        );

    // DeleteFilesResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityDeleteFilesResponse(
            const FBPEntityDeleteFilesResponse& In
            , FBPEntityEntityKey& OutEntity
            , int32& OutProfileVersion
);

    // DeleteGroupRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityDeleteGroupRequest MakeBPEntityDeleteGroupRequest(
            FBPEntityEntityKey InGroup
        );

    // DeleteRoleRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityDeleteRoleRequest MakeBPEntityDeleteRoleRequest(
            FBPEntityEntityKey InGroup
            , FString InRoleId
        );

    // EmptyResult
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityEmptyResult(
            const FBPEntityEmptyResult& In
);

    // EntityDataObject
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityEntityDataObject MakeBPEntityEntityDataObject(
            UPlayFabJsonValue* InDataObject
            , FString InEscapedDataObject
            , FString InObjectName
        );
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityEntityDataObject(
            const FBPEntityEntityDataObject& In
            , UPlayFabJsonValue*& OutDataObject
            , FString& OutEscapedDataObject
            , FString& OutObjectName
);

    // EntityKey
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityEntityKey MakeBPEntityEntityKey(
            FString InId
            , EBPEntityEntityTypes InType
            , FString InTypeString
        );
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityEntityKey(
            const FBPEntityEntityKey& In
            , FString& OutId
            , EBPEntityEntityTypes& OutType
            , FString& OutTypeString
);

    // EntityMemberRole
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityEntityMemberRole MakeBPEntityEntityMemberRole(
            TArray<FBPEntityEntityWithLineage> InMembers
            , FString InRoleId
            , FString InRoleName
        );
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityEntityMemberRole(
            const FBPEntityEntityMemberRole& In
            , TArray<FBPEntityEntityWithLineage>& OutMembers
            , FString& OutRoleId
            , FString& OutRoleName
);

    // EntityPermissionStatement
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityEntityPermissionStatement MakeBPEntityEntityPermissionStatement(
            FString InAction
            , FString InComment
            , UPlayFabJsonValue* InCondition
            , EBPEntityEffectType InEffect
            , UPlayFabJsonValue* InPrincipal
            , FString InResource
        );
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityEntityPermissionStatement(
            const FBPEntityEntityPermissionStatement& In
            , FString& OutAction
            , FString& OutComment
            , UPlayFabJsonValue*& OutCondition
            , EBPEntityEffectType& OutEffect
            , UPlayFabJsonValue*& OutPrincipal
            , FString& OutResource
);

    // EntityProfileBody
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityEntityProfileBody MakeBPEntityEntityProfileBody(
            FBPEntityEntityKey InEntity
            , FString InEntityChain
            , TMap<FString, FBPEntityEntityProfileFileMetadata> InFiles
            , TMap<FString, FBPEntityEntityDataObject> InObjects
            , TArray<FBPEntityEntityPermissionStatement> InPermissions
            , int32 InVersionNumber
        );
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityEntityProfileBody(
            const FBPEntityEntityProfileBody& In
            , FBPEntityEntityKey& OutEntity
            , FString& OutEntityChain
            , TMap<FString, FBPEntityEntityProfileFileMetadata>& OutFiles
            , TMap<FString, FBPEntityEntityDataObject>& OutObjects
            , TArray<FBPEntityEntityPermissionStatement>& OutPermissions
            , int32& OutVersionNumber
);

    // EntityProfileFileMetadata
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityEntityProfileFileMetadata MakeBPEntityEntityProfileFileMetadata(
            FString InChecksum
            , FString InFileName
            , FDateTime InLastModified
            , int32 InSize
        );
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityEntityProfileFileMetadata(
            const FBPEntityEntityProfileFileMetadata& In
            , FString& OutChecksum
            , FString& OutFileName
            , FDateTime& OutLastModified
            , int32& OutSize
);

    // EntityWithLineage
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityEntityWithLineage MakeBPEntityEntityWithLineage(
            FBPEntityEntityKey InKey
            , TMap<FString, FBPEntityEntityKey> InLineage
        );
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityEntityWithLineage(
            const FBPEntityEntityWithLineage& In
            , FBPEntityEntityKey& OutKey
            , TMap<FString, FBPEntityEntityKey>& OutLineage
);

    // FinalizeFileUploadsRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityFinalizeFileUploadsRequest MakeBPEntityFinalizeFileUploadsRequest(
            FBPEntityEntityKey InEntity
            , TArray<FString> InFileNames
        );

    // FinalizeFileUploadsResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityFinalizeFileUploadsResponse(
            const FBPEntityFinalizeFileUploadsResponse& In
            , FBPEntityEntityKey& OutEntity
            , TMap<FString, FBPEntityGetFileMetadata>& OutMetadata
            , int32& OutProfileVersion
);

    // GetEntityProfileRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityGetEntityProfileRequest MakeBPEntityGetEntityProfileRequest(
            bool InDataAsObject
            , FBPEntityEntityKey InEntity
        );

    // GetEntityProfileResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityGetEntityProfileResponse(
            const FBPEntityGetEntityProfileResponse& In
            , FBPEntityEntityProfileBody& OutProfile
);

    // GetEntityProfilesRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityGetEntityProfilesRequest MakeBPEntityGetEntityProfilesRequest(
            bool InDataAsObject
            , TArray<FBPEntityEntityKey> InEntities
        );

    // GetEntityProfilesResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityGetEntityProfilesResponse(
            const FBPEntityGetEntityProfilesResponse& In
            , TArray<FBPEntityEntityProfileBody>& OutProfiles
);

    // GetEntityTokenRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityGetEntityTokenRequest MakeBPEntityGetEntityTokenRequest(
            FBPEntityEntityKey InEntity
        );

    // GetEntityTokenResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityGetEntityTokenResponse(
            const FBPEntityGetEntityTokenResponse& In
            , FBPEntityEntityKey& OutEntity
            , FString& OutEntityToken
            , FDateTime& OutTokenExpiration
);

    // GetFileMetadata
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityGetFileMetadata MakeBPEntityGetFileMetadata(
            FString InChecksum
            , FString InDownloadUrl
            , FString InFileName
            , FDateTime InLastModified
            , int32 InSize
        );
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityGetFileMetadata(
            const FBPEntityGetFileMetadata& In
            , FString& OutChecksum
            , FString& OutDownloadUrl
            , FString& OutFileName
            , FDateTime& OutLastModified
            , int32& OutSize
);

    // GetFilesRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityGetFilesRequest MakeBPEntityGetFilesRequest(
            FBPEntityEntityKey InEntity
        );

    // GetFilesResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityGetFilesResponse(
            const FBPEntityGetFilesResponse& In
            , FBPEntityEntityKey& OutEntity
            , TMap<FString, FBPEntityGetFileMetadata>& OutMetadata
            , int32& OutProfileVersion
);

    // GetGlobalPolicyRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityGetGlobalPolicyRequest MakeBPEntityGetGlobalPolicyRequest(
        );

    // GetGlobalPolicyResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityGetGlobalPolicyResponse(
            const FBPEntityGetGlobalPolicyResponse& In
            , TArray<FBPEntityEntityPermissionStatement>& OutPermissions
);

    // GetGroupRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityGetGroupRequest MakeBPEntityGetGroupRequest(
            FBPEntityEntityKey InGroup
            , FString InGroupName
        );

    // GetGroupResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityGetGroupResponse(
            const FBPEntityGetGroupResponse& In
            , FString& OutAdminRoleId
            , FDateTime& OutCreated
            , FBPEntityEntityKey& OutGroup
            , FString& OutGroupName
            , FString& OutMemberRoleId
            , int32& OutProfileVersion
            , TMap<FString, FString>& OutRoles
);

    // GetObjectsRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityGetObjectsRequest MakeBPEntityGetObjectsRequest(
            FBPEntityEntityKey InEntity
            , bool InEscapeObject
        );

    // GetObjectsResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityGetObjectsResponse(
            const FBPEntityGetObjectsResponse& In
            , FBPEntityEntityKey& OutEntity
            , TMap<FString, FBPEntityObjectResult>& OutObjects
            , int32& OutProfileVersion
);

    // GroupApplication
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityGroupApplication MakeBPEntityGroupApplication(
            FBPEntityEntityWithLineage InEntity
            , FDateTime InExpires
            , FBPEntityEntityKey InGroup
        );
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityGroupApplication(
            const FBPEntityGroupApplication& In
            , FBPEntityEntityWithLineage& OutEntity
            , FDateTime& OutExpires
            , FBPEntityEntityKey& OutGroup
);

    // GroupBlock
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityGroupBlock MakeBPEntityGroupBlock(
            FBPEntityEntityWithLineage InEntity
            , FBPEntityEntityKey InGroup
        );
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityGroupBlock(
            const FBPEntityGroupBlock& In
            , FBPEntityEntityWithLineage& OutEntity
            , FBPEntityEntityKey& OutGroup
);

    // GroupInvitation
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityGroupInvitation MakeBPEntityGroupInvitation(
            FDateTime InExpires
            , FBPEntityEntityKey InGroup
            , FBPEntityEntityWithLineage InInvitedByEntity
            , FBPEntityEntityWithLineage InInvitedEntity
            , FString InRoleId
        );
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityGroupInvitation(
            const FBPEntityGroupInvitation& In
            , FDateTime& OutExpires
            , FBPEntityEntityKey& OutGroup
            , FBPEntityEntityWithLineage& OutInvitedByEntity
            , FBPEntityEntityWithLineage& OutInvitedEntity
            , FString& OutRoleId
);

    // GroupRole
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityGroupRole MakeBPEntityGroupRole(
            FString InRoleId
            , FString InRoleName
        );
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityGroupRole(
            const FBPEntityGroupRole& In
            , FString& OutRoleId
            , FString& OutRoleName
);

    // GroupWithRoles
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityGroupWithRoles MakeBPEntityGroupWithRoles(
            FBPEntityEntityKey InGroup
            , FString InGroupName
            , int32 InProfileVersion
            , TArray<FBPEntityGroupRole> InRoles
        );
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityGroupWithRoles(
            const FBPEntityGroupWithRoles& In
            , FBPEntityEntityKey& OutGroup
            , FString& OutGroupName
            , int32& OutProfileVersion
            , TArray<FBPEntityGroupRole>& OutRoles
);

    // InitiateFileUploadMetadata
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityInitiateFileUploadMetadata MakeBPEntityInitiateFileUploadMetadata(
            FString InFileName
            , FString InUploadUrl
        );
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityInitiateFileUploadMetadata(
            const FBPEntityInitiateFileUploadMetadata& In
            , FString& OutFileName
            , FString& OutUploadUrl
);

    // InitiateFileUploadsRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityInitiateFileUploadsRequest MakeBPEntityInitiateFileUploadsRequest(
            FBPEntityEntityKey InEntity
            , TArray<FString> InFileNames
            , int32 InProfileVersion
        );

    // InitiateFileUploadsResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityInitiateFileUploadsResponse(
            const FBPEntityInitiateFileUploadsResponse& In
            , FBPEntityEntityKey& OutEntity
            , int32& OutProfileVersion
            , TArray<FBPEntityInitiateFileUploadMetadata>& OutUploadDetails
);

    // InviteToGroupRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityInviteToGroupRequest MakeBPEntityInviteToGroupRequest(
            bool InAutoAcceptOutstandingApplication
            , FBPEntityEntityKey InEntity
            , FBPEntityEntityKey InGroup
            , FString InRoleId
        );

    // InviteToGroupResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityInviteToGroupResponse(
            const FBPEntityInviteToGroupResponse& In
            , FDateTime& OutExpires
            , FBPEntityEntityKey& OutGroup
            , FBPEntityEntityWithLineage& OutInvitedByEntity
            , FBPEntityEntityWithLineage& OutInvitedEntity
            , FString& OutRoleId
);

    // IsMemberRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityIsMemberRequest MakeBPEntityIsMemberRequest(
            FBPEntityEntityKey InEntity
            , FBPEntityEntityKey InGroup
            , FString InRoleId
        );

    // IsMemberResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityIsMemberResponse(
            const FBPEntityIsMemberResponse& In
            , bool& OutIsMember
);

    // ListGroupApplicationsRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityListGroupApplicationsRequest MakeBPEntityListGroupApplicationsRequest(
            FBPEntityEntityKey InGroup
        );

    // ListGroupApplicationsResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityListGroupApplicationsResponse(
            const FBPEntityListGroupApplicationsResponse& In
            , TArray<FBPEntityGroupApplication>& OutApplications
);

    // ListGroupBlocksRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityListGroupBlocksRequest MakeBPEntityListGroupBlocksRequest(
            FBPEntityEntityKey InGroup
        );

    // ListGroupBlocksResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityListGroupBlocksResponse(
            const FBPEntityListGroupBlocksResponse& In
            , TArray<FBPEntityGroupBlock>& OutBlockedEntities
);

    // ListGroupInvitationsRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityListGroupInvitationsRequest MakeBPEntityListGroupInvitationsRequest(
            FBPEntityEntityKey InGroup
        );

    // ListGroupInvitationsResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityListGroupInvitationsResponse(
            const FBPEntityListGroupInvitationsResponse& In
            , TArray<FBPEntityGroupInvitation>& OutInvitations
);

    // ListGroupMembersRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityListGroupMembersRequest MakeBPEntityListGroupMembersRequest(
            FBPEntityEntityKey InGroup
        );

    // ListGroupMembersResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityListGroupMembersResponse(
            const FBPEntityListGroupMembersResponse& In
            , TArray<FBPEntityEntityMemberRole>& OutMembers
);

    // ListMembershipOpportunitiesRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityListMembershipOpportunitiesRequest MakeBPEntityListMembershipOpportunitiesRequest(
            FBPEntityEntityKey InEntity
        );

    // ListMembershipOpportunitiesResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityListMembershipOpportunitiesResponse(
            const FBPEntityListMembershipOpportunitiesResponse& In
            , TArray<FBPEntityGroupApplication>& OutApplications
            , TArray<FBPEntityGroupInvitation>& OutInvitations
);

    // ListMembershipRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityListMembershipRequest MakeBPEntityListMembershipRequest(
            FBPEntityEntityKey InEntity
        );

    // ListMembershipResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityListMembershipResponse(
            const FBPEntityListMembershipResponse& In
            , TArray<FBPEntityGroupWithRoles>& OutGroups
);

    // ObjectResult
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityObjectResult(
            const FBPEntityObjectResult& In
            , UPlayFabJsonValue*& OutDataObject
            , FString& OutEscapedDataObject
            , FString& OutObjectName
);

    // RemoveGroupApplicationRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityRemoveGroupApplicationRequest MakeBPEntityRemoveGroupApplicationRequest(
            FBPEntityEntityKey InEntity
            , FBPEntityEntityKey InGroup
        );

    // RemoveGroupInvitationRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityRemoveGroupInvitationRequest MakeBPEntityRemoveGroupInvitationRequest(
            FBPEntityEntityKey InEntity
            , FBPEntityEntityKey InGroup
        );

    // RemoveMembersRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityRemoveMembersRequest MakeBPEntityRemoveMembersRequest(
            FBPEntityEntityKey InGroup
            , TArray<FBPEntityEntityKey> InMembers
            , FString InRoleId
        );

    // SetEntityProfilePolicyRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntitySetEntityProfilePolicyRequest MakeBPEntitySetEntityProfilePolicyRequest(
            FBPEntityEntityKey InEntity
            , TArray<FBPEntityEntityPermissionStatement> InStatements
        );

    // SetEntityProfilePolicyResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntitySetEntityProfilePolicyResponse(
            const FBPEntitySetEntityProfilePolicyResponse& In
            , TArray<FBPEntityEntityPermissionStatement>& OutPermissions
);

    // SetGlobalPolicyRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntitySetGlobalPolicyRequest MakeBPEntitySetGlobalPolicyRequest(
            TArray<FBPEntityEntityPermissionStatement> InPermissions
        );

    // SetGlobalPolicyResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntitySetGlobalPolicyResponse(
            const FBPEntitySetGlobalPolicyResponse& In
);

    // SetObject
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntitySetObject MakeBPEntitySetObject(
            UPlayFabJsonValue* InDataObject
            , bool InDeleteObject
            , FString InEscapedDataObject
            , FString InObjectName
        );
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntitySetObject(
            const FBPEntitySetObject& In
            , UPlayFabJsonValue*& OutDataObject
            , bool& OutDeleteObject
            , FString& OutEscapedDataObject
            , FString& OutObjectName
);

    // SetObjectInfo
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntitySetObjectInfo MakeBPEntitySetObjectInfo(
            FString InObjectName
            , FString InOperationReason
            , EBPEntityOperationTypes InSetResult
        );
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntitySetObjectInfo(
            const FBPEntitySetObjectInfo& In
            , FString& OutObjectName
            , FString& OutOperationReason
            , EBPEntityOperationTypes& OutSetResult
);

    // SetObjectsRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntitySetObjectsRequest MakeBPEntitySetObjectsRequest(
            FBPEntityEntityKey InEntity
            , int32 InExpectedProfileVersion
            , TArray<FBPEntitySetObject> InObjects
        );

    // SetObjectsResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntitySetObjectsResponse(
            const FBPEntitySetObjectsResponse& In
            , int32& OutProfileVersion
            , TArray<FBPEntitySetObjectInfo>& OutSetResults
);

    // UnblockEntityRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityUnblockEntityRequest MakeBPEntityUnblockEntityRequest(
            FBPEntityEntityKey InEntity
            , FBPEntityEntityKey InGroup
        );

    // UpdateGroupRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityUpdateGroupRequest MakeBPEntityUpdateGroupRequest(
            FString InAdminRoleId
            , int32 InExpectedProfileVersion
            , FBPEntityEntityKey InGroup
            , FString InGroupName
            , FString InMemberRoleId
        );

    // UpdateGroupResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityUpdateGroupResponse(
            const FBPEntityUpdateGroupResponse& In
            , FString& OutOperationReason
            , int32& OutProfileVersion
            , EBPEntityOperationTypes& OutSetResult
);

    // UpdateGroupRoleRequest
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeMakeFunc))
        static FBPEntityUpdateGroupRoleRequest MakeBPEntityUpdateGroupRoleRequest(
            int32 InExpectedProfileVersion
            , FBPEntityEntityKey InGroup
            , FString InRoleId
            , FString InRoleName
        );

    // UpdateGroupRoleResponse
    UFUNCTION(BlueprintPure, Category = "PlayFab|Entity", meta = (NativeBreakFunc))
        static void BreakBPEntityUpdateGroupRoleResponse(
            const FBPEntityUpdateGroupRoleResponse& In
            , FString& OutOperationReason
            , int32& OutProfileVersion
            , EBPEntityOperationTypes& OutSetResult
);

};
