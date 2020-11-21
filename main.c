#include"game.h"
int main(){
	int quit = 0;
	while (!quit){
		Menu();
		int select = 0;
		scanf("%d", &select);
		switch (select){
		case 1:
			Game();
			break;
		case 2:

			break;
		default:
			printf("Enter Error! Please Try Again!");
			break;
		}
	}
	system("pause");
	return 0;
}