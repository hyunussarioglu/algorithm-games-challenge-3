/*
Bu program girilen bir N , X ve Y i�in;
N gezegenden her ikisi i�in aralar�nda do�rudan yol olup olmad��� bilgisini al�r.
Gezegen-X'den Gezegen-Y'ye en fazla 1 gezegene u�rayarak ka� yoldan gidilebilece�ini ekrana yazd�r�r.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N, **matrix, x, y;
	int i, j, sum;
	
	printf("Enter N: ");
	scanf("%i", &N);
	
	matrix = (int**)malloc(N * sizeof(int*));
	
	printf("Enter the matrix:\n");
	for (i = 0; i < N; i++)
	{
		*(matrix + i) = (int*)malloc(N * sizeof(int));
		for (j = 0; j < N; j++)
		{
			scanf("%i", (*(matrix + i) + j));
		}
	}
	
	printf("Enter x and y: ");
	scanf("%i %i", &x, &y);
	
	sum = matrix[x-1][y-1]; // x ve y aras�nda do�rudan yol varsa sum = 1, yoksa 0 olur.
	
	// Bu i�lemi if kullanmadan yapmak i�in gezegenin Gezegen-X sat�r�ndaki ve Gezegen-Y sat�r�ndaki kar��l��� AND'lenir.
	// Bu sayede yaln�zca gezegenden hem X hem Y gezegenine do�rudan yol varsa sum artacakt�r.
	for (i = 0; i < N; i++)
	{
		sum += matrix[x-1][i] && matrix[y-1][i];
	}
	
	printf("Number of ways from Planet-%i to Planet-%i is %i", x, y, sum);
	
	return 0;
}
