#include "task.h"

void free_task (struct task *t){
    if (t->next == NULL){ return; }
    else {
        free_task(t->next);
        return;
    }
}
