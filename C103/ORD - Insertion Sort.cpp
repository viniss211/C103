#include <iostream>
using namespace std;
void insercaoDireta(int vetor[], int tamanho) //função insertion sort que ordena o vetor em forma crescente
{
	int i, j;
	int chave;
	for (j = 1; j < tamanho; j++)
	{
		chave = vetor[j];
		i = j - 1;
		while ((i >= 0) && (vetor[i] < chave)) //aqui em vet < chave ele ordena em decrescente
		{
			vetor[i + 1] = vetor[i];
			i = i - 1;
		}
		vetor[i + 1] = chave;
	}
}
int main()
{
	int vetor[100];
	int j = 0;
	int i = 0; // contador


	while(vetor[i] != 0)
	{
		i++;
		cin >> vetor[i];
	}

	
	insercaoDireta(vetor, i); //chamada da função

	for (j =0 ; j < i; j++) //estrutura para saída dovet ordenado
	{
		cout << vetor[j] << endl;
	}


	return 0;
}
