#include <stdio.h>
#include <stdlib.h>
int main()
{
    int list[5];
    int *plist[5] = {NULL,};    //������ �迭 ���� �� �ʱ�ȭ

    plist[0] = (int *)malloc(sizeof(int)); //�����Ϳ� �����Ҵ����� heap������ �޸� ������ ����Ŵ

    list[0] = 1;                   
    list[1] = 100;

    *plist[0] = 200;            //plist[0]�� ����Ű�� �ּҿ� ���� ����

    printf("==========�̸�: ������ �й�: 2017038015==========\n");
    printf("value of list[0] = %d\n", list[0]);             
    printf("address of list[0]       = %p\n",&list[0]);  
    printf("value of list            = %p\n", list);   
    printf("address of list(&list)   = %p\n", &list);   //list�迭�� �ּ�. list[0]�� �ּ�, �׸��� �迭�� �̸��� ���� ���� ����.

    printf("-----------------------------------------\n");
    printf("value of list[1]    = %d\n", list[1]); 
    printf("address of list[1]  = %d\n", &list[1]);  
    printf("value of *(list+1)  = %d\n", *(list +1));  //list[1]�� ����Ű�� ������ ���.
    printf("address of list+1   = %d\n", list+1);  //list[1]�� �ּҿ� ����. list[0]���� 4����Ʈ ���� ��.

    
    printf("-----------------------------------------\n");

    printf("value of *plist[0]  = %d\n", *plist[0]);   //plist[0]�ȿ� ����ִ� �ּҰ� ����Ű�� ��.
    printf("&plist[0]           = %p\n", &plist[0]);   
    printf("&plist              = %p\n", &plist);      
    printf("plist               = %p\n", plist);       //&plist[0],&plist,plist��� ���� �� ���.
    printf("plist[0]            = %p\n", plist[0]);
    printf("plist[1]            = %p\n", plist[1]);
    printf("plist[2]            = %p\n", plist[2]);
    printf("plist[3]            = %p\n", plist[3]);
    printf("plist[4]            = %p\n", plist[4]);    //������ ��� null�� �Ǿ�����.

    free(plist[0]);   //�Ҵ��� �޸𸮸� ���� ��Ų��. 

}