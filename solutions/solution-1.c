// Bu program girilen bir n sayýsý için n basamaklý en büyük asal sayýyý ekrana yazdýrýr.

#include <stdio.h>
#include <math.h>

int prime(unsigned long long); // Fonksiyona giren sayý asal ise 1, deðil ise 0 döndürür.

int main(void)
{
	int n;
	int i;
	unsigned long long number;
	
	printf("Enter a value: ");
	scanf("%i", &n);
	
	i = 0;
	number = 1;
	
	// n basamaklý en büyük sayý hesaplanýr.
	while (i < n)
	{
		number *= 10;
		i++;
	}
	number--;
	
	// n basamaklý en büyük sayý her zaman tek sayýdýr.
	// Sayýyý ikiþer ikiþer azaltarak çift sayýlarý kontrol etmeden sayý asal olana kadar ilerler.
	while (!prime(number))
	{
		number -= 2;
	}
	
	printf("%llu", number);
	
	return 0;
}

int prime(unsigned long long number)
{
	unsigned long long i = 3; // Giren sayý tek olduðu için kontrole 3'ten baþlar.
	unsigned long long max = sqrt(number); // Sayýnýn karekökünü hesaplar.
	
	
	// 3'ten sayýnýn kareköküne kadar sayýnýn bir bölenini bulana kadar ilerler.
	while ((i <= max) && (number % i != 0))
	{
		i += 2;
	}
	
	
	// i sayýnýn karekökünden büyükse bölen bulunmamýþtýr. Sayý asaldýr, 1 döndürür. Deðilse 0 döndürür. 
	if (i > max)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
