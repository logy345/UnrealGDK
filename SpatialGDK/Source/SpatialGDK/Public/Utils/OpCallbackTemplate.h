// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include <WorkerSDK/improbable/c_worker.h>
#include "OpCallbackTemplate.generated.h"

UCLASS(abstract)
class SPATIALGDK_API UOpCallbackTemplate : public UObject
{
	GENERATED_BODY()

public:
	UOpCallbackTemplate() = default;
	~UOpCallbackTemplate() = default;

	/**
	  * Called by SpatialDispatcher on initialization, this is to allow the user to write more useful callbacks.
	  * @param World the UWorld top level hierarchy object.
	  */
	void Init(UWorld* InWorld) {
		World = InWorld;
	}

	/**
	  * Component ID the callbacks should apply to
	  */
	virtual Worker_ComponentId GetComponentId() PURE_VIRTUAL(UOpCallbackTemplate::GetComponentId, return -1;);

	/**
	  * Add callbacks for the ops being processed by the SpatialDispatcher for component_id
	  * @param op the Worker_OP C API object reference.
	  */
	virtual void OnAddComponent(const Worker_AddComponentOp& op) {}
	virtual void OnRemoveComponent(const Worker_RemoveComponentOp& op) {}
	virtual void OnComponentUpdate(const Worker_ComponentUpdateOp& op) {}
	virtual void OnAuthorityChange(const Worker_AuthorityChangeOp& op) {}
	virtual void OnCommandRequest(const Worker_CommandRequestOp& op) {}
	virtual void OnCommandResponse(const Worker_CommandResponseOp& op) {}

protected:
	UWorld* World;
};