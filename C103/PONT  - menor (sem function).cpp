#include <iostream>
using namespace std;
//a fun��o maluca precisa fazer aql chamada por endere�o sla alguma coisa assim pergunta dps

int main() //ponteiro aponta para o endere�o de uma variavel e vc pode fzr o *ponteiro ter o msm valor q tem no endere�o
{
	int vetor[5];
	int i; //contador
	int *p = NULL; //ponteiro aux
	int tam;
	int menor = 99999;
	int elemento;
	cin >> N; //tamanho do vet

	for (i = 0 ; i < N; i++) //estrutura para inserir os elemento
	{
		cin >> elemento;
		vetor [i] = elemento;
	}
	p = vetor;
	for (i = 0 ; i < N; i++)
	{
		if (*p < menor)
		{
			menor = *p;
		}
		p++;
	}
	cout << menor << endl;
	return 0;
}
