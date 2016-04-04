/*
#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef int Elemtype;
typedef int Status;
typedef struct
{
Elemtype *elem;
int length;
int listsize;
}SqList; //定义顺序表类型
Status InitList_Sq(SqList &L) //初始化顺序表
{
L.elem=(Elemtype *)malloc(LIST_INIT_SIZE* sizeof(Elemtype));
L.length=0;
L.listsize=LIST_INIT_SIZE;
return 1;
}
void main() //创建顺序表
{
int i,elem[5],length;
printf("请输入你要创建的顺序表元素个数 ");
scanf("%d",&length);
printf("请输入你要创建的顺序表:\n");
for(i=0;i<length;i++){
scanf("%d",&elem[i]);
}

	int t;
	for(t=0;t<length;t++){
		printf("%3d",elem[t]);
	}
}*/
