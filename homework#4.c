
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void checkp(int a); //함수가 정상적으로 작동햇는지 확인하는 함수 추가
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
    srand(time(NULL)); //난수 생성
    int** matrixA = NULL;int** matrixB = NULL;int** matrix_Sum = NULL;int** matrix_Sub = NULL;int** matrix_Axt = NULL;int** matrix_T = NULL;
    printf("행과 열을 입력하시오: ");
    scanf("%d %d", &row, &col);
    matrixA = create_matrix(row, col);
    matrixB = create_matrix(row, col);
    matrix_Sum = create_matrix(row, col);
    matrix_Sub = create_matrix(row, col);
    matrix_Axt = create_matrix(row, row);  //전치행렬과 곱하기 때문에 행렬곱셈은 무조건 가능하다. 
    matrix_T = create_matrix(col, row);    //m*n행렬과 n*m행렬의 곱셈결과는 m*m행렬이 된다.
       

    if (matrixA == NULL || matrixB == NULL) { //동적할당이 잘 됐는 지 확인
        printf("유효하지 않은 값입니다. 프로그램을 종료합니다.");
        return 0;
    }

    if ((fill_data(matrixA, row, col) == -1) || (fill_data(matrixB, row, col) == -1)) { //A와B행렬을 난수로 채움
        printf("유효하지 않은 값입니다. 프로그램을 종료합니다.");
        return 0;
    }
    printf("==========이름:신윤성 학번:2017038015==========\n");
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
    printf("A의 전치행렬:\n");
    print_matrix(matrix_T, col, row);
    checkp(multiply_matrix(matrixA, matrix_T, matrix_Axt, row, col));
    printf("A * A^T:\n");
    print_matrix(matrix_Axt, row, row); //각 행렬들 출력

    free_matrix(matrixA,row,col);
    free_matrix(matrixB,row,col);
    free_matrix(matrix_Sum,row,col);
    free_matrix(matrix_Sub,row,col);
    free_matrix(matrix_T,col,row);
    free_matrix(matrix_Axt,row,row); //동적할당된 메모리 해제
}
void checkp(int a) {
    if (a == -1) {
        printf("유효하지 않은 값입니다. 프로그램을 종료합니다.");
        exit(1);
    }
}

int** create_matrix(int row, int col) {  
    int** matrix = NULL;
    if (row <= 0 || col <= 0) { //행과 열값에 비정상적인 값이 들어오면 종료. 연산하는 함수에 전부 적용
        return NULL;
    }
    if ((matrix = (int**)malloc(row * sizeof(int*))) == NULL) { //matrix에 먼저 동적할당
        printf("동적할당 실패");
        return NULL;
    }

    for (int i = 0;i < row;i++) {
        if ((matrix[i] = (int*)malloc(col * sizeof(int))) == NULL) { //matrix가 가리키는 원소들 각각에 동적할당
            printf("동적할당 실패");
            return NULL;
        }
    }
    return matrix;
}
int free_matrix(int** matrix, int row, int col) {  //동적할당된 메모리 해제
    if (row <= 0 || col <= 0) {
        printf("유효하지 않은 값입니다.\n");
        return -1;
    }

    for (int i = 0;i < row;i++) {
        free(matrix[i]);
    }
    free(matrix);
}
void print_matrix(int** matrix, int row, int col) { //행렬 출력
    if (row <= 0 || col <= 0) {
        printf("유효하지 않은 값입니다.\n");
        exit(1);
    }

    if (!matrix) {
        printf("동적할당이 되지않았습니다.");
        
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
int fill_data(int** matrix, int row, int col) { //동적할당된 행렬을 1에서 19사이의 값으로 채움
    if (row <= 0 || col <= 0) {
        printf("유효하지 않은 값입니다.\n");  
        return -1;
    }

    for (int i = 0; i < row;i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = 1 + rand() % 19;
        }
    }

    if (matrix == NULL) {  //후처리 검사. 메모리가 할당되지 않았을 경우를 대비. 연산하는 함수에 전부 적용
        return -1;
    }
    else {
        return 1;
    }

}
int transpose_matrix(int** matrix, int** matrix_t, int row, int col) {  //전치행렬 구하는 함수
    if (row <= 0 || col <= 0) {
        printf("유효하지 않은 값입니다.\n");
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
int addition_matrix(int** matrix_a, int** matrix_b, int** matrix_sum, int row, int col) { //행렬덧셈 구하는 함수
    if (row <= 0 || col <= 0) {
        printf("유효하지 않은 값입니다.\n");
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
int subtraction_matrix(int** matrix_a, int** matrix_b, int** matrix_sub, int row, int col) {//행렬뺄셈 구하는 함수
    if (row <= 0 || col <= 0) {
        printf("유효하지 않은 값입니다.\n");
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
int multiply_matrix(int** matrix_a, int** matrix_t, int** matrix_axt, int row, int col) {//행렬곱셈 구하는 함수
    if (row <= 0 || col <= 0) {
        printf("유효하지 않은 값입니다.\n");
        return -1;
    }

    for (int i = 0;i < row;i++) {
        for (int j = 0;j < row;j++) {
            matrix_axt[i][j] = 0;  //곱셈결과를 저장할 행렬을 0으로 초기화
        }
    }

    for (int i = 0;i < row;i++) {
        for (int j = 0;j < row;j++) {
            for (int z = 0;z < col;z++) {
                matrix_axt[i][j] += matrix_a[i][z] * matrix_t[z][j]; //곱셈결과를 저장한다.
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

