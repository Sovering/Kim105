#include "stdio.h"
#include "stdlib.h"
#include "locale.h"
#include "conio.h"

int main()
{
 int N, M, N1, M1, i, j, k;
 setlocale(0, "RUS");
 N = 10;
 int **A = (int**)malloc(N * sizeof(int*));
 int **B = (int**)malloc(N * sizeof(int*));
 int **C = (int**)malloc(N * sizeof(int*));
 for (i = 0; i < N; i++)
 {
 A[i] = (int*)malloc(N * sizeof(int));
 B[i] = (int*)malloc(N * sizeof(int));
 C[i] = (int*)malloc(N * sizeof(int));
 }
 printf("Введите количество строк первой матрицы: ");
 scanf("%d", &N);
 printf("Введите количество столбцов первой матрицы: ");
 scanf("%d", &M);
 printf("Заполните матрицу A:\n");
 for (i = 0; i < N; i++)
 for (j = 0; j < M; j++)
 {
 scanf("%d", &A[i][j]);
 }
 printf("Введите количество строк второй матрицы: ");
 scanf("%d", &N1);
 printf("Введите количество столбцов второй матрицы: ");
 scanf("%d", &M1);
 if (M != N1)
 printf("Эти матрицы невозможно перемножить");
 else
 {
 printf("Заполните матрицу B:\n");
 for (i = 0; i < N1; i++)
 for (j = 0; j < M1; j++)
 {
 scanf("%d", &B[i][j]);
 }
 for (i = 0; i < N; i++)
 for (j = 0; j < M; j++)
 {
 C[i][j] = 0;
 for (k = 0; k < M1; k++)
 C[i][j] += A[i][k] * B[k][j];
 }
 printf("\nВид матрицы А\n");
 for (i = 0; i < N; i++)
 {
 for (j = 0; j < M; j++)
 printf("%d ", A[i][j]);
 printf("\n");
 }
 printf("\nМатрица B\n");
 for (i = 0; i < N1; i++)
 {
 for (j = 0; j < M1; j++)
 printf("%d ", B[i][j]);
 printf("\n");
 }
 printf("\nПри умножении получаем матрицу порядка %dx%d\n", N, M1);
 for (i = 0; i < N; i++)
 {
 for (j = 0; j < M1; j++)
 printf("%d ", C[i][j]);
 printf("\n");
 }
 _getch();
 return 0;
 }
}
