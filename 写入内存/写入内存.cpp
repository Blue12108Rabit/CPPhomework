#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
int main()
{
	//打开创建文件
	FILE* fp;
	if ((fp = fopen("C://Users/DELL/Desktop/地理编码.txt", "w+")) == NULL) {
		printf("The file is not open\n ");
		system("pause");
	}
	else {
		printf("The file is open\n ");
		system("pause");
	}

	//写入文件
	char str[] = "hello file word";
	if (fwrite(str, sizeof(char), sizeof(str), fp) > 0) {
		fclose(fp);
	}
	else {
		printf("The file is not write");
		fclose(fp);
	}
	//读取文件
		//获取文件大小
	FILE* fp2;
	fp2 = fopen("D:Test.txt", "r+");

	int length;
	//指针指到文件尾
	if (fseek(fp2, 0L, SEEK_END) == 0) {
		//获取头尾指针的大小间距=文件大小
		length = ftell(fp2);
		printf("%i", length);	//输出大小
		system("pause");
		//关闭文件
		fclose(fp2);
	}
	else {
		exit(0);
		//关闭文件
		fclose(fp2);
	}
	//打开一个新文件
	FILE* fp3;
	fp3 = fopen("D:Test.txt", "r+");
	//读取文件具体内容
	char read[16];				//暂定值16
	if (fread(read, sizeof(char), sizeof(read), fp3) != NULL) {
		for (int i = 0; i < sizeof(read); i++) {
			printf("%c", read[i]);			//输出文件内容
		}
	}
	else {
		printf("The file is not read");
	}
	//分配内存空间
	char* path;
	if ((path = (char*)malloc(length)) == NULL) {
		exit(0);
		fclose(fp3);
	}
	else {
		//读取内存7	
		printf("");
		system("pause");
		fclose(fp3);
	};
	//写入内存
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
	//读取内存
	//容器
	char storebox[160] = { 0 };
	char* store = (char*)0x00400B48;

	//把想读取的内存复制到指定的地址     void *memcpy( void *dest, const void *src, size_t count );
	//数组和指针其实运算上是一样的
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