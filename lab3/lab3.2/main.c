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
 printf("������� ���������� ����� ������ �������: ");
 scanf("%d", &N);
 printf("������� ���������� �������� ������ �������: ");
 scanf("%d", &M);
 printf("��������� ������� A:\n");
 for (i = 0; i < N; i++)
 for (j = 0; j < M; j++)
 {
 scanf("%d", &A[i][j]);
 }
 printf("������� ���������� ����� ������ �������: ");
 scanf("%d", &N1);
 printf("������� ���������� �������� ������ �������: ");
 scanf("%d", &M1);
 if (M != N1)
 printf("��� ������� ���������� �����������");
 else
 {
 printf("��������� ������� B:\n");
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
 printf("\n��� ������� �\n");
 for (i = 0; i < N; i++)
 {
 for (j = 0; j < M; j++)
 printf("%d ", A[i][j]);
 printf("\n");
 }
 printf("\n������� B\n");
 for (i = 0; i < N1; i++)
 {
 for (j = 0; j < M1; j++)
 printf("%d ", B[i][j]);
 printf("\n");
 }
 printf("\n��� ��������� �������� ������� ������� %dx%d\n", N, M1);
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
