#include "gameplay_ability_task.h"
#include "gameplay_ability_system.h"

void GameplayAbilityTask::TickTask(float delta)
{
    ERR_FAIL_COND(owner == nullptr || owner->is_queued_for_deletion());
    if(has_method("_on_TickTask"))
    {
        call_deferred("_on_TickTask", delta);
    }
}

void GameplayAbilityTask::initialise(GameplayAbilitySystem* taskOwner)
{
    if(taskOwner != nullptr && !taskOwner->is_queued_for_deletion())
    {
        owner = taskOwner;
    }
}

void GameplayAbilityTask::task_completed()
{
    if(has_method("_on_task_completed"))
    {
        call_deferred("_on_task_completed");
    }

    emit_signal("task_completed", Ref<GameplayAbilityTask>(this));
}

void GameplayAbilityTask::_bind_methods()
{
    BIND_VMETHOD(MethodInfo("_on_TickTask",PropertyInfo(Variant::REAL, "delta")));
    BIND_VMETHOD(MethodInfo("_on_task_completed"));

    ClassDB::bind_method(D_METHOD("get_owner"), &GameplayAbilityTask::get_owner);
    ClassDB::bind_method(D_METHOD("task_completed"), &GameplayAbilityTask::task_completed);

    ADD_SIGNAL(MethodInfo("task_completed", PropertyInfo(Variant::OBJECT, "task")));
}