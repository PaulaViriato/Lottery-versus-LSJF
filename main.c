#include "lottery.c"
#include "lsjf.c"
#include "task.c"

int main (int argc, char *argv[]){
	printf("************** SIMULATION *************\n");
	printf("*-------------------------------------*\n");
	printf("* ALGO (1): LOTTERY                   *\n");
	printf("* ALGO (2): LSJF (LOTTERY AND SJF)    *\n");
	printf("* ALGO (3): LOTTERY VERSUS LSJF       *\n");
	printf("*-------------------------------------*\n");
	printf("* TYPE (1): STATIC TIME               *\n");
	printf("* TYPE (2): STATIC PRIORITY           *\n");
	printf("* TYPE (3): STATIC TIME AND PRIORITY  *\n");
	printf("* TYPE (4): ALL RANDOM                *\n");
	printf("* TYPE (5): ALL FOUR TESTS            *\n");
	printf("*-------------------------------------*\n");
	printf("* STEP: TIME PARTITION                *\n");
	printf("* PRIO: IMPORTANCE OF PRIORITY        *\n");
	printf("* PROC: NUMBER OF PROCESS             *\n");
	printf("* TIME: MAXIMUM PROCESS TIME          *\n");
	printf("*-------------------------------------*\n");
	printf("***************************************\n");

	int algo=0, type=0, step=0, prio, proc=0, time=0, i;

	while ((algo < 1)||(algo > 3)){
		printf("ALGO: ");
		scanf("%d", &algo);
	}

	while ((type < 1)||(type > 5)){
		printf("TYPE: ");
		scanf("%d", &type);
	}

	while (step <= 0){
		printf("STEP: ");
		scanf("%d", &step);
	}

	printf("PRIO: ");
	scanf("%d", &prio);

	while (proc <= 0){
		printf("PROC: ");
		scanf("%d", &proc);
	}

	while (time <= 0){
		printf("TIME: ");
		scanf("%d", &time);
	}

	if (type == 5){
		for (i=0; i < proc; i++){
			if ((algo == 1)||(algo == 3)){ lottery_insert (time, 1+rand()%5); }
			if ((algo == 2)||(algo == 3)){ lsjf_insert (time, 1+rand()%5); }
		}

		if ((algo == 1)||(algo == 3)){ __lottey ("test_lottery.txt", step); }
		if ((algo == 2)||(algo == 3)){ __lsjf ("test_lsjf.txt", prio, step); }

		for (i=0; i < proc; i++){
			if ((algo == 1)||(algo == 3)){ lottery_insert (1+rand()%time, 1); }
			if ((algo == 2)||(algo == 3)){ lsjf_insert (1+rand()%time, 1); }
		}

		if ((algo == 1)||(algo == 3)){ __lottey ("test_lottery.txt", step); }
		if ((algo == 2)||(algo == 3)){ __lsjf ("test_lsjf.txt", prio, step); }

		for (i=0; i < proc; i++){
			if ((algo == 1)||(algo == 3)){ lottery_insert (time, 1); }
			if ((algo == 2)||(algo == 3)){ lsjf_insert (time, 1); }
		}

		if ((algo == 1)||(algo == 3)){ __lottey ("test_lottery.txt", step); }
		if ((algo == 2)||(algo == 3)){ __lsjf ("test_lsjf.txt", prio, step); }

		for (i=0; i < proc; i++){
			if ((algo == 1)||(algo == 3)){ lottery_insert (1+rand()%time, 1+rand()%5); }
			if ((algo == 2)||(algo == 3)){ lsjf_insert (1+rand()%time, 1+rand()%5); }
		}

		if ((algo == 1)||(algo == 3)){ __lottey ("test_lottery.txt", step); }
		if ((algo == 2)||(algo == 3)){ __lsjf ("test_lsjf.txt", prio, step); }
	} else if (type == 1) {
		for (i=0; i < proc; i++){
			if ((algo == 1)||(algo == 3)){ lottery_insert (time, 1+rand()%5); }
			if ((algo == 2)||(algo == 3)){ lsjf_insert (time, 1+rand()%5); }
		}

		if ((algo == 1)||(algo == 3)){ __lottey ("test_lottery.txt", step); }
		if ((algo == 2)||(algo == 3)){ __lsjf ("test_lsjf.txt", prio, step); }
	} else if (type == 2){
		for (i=0; i < proc; i++){
			if ((algo == 1)||(algo == 3)){ lottery_insert (1+rand()%time, 1); }
			if ((algo == 2)||(algo == 3)){ lsjf_insert (1+rand()%time, 1); }
		}

		if ((algo == 1)||(algo == 3)){ __lottey ("test_lottery.txt", step); }
		if ((algo == 2)||(algo == 3)){ __lsjf ("test_lsjf.txt", prio, step); }
	} else if (type == 3){
		for (i=0; i < proc; i++){
			if ((algo == 1)||(algo == 3)){ lottery_insert (time, 1); }
			if ((algo == 2)||(algo == 3)){ lsjf_insert (time, 1); }
		}

		if ((algo == 1)||(algo == 3)){ __lottey ("test_lottery.txt", step); }
		if ((algo == 2)||(algo == 3)){ __lsjf ("test_lsjf.txt", prio, step); }
	} else if (type == 4){
		for (i=0; i < proc; i++){
			if ((algo == 1)||(algo == 3)){ lottery_insert (1+rand()%time, 1+rand()%5); }
			if ((algo == 2)||(algo == 3)){ lsjf_insert (1+rand()%time, 1+rand()%5); }
		}

		if ((algo == 1)||(algo == 3)){ __lottey ("test_lottery.txt", step); }
		if ((algo == 2)||(algo == 3)){ __lsjf ("test_lsjf.txt", prio, step); }
	}

return 0;
}
