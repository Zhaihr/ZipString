#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 1024
typedef struct DateString {
	int count;
	char ch;
}DateStr;

void openFile(char *string) {
	FILE* fp;
	char ch;
	int i = 0;
	fp = fopen("in.txt", "r");  //默认路径与Debug在同一文件夹下
	if (fp == NULL) {
		puts("打开文件错误！");
		exit(0);
	}
	while ((ch = fgetc(fp)) != EOF) {  //一个一个字符的读取直至文件结尾
		string[i] = ch;
		i++;
	}
	string[i + 1] = '\0';  //文件末尾手动加入\0
	fclose(fp);
}
void writeFile(DateStr string[],int len) {
	FILE* fp;
	fp = fopen("out.txt", "w");
	if (fp == NULL) {
		puts("打开文件错误！");
		exit(0);
	}
	for (int i = 0; i < len; i++) {
		if (string[i].count > 1) {
			fprintf(fp,"%d",string[i].count);
			fputc(string[i].ch, fp);
		}
		else
			fputc(string[i].ch,fp);
	}
	fclose(fp);
}
int ZipString(char str[], DateStr string[],int len) {
	int j,k = 0;
	bool found = false;
	for (int i = 0; i < len - 1; i++) {
		j = i + 1;
		while (str[i] == str[j]) {
			found = true;
			string[k].count++;
			j++;
		}
		if (found == true) {
			string[k].ch = str[i];
			i = j - 1;
			found = false;
		}else
			string[k].ch = str[i];
		k++;	
	}
	return k;
}

int main() {
	char string[MAX_SIZE];
	int len;
	int ziplen;
	DateStr zipstring[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE - 1; i++) {
		zipstring[i].count = 1;
	}
	openFile(string);
	len = strlen(string);
	ziplen = ZipString(string, zipstring,len);
	for (int i = 0; i < ziplen; i++) {
		if (zipstring[i].count > 1)
			printf("%d%c", zipstring[i].count, zipstring[i].ch);
		else
			printf("%c", zipstring[i].ch);
	}
	writeFile(zipstring, ziplen);
	return 0;
}