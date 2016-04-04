#include <stdio.h>
#include <malloc.h>
#include "DataStru.h"

//------ 线性表的顺序存储结构 --------
#define LIST_INIT_SIZE	100	//初始化大小
#define LISTINCREMENT	10	//分配增量

typedef int ElemType;

typedef struct{
	ElemType *elem;	//基址
	int length;		//当前长度
	int listsize;	//分配的容量（以sizeof(ElemType)为单位）
}SqList;	//定义顺序表类型

Status InitSqList(SqList &L){
	//创建空的表l
	L.elem = (ElemType *)malloc (LIST_INIT_SIZE * sizeof(ElemType));
	if(!L.elem)
		return OVERFLOW;
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

//创建顺序表
void CreateList(SqList &L){
	int i;
	printf("请输入你要创建的元素个数：");
	scanf("%d",&L.length);
	for(i=0;i<L.length;i++){
		printf("请输入第%d个数：\n",i+1);
		scanf("%d",&L.elem[i]);
	}
}

//输出顺序表
void InputList(SqList &L){
	int i;
	printf("表中有如下元素：\n");
	for(i=0;i<L.length;i++){
		printf("%3d",L.elem[i]);		
	}
	printf("\n");
}

