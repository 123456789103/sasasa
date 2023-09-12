#include "CONACT.h"







int main(){
	struct contact con;
	int input = 0;
	
	initcontact(&con);
	printf("please enter a num.");
   
	int n = 0;
	do {
		manu();
	 scanf_s("%d", &n);
		switch (n) {
		case ADD:
			add(&con);
			break;
		case DLE:
			break;
		case SEARCH:
			break;
		case SHOW:
			//show(&con);
			break;
		case MODIFY:
			break;
		case SORT:
			break;
		case EXIT:
			printf("exit program");
			break;
		default:
			printf("went wrong");
			break;
			
		}
    } while (n);





		return 0;
	}


