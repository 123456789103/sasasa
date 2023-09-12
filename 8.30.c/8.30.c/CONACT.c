#include "CONACT.h"




void manu() {
	printf("******************************\n");
	printf("******************************\n");
	printf("******1 add     2 del   ******\n");
	printf("******3 search  4 modify******\n");
	printf("******5 show    6 sort  ******\n");
	printf("******0 exit            ******\n");
	printf("******************************\n");
}	

void initcontact(struct contact* pc) {
	assert(pc);
	pc->count = 0;
	memset(pc->date, 0, sizeof(pc->date));

}


void add(struct contact* cp) {
	
	assert(cp);
	if (cp ->count = MAX); {

		printf("程序已满");
		return;
	}



	
	
	printf("please enter a name\n");
	scanf("%s",cp->date[cp->count].name);
	printf("please enter a age \n");
	scanf("%d", &(cp->date[cp->count].age));
	printf("please enter a sex\n");
	scanf("%s",cp->date[cp->count].sex);
	printf("please enter a telephone number\n");
	scanf("%s", cp->date[cp->count].tele);
	printf("please enter a position\n");
	scanf("%s", cp->date[cp->count].pos);


	cp->count += 1;


	printf("增加成功");
}
/*
void show(struct contact* cp) {
	printf("s", cp -> date.name);







}
*/




