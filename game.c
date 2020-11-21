#include "game.h"
void Menu(){
	printf("###########################\n");
	printf("###### 1. Play  2. Exit ###\n");
	printf("###########################\n");
	printf("##Please Enter##\n");
}
void DrawBoard(char board[][COL], int row, int col){
	printf("   1 | 2 | 3 |\n");
	printf("--------------\n");
	for (int i = 0; i < row; i++){
		printf("%d|",i+1);
		for (int j = 0; j < col; j++){
			printf(" %c |", board[i][j]);
		}
		printf("\n--------------\n");	
	}
}
void Playmove(char board[][COL], int row, int col) {
	int x = 0;
	int y = 0;
	while (1){
		printf("Please Enter your pos!");
		scanf("%d %d", &x, &y);
		if (x<1 || x>3 || y<1 || y>3){
			printf("Pos Error!!\n");
			continue;
		}
		if (board[x - 1][y - 1] != ' '){
			printf("chess exist!\n");
			continue;
		}
		board[x - 1][y - 1] = P_PRESS;
		return;
	}
}
char Judge(char board[][COL], int row, int col){
	for (int i = 0; i < row; i++){
		if (board[i][0] == board[i][1] && \
			board[i][1] == board[i][2] && \
			board[i][0] != ' '){
			return board[i][0];
		}
	}
	for (int i = 0; i < col; i++){
		if (board[0][i] == board[1][i] && \
			board[1][i] == board[2][i] && \
			board[0][i] != ' '){
			return board[0][i];
		}
	}
	if (board[0][0] == board[1][1] && \
		board[1][1] == board[2][2] && \
		board[0][0] != ' '){
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && \
		board[1][1] == board[2][0] && \
		board[0][2] != ' '){
		return board[1][1];
	}
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			if (board[i][j] == ' '){
				return 'N';
			}
		}
	}
	return 'P';
}
void Computermove(char board[][COL], int row, int col){
	while (1){
		int x = rand() % row;//形成随机数
		int y = rand() % col;
		if (board[x][y] == ' '){
			board[x][y] = C_PRESS;
			break;
		}
	}
}
void Game(){
	srand((unsigned long)time(NULL));//种随机数种子
	char board[ROW][COL];
	memset(board, ' ', sizeof(board));
	char win = '\0';
	do{
		DrawBoard(board,ROW,COL);
		Playmove(board, ROW, COL);
		win = Judge(board, ROW, COL);
		if (win != 'N'){
			break;
		}
		Computermove(board, ROW, COL);
		win = Judge(board, ROW, COL);
		if (win != 'N'){
			break;
		}
	} while (1);
	switch (win){
	case P_PRESS:
		printf("you win~\n");
		break;
	case C_PRESS:
		printf("you lose!");
		break;
	case 'P':
		printf("平局\n");
		break;
	default:
		break;	
	}
	DrawBoard(board, ROW, COL);
}