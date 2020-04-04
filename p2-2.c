#include <stdio.h>

void print1(int *ptr, int rows);

int main(){

    int one[] = {0, 1, 2, 3, 4};
    
    printf("==========이름: 신윤성 학번: 2017038015==========");
    printf("one     = %p\n", one);
    printf("&one    = %p\n", &one);
    printf("&one[0] = %p\n", &one[0]);   //배열의 이름은 배열 첫 번째 값의 주소와 같다.
    printf("\n");

    print1(&one[0],5);

    return 0;
}

void print1(int *ptr, int rows){ //주소와 배열 원소를 출력하는 함수

    int i;
    printf("Address \t Contents\n");
    for(i = 0;i<rows;i++){
        printf("%p \t %5d\n", ptr +i, *(ptr + i));  //*을 써야 비로소 주소 안의 값을 출력가능
    }
    printf("\n");
}