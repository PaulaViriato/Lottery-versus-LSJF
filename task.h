#ifndef TASK_H
#define TASK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

/* ------- STRUCT -------- **
** ----------------------- */

struct task {
    int current_time;
    int prev_time;
    int ticket;
    int prio;
    struct task *next;
};

/* ------ FUNCTIONS ------ **
** ----------------------- */
void free_task (struct task *t);

#endif