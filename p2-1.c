#include <stdio.h>

#define MAX_SIZE 100

float sum(float [], int);
float input[MAX_SIZE], answer;
int i;
int main()
{
  for(i = 0;i<MAX_SIZE;i++){
      input[i] = i;  //�迭�� 0���� 99���� ä���ִ´�.
  }
  printf("address of input = %p\n", input);  //input�� �������� �ּҸ� ����Ѵ�.

  answer = sum(input, MAX_SIZE);  //input�� ũ�⸦ sum�Լ��� �Ű������� ������.
  printf("the sum is: %f\n", answer);

}

float sum(float list[], int n)  //�迭���� ���ҵ��� ������ ���Ѵ�.
{
    printf("value of list = %p\n", list); //�Ű������� input�� �ּҸ� ���� ���� Ȯ��
    printf("address of list = %p\n\n", &list);  //�ٸ� �� ���. ������ �����̱⿡ �ٸ� �ּҸ� ���� �ִ�.

    int i;
    float tempsum = 0;
    for(i = 0;i<n;i++){
        tempsum += list[i];  //���ҵ��� ���Ѵ�.
    }
    return tempsum;  //������ �����Ѵ�.
}