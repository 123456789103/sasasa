#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<assert.h>
#define MAX 100
#define MAXNAME 40
#define MAXAGE  3
#define MAXTELE 18
#define MAXPOS  30
#define MAXSEX  10


void manu();

enum aa {
	EXIT,
	ADD,
	DLE,
	SEARCH,
	SHOW,
	MODIFY,
	SORT,
	




};

typedef struct peoinfo {
	char name[MAXNAME];
	int  age[MAXAGE];
	char sex[MAXSEX];
	char  tele[MAXTELE];
	char pos[MAXPOS];


}peoinfo;

typedef struct contact {

	peoinfo date[100];
	int count;


};



void initcontact(struct contact *cp);

void show(struct contact* pc);



void add(struct contact* cp);




#pragma once
