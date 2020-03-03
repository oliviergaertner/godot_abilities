#pragma once

#include "gameplay_node.h"
#include <core/reference.h>

class GameplayAbilitySystem;

class GAMEPLAY_ABILITIES_API GameplayAbilityTask : public Reference {
	GDCLASS(GameplayAbilityTask, Reference);
	OBJ_CATEGORY("GameplayAbilities");

public:
    virtual ~GameplayAbilityTask() = default;

    void TickTask(float delta);
    
    void initialise(GameplayAbilitySystem* taskOwner);

    GameplayAbilitySystem* get_owner() {return owner;}

    virtual void task_completed();

    static void _bind_methods();
private:
    GameplayAbilitySystem *owner = nullptr;
};