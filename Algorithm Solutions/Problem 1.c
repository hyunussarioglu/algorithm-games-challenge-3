// Bu program girilen bir n say�s� i�in n basamakl� en b�y�k asal say�y� ekrana yazd�r�r.

#include <stdio.h>
#include <math.h>

int prime(unsigned long long); // Fonksiyona giren say� asal ise 1, de�il ise 0 d�nd�r�r.

int main(void)
{
	int n;
	int i;
	unsigned long long number;
	
	printf("Enter a value: ");
	scanf("%i", &n);
	
	i = 0;
	number = 1;
	
	// n basamakl� en b�y�k say� hesaplan�r.
	while (i < n)
	{
		number *= 10;
		i++;
	}
	number--;
	
	// n basamakl� en b�y�k say� her zaman tek say�d�r.
	// Say�y� iki�er iki�er azaltarak �ift say�lar� kontrol etmeden say� asal olana kadar ilerler.
	while (!prime(number))
	{
		number -= 2;
	}
	
	printf("%llu", number);
	
	return 0;
}

int prime(unsigned long long number)
{
	unsigned long long i = 3; // Giren say� tek oldu�u i�in kontrole 3'ten ba�lar.
	unsigned long long max = sqrt(number); // Say�n�n karek�k�n� hesaplar.
	
	
	// 3'ten say�n�n karek�k�ne kadar say�n�n bir b�lenini bulana kadar ilerler.
	while ((i <= max) && (number % i != 0))
	{
		i += 2;
	}
	
	
	// i say�n�n karek�k�nden b�y�kse b�len bulunmam��t�r. Say� asald�r, 1 d�nd�r�r. De�ilse 0 d�nd�r�r. 
	if (i > max)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
