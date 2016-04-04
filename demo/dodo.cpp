/*顺序表的实现
*问:可不可以在插入删除等操作后让顺序表恢复初始状态*/
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"  
#include "malloc.h"
#define maxsize 1024
typedef char datatype;
typedef struct
{
    datatype data[maxsize];
    int last;   //记录sequenlist最后一个元素的位置    
}sequenlist;
/*在第i个元素前插入元素x(注意:元素从0开始计数)*/
int insert(sequenlist *L, datatype x, int i)
{
    int j;
    if (L->last == maxsize - 1)  //若原表已满
    {
        printf("overflow");
            return 0;
    }
    else if ((i<0) || (i>L->last)) //超出范围
    {
        printf("error,please input the right 'i'");
        return 0;
    }
    else
    {
        for (j = L->last; j >= i; j--)
            L->data[j + 1] = L->data[j];  //从第i个元素起,每个元素后移一位
        L->data[i] = x;
        L->last = L->last + 1;
    }
    return (1);
}
/*删除第i个元素,从0计数*/
int dellist(sequenlist *L, int i)
{
    if ((i<0) || (i>L->last))  //超出范围
    {
        printf("error,please input the right 'i'");
        return 0;
    }
    else
    {
        for (;i<L->last ; i++)
            L->data[i] = L->data[i+1];    //从第i+1个元素起,每个元素前移一位
        L->last = L->last - 1;
        return (1);
    }
}
/*建立sequenlist,元素为单个字符*/
void creatlist(sequenlist *L)
{
    int n, i;
    char tmp;
    printf("please input the number of data:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("data[%d]=", i);
        fflush(stdin);  //清除键盘缓冲区
        scanf("%c", &tmp);
        L->data[i] = tmp;
    }
    L->last = n - 1;
    printf("\n");
}
/*打印顺序表*/
void printfout(sequenlist *L)
{
    int i;
    for (i = 0; i <= L->last; i++)
    {
        printf("data[%d]=", i);
        printf("%c\n", L->data[i]);
    }
}
/*按值查找顺序表中元素*/
int locbyelem(sequenlist L, datatype Item)
{//只能查找首次出现的位置
    int i = 0;
    while(i <= L.last + 1 && L.data[i] != Item)
        i++;
    if (L.data[i] == Item)
        printf("%d",i);
    else
        printf("not found!");
    printf("\n");
    return i;
}
/*按位置查找第y个位置是什么元素*/
datatype locbypos(sequenlist L, int y)
{
    datatype e;
    if ((y<0) || (y>L.last))
    {
        printf("输入的位置非法\n");
    }
    e = L.data[y];
    printf("%c",e);
    printf("\n");
    return (e);
}
/*查找顺序表中元素e的所有位置*/
int locbyelemall(sequenlist L,datatype e)
{
    int i;
    for (i = 0; i <= L.last; i++)
    {
        if (L.data[i] == e)
            printf("%d ",i);
    }
    printf("\n");
    return 0;
}
/*main()
{
    sequenlist *L;
    char cmd, x;    //cmd is what you choose
    int i;
    L = (sequenlist *)malloc(sizeof(sequenlist));   //指针在使用前要先初始化
    creatlist(L);
    printfout(L);
    do
    {
        printf("i,I...插入\n");
        printf("d,D...删除\n");
        printf("l...按位置查找\n");
        printf("L...按值查找\n");
        printf("A...查找所有位置\n");
        printf("q,Q...退出\n");
        do
        {
            fflush(stdin);  //清除键盘缓冲区
            scanf("%c", &cmd);
        } while ((cmd != 'd') && (cmd != 'D') && (cmd != 'i') && (cmd != 'I') && (cmd != 'q') && (cmd != 'Q') && (cmd != 'l') && (cmd != 'L') && (cmd != 'A'));
        switch (cmd)
        {
        case 'A':printf("please input what you what search:");
            fflush(stdin);
            scanf("%c", &i);
            locbyelemall(*L, i);
            break;
        case 'i':
        case 'I':printf("please input what you want insert:");
            fflush(stdin);
            scanf("%c", &x);    //只能输入字符
            printf("please input where you want insert:");
            scanf("%d", &i);    //这里写数字
            insert(L, x, i);
            printfout(L);
            break;
        case 'd':
        case 'D':printf("please input where you want delete:");
            fflush(stdin);
            scanf("%d", &i);
            dellist(L, i);
            printfout(L);
            break;
        case 'l':
            printf("please input where you want search:");
            fflush(stdin);
            scanf("%d", &i);
            locbypos(*L, i);
            break;
        case 'L':printf("please input what you want search:");
            fflush(stdin);
            scanf("%c",&x);
            locbyelem(*L, x);
            break;
        }
    } while ((cmd!='q')&&(cmd!='Q'));
}*/