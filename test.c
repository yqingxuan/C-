//字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
char* ReverseLeftWords(char* s, int n){
	
	int len = strlen(s);
	int i = 0;
	char *start = &s[0];
	char *end = &s[len - 1];
	while (start<end){        //字符串逆置
		char temp = *start;
		*start = *end;
		*end = temp;
		start++; end--;
	}
	for (i = 0; i < (len - n)/2; i++){     //len-n前字符的逆置
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