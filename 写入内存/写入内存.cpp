#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
int main()
{
	//�򿪴����ļ�
	FILE* fp;
	if ((fp = fopen("C://Users/DELL/Desktop/�������.txt", "w+")) == NULL) {
		printf("The file is not open\n ");
		system("pause");
	}
	else {
		printf("The file is open\n ");
		system("pause");
	}

	//д���ļ�
	char str[] = "hello file word";
	if (fwrite(str, sizeof(char), sizeof(str), fp) > 0) {
		fclose(fp);
	}
	else {
		printf("The file is not write");
		fclose(fp);
	}
	//��ȡ�ļ�
		//��ȡ�ļ���С
	FILE* fp2;
	fp2 = fopen("D:Test.txt", "r+");

	int length;
	//ָ��ָ���ļ�β
	if (fseek(fp2, 0L, SEEK_END) == 0) {
		//��ȡͷβָ��Ĵ�С���=�ļ���С
		length = ftell(fp2);
		printf("%i", length);	//�����С
		system("pause");
		//�ر��ļ�
		fclose(fp2);
	}
	else {
		exit(0);
		//�ر��ļ�
		fclose(fp2);
	}
	//��һ�����ļ�
	FILE* fp3;
	fp3 = fopen("D:Test.txt", "r+");
	//��ȡ�ļ���������
	char read[16];				//�ݶ�ֵ16
	if (fread(read, sizeof(char), sizeof(read), fp3) != NULL) {
		for (int i = 0; i < sizeof(read); i++) {
			printf("%c", read[i]);			//����ļ�����
		}
	}
	else {
		printf("The file is not read");
	}
	//�����ڴ�ռ�
	char* path;
	if ((path = (char*)malloc(length)) == NULL) {
		exit(0);
		fclose(fp3);
	}
	else {
		//��ȡ�ڴ�7	
		printf("");
		system("pause");
		fclose(fp3);
	};
	//д���ڴ�
	char* content = read;
	if (memcpy(content, path, length) != NULL)
	{
		printf("Malloc OK");
		system("pause");
	}
	else {
		printf("Malloc falseK");
		system("pause");
	}
	//��ȡ�ڴ�
	//����
	char storebox[160] = { 0 };
	char* store = (char*)0x00400B48;

	//�����ȡ���ڴ渴�Ƶ�ָ���ĵ�ַ     void *memcpy( void *dest, const void *src, size_t count );
	//�����ָ����ʵ��������һ����
	if (memcpy(storebox, store, 160) != NULL)
	{
		for (int z = 0; z < 160; z++)
		{
			printf("%c", storebox[z]);
		}
		system("pause");
	}


	return 0;
}