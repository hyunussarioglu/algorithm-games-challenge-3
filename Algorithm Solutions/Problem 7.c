/* 
	Bu program girilen N ve M için;
	Sýfýrlardan oluþan N boyutlu bir dizi oluþturur.
	Kullanýcýdan M adet a, b, k ve iþlem bilgisi alýr.
	[a, b] aralýðýnda dizi elemanlarýný k ile iþleme sokar.
	Sonuçta oluþan diziyi ekrana yazdýrýr.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j, N, M;
	float tmp, *array;
	int a, b, k;
	char operation;
	
	printf("Enter N and M: ");
	scanf("%i %i", &N, &M);
	
	array = (float*)calloc(N, sizeof(float));
	
	for (i = 0; i < M; i++)
	{
		scanf("%i %i %i %c", &a, &b, &k, &operation);
		
		switch (operation)
		{
			case '+':
				for (j = a-1; j < b; j++)
				{
					array[j] += k;
				}
				break;
				
			case '-':
				for (j = a-1; j < b; j++)
				{
					array[j] -= k;
				}
				break;
				
			case '*':
				for (j = a-1; j < b; j++)
				{
					array[j] *= k;
				}
				break;
				
			case '/':
				for (j = a-1; j < b; j++)
				{
					array[j] /= k;
				}
				break;
			
			// Özel bir iþlem olan s iþlemi k=0 iken a ve b indislerindeki elemanlarýn yerlerini, k=1 iken [a, b] aralýðýndaki elemanlarýn sýrasýný deðiþtirir.
			case 's':
				if (k)
				{
					for (j = a-1; j < (a+b)/2; j++)
					{
						tmp = array[j];
						array[j] = array[b-j-1];
						array[b-j-1] = tmp;
					}
				}
				else
				{
					tmp = array[a-1];
					array[a-1] = array[b-1];
					array[b-1] = tmp;
				}	
		}
	}
	
	printf("\n");
	for (i = 0; i < N; i++)
	{
		printf("%f ", array[i]);
	}
	
	return 0;
}
