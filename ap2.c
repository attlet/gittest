#include <stdio.h>
#include <stdlib.h>
int main()
{
    int list[5];
    int *plist[5];  //포인터 배열 선언

    list[0] = 10;
    list[1] = 11;

    plist[0] = (int *)malloc(sizeof(int));  //동적할당으로 heap영역에 메모리 영역 할당.
    
    printf("==========이름: 신윤성 학번:2017038015==========\n");
    printf("list[0] \t= %d\n", list[0]);      
    printf("address of list \t= %p\n", list);  //list의 주소 출력.
    printf("address of list[0] \t= %p\n", &list[0]);  //배열의 이름과 같은 값 출력. 
    printf("address of list + 0 \t= %p\n", list+0);
    printf("address of list + 1 \t= %p\n", list+1);
    printf("address of list + 2 \t= %p\n", list+2);
    printf("address of list + 3 \t= %p\n", list+3);
    printf("address of list + 4 \t= %p\n", list+4);  //1이 더해질 때마다 4바이트 더해져 출력.
    printf("address of list[4] \t= %p\n", &list[4]); //4번째 원소의 주소 출력. 

    free(plist[0]);  //할당된 메모리 해제
}