#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<cstdio> 
using namespace std;
int Countcharacters(char File[]) { //�ַ������� 
	int characters = 0;
	FILE* file_Read = fopen(File, "rt");
	char chr = ' ';
	if (file_Read == NULL) {
		cout << "�ļ���ַ������ر�����" << endl;
		return 0;
	}
	while ((chr = fgetc(file_Read)) != EOF) {
		if (isspace(chr) == NULL)characters++;
	}
	fclose(file_Read);
	cout << "�ַ������ǣ�"<< characters << endl;
	return 1;
}

int Countwords(char File[]) {//����������
	int words = 0;
	FILE* file_Read = fopen(File, "rt");
	char chr = ' ';
	if (file_Read == NULL) {
		cout << "�ļ���ַ������ر�����" << endl;
		return 0;
	}
	while ((chr = fgetc(file_Read)) != EOF) {
		while ((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z') || chr == '-')
			chr = fgetc(file_Read);
		words++;
	}
	fclose(file_Read);
	cout << "���ʸ����ǣ�" << words << endl;
	return 1;
}


int main() {
	int  tag;
	char control;
	char File[100];
	int  number = 1;
	printf("\nָ���\nc ͳ���ַ�����w ͳ�Ƶ�����\n");
	cout << "�������û�����:" << endl;
	cin >> control;
	cout << "�������ļ���ַ:" << endl;
	cin >> File;
	while (number!=0) {
		switch (control) {
		case 'c':tag = Countcharacters(File);
			if (tag == 0)number = 0;
			break;
		case 'w':tag = Countwords(File);
			if (tag == 0)number = 0;
			break;
		default:cout << "�����������û�����:" << endl;
		}
		cin >> control;
	}
}