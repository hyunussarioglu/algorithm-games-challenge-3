/*
	Bu program girilen n, m, x, y ve day için;
	n x m birim bölgede (y, x) koordinatlarýndaki enfekte bir bireyin her gün temas ettiði birimleri de enfekte ettiði bir senaryoyu simüle eder.
	'day' gün sonra ilk enfekte birey dýþýnda enfekte olan birey sayýsýný ekrana yazdýrýr. (bireyler bulunduklarý yerden hareket edemezler) 
*/

#include <stdio.h>

int main(void)
{
	// Enfekte bireyin bulunduðu satýr y, sütun ise x'tir.
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
	
	// (y, x) koordinatlarýndan 4 yana doðru n x m birimlik alaný aþmayacak þekilde day birim uzaklaþýlýr.
	// minimum_satýr, maksimum satýr, minimum sütun ve maksimum sütun bulunur.
	// Sýnýrlarý bu 4 deðer olan dikdörtgen içindeki herkes hastalanmýþtýr.
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
