// Bu program girilen N sayýsý için (2N+3)x(2N+3) boyutunda sýfýrlardan oluþan bir kare matris oluþturur.
// Matrisin merkezinden dört yöne N birim ilerlendiðinde ulaþýlan noktalarýn birleþmesiyle oluþacak eþkenar dörtgeni birlerle doldurur.
// Her satýrda kaç tane bir olduðunu ve matrisi ekrana yazdýrýr.

#include <stdio.h>
#include <stdlib.h>

// Matrisin orta satýrýndan baþlayarak önce yukarý recursive olarak ilerler. Orta satýra dönerken bulunduðu satýrlarý boyar.
// Orta satýra dönüldüðünde ayný mantýkla aþaðý iner ve yine orta satýra dönerken bulunduðu satýrlarý boyar.
void paint(int**, int, int, int, int);

int main(void)
{
	int N;
	int **matrix;
	int i, j;
	
	printf("Enter N: ");
	scanf("%i", &N);
	
	// Tüm elemanlarý sýfýr olan matris oluþturulur.
	matrix = (int**)malloc((2*N + 3) * sizeof(int*));
	for (i = 0; i < (2*N + 3); i++)
	{
		*(matrix + i) = (int*)calloc(2*N + 3, sizeof(int));
	}
	
	paint(matrix, N, N+1, N+1, -1); // Fonksiyon N adým yukarý(-1 yukarý, 1 aþaðý parametresidir) çýkacak þekilde ortanca satýrdan çalýþmaya baþlar.
	
	
	// Matris yazdýrýlýr
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
		// Merkez satýrdan aþaðýdaysak satýrdaki 1 adedini yazdýrýr.
		if (row > col)
		{
			printf("Total 1 in row %i is: %i\n", row, (2*N + 1));
		}
		
		// Merkez satýrdan yukarýdaysak satýrdaki 1 adedi yazdýrýlmadan önce, aþaðýdaysak da 1 adedi yazdýrýldýktan sonra fonksiyon çaðrýlýr.
		paint(matrix, N-1, row+move, col, move);
	
		for (i = col-N; i <= col+N; i++)
		{
			*(*(matrix+row)+i) = 1;
		}
		
		// Merkez satýrdan aþaðýdaysak satýrdaki 1 adedini yazdýrýr.
		if (row <= col)
		{
			printf("Total 1 in row %i is: %i\n", row, (2*N + 1));
		}
		
		// Fonksiyonun gidiþ yönünü terse çevirir
		if (row == col)
		{
			move *= -1; 
			paint(matrix, N-1, row+move, col, move);
		}
	}
}
