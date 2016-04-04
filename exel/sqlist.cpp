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
void CreateList(SqList &L) //����˳���
{
int i;
printf("��������Ҫ������˳���Ԫ�ظ��� ");
scanf("%d",&L.length);
printf("��������Ҫ������˳���:\n");
for(i=0;i<L.length;i++)
scanf("%d",&L.elem[i]);

}
void print( SqList &L)//���˳���
{
	int i;
for(i=0;i<L.length;i++)
printf("%3d",L.elem[i]);

}
Status  location( SqList L,Elemtype e)//����Ԫ�ص�λ��
{
	int i=0;
	
	while(L.elem[i]!=e && i<L.length)
		i++;
	if(i>L.length)
		return -1;
	else
		return i+1;//��Ϊc�����Ǵ��±�0��ʼ�ĵ�i=0ʱʵ������˳���ĵ�i+1��Ԫ��


}

Status ListInsert_Sq(SqList &L,int i,Elemtype e)//��˳���ĵ�i��λ�ò���ֵΪe��Ԫ��
{
Elemtype *newbase,*q,*p;
	if(i<1||i>L.length+1)
		return 0;
	if(L.length>=L.listsize)
	{
		newbase=(Elemtype *)realloc(L.elem,(L.listsize+LISTINCREMENT)* sizeof(Elemtype));
		L.elem=newbase;
		L.listsize+=LISTINCREMENT;
	}
	q=&(L.elem[i-1]);
	for(p=&(L.elem[L.length-1]);p>=q;--p)
		*(p+1)=*p;
	*q=e;
	++L.length;
	return 1;

}
Status  ListDelect_Sq(SqList &L,int i,Elemtype e)//��˳���ĵ�i��λ��ɾ��ֵΪe��Ԫ�ز�����e��ֵ
{
Elemtype *q,*p;

	if(i<1||(i>L.length))
		return 0;
p=&(L.elem[i-1]);
e=*p;
q=L.elem+L.length-1;
for(++p;p<=q;++p)
*(p-1)=*p;
--L.length;
return 1;


}
void Combine(SqList La,SqList Lb,SqList &Lc)//�������ǵݼ���˳���ϲ���һ��˳����ϲ���Ԫ��Ҳ��ֵ�ǵݼ�����
{
  Elemtype *pa_last,*pb_last,*pa,*pb,*pc;
  pa=La.elem;
 pb=Lb.elem;
  Lc.listsize=Lc.length=La.length+Lb.length;
  pc= Lc.elem=(Elemtype *)malloc(Lc.listsize* sizeof(Elemtype));
  pa_last=La.elem+La.length-1;
pb_last=Lb.elem+Lb.length-1;
while(pa<=pa_last && pb<=pb_last)
{
	if(*pa<= *pb)
		*pc++=*pa++;
	else
		*pc++=*pb++;
}
while(pa<=pa_last)
*pc++=*pa++;
while(pb<=pb_last)
*pc++=*pb++;



}


void main()

{
SqList la,lb,lc,ld;
int i,j;
Elemtype e;
 InitList_Sq(la);
CreateList(la);
print(la);
printf("������Ҫ���ҵ�Ԫ��:\n");
scanf("%d",&e);
j=location(la,e);
printf("��Ԫ�ص�λ��Ϊ%d\n",j);

printf("������Ҫ�����λ�ú�Ԫ��:\n");
scanf("%d%d",&i,&e);

ListInsert_Sq(la,i,e);
printf("���������˳���:\n");
print(la);
printf("������Ҫɾ����λ��:\n");
scanf("%d",&i);
ListDelect_Sq(la,i,e);
printf("ɾ�����Ǹ�Ԫ����:%d\n",e);
printf("���ɾ�����˳���:\n");
print(la);
InitList_Sq(lb);
CreateList(lb);
print(lb);
InitList_Sq(lc);
CreateList(lc);
print(lc);
InitList_Sq(ld);
Combine(lb,lc,ld);
printf("�ϲ����˳���Ϊ:\n");
print(ld);

}