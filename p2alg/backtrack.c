#include <stdio.h>

void imprime_vetor(int *set, int *v, int n)
{
    for(int i = 0; i < n; i++)
        if(v[i] == 1)
            printf("%d ", set[i]);

}

void backtrack(int *set, int *v, int n, int i, int b, int s)
{
    if(n == i)
    {
        imprime_vetor(set, v, n);
        printf("\n");
        return;
    }

    int k = 3;

    for(int j = 0; j < k; j++)
    {
        v[i] = j;
        if(j == 1)
        {
            s += v[i];
            if(s > b)
                return;
        }
        backtrack(set, v, n, i+1, b, s);
    }
}

int subconjuntos(int *set, int n, int b)
{
    int v[n];
    backtrack(set, v, n, 0, b, 0);

}
int main()
{
    int set[] = {1, 2, 3, 4, 5};
    int n = 4;
    int v[n];
    int b = 6;

    subconjuntos(set, n, b);

    return 0;
}