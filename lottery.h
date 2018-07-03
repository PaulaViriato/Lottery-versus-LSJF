#ifndef LOTTERY_H
#define LOTTERY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include "task.h"

/* ------ VARIABLES ------ **
** ----------------------- */

struct  task *lottery_task = NULL;
FILE    *lottery_archive;
int     lottery_priorit_total = 0;
int     lottery_step = 1;

/* ------ FUNCTIONS ------ **
** ----------------------- */
void __lottey       (char *archive, int st);
void lottery_insert (int prevision, int priorit);
void lottery_print  ();
void lottery_update (struct task *t);
void lottery_free   ();

#endif