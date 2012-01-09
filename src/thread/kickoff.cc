#include "thread/kickoff.h"

void kickoff(Coroutine* object) {
    object->action();
}