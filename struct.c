
#include <stdio.h>

struct student1{
    char lastName;
    int studentId;
    char grade;
};

typedef struct{
    char lastName;
    int studentId;
    char grade;
} student2;        //둘 다 구조체를 선언하는데 형태가 다르다.

int main(){
    struct student1 st1 = {'A', 100, 'A'}; //struct를 쓰지않으면 컴파일 에러발생
    printf("==========이름: 신윤성 학번:2017038015==========\n");
    printf("st1.lastName = %c\n", st1.lastName);
    printf("st1.studentId = %d\n", st1.studentId);
    printf("st1.grade = %c\n", st1.grade);  //구조체 안의 값 출력.

    student2 st2 = {'B', 200, 'B'}; //구조체를 선언할 때 typedef을 썼기 때문에 struct를 안써도 됨.

    printf("\nst2.lastName = %c\n", st2.lastName);
    printf("st2.studentId = %d\n", st2.studentId);
    printf("st2.grade = %c\n", st2.grade);  //구조체 안의 값 출력.

    student2 st3;

    st3 = st2; /*예전 버전에서는 허용되지 않던 형태. 하나하난 대입을 해줘야 했지만 
               이제는 그럴 필요 없어짐.*/
    printf("\nst3.lastName = %c\n", st3.lastName);
    printf("st3.studentId = %d\n",st3.studentId);
    printf("st3.grade = %c\n", st3.grade);

    /*if(st3 == st2){  //허용되지 않는 방식. 원소 하나하나를 일일히 비교해줘야 된다.
        printf("equal\n");
    }
    else{
        printf("not equal\n");
    }*/
      
    return 0;


}

