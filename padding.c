
#include <stdio.h>

struct student{
    char lastName[13];   /*13 bytes */
    int studentId;       /*4  bytes */
    short grade;         /*2  bytes */
};  //����ü ũ�⸦ ���� 19����Ʈ�� ������ �� �ִ�.

int main(){

    struct student pst; //typedef���� ����ü�� ����Ʊ⿡ �տ� struct�� �ٿ��ش�.
    printf("==========�̸�: ������ �й�: 2017038015==========\n");
    printf("size of student = %ld\n", sizeof(struct student)); //����� �޸� 24����Ʈ�� ��µǾ���.
    printf("size of int = %ld\n", sizeof(int));                //�̴� padding�� �ϱ� �����̴�. ���� ���� �� ������ ä���ִ´�. 
    printf("size of short = %ld\n", sizeof(short));            //¦�� ����Ʈ, 4,8,16���� �޸� ���. 13/4�� �������� 1�̱� ������ ������ 3����Ʈ�� �ִ� ��.

    return 0;

}