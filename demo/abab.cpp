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
}SqList; //����˳�������
Status InitList_Sq(SqList &L) //��ʼ��˳���
{
L.elem=(Elemtype *)malloc(LIST_INIT_SIZE* sizeof(Elemtype));
L.length=0;
L.listsize=LIST_INIT_SIZE;
return 1;
}
void main() //����˳���
{
int i,elem[5],length;
printf("��������Ҫ������˳���Ԫ�ظ��� ");
scanf("%d",&length);
printf("��������Ҫ������˳���:\n");
for(i=0;i<length;i++){
scanf("%d",&elem[i]);
}

	int t;
	for(t=0;t<length;t++){
		printf("%3d",elem[t]);
	}
}*/
