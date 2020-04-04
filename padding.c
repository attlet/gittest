
#include <stdio.h>

struct student{
    char lastName[13];   /*13 bytes */
    int studentId;       /*4  bytes */
    short grade;         /*2  bytes */
};  //구조체 크기를 총합 19바이트라 예측할 수 있다.

int main(){

    struct student pst; //typedef없이 구조체가 선언됐기에 앞에 struct를 붙여준다.
    printf("==========이름: 신윤성 학번: 2017038015==========\n");
    printf("size of student = %ld\n", sizeof(struct student)); //예상과 달리 24바이트가 출력되었다.
    printf("size of int = %ld\n", sizeof(int));                //이는 padding을 하기 때문이다. 구조 내의 빈 공간을 채워넣는다. 
    printf("size of short = %ld\n", sizeof(short));            //짝수 바이트, 4,8,16등의 메모리 경계. 13/4는 나머지가 1이기 때문에 나머지 3바이트를 넣는 등.

    return 0;

}