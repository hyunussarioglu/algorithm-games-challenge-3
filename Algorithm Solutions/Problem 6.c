/*
	Bu program girilen X, N ve A  i�in;
	Kullan�c�dan X x N boyutunda bir matris al�r.
	Matrisin rastgele A sat�r�n� K matrisine, kalan sat�rlar� L matrisine atar.
	Ekrana K ve L matrisleri �arp�labiliyorsa �arp�m sonucunu, �arp�lam�yorsa ? yazd�r�r.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long **dot(long**, int, int, long**, int, int); // 2 matris al�r ve matris �arp�m� yapar.
void print_matrix(long**, int, int); // Matrisi ekrana yazd�r�r.

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
	
	matrix = (long**)malloc(X * sizeof(long*)); // Kullan�c�n�n girece�i matris.
	
	printf("Enter N: ");
	scanf("%i", &N);
	
	vecs = (int*)malloc(N * sizeof(int)); // Hangi sat�rlar�n se�ildi�ini g�steren dizi. T�m elemanlar� 0'd�r. i.sat�r se�ildi�ininde i.eleman 1 olur.
	
	// Matris girilir ve se�ilen sat�rlar dizisinin elemanlar� 0 yap�l�r.
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
	
	K = (long**)malloc(A * sizeof(long*));     // Rastgele se�ilen sat�rlar�n at�ld��� matris
	L = (long**)malloc((X-A) * sizeof(long*)); // Se�ilmeyen sat�rlar�n at�ld��� matris
	
	// Rastgele se�ilen sat�rlar K matrisine at�l�r.
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
	
	// Se�ilmeyen sat�rlar(dizide 0 olanlar) L matrisine at�l�r.
	L_cnt = 0;
	for (i = 0; i < X; i++)
	{
		if(!vecs[i])
		{
			*(L + L_cnt++) = *(matrix + i);
		}
	}
	
	// A veya X-A s�tun say�s�na e�it ise matrisler �arp�l�r ve sonu� yazd�r�l�r. De�ilse ? yazd�r�l�r.
	if ((X - A) == N)
	{
		mul = dot(K, A, N, L, (X-A), N); // X-A s�tun say�s�na e�it oldu�undan KxL i�lemi yap�l�r.
		print_matrix(mul, A, N);
	}
	else
	{
		if (A == N)
		{
			mul = dot(L, (X-A), N, K, A, N); // A s�tun say�s�na e�it oldu�u i�in LxK i�lemi yap�l�r.
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
