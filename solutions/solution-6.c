/*
	Bu program girilen X, N ve A  için;
	Kullanıcıdan X x N boyutunda bir matris alır.
	Matrisin rastgele A satırını K matrisine, kalan satırları L matrisine atar.
	Ekrana K ve L matrisleri çarpıldığında çarpım sonucunu, çarpılamıyorsa ? yazdırır.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long **dot(long**, int, int, long**, int, int); // 2 matris alır ve matris çarpımı yapar.
void print_matrix(long**, int, int); // Matrisi ekrana yazdırır.

int main(void)
{
	int i, j;
	int X, N, A;
	long **matrix, **K, **L;
	int *vecs, row, L_cnt;
	long **mul;
	
	srand(time(NULL));
	
	printf("Enter X: ");
	scanf("%i", &X);
	
	matrix = (long**)malloc(X * sizeof(long*)); // Kullanıcının gireceği matris.
	
	printf("Enter N: ");
	scanf("%i", &N);
	
	vecs = (int*)malloc(N * sizeof(int)); // Hangi satırların seçildiğini gösteren dizi. Tüm elemanları 0'dır. i.satır seçildiğininde i.eleman 1 olur.
	
	// Matris girilir ve seçilen satırlar dizisinin elemanları 0 yapılır.
	for (i = 0; i < X; i++)
	{
		vecs[i] = 0;
		*(matrix + i) = (long*)malloc(N * sizeof(long));
		printf("Enter the %i. vector: ", i+1);
		for (j = 0; j < N; j++)
		{
			scanf("%i", *(matrix + i) + j);
		}
	}
	
	printf("Enter A: ");
	scanf("%i", &A);
	
	K = (long**)malloc(A * sizeof(long*));     // Rastgele seçilen satırlardan oluşan matris
	L = (long**)malloc((X-A) * sizeof(long*)); // Seçilmeyen satırlardan oluşan matris
	
	// Rastgele seçilen satırlar K matrisine atılır.
	for (i = 0; i < A; i++)
	{
		do
		{
			row = rand() % X;
		}
		while (vecs[row]);
		
		*(K + i) = *(matrix + row);
		vecs[row]++;
	}
	
	// Seçilmeyen satırlar(vecs dizisinde 0 olanlar) L matrisine atılır.
	L_cnt = 0;
	for (i = 0; i < X; i++)
	{
		if(!vecs[i])
		{
			*(L + L_cnt++) = *(matrix + i);
		}
	}
	
	// A veya X-A sütun sayısına eşit ise matrisler çarpılır ve sonuç yazdırılır. Değilse ? yazdırılır.
	if ((X - A) == N)
	{
		mul = dot(K, A, N, L, (X-A), N); // X-A sütun sayısına eşit olduğundan KxL işlemi yapılır.
		print_matrix(mul, A, N);
	}
	else
	{
		if (A == N)
		{
			mul = dot(L, (X-A), N, K, A, N); // A sütun sayısına eşit olduðu için LxK işlemi yapılır.
			print_matrix(mul, (X-A), N);
		}
		else
		{
			printf("?");
		}
	}
	
	return 0;
}

long **dot(long **mat1, int n1, int m1, long **mat2, int n2, int m2)
{
	int i, j, k;
	long **mat3;
	
	mat3 = (long**)malloc(n1 * sizeof(long*));
	
	for (i = 0; i < n1; i++)
	{
		*(mat3 + i) = (long*)malloc(m2 * sizeof(long));
		
		for (j = 0; j < m2; j++)
		{
			mat3[i][j] = 0;
			
			for (k = 0; k < m1; k++)
			{
				mat3[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
	
	return mat3;
}

void print_matrix(long **matrix, int n, int m)
{
	int i, j;
	
	printf("\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%li ", matrix[i][j]);
		}
		printf("\n");
	}
}
