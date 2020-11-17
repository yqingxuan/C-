#include<stdio.h>
#include<windows.h>
void  Star(int x , int y){
	int i = 0;
	int n = 0;
	for (x = 1; x < 8; x++){
		for (y = 1; y < 8 - x; y++){
			printf(" ");
		}

		for (i = 0; i < (2 * x-1); i++){

			printf("%c", 42);
		}
		printf("\n");
	}
	for (x = 8; x <14; x++){
		for (y = 1; y < x-6; y++){
			printf(" ");
		}

		for (i = 0; i < -2 * x+27; i++){

			printf("%c", 42);
		}
		printf("\n");
	}

}
int main(){
	int x = 1;
	int y = 1;


	Star(x, y);
	

	system("pause");
	return 0;

}