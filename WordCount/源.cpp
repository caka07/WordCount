#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<cstdio> 
using namespace std;
int Countcharacters(char File[]) { //字符数计算 
	int characters = 0;
	FILE* file_Read = fopen(File, "rt");
	char chr = ' ';
	if (file_Read == NULL) {
		cout << "文件地址错误，请关闭重试" << endl;
		return 0;
	}
	while ((chr = fgetc(file_Read)) != EOF) {
		if (isspace(chr) == NULL)characters++;
	}
	fclose(file_Read);
	cout << "字符个数是："<< characters << endl;
	return 1;
}

int Countwords(char File[]) {//单词数计算
	int words = 0;
	FILE* file_Read = fopen(File, "rt");
	char chr = ' ';
	if (file_Read == NULL) {
		cout << "文件地址错误，请关闭重试" << endl;
		return 0;
	}
	while ((chr = fgetc(file_Read)) != EOF) {
		while ((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z') || chr == '-')
			chr = fgetc(file_Read);
		words++;
	}
	fclose(file_Read);
	cout << "单词个数是：" << words << endl;
	return 1;
}


int main() {
	int  tag;
	char control;
	char File[100];
	int  number = 1;
	printf("\n指令表：\nc 统计字符数，w 统计单词数\n");
	cout << "请输入用户命令:" << endl;
	cin >> control;
	cout << "请输入文件地址:" << endl;
	cin >> File;
	while (number!=0) {
		switch (control) {
		case 'c':tag = Countcharacters(File);
			if (tag == 0)number = 0;
			break;
		case 'w':tag = Countwords(File);
			if (tag == 0)number = 0;
			break;
		default:cout << "请重新输入用户命令:" << endl;
		}
		cin >> control;
	}
}