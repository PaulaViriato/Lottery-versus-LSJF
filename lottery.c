#include "lottery.h"

void __lottey       (char *archive, int st){
  lottery_archive = fopen (archive, "a");
	lottery_step = st;

	if (lottery_archive == NULL){
        printf("ERROR! Archive unavailable (WRITE)!\n");
		return;
	} else {
        int counter, winner, i=1;
       	struct task *current;
        srand(time(NULL));

        current = lottery_task;
        while (current){
            fprintf(lottery_archive, "TASK %d (%d)\t", i, current->prio);
            current = current->next; i++;
        }
        fprintf(lottery_archive, "\n");

        while (lottery_priorit_total > 0) {
            counter = 0;
            winner  = rand()%lottery_priorit_total;
            current = lottery_task;

           	while (current) {
           	    counter += current->prio;
           	    if (counter > winner){ break; }
           		current = current->next;
           	}

            lottery_update(current);
           	lottery_print();
        }
        fprintf(lottery_archive, "\n");
	}

	lottery_free();
}

void lottery_insert (int prevision, int priorit){
	struct task *lottery = malloc(sizeof(struct task));
	assert(lottery != NULL);

    lottery->current_time = 0;
    lottery->prev_time    = prevision;
    lottery->prio         = priorit;

    lottery->next = lottery_task;
    lottery_task  = lottery;
    lottery_priorit_total += priorit;
}

void lottery_print  (){
    struct task *curr = lottery_task;
    while (curr) {
        fprintf(lottery_archive, "%d\t", (curr->prev_time - curr->current_time));
    	curr = curr->next;
    }
    fprintf(lottery_archive, "\n");
}

void lottery_update (struct task *t){
    t->current_time += lottery_step;
    if (t->current_time >= t->prev_time){
        lottery_priorit_total -= t->prio;
        t->prio               = 0;
    }
}

void lottery_free   (){
	fclose(lottery_archive);
	free_task(lottery_task);
	lottery_task = NULL;
}
