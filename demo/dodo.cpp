/*˳����ʵ��
*��:�ɲ������ڲ���ɾ���Ȳ�������˳���ָ���ʼ״̬*/
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"  
#include "malloc.h"
#define maxsize 1024
typedef char datatype;
typedef struct
{
    datatype data[maxsize];
    int last;   //��¼sequenlist���һ��Ԫ�ص�λ��    
}sequenlist;
/*�ڵ�i��Ԫ��ǰ����Ԫ��x(ע��:Ԫ�ش�0��ʼ����)*/
int insert(sequenlist *L, datatype x, int i)
{
    int j;
    if (L->last == maxsize - 1)  //��ԭ������
    {
        printf("overflow");
            return 0;
    }
    else if ((i<0) || (i>L->last)) //������Χ
    {
        printf("error,please input the right 'i'");
        return 0;
    }
    else
    {
        for (j = L->last; j >= i; j--)
            L->data[j + 1] = L->data[j];  //�ӵ�i��Ԫ����,ÿ��Ԫ�غ���һλ
        L->data[i] = x;
        L->last = L->last + 1;
    }
    return (1);
}
/*ɾ����i��Ԫ��,��0����*/
int dellist(sequenlist *L, int i)
{
    if ((i<0) || (i>L->last))  //������Χ
    {
        printf("error,please input the right 'i'");
        return 0;
    }
    else
    {
        for (;i<L->last ; i++)
            L->data[i] = L->data[i+1];    //�ӵ�i+1��Ԫ����,ÿ��Ԫ��ǰ��һλ
        L->last = L->last - 1;
        return (1);
    }
}
/*����sequenlist,Ԫ��Ϊ�����ַ�*/
void creatlist(sequenlist *L)
{
    int n, i;
    char tmp;
    printf("please input the number of data:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("data[%d]=", i);
        fflush(stdin);  //������̻�����
        scanf("%c", &tmp);
        L->data[i] = tmp;
    }
    L->last = n - 1;
    printf("\n");
}
/*��ӡ˳���*/
void printfout(sequenlist *L)
{
    int i;
    for (i = 0; i <= L->last; i++)
    {
        printf("data[%d]=", i);
        printf("%c\n", L->data[i]);
    }
}
/*��ֵ����˳�����Ԫ��*/
int locbyelem(sequenlist L, datatype Item)
{//ֻ�ܲ����״γ��ֵ�λ��
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
/*��λ�ò��ҵ�y��λ����ʲôԪ��*/
datatype locbypos(sequenlist L, int y)
{
    datatype e;
    if ((y<0) || (y>L.last))
    {
        printf("�����λ�÷Ƿ�\n");
    }
    e = L.data[y];
    printf("%c",e);
    printf("\n");
    return (e);
}
/*����˳�����Ԫ��e������λ��*/
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
    L = (sequenlist *)malloc(sizeof(sequenlist));   //ָ����ʹ��ǰҪ�ȳ�ʼ��
    creatlist(L);
    printfout(L);
    do
    {
        printf("i,I...����\n");
        printf("d,D...ɾ��\n");
        printf("l...��λ�ò���\n");
        printf("L...��ֵ����\n");
        printf("A...��������λ��\n");
        printf("q,Q...�˳�\n");
        do
        {
            fflush(stdin);  //������̻�����
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
            scanf("%c", &x);    //ֻ�������ַ�
            printf("please input where you want insert:");
            scanf("%d", &i);    //����д����
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