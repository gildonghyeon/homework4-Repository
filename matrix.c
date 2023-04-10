#include <stdio.h>
#include <stdlib.h>
int count;
typedef struct
{
    int row;       // 행
    int col;       // 열
    double** data; // 데이터
} Matrix;

// 행렬 생성 함수
Matrix create_matrix(int row, int col)
{
    Matrix mat;
    mat.row = row;
    mat.col = col;
    mat.data = (double**)malloc(sizeof(double*) * row); //동적메모리 할당
    if (count == 0)
    {
        for (int i = 0; i < row; i++)
        {
            mat.data[i] = (double*)malloc(sizeof(double) * col);
            for (int j = 0; j < col; j++)
            {
                printf("(%d, %d)의 값을 입력하세요: ", i + 1, j + 1);  
                scanf("%lf", &mat.data[i][j]); //행 열 각 자리에 값 저장
            }
        }
    }
    else {
        for (int a = 0; a < row; a++) {
            mat.data[a] = (double*)malloc(sizeof(double) * col);
            for (int b = 0; b < col; b++)

                mat.data[a][b] = 0; // 행 열 빈 상태로 유지
        }
    }
    return mat;
}
// 행렬 출력 함수
void print_matrix(Matrix mat)
{
    printf("Matrix %dx%d:\n", mat.row, mat.col);
    for (int i = 0; i < mat.row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {
            printf("%6.2f ", mat.data[i][j]); // 행렬에 저장된 값 출력
        }
        printf("\n");
    }
}

void free_matrix(Matrix mat)
{
    for (int i = 0; i < mat.row; i++)
    {
        free(mat.data[i]); 
    }
    free(mat.data); 
}

// 행렬 덧셈 함수
void addition_matrix(Matrix mat1, Matrix mat2)
{
    if (mat1.row != mat2.row || mat1.col != mat2.col)
    {
        printf("두 행렬의 크기가 일치하지 않습니다.\n");
    }
    else {
        Matrix res = create_matrix(mat1.row, mat1.col);
        for (int i = 0; i < mat1.row; i++)
        {
            for (int j = 0; j < mat1.col; j++)
            {
                res.data[i][j] = mat1.data[i][j] + mat2.data[i][j]; // 두 행렬의 합 저장
            }
        }
        print_matrix(res);
        free_matrix(res);
    }
}

// 행렬 뺄셈 함수
void subtraction_matrix(Matrix mat1, Matrix mat2)
{
    if (mat1.row != mat2.row || mat1.col != mat2.col)
    {
        printf("두 행렬의 크기가 일치하지 않습니다.\n");
    }
    else {
        Matrix res = create_matrix(mat1.row, mat1.col);
        for (int i = 0; i < mat1.row; i++)
        {
            for (int j = 0; j < mat1.col; j++)
            {
                res.data[i][j] = mat1.data[i][j] - mat2.data[i][j]; // 두 행렬의 뺄셈 저장
            }
        }
        print_matrix(res);
        free_matrix(res);
    }
}

// 행렬 전치 함수
void transpose_matrix(Matrix mat)
{
    Matrix res = create_matrix(mat.col, mat.row);
    for (int i = 0; i < mat.row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {
            res.data[j][i] = mat.data[i][j]; // 전치행렬을 빈 행렬에 저장
        }
    }
    print_matrix(res);
    free_matrix(res);
}

// 행렬 곱셈 함수
void multiply_matrix(Matrix mat1, Matrix mat2)
{
    if (mat1.col != mat2.row)
    {
        printf("첫 번째 행렬의 열과 두 번째 행렬의 행의 크기가 일치하지 않습니다.\n");
        exit(1);
    }
    else {
        Matrix res = create_matrix(mat1.row, mat2.col);
        for (int i = 0; i < mat1.row; i++)
        {
            for (int j = 0; j < mat2.col; j++)
            {
                double sum = 0;
                for (int k = 0; k < mat1.col; k++)
                {
                    sum += mat1.data[i][k] * mat2.data[k][j]; // 행렬의 곱 차례대로 계싼
                }
                res.data[i][j] = sum;
            }
        }
        print_matrix(res);
        free_matrix(res);
    }
}

int main()
{
    count = 0;
    int r, c, r1, c1;
    Matrix m1, m2;
    printf("[----- 길동현 2022041025 -----]\n");
    printf("첫번째 행렬의 행과 열을 입력하세요 : ");
    scanf("%d %d", &r, &c);
    printf("두번째 행렬의 행과 열을 입력하세요 : ");
    scanf("%d %d", &r1, &c1);
    printf("첫번째 행렬 : \n");
    m1 = create_matrix(r, c);
    printf("두번째 행렬 : \n");
    m2 = create_matrix(r1, c1);
    printf("m1 행렬 : ");
    print_matrix(m1);
    printf("\nm2 행렬 : ");
    print_matrix(m2);
    printf("\n");
    printf("행렬의 합 : \n");
    addition_matrix(m1, m2);
    printf("행렬의 뺼셈 : \n");
    subtraction_matrix(m1, m2);
    count = 1;
    printf("전치행렬m1 : \n");
    transpose_matrix(m1);
    printf("전치행렬m2 : \n");
    transpose_matrix(m2);
    printf("행렬의 곱 : \n");
    multiply_matrix(m1, m2);
    free_matrix(m1);
    free_matrix(m2);
    return 0;
}