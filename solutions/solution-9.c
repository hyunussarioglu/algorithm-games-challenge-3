/*
	Bu program girilen n, m, x, y ve day i�in;
	n x m birim b�lgede (y, x) koordinatlar�ndaki enfekte bir bireyin her g�n temas etti�i birimleri de enfekte etti�i bir senaryoyu sim�le eder.
	'day' g�n sonra ilk enfekte birey d���nda enfekte olan birey say�s�n� ekrana yazd�r�r. (bireyler bulunduklar� yerden hareket edemezler) 
*/

#include <stdio.h>

int main(void)
{
	// Enfekte bireyin bulundu�u sat�r y, s�tun ise x'tir.
	int n, m, x, y, day;
	int min_row, max_row, min_col, max_col, infected;
	
	printf("Enter the size of x axis: ");
	scanf("%i", &m);
	printf("Enter the size of y axis: ");
	scanf("%i", &n);
	printf("Enter the coordinate x of infected person: ");
	scanf("%i", &x);
	printf("Enter the coordinate y of infected person: ");
	scanf("%i", &y);
	printf("Enter the number of days: ");
	scanf("%i", &day);
	
	// (y, x) koordinatlar�ndan 4 yana do�ru n x m birimlik alan� a�mayacak �ekilde day birim uzakla��l�r.
	// minimum_sat�r, maksimum sat�r, minimum s�tun ve maksimum s�tun bulunur.
	// S�n�rlar� bu 4 de�er olan dikd�rtgen i�indeki herkes hastalanm��t�r.
	if ((y-1-day) < 0)
	{
		min_row = 0;
	}
	else
	{
		min_row = y-1-day;
	}
	
	if ((y-1+day) > n-1)
	{
		max_row = n-1;
	}
	else
	{
		max_row = y-1+day;
	}
	
	if ((x-1-day) < 0)
	{
		min_col = 0;
	}
	else
	{
		min_col = x-1-day;
	}
	
	if ((x-1+day) > m-1)
	{
		max_col = m-1;
	}
	else
	{
		max_col = x-1+day;
	}
	
	infected = (max_row - min_row +1) * (max_col - min_col + 1) - 1;
	printf("\nNumber of infected person: %i\n", infected);
	
	return 0;
}
