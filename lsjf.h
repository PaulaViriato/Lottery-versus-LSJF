#ifndef LSJF_H
#define LSJF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include "task.h"

/* ------ VARIABLES ------ **
** ----------------------- */

struct  task *lsjf_task = NULL;
FILE    *lsjf_archive;
int     lsjf_ticket_total = 0;
int     lsjf_priorit_total = 0;
int     imp_prio = 1;
int     lsjf_step = 1;

/* ------ FUNCTIONS ------ **
** ----------------------- */
void __lsjf         (char *archive, int prio, int st);
void lsjf_insert    (int prevision, int priorit);
void lsjf_setticket (struct task *t);
void lsjf_print     ();
void lsjf_update    (struct task *t);
void lsjf_free      ();

#endif