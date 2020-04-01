#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE *f_file, *f_pic, *f_finish;
	char ch, pic_name[20], file_name[20], finish_name[20];

	printf("请输入要合成的图片、文件名称: \n");
	printf("图片: ");
	scanf("%s", pic_name);
	printf("文件: ");
	scanf("%s", file_name);
	printf("结果: ");
	scanf("%s", finish_name);

	if( !(f_pic = fopen(pic_name, "rb")))
	{
		printf("Cannot open the ficture %s!\n", pic_name);
		exit(0);   // 终止程序
	}
	if( !(f_file = fopen(file_name, "rb")))
	{
		printf("Cannot open the file %s!\n", file_name);
		exit(0);   // 终止程序
	}
	if( !(f_finish = fopen(finish_name, "wb")))
	{
		printf("Cannot open the file %s!\n", finish_name);
		exit(0);    // 终止程序
	}

	while( !feof(f_pic) )
	{
		ch = fgetc(f_pic);
		fputc(ch, f_finish);
	}
	fclose(f_pic);

	while( !feof(f_file) )
	{
		ch = fgetc(f_file);
		fputc(ch, f_finish);
	}
	fclose(f_file);
	fclose(f_finish);
	system("pause");
}