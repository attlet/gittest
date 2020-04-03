#include <stdio.h>

#define MAX_SIZE 100

float sum(float [], int);
float input[MAX_SIZE], answer;
int i;
int main()
{
  for(i = 0;i<MAX_SIZE;i++){
      input[i] = i;  //배열에 0부터 99까지 채워넣는다.
  }
  printf("address of input = %p\n", input);  //input의 시작지점 주소를 출력한다.

  answer = sum(input, MAX_SIZE);  //input과 크기를 sum함수의 매개변수로 보낸다.
  printf("the sum is: %f\n", answer);

}

float sum(float list[], int n)  //배열들의 원소들의 총합을 구한다.
{
    printf("value of list = %p\n", list); //매개변수로 input의 주소를 받은 것을 확인
    printf("address of list = %p\n\n", &list);  //다른 값 출력. 포인터 변수이기에 다른 주소를 갖고 있다.

    int i;
    float tempsum = 0;
    for(i = 0;i<n;i++){
        tempsum += list[i];  //원소들을 더한다.
    }
    return tempsum;  //총합을 리턴한다.
}