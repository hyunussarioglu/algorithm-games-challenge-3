/*
Bu program girilen bir N , X ve Y için;
N gezegenden her ikisi için aralarýnda doðrudan yol olup olmadýðý bilgisini alýr.
Gezegen-X'den Gezegen-Y'ye en fazla 1 gezegene uðrayarak kaç yoldan gidilebileceðini ekrana yazdýrýr.
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
	
	sum = matrix[x-1][y-1]; // x ve y arasýnda doðrudan yol varsa sum = 1, yoksa 0 olur.
	
	// Bu iþlemi if kullanmadan yapmak için gezegenin Gezegen-X satýrýndaki ve Gezegen-Y satýrýndaki karþýlýðý AND'lenir.
	// Bu sayede yalnýzca gezegenden hem X hem Y gezegenine doðrudan yol varsa sum artacaktýr.
	for (i = 0; i < N; i++)
	{
		sum += matrix[x-1][i] && matrix[y-1][i];
	}
	
	printf("Number of ways from Planet-%i to Planet-%i is %i", x, y, sum);
	
	return 0;
}
