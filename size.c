
#include <stdio.h>
#include<stdlib.h>

int main(){
    int **x; //���� ������ ����

    printf("==========�̸�: ������ �й�: 2017038015==========\n");
    printf("sizeof(x) = %lu\n", sizeof(x));  //x�� �ּҸ� �����ϱ� ������ 4����Ʈ. 64��Ʈ ȯ�濡�� 8����Ʈ.
    printf("sizeof(*x) = %lu\n", sizeof(*x));  //���ó� �ּҸ� �����ϱ� ������ 4����Ʈ.64��Ʈ ȯ�濡�� 8����Ʈ.
    printf("sizeof(**x) = %lu\n", sizeof(**x)); //�� �� ������ ������ int���� �����ϱ� ������ 4����Ʈ.
}

