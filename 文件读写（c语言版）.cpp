// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[])
{
	FILE *in,*out;
	int ch=0;
	if (argc != 3) {
		fprintf(stderr, "输入形式错误\n");
		exit(EXIT_FAILURE);
	}
	if ((in = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "打不开文件:%s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((out = fopen(argv[2], "wb")) == NULL) {
		fprintf(stderr, "无法写入:%s\n", argv[2]);
		fclose(in);
		exit(EXIT_FAILURE);
	}
	while ((ch==getc(in))!=EOF) {
		if (putc(ch, out) == EOF)
			break;
	}
	if (ferror(in)) {
		printf("读取文件%s失败", argv[1]);
	}
	if (ferror(out)) {
		printf("写入文件%s失败", argv[2]);
	}
	printf("成功");
	fclose(in);
	fclose(out);
	return 0;
}