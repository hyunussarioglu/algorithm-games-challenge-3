// Bu program girilen N say�s� i�in (2N+3)x(2N+3) boyutunda s�f�rlardan olu�an bir kare matris olu�turur.
// Matrisin merkezinden d�rt y�ne N birim ilerlendi�inde ula��lan noktalar�n birle�mesiyle olu�acak e�kenar d�rtgeni birlerle doldurur.
// Her sat�rda ka� tane bir oldu�unu ve matrisi ekrana yazd�r�r.

#include <stdio.h>
#include <stdlib.h>

// Matrisin orta sat�r�ndan ba�layarak �nce yukar� recursive olarak ilerler. Orta sat�ra d�nerken bulundu�u sat�rlar� boyar.
// Orta sat�ra d�n�ld���nde ayn� mant�kla a�a�� iner ve yine orta sat�ra d�nerken bulundu�u sat�rlar� boyar.
void paint(int**, int, int, int, int);

int main(void)
{
	int N;
	int **matrix;
	int i, j;
	
	printf("Enter N: ");
	scanf("%i", &N);
	
	// T�m elemanlar� s�f�r olan matris olu�turulur.
	matrix = (int**)malloc((2*N + 3) * sizeof(int*));
	for (i = 0; i < (2*N + 3); i++)
	{
		*(matrix + i) = (int*)calloc(2*N + 3, sizeof(int));
	}
	
	paint(matrix, N, N+1, N+1, -1); // Fonksiyon N ad�m yukar�(-1 yukar�, 1 a�a�� parametresidir) ��kacak �ekilde ortanca sat�rdan �al��maya ba�lar.
	
	
	// Matris yazd�r�l�r
	printf("\n");
	for (i = 0; i < (2*N + 3); i++)
	{
		for (j = 0; j < (2*N + 3); j++)
		{
			printf("%i ", *(*(matrix + i) + j));
		}
		printf("\n");
	}
	
	return 0;
}

void paint(int **matrix, int N, int row, int col, int move)
{
	int i;
	
	if (N >= 0)
	{
		// Merkez sat�rdan a�a��daysak sat�rdaki 1 adedini yazd�r�r.
		if (row > col)
		{
			printf("Total 1 in row %i is: %i\n", row, (2*N + 1));
		}
		
		// Merkez sat�rdan yukar�daysak sat�rdaki 1 adedi yazd�r�lmadan �nce, a�a��daysak da 1 adedi yazd�r�ld�ktan sonra fonksiyon �a�r�l�r.
		paint(matrix, N-1, row+move, col, move);
	
		for (i = col-N; i <= col+N; i++)
		{
			*(*(matrix+row)+i) = 1;
		}
		
		// Merkez sat�rdan a�a��daysak sat�rdaki 1 adedini yazd�r�r.
		if (row <= col)
		{
			printf("Total 1 in row %i is: %i\n", row, (2*N + 1));
		}
		
		// Fonksiyonun gidi� y�n�n� terse �evirir
		if (row == col)
		{
			move *= -1; 
			paint(matrix, N-1, row+move, col, move);
		}
	}
}
