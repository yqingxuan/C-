//дһ������������ n ����쳲�������Fibonacci�����еĵ� n �쳲��������еĶ������£�
//F(0) = 0, F(1) = 1
//F(N) = F(N - 1) + F(N - 2), ���� N > 1.
#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int Fib(int n){
	if (n <= 0){
		return 0;
	}
	if (1==n||2==n){
		return 1;
	}
	int cur1 = 1;
	int cur2= 1;
	int cur3 = 0;
	for (int i = 3; i <=n; i++){
		cur3 = cur1 + cur2;
		cur1 = cur2;
		cur2 = cur3;
		
	}
	return cur3;
}
int main(){
	int n = 0;
	printf("Please in put a num!\n");
	scanf("%d", &n);
	printf("%d\n", Fib(n));
	system("pause");
	return 0;
}