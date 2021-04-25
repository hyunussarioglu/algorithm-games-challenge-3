/*
	Bu program girilen X, N ve A  için;
	Kullanýcýdan X x N boyutunda bir matris alýr.
	Matrisin rastgele A satýrýný K matrisine, kalan satýrlarý L matrisine atar.
	Ekrana K ve L matrisleri çarpýlabiliyorsa çarpým sonucunu, çarpýlamýyorsa ? yazdýrýr.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long **dot(long**, int, int, long**, int, int); // 2 matris alýr ve matris çarpýmý yapar.
void print_matrix(long**, int, int); // Matrisi ekrana yazdýrýr.

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
	
	matrix = (long**)malloc(X * sizeof(long*)); // Kullanýcýnýn gireceði matris.
	
	printf("Enter N: ");
	scanf("%i", &N);
	
	vecs = (int*)malloc(N * sizeof(int)); // Hangi satýrlarýn seçildiðini gösteren dizi. Tüm elemanlarý 0'dýr. i.satýr seçildiðininde i.eleman 1 olur.
	
	// Matris girilir ve seçilen satýrlar dizisinin elemanlarý 0 yapýlýr.
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
	
	K = (long**)malloc(A * sizeof(long*));     // Rastgele seçilen satýrlarýn atýldýðý matris
	L = (long**)malloc((X-A) * sizeof(long*)); // Seçilmeyen satýrlarýn atýldýðý matris
	
	// Rastgele seçilen satýrlar K matrisine atýlýr.
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
	
	// Seçilmeyen satýrlar(dizide 0 olanlar) L matrisine atýlýr.
	L_cnt = 0;
	for (i = 0; i < X; i++)
	{
		if(!vecs[i])
		{
			*(L + L_cnt++) = *(matrix + i);
		}
	}
	
	// A veya X-A sütun sayýsýna eþit ise matrisler çarpýlýr ve sonuç yazdýrýlýr. Deðilse ? yazdýrýlýr.
	if ((X - A) == N)
	{
		mul = dot(K, A, N, L, (X-A), N); // X-A sütun sayýsýna eþit olduðundan KxL iþlemi yapýlýr.
		print_matrix(mul, A, N);
	}
	else
	{
		if (A == N)
		{
			mul = dot(L, (X-A), N, K, A, N); // A sütun sayýsýna eþit olduðu için LxK iþlemi yapýlýr.
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
