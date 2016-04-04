#include <stdio.h>
#include <malloc.h>
#include "DataStru.h"

//------ ���Ա��˳��洢�ṹ --------
#define LIST_INIT_SIZE	100	//��ʼ����С
#define LISTINCREMENT	10	//��������

typedef int ElemType;

typedef struct{
	ElemType *elem;	//��ַ
	int length;		//��ǰ����
	int listsize;	//�������������sizeof(ElemType)Ϊ��λ��
}SqList;	//����˳�������

Status InitSqList(SqList &L){
	//�����յı�l
	L.elem = (ElemType *)malloc (LIST_INIT_SIZE * sizeof(ElemType));
	if(!L.elem)
		return OVERFLOW;
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

//����˳���
void CreateList(SqList &L){
	int i;
	printf("��������Ҫ������Ԫ�ظ�����");
	scanf("%d",&L.length);
	for(i=0;i<L.length;i++){
		printf("�������%d������\n",i+1);
		scanf("%d",&L.elem[i]);
	}
}

//���˳���
void InputList(SqList &L){
	int i;
	printf("����������Ԫ�أ�\n");
	for(i=0;i<L.length;i++){
		printf("%3d",L.elem[i]);		
	}
	printf("\n");
}

