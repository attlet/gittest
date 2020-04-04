
#include <stdio.h>
#include<stdlib.h>

int main(){
    int **x; //이중 포인터 선언

    printf("==========이름: 신윤성 학번: 2017038015==========\n");
    printf("sizeof(x) = %lu\n", sizeof(x));  //x는 주소를 저장하기 때문에 4바이트. 64비트 환경에선 8바이트.
    printf("sizeof(*x) = %lu\n", sizeof(*x));  //역시나 주소를 저장하기 때문에 4바이트.64비트 환경에선 8바이트.
    printf("sizeof(**x) = %lu\n", sizeof(**x)); //두 번 참조한 곳에는 int형을 저장하기 때문에 4바이트.
}

