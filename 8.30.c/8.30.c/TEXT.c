#include "CONACT.h"







int main(){
	struct contact con;
	int input = 0;
	
	initcontact(&con);
	
   
	int n = 0;
	do {
		printf("please enter a num.\n\n");
		manu();
	 scanf_s("%d", &n);
		switch (n) {
		case ADD:
			add(&con);
			break;
		case DLE:
			del(&con);
			break;
		case SEARCH:
			search(&con);
			break;
		case SHOW:
			show(&con);
			break;
		case MODIFY:
			modify(&con);
			break;
		case SORT:
			sort(&con);
			break;
		case EXIT:
			save(&con);
			destory(&con);
			printf("exit program");
			break;
		default:
			printf("went wrong");
			break;
			
		}
    } while (n);





		return 0;
	}


