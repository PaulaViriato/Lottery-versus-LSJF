#include "lsjf.h"

void __lsjf         (char *archive, int prio, int st){
	lsjf_archive = fopen (archive, "a");
	lsjf_step = st;
    imp_prio  = prio;

	if (lsjf_archive == NULL){
        printf("ERROR! Archive unavailable (WRITE)!\n");
		return;
	} else {
		int counter, winner, i=1;
       	struct task *current;
        srand(time(NULL));

        current = lsjf_task;
        while (current){
            fprintf(lsjf_archive, "TASK %d (%d)\t", i, current->prio);
            current = current->next; i++;
        }
        fprintf(lsjf_archive, "\n");

        while (lsjf_ticket_total > 0){
            counter = 0;
            winner  = rand()%lsjf_priorit_total;
            current = lsjf_task;

           	while (current) {
           	    counter += (current->prio*imp_prio)+current->ticket;
           	    if (counter > winner){ break; }
           		current = current->next;
           	}

            lsjf_update(current);
           	lsjf_print();
        }

        fprintf(lsjf_archive, "\n");
	}

    lsjf_free();
}

void lsjf_insert    (int prevision, int priorit){
    struct task *lsjf = malloc(sizeof(struct task));
    assert(lsjf != NULL);

    lsjf->current_time = 0;
    lsjf->prev_time    = prevision;
    lsjf->prio         = priorit;
    lsjf_setticket(lsjf);

    lsjf->next         = lsjf_task;
    lsjf_task          = lsjf;
    lsjf_ticket_total  += lsjf->ticket;
    lsjf_priorit_total += (priorit*imp_prio)+lsjf->ticket;
}

void lsjf_setticket (struct task *t){
    int check = 0;
    struct task *aux = lsjf_task;

    while (aux){
        if (t->prev_time <= aux->prev_time){
            check = 1;
            if (t->prev_time < aux->prev_time){
                t->ticket = aux->ticket +1;
            } else { t->ticket = aux->ticket; }
        }
        aux = aux->next;
    }

    if (check == 0){
        t->ticket = 1;
        if (lsjf_task != NULL){
            aux = lsjf_task;

            while (aux){
                aux->ticket ++;
                lsjf_ticket_total ++;
                lsjf_priorit_total ++;
                aux = aux->next;
            }
        }
    }
}

void lsjf_print     (){
    struct task *curr = lsjf_task;
    while (curr) {
        fprintf(lsjf_archive, "%d\t", (curr->prev_time - curr->current_time));
    	curr = curr->next;
    }
    fprintf(lsjf_archive, "\n");
}

void lsjf_update    (struct task *t){
    t->current_time += lsjf_step;

    if (t->current_time >= t->prev_time){
        lsjf_ticket_total  -= t->ticket;
        lsjf_priorit_total -= (t->prio*imp_prio)+t->ticket;
        t->ticket          = 0;
        t->prio            = 0;
    }
}

void lsjf_free      (){
	fclose(lsjf_archive);
	free_task(lsjf_task);
    lsjf_task = NULL;
}
