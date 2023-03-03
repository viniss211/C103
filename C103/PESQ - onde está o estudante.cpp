#include <iostream>
using namespace std;

int main()
{
	int vetor[100]; //vetor de id do aluno
	int procura;//id a ser procurado
	int aux = 0; //auxiliar
	int aux1; //auxiliar que guadara tamannho do vetor
	int aux2 = 0; //auxiliar para caso procura nao seja encontrado
	int n; //número de alunos

	cin >> n;

	for (aux=0;aux<n;aux++) //estrada do id dos alunos
	{
		cin >> vetor[aux];
	}
	

	cin >> procura; //entrada de 

	for(aux1 = 0; aux1 < aux; aux1++) //estrutura de repeticao que vasculhara o vetor para encontrar um elemento que seja igual a x e mostrara sua posicao
	{
		if (procura == vetor[aux1])
			cout << "Corredor " << aux1 << endl;
		if(procura != vetor[aux1])
			aux2++;
	}

	if(aux1 == aux2)
		cout  << "Nao localizado" << endl;

	return 0;
}
