#include "CONACT.h"




void manu() {
	printf("******************************\n");
	printf("******************************\n");
	printf("******1 add     2 del   ******\n");
	printf("******3 search  4 show  ******\n");
	printf("******5 modify  6 sort  ******\n");
	printf("******0 exit            ******\n");
	printf("******************************\n");
}	

//void initcontact(struct contact* pc) {
//	assert(pc);
//	pc->count = 0;
//	memset(pc->date, 0, sizeof(pc->date));
//
//}
//动态

void loadcontact(struct contact* cp) {
	
	FILE* pread = fopen("CONTACT.txt", "rb");
	if (pread == NULL) {
		perror(loadcontact);
		return;
	}
	
	peoinfo tam = { 0 };
	while (fread(&tam, sizeof(peoinfo), 1, pread) == 1) {
		checkcontact(cp);
		cp->date[cp->count] = tam;
		cp->count++;
	}
	
	
	//关闭文件
	fclose(pread);
	pread = NULL;
}



void initcontact(struct contact* pc) {
	assert(pc);
	
	pc->count = 0;
	pc->date = (peoinfo*)malloc(sizeof(peoinfo)*3);
	if (pc->date == NULL) {
		printf("%s", strerror(errno));
		return;
	}
	loadcontact(pc);
	pc->capacity = DEFAUSIZE;

}
void destory(struct contact* cp) {

	assert(cp);
	free(cp->date);
	cp->date = NULL;


}
void save(const struct contact* cp) {
	assert(cp);
	FILE* pwrite = fopen("CONTACT.txt", "wb");
	if (pwrite == NULL) {
		perror(save);
		return;
	}
	
	int i = 0;
	for (i; i < cp->count; i++) {
		fwrite(cp->date + i, sizeof(peoinfo), 1, pwrite);
	}
	fclose(pwrite);
	pwrite = NULL;
	}
void checkcontact(struct contact* cp) {
	if (cp->count == cp->capacity) {
		peoinfo* ptr = (peoinfo*)realloc(cp->date, (cp->capacity + INC_ZE) * sizeof(peoinfo));
		if (ptr == NULL) {
			printf("add::%s", strerror(errno));
			return;
		}
		else {
			cp->date = ptr;
			cp->capacity += INC_ZE;
			printf("增容成功\n");
		}

	}






//void add(struct contact* cp) {
//	
//	assert(cp);
//	if (cp ->count == MAX){
//
//		printf("程序已满\n");
//		return;
//	}
//
//
//
//	
//	
//	printf("please enter a name\n");
//	scanf("%s",cp->date[cp->count].name);
//	printf("please enter a age \n");
//	scanf("%d", &(cp->date[cp->count].age));
//	printf("please enter a sex\n");
//	scanf("%s",cp->date[cp->count].sex);
//	printf("please enter a telephone number\n");
//	scanf("%s", cp->date[cp->count].tele);
//	printf("please enter a position\n");
//	scanf("%s", cp->date[cp->count].pos);
//
//
//	cp->count += 1;
//
//	printf("\n");
//	printf("增加成功\n");
//}


}
void add(struct contact* cp) {
	assert(cp);
	
	checkcontact(cp);

	printf("please enter a name\n");
	scanf("%s", cp->date[cp->count].name);
	printf("please enter a age \n");
	scanf("%d", &(cp->date[cp->count].age));
	printf("please enter a sex\n");
	scanf("%s", cp->date[cp->count].sex);
	printf("please enter a telephone number\n");
	scanf("%s", cp->date[cp->count].tele);
	printf("please enter a position\n");
	scanf("%s", cp->date[cp->count].pos);


	cp->count += 1;

	printf("\n");
	printf("增加成功\n");
}




void show(const struct contact* cp) {

	assert(cp);
	int i;


	printf("%-20s %-5s %-5s %-20s %-30s","NAME","AGE","SEX","NUMBER","ADRESS");
	printf("\n");
	for (i = 0; i < cp->count; i++) {

		printf("%-20s %-5d %-5s %-20s %-30s", cp->date[i].name, 
			                                  cp->date[i].age,
		                                   	  cp->date[i].sex, 
			                                  cp->date[i].tele,
		                                	  cp->date[i].pos);
		printf("\n");
	}
	
	
}

void del(struct contact* cp) {
	assert(cp);
	char name[MAXNAME];
	scanf("%s", name);
	int pos = FIND_BY_NAME(cp, name);
	if (pos == -1) {
		printf("the man you want to del is not exist\n");
		return;
	}
		
	int i;
	for (i = pos; i < cp->count - 1; i++)
		cp->date[i] = cp->date[i + 1];
	cp->count--;
	printf("删除成功\n");
}



static FIND_BY_NAME(struct contact* cp, char name[]) {
	assert(cp);
	int i = 0;
	for (i = 0; i < cp->count;i++){
		if (0 == strcmp(cp->date[i].name, name))
		{
			return i;
		}
	}
		return -1;
	}
void search(struct contact* cp) {
	assert(cp);
	char name[MAXNAME];
	printf("please enter a name\n");
	scanf("%s", name);
	int pos = FIND_BY_NAME(cp, name);
	if (pos == -1) {
		printf("the man you want to del is not exist\n");
		return;
	}
	printf("%-20s %-5d %-5s %-20s %-30s", cp->date[pos].name,
		cp->date[pos].age,
		cp->date[pos].sex,
		cp->date[pos].tele,
		cp->date[pos].pos);
	printf("\n");


}
void modify(struct contact* cp) {
	assert(cp);
	char name[MAXNAME];
	printf("please enter the name you want to modify\n");
	scanf("%s", name);
	int pos = FIND_BY_NAME(cp, name);
	if (pos == -1) {
		printf("the man you want to del is not exist\n");
		return;
	}
	printf("pelase enter modified information\n");
	printf("please enter a name\n");
	scanf("%s", cp->date[pos].name);
	printf("please enter a age \n");
	scanf("%d", &(cp->date[pos].age));
	printf("please enter a sex\n");
	scanf("%s", cp->date[pos].sex);
	printf("please enter a telephone number\n");
	scanf("%s", cp->date[pos].tele);
	printf("please enter a position\n");
	scanf("%s", cp->date[pos].pos);


	printf("修改成功\n");



}
int com_by_name(const void *e1,const void *e2){
	return strcmp(((peoinfo*)e1)->name, ((peoinfo*)e2)->name);
}

//int com_by_age(const void* e1, const void* e2) {
//	return ()
//}


void sort(struct contact* cp) {

	qsort(cp->date,cp->count,sizeof(peoinfo),com_by_name);
	printf("排序成功\n");
}