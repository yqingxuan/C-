//�ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β�����붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ����磬�����ַ���"abcdefg"������2���ú�������������ת��λ�õ��Ľ��"cdefgab"��
#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
char* ReverseLeftWords(char* s, int n){
	
	int len = strlen(s);
	int i = 0;
	char *start = &s[0];
	char *end = &s[len - 1];
	while (start<end){        //�ַ�������
		char temp = *start;
		*start = *end;
		*end = temp;
		start++; end--;
	}
	for (i = 0; i < (len - n)/2; i++){     //len-nǰ�ַ�������
		char temp = *(s + i);
		*(s + i) = *(s + len - i - 1-n);
		*(s + len - i - 1-n) = temp;
	}
	for (i = 0; i < (n/2); i++){
		char temp = *(s + len - n +i);
		*(s + len - n +i) = *(s +len-i-1);
		*(s + len - i - 1) = temp;
	}
	return s;
	}
int main(){
	char str[20] = { '\0' };
	int n = 0;
	printf("please input a character string  and input  a  number!");
	scanf("%s %d", &str, &n);
	printf("Before:%s",str );
	ReverseLeftWords(str, n);
	printf("After:%s", str);
	system("pause");
	return 0;
}