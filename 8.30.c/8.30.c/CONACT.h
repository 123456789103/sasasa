#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
#define MAXNAME 40
#define MAXAGE  
#define MAXTELE 18
#define MAXPOS  30
#define MAXSEX  10
#define DEFAUSIZE 3
#define INC_ZE  2
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
	int  age;
	char sex[MAXSEX];
	char tele[MAXTELE];
	char pos[MAXPOS];


}peoinfo;
 //¾²Ì¬
//typedef struct contact {
//
//	peoinfo date[MAX];
//	int count;
//
//
//};
 //¶¯Ì¬
typedef struct contact {

	peoinfo* date;
	int count;
	int capacity;	

};



void initcontact(struct contact *cp);

void show(struct contact* pc);



void add(struct contact* cp);//Ìí¼Ó

void show(const struct contact* cp);//Õ¹Ê¾

void del(struct contact* cp);//É¾³ý


void search(struct contact* cp);//²éÕÒ


void modify(struct contact* cp);//ÐÞ¸Ä

void sort(struct contact* cp);//ÅÅÐò

void destory(struct contact* cp);

void save(const struct contact* cp);

void loadcontact(struct contact* cp);
void checkcontact(struct contact* cp);