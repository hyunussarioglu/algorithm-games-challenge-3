// Bu program girilen 1 ve 0'lardan olu�an string ve slot i�in;
// 'slot' numaral� slotta bir �r�n varsa slot numaras�n�, yoksa �r�n olan en yak�n slotun numaras�n� ekrana yazd�r�r.

#include <stdio.h>

int main(void)
{
	char string[20];
	int i, length, left, right, slot;
	int left_found, right_found, left_limit, right_limit;
	
	printf("Enter String: ");
	i = 0;
	
	// Klavyeden string okur
	do
	{
		scanf("%c", string + i);
	}
	while (string[i++] != '\n');
	
	length = i-1; // String uzunlu�u
	
	printf("Enter slot: ");
	scanf("%i", &slot);
	
	printf("\n");
	
	// Girilen slot numaras�nda �r�n varsa ekrana yazd�r�r, yoksa �r�n aramaya ba�lar.
	if (string[slot-1] - 48)
	{
		printf("%i", slot);
	}
	else
	{
		// Stringin d���na ��kmamak i�in kontroller
		if (slot-2 < 0)
		{
			left = 0;
		}
		else
		{
			left = slot-2;
		}
		
		if (slot > (length-1))
		{
			right = length-1;
		}
		else
		{
			right = slot;
		}
		
		right_found = left_found = 0;
		right_limit = left_limit = 1;
		
		// Dolu slot bulana kadar veya t�m slotlar� kontrol edene kadar �al���r.
		while ((left_limit || right_limit) && !(left_found || right_found))
		{
			if (left >= 0)
			{
				if(!(string[left]-48))
				{
					left--;
				}
				else
				{
					left_found = 1;
				}
				
				if (left < 0)
				{
					left_limit = 0;
				}
			}
			
			if (right <= (length-1))
			{
				if(!(string[right]-48))
				{
					right++;
				}
				else
				{
					right_found = 1;
				}
				
				if (right > (length-1))
				{
					right_limit = 0;
				}
			}
		}
		
		if (left_found)
		{
			printf("%i", left+1);
		}
		else if(right_found)
		{
			printf("%i", right+1);
		}
		else
		{
			printf("Product not found!");
		}
	}
	
	return 0;
}
