/* 
	Bu program girilen n i�im n. fibonacci say�s�n� ekrana yazd�r�r.(Sayma say�lar� 1'den ba�lad���ndan n'in 0'dan b�y�k girildi�i varsay�l�r)
	|1 1|   matrisinin n-1. kuvveti al�n�p |1|  vekt�r� ile �arp�ld���nda olu�an vekt��n ikinci eleman� n. fibonacci say�s�n� verir.
	|1 0|                                |0|
*/ 

#include <stdio.h>
#include <stdlib.h>

unsigned long long **dot(unsigned long long**, int, int, unsigned long long**, int, int); // Matris �arp�m� yapan fonksiyon
unsigned long long **exp_n(int); // matrisin n-1. kuvvetini hesaplayan recursive fonksiyon

int main(void)
{
	int n;
	int i;
	unsigned long long **fibonacci, **result;
	
	// Vekt�r olu�turulur
	fibonacci = (unsigned long long**)malloc(2 * sizeof(unsigned long long*));
	for (i = 0; i < 2; i++)
	{
		*(fibonacci+i) = (unsigned long long*)malloc(sizeof(unsigned long long));
		fibonacci[i][0] = 1-i;
	}
	
	printf("Enter n: ");
	scanf("%i", &n);
	
	result = dot(exp_n(n-1), 2, 2, fibonacci, 2, 1); // Sonu� vekt�r� hesaplan�r
	
	printf("%i. Fibonacci number is %lli", n, result[1][0]);
	
	return 0;
}

unsigned long long **dot(unsigned long long **mat1, int n1, int m1, unsigned long long **mat2, int n2, int m2)
{
	int i, j, k;
	unsigned long long **mat3;
	
	mat3 = (unsigned long long**)malloc(n1 * sizeof(unsigned long long*));
	
	for (i = 0; i < n1; i++)
	{
		*(mat3 + i) = (unsigned long long*)malloc(m2 * sizeof(unsigned long long));
		
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

unsigned long long **exp_n(int n)
{
	int i, j;
	unsigned long long **identity, **fibo;
	
	identity = (unsigned long long**)malloc(2 * sizeof(unsigned long long*));
	fibo = (unsigned long long**)malloc(2 * sizeof(unsigned long long*));
	
	// Kuvvetini ald���m�z matris ve birim matris olu�turulur.
	for (i = 0; i < 2; i++)
	{
		*(identity+i) = (unsigned long long*)malloc(2 * sizeof(unsigned long long));
		*(fibo+i) = (unsigned long long*)malloc(2 * sizeof(unsigned long long));
		
		for (j = 0; j < 2; j++)
		{
			identity[i][j] = !(i^j);
			fibo[i][j] = !(i && j);
		}
	}
	
	/*
		n>0 oldu�u s�rece;
		n tek ise matris^n = matris^(n/2) * matris^(n/2) * matris �eklinde hesaplan�r
		n �ift ise matris^n = matris^(n/2) * matris^(n/2) �eklinde hesaplan�r
		n 0 ise birim matris d�nd�r�l�r.
	*/
	if (n > 0)
	{
		if (n % 2)
		{
			return dot(dot(exp_n(n / 2), 2, 2, exp_n(n / 2), 2, 2), 2, 2, fibo, 2, 2);
		}
		else
		{
			return dot(exp_n(n / 2), 2, 2, exp_n(n / 2), 2, 2);
		}
	}
	else
	{
		return identity;
	}
}
