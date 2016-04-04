#include <stdio.h>

void swap(int a, int b)
{
    int t = a;
    a = b;
    b = t;
//	printf("%2d%d",a,b);
}

void swap2(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
//	printf("%2d%d",a,b);
}

void main(){
	int a=2, b=3;
    swap(a,b);//不能实现a和b值的互换
	printf("%2d%d",a,b);
	swap2(a,b);//可以实现a和b值的互换
	printf("%2d%d",a,b);
   // swap(&a,&b);//可以实现a和b值的互换

	
}