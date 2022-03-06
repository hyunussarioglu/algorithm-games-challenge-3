/*
Bu program girilen N, start ve k de�erleri i�in;
N ki�ilik bir �emberde start numaral� ki�iyi ba�lang�� noktas� kabul eden
ve k ad�m ilerideki ki�iyi �emberden ��kararak 1 ki�i kalana kadar s�rd�r�len bir oyunu sim�le eder.
Sona kalan ki�iyi ekrana yazd�r�r.
*/

#include <stdio.h>
#include <stdlib.h>

// Bu problem i�in en uygun veri yap�lar�ndan biri circular linked list'tir.
// Her node kendi numaras�n� ve kendisinden sonraki node'un adresini tutar.
typedef struct Node
{
	int value;
	struct Node *next;
}NODE;

NODE *last; // Linked listin son eleman�n� g�sterir. last->next listin ilk eleman�n� g�sterir.

NODE *create_node(int); // Yeni bir node olu�turur.
void insert_node(int); // Liste sondan bir node ekler.
int delete_node(int, int); // Listteki istenen numaral� node'u siler.

int main(void)
{
	int N, start, k;
	int i;
	
	last = NULL;
	
	printf("Enter N, start and k: ");
	scanf("%i %i %i", &N, &start, &k);
	
	// Liste 1'den N'e kadar numaraland�r�lm�� N adet node ekler.
	for (i = 1; i <= N; i++)
	{
		insert_node(i);
	}
	
	// Bir node silindi�inde ad�m saymaya o node'dan ba�layamayaca��m�z i�in bir sonraki node'dan ba�lan�r.
	// Bu nedenle ba�lang�� ki�isinden de�il bir sonraki ki�iden ba�lan�r.
	// Dolay�s�yla ad�m say�m�z k de�il k-1 kabul edilir.
	start = 1 + (start % N);
	k--;
	
	// �lk node ile son node e�it ise listte bir node vard�r.
	// Bir node kalana kadar k ad�m sonraki node silinir.
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
	
	
	// Ba�lang�� node'unu bulana kadar ilerler.
	while(current->value != start)
	{
		prev = current;
		current = current->next;
	}
	
	// Ba�lang�� node'undan ad�m say�s� kadar ilerler.
	for (i = 0; i < k; i++)
	{
		prev = current;
		current = current->next;
	}
	
	// Son node silinecekse last art�k sondan bir �nceki node'u g�sterir.
	if (current == last)
	{
		last = prev;
	}
	
	// Node circular linked listten ��kar�l�r.
	new_start = current->next->value;
	prev->next = current->next;
	free(current);
	
	return new_start; // Silinen elemandan bir sonraki node'un numaras�n� d�nd�r�r.
}
