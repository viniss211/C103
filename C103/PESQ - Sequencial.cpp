#include <iostream>
using namespace std;

int main()
{
	int vetor[100]; //vetor de dados
	int x;//elemento a ser procurado
	int aux = 0; //auxiliar
	int aux1; //auxiliar que guadara tamannho do vetor
	int aux2 = 0; //auxiliar para caso x nao seja encontrado

	cout << "elementos do vetor:" << endl;
	cin >> vetor[aux];

	while(vetor[aux] != -1) //estrutura de repeticao para entrada dos elementos do vetor
	{
		aux++;
		cin >> vetor[aux];
	}

	cin >> x; //entrada de x

	for(aux1 = 0; aux1 < aux; aux1++) //estrutura de repeticao que vasculhara o vetor para encontrar um elemento que seja igual a x e mostrara sua posicao
	{
		if (x == vetor[aux1])
			cout << x << " encontrado na posicao " << aux1 << endl;
		if(x != vetor[aux1])
			aux2++;
	}
	
	if(aux1 == aux2)
		cout << x << " nao encontrado" << endl;

	return 0;
}