/*
Bu program girilen N, start ve k deðerleri için;
N kiþilik bir çemberde start numaralý kiþiyi baþlangýç noktasý kabul eden
ve k adým ilerideki kiþiyi çemberden çýkararak 1 kiþi kalana kadar sürdürülen bir oyunu simüle eder.
Sona kalan kiþiyi ekrana yazdýrýr.
*/

#include <stdio.h>
#include <stdlib.h>

// Bu problem için en uygun veri yapýlarýndan biri circular linked list'tir.
// Her node kendi numarasýný ve kendisinden sonraki node'un adresini tutar.
typedef struct Node
{
	int value;
	struct Node *next;
}NODE;

NODE *last; // Linked listin son elemanýný gösterir. last->next listin ilk elemanýný gösterir.

NODE *create_node(int); // Yeni bir node oluþturur.
void insert_node(int); // Liste sondan bir node ekler.
int delete_node(int, int); // Listteki istenen numaralý node'u siler.

int main(void)
{
	int N, start, k;
	int i;
	
	last = NULL;
	
	printf("Enter N, start and k: ");
	scanf("%i %i %i", &N, &start, &k);
	
	// Liste 1'den N'e kadar numaralandýrýlmýþ N adet node ekler.
	for (i = 1; i <= N; i++)
	{
		insert_node(i);
	}
	
	// Bir node silindiðinde adým saymaya o node'dan baþlayamayacaðýmýz için bir sonraki node'dan baþlanýr.
	// Bu nedenle baþlangýç kiþisinden deðil bir sonraki kiþiden baþlanýr.
	// Dolayýsýyla adým sayýmýz k deðil k-1 kabul edilir.
	start = 1 + (start % N);
	k--;
	
	// Ýlk node ile son node eþit ise listte bir node vardýr.
	// Bir node kalana kadar k adým sonraki node silinir.
	while (last->next != last)
	{
		start = delete_node(start, k);
	}
	
	printf("%i", last->value);
	
	return 0;
}

NODE *create_node(int value)
{
	NODE *node;
	
	node = (NODE*)malloc(sizeof(NODE));
	
	if (node == NULL)
	{
		printf("\nAllocation error!\n");
		exit(0);
	}
	else
	{
		node->value = value;
		node->next = NULL;
	}
	
	return node;
}

void insert_node(int value)
{
	NODE *node;
	
	node = create_node(value);
	
	if (last == NULL)
	{
		last = node;
		node->next = last;
	}
	else
	{
		node->next = last->next;
		last->next = node;
		last = node;
	}
}

int delete_node(int start, int k)
{
	int i, new_start;
	NODE *prev, *current;
	
	prev = last;
	current = prev->next;
	
	
	// Baþlangýç node'unu bulana kadar ilerler.
	while(current->value != start)
	{
		prev = current;
		current = current->next;
	}
	
	// Baþlangýç node'undan adým sayýsý kadar ilerler.
	for (i = 0; i < k; i++)
	{
		prev = current;
		current = current->next;
	}
	
	// Son node silinecekse last artýk sondan bir önceki node'u gösterir.
	if (current == last)
	{
		last = prev;
	}
	
	// Node circular linked listten çýkarýlýr.
	new_start = current->next->value;
	prev->next = current->next;
	free(current);
	
	return new_start; // Silinen elemandan bir sonraki node'un numarasýný döndürür.
}
