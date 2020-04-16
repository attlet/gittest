
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void checkp(int a); //�Լ��� ���������� �۵��޴��� Ȯ���ϴ� �Լ� �߰�
int** create_matrix(int row, int col);
int free_matrix(int** matrix, int row, int col);
void print_matrix(int** matrix, int row, int col);
int fill_data(int** matrix, int row, int col);
int transpose_matrix(int** matrix, int** matrix_t, int row, int col);
int addition_matrix(int** matrix_a, int** matrix_b, int** matrix_sum, int row, int col);
int subtraction_matrix(int** matrix_a, int** matrix_b, int** matrix_sub, int row, int col);
int multiply_matrix(int** matrix_a, int** matrix_t, int** matrix_axt, int row, int col);

int main() {
    int row, col;
    srand(time(NULL)); //���� ����
    int** matrixA = NULL;int** matrixB = NULL;int** matrix_Sum = NULL;int** matrix_Sub = NULL;int** matrix_Axt = NULL;int** matrix_T = NULL;
    printf("��� ���� �Է��Ͻÿ�: ");
    scanf("%d %d", &row, &col);
    matrixA = create_matrix(row, col);
    matrixB = create_matrix(row, col);
    matrix_Sum = create_matrix(row, col);
    matrix_Sub = create_matrix(row, col);
    matrix_Axt = create_matrix(row, row);  //��ġ��İ� ���ϱ� ������ ��İ����� ������ �����ϴ�. 
    matrix_T = create_matrix(col, row);    //m*n��İ� n*m����� ��������� m*m����� �ȴ�.
       

    if (matrixA == NULL || matrixB == NULL) { //�����Ҵ��� �� �ƴ� �� Ȯ��
        printf("��ȿ���� ���� ���Դϴ�. ���α׷��� �����մϴ�.");
        return 0;
    }

    if ((fill_data(matrixA, row, col) == -1) || (fill_data(matrixB, row, col) == -1)) { //A��B����� ������ ä��
        printf("��ȿ���� ���� ���Դϴ�. ���α׷��� �����մϴ�.");
        return 0;
    }
    printf("==========�̸�:������ �й�:2017038015==========\n");
    printf("A:\n");
    print_matrix(matrixA,row,col);
    printf("B:\n");
    print_matrix(matrixB,row,col);
    checkp(addition_matrix(matrixA, matrixB, matrix_Sum, row, col));
    printf("A+B:\n");
    print_matrix(matrix_Sum, row, col);
    checkp(subtraction_matrix(matrixA, matrixB, matrix_Sub, row, col));
    printf("A-B:\n");
    print_matrix(matrix_Sub, row, col);
    checkp(transpose_matrix(matrixA, matrix_T, row, col));
    printf("A�� ��ġ���:\n");
    print_matrix(matrix_T, col, row);
    checkp(multiply_matrix(matrixA, matrix_T, matrix_Axt, row, col));
    printf("A * A^T:\n");
    print_matrix(matrix_Axt, row, row); //�� ��ĵ� ���

    free_matrix(matrixA,row,col);
    free_matrix(matrixB,row,col);
    free_matrix(matrix_Sum,row,col);
    free_matrix(matrix_Sub,row,col);
    free_matrix(matrix_T,col,row);
    free_matrix(matrix_Axt,row,row); //�����Ҵ�� �޸� ����
}
void checkp(int a) {
    if (a == -1) {
        printf("��ȿ���� ���� ���Դϴ�. ���α׷��� �����մϴ�.");
        exit(1);
    }
}

int** create_matrix(int row, int col) {  
    int** matrix = NULL;
    if (row <= 0 || col <= 0) { //��� ������ ���������� ���� ������ ����. �����ϴ� �Լ��� ���� ����
        return NULL;
    }
    if ((matrix = (int**)malloc(row * sizeof(int*))) == NULL) { //matrix�� ���� �����Ҵ�
        printf("�����Ҵ� ����");
        return NULL;
    }

    for (int i = 0;i < row;i++) {
        if ((matrix[i] = (int*)malloc(col * sizeof(int))) == NULL) { //matrix�� ����Ű�� ���ҵ� ������ �����Ҵ�
            printf("�����Ҵ� ����");
            return NULL;
        }
    }
    return matrix;
}
int free_matrix(int** matrix, int row, int col) {  //�����Ҵ�� �޸� ����
    if (row <= 0 || col <= 0) {
        printf("��ȿ���� ���� ���Դϴ�.\n");
        return -1;
    }

    for (int i = 0;i < row;i++) {
        free(matrix[i]);
    }
    free(matrix);
}
void print_matrix(int** matrix, int row, int col) { //��� ���
    if (row <= 0 || col <= 0) {
        printf("��ȿ���� ���� ���Դϴ�.\n");
        exit(1);
    }

    if (!matrix) {
        printf("�����Ҵ��� �����ʾҽ��ϴ�.");
        
    }
    else
    {
        for (int i = 0;i < row;i++) {
            for (int j = 0;j < col;j++) {
                printf(" %d ", matrix[i][j]);
            }

            printf("\n");
        }
        printf("\n\n");
    }


}
int fill_data(int** matrix, int row, int col) { //�����Ҵ�� ����� 1���� 19������ ������ ä��
    if (row <= 0 || col <= 0) {
        printf("��ȿ���� ���� ���Դϴ�.\n");  
        return -1;
    }

    for (int i = 0; i < row;i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = 1 + rand() % 19;
        }
    }

    if (matrix == NULL) {  //��ó�� �˻�. �޸𸮰� �Ҵ���� �ʾ��� ��츦 ���. �����ϴ� �Լ��� ���� ����
        return -1;
    }
    else {
        return 1;
    }

}
int transpose_matrix(int** matrix, int** matrix_t, int row, int col) {  //��ġ��� ���ϴ� �Լ�
    if (row <= 0 || col <= 0) {
        printf("��ȿ���� ���� ���Դϴ�.\n");
        return -1;
    }

    for (int i = 0;i < col;i++) {
        for (int j = 0;j < row;j++) {
            matrix_t[i][j] = matrix[j][i];
        }
    }

    if (matrix_t == NULL) {
        return -1;
    }
    else {
        return 1;
    }
}
int addition_matrix(int** matrix_a, int** matrix_b, int** matrix_sum, int row, int col) { //��ĵ��� ���ϴ� �Լ�
    if (row <= 0 || col <= 0) {
        printf("��ȿ���� ���� ���Դϴ�.\n");
        return -1;
    }

    for (int i = 0;i < row;i++) {
        for (int j = 0;j < col;j++) {
            matrix_sum[i][j] = matrix_a[i][j] + matrix_b[i][j];
        }
    }

    if (matrix_sum == NULL) {
        return -1;
    }
    else
    {
        return 1;
    }
}
int subtraction_matrix(int** matrix_a, int** matrix_b, int** matrix_sub, int row, int col) {//��Ļ��� ���ϴ� �Լ�
    if (row <= 0 || col <= 0) {
        printf("��ȿ���� ���� ���Դϴ�.\n");
        return -1;
    }

    for (int i = 0;i < row;i++) {
        for (int j = 0;j < col;j++) {
            matrix_sub[i][j] = matrix_a[i][j] - matrix_b[i][j];
        }
    }

    if (matrix_sub == NULL) {
        return -1;
    }
    else
    {
        return 1;
    }


}
int multiply_matrix(int** matrix_a, int** matrix_t, int** matrix_axt, int row, int col) {//��İ��� ���ϴ� �Լ�
    if (row <= 0 || col <= 0) {
        printf("��ȿ���� ���� ���Դϴ�.\n");
        return -1;
    }

    for (int i = 0;i < row;i++) {
        for (int j = 0;j < row;j++) {
            matrix_axt[i][j] = 0;  //��������� ������ ����� 0���� �ʱ�ȭ
        }
    }

    for (int i = 0;i < row;i++) {
        for (int j = 0;j < row;j++) {
            for (int z = 0;z < col;z++) {
                matrix_axt[i][j] += matrix_a[i][z] * matrix_t[z][j]; //��������� �����Ѵ�.
            }
        }
    }

    if (matrix_axt == NULL) {
        return -1;
    }
    else
    {
        return 1;
    }

}

