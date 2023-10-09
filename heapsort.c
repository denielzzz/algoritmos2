#include <stdio.h>

int esquerda(int i)
{
	return i*2;
}

int direita(int i)
{
	return i*2+1;
}

int pai(int i)
{
	return i/2;
}

void troca(int *v, int x, int y)
{
	int aux = v[x];
	v[x] = v[y];
	v[y] = aux;
}

void imprime_vetor(int *v, int n)
{
	for(int j = 0; j < n; j++)
		printf("%d ", v[j]);
	printf("\n");
}

void max_heap(int *v, int n, int i)
{
	int esq = esquerda(i);
	int dir = direita(i);
	int maior;

	if(esq < n && v[esq] > v[i])
		maior = esq;
	else
		maior = i;
	if(dir < n && v[dir] > v[maior])
		maior = dir;
	if(maior != i)
	{
		troca(v, maior, i);
		max_heap(v, n, maior);
	}
}

void build_max_heap(int *v, int n)
{
	for(int j = n/2; j >= 0; j--)
		max_heap(v, n, j);
}

void heapsort(int *v, int n)
{
	if(n == 2)
		return;
	build_max_heap(v, n);
	troca(v, 0, n-1);
	heapsort(v, n-1);
}

int main()
{
	int v[50];
	int n;
	scanf(" %d", &n);
	for(int i = 0; i < n; i++)
		scanf(" %d", &v[i]);

	heapsort(v, n);

	imprime_vetor(v, n);

	return 0;
}