#include <iostream>
using namespace std;

void bubbleSort(int vetor[], int tamanho)
{
	int i, j;//contadores
	int trab; //� a variavel auxiliar para fazer as trocas de posi��es (para fazer a troca de pos � necess�rio 3)
	bool troca;
	int limite;
	int cont = 0; //contar� quantas vezes troca ser� true
	troca = true;
	limite = tamanho - 1;
	while (troca)
	{
		troca = false;
		for (i = 0; i < limite; i++)if (vetor[i] > vetor[i + 1])
			{
				trab = vetor[i];
				cout << "New trab:"<<trab << endl; //este cout mostrar� qual � o trab da vez
				vetor[i] = vetor[i + 1];
				vetor[i + 1] = trab;
				j = i;
				troca = true;
				if (troca)
				cont ++;
			}
		limite = j;
	}
	cout << "Contador:" <<cont << endl;
}
int main()
{
	int vetor[100];
	int tamanho;
	int i = 0; // contador
	cin >> tamanho;

	for (i = 0; i < tamanho; i++) //estrutura para entrada
	{
		cin >> vetor[i];
	}
	
	bubbleSort(vetor, tamanho);
	
	return 0;
}
