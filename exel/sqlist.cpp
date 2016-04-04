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
void CreateList(SqList &L) //创建顺序表
{
int i;
printf("请输入你要创建的顺序表元素个数 ");
scanf("%d",&L.length);
printf("请输入你要创建的顺序表:\n");
for(i=0;i<L.length;i++)
scanf("%d",&L.elem[i]);

}
void print( SqList &L)//输出顺序表
{
	int i;
for(i=0;i<L.length;i++)
printf("%3d",L.elem[i]);

}
Status  location( SqList L,Elemtype e)//查找元素的位置
{
	int i=0;
	
	while(L.elem[i]!=e && i<L.length)
		i++;
	if(i>L.length)
		return -1;
	else
		return i+1;//因为c语言是从下标0开始的当i=0时实际上是顺序表的第i+1个元素


}

Status ListInsert_Sq(SqList &L,int i,Elemtype e)//在顺序表的第i个位置插入值为e的元素
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
Status  ListDelect_Sq(SqList &L,int i,Elemtype e)//在顺序表的第i个位置删除值为e的元素并返回e的值
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
void Combine(SqList La,SqList Lb,SqList &Lc)//将两个非递减的顺序表合并成一个顺序表，合并后元素也按值非递减排列
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
printf("请输入要查找的元素:\n");
scanf("%d",&e);
j=location(la,e);
printf("该元素的位置为%d\n",j);

printf("请输入要插入的位置和元素:\n");
scanf("%d%d",&i,&e);

ListInsert_Sq(la,i,e);
printf("输出插入后的顺序表:\n");
print(la);
printf("请输入要删除的位置:\n");
scanf("%d",&i);
ListDelect_Sq(la,i,e);
printf("删除的那个元素是:%d\n",e);
printf("输出删除后的顺序表:\n");
print(la);
InitList_Sq(lb);
CreateList(lb);
print(lb);
InitList_Sq(lc);
CreateList(lc);
print(lc);
InitList_Sq(ld);
Combine(lb,lc,ld);
printf("合并后的顺序表为:\n");
print(ld);

}