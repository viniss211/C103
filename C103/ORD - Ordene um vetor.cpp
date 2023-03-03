#include <iostream>
#include <cmath>
using namespace std;
void quickSort(int vetor[], int tamanho, int i, int j)
{
	int trab, esq, dir, pivo;
	esq = i;
	dir = j;
	pivo = vetor[(int)round((esq + dir) / 2.0)];
	do
	{
		while (vetor[esq] < pivo)esq++;
		while (vetor[dir] > pivo)dir--;
		if (esq <= dir)
		{
			trab = vetor[esq];
			vetor[esq] = vetor[dir];
			vetor[dir] = trab;
			esq++;
			dir--;
		}
	}
	while (esq <= dir);
	if (dir - i >= 0)quickSort(vetor, tamanho, i, dir);
	if (j - esq >= 0)quickSort(vetor, tamanho, esq, j);
}
int main()
{
	int vetor[100];
	int j = 0;
	int i = 0; // contador
	int esq = 0;
	int dir;
	int tam = 0;
	int aux; //variavel que auxiliara na entrada de eementos do vetor

	do //estrutura para entrada do vet e excluir o -1/estrutura salvadora de vidas usar dnv qnd precisar
	{
		tam++;
		cin >> aux;
		if(aux != -1)
			vetor[i] = aux;
		i++;
	}
	while(aux != -1);

	dir = tam; //dir recebe o valor tamnho para q a função pegue o valor que está na ultima posição

	quickSort(vetor, tam, esq, dir);

	for (j = 0 ; j < i-1; j++) //estrutura para saída do vet ordenado coloca o i-1 se nda pau 
	{
		cout << vetor[j] << endl;
	}

	return 0;
}

