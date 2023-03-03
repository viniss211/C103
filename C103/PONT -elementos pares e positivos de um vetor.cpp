#include <iostream>
using namespace std;
//a função maluca precisa fazer aql chamada por endereço sla alguma coisa assim pergunta dps

int main() //ponteiro aponta para o endereço de uma variavel e vc pode fzr o *ponteiro ter o msm valor q tem no endereço
{
	int vetor[100];
	int i; //contador
	int *p = NULL; //ponteiro aux
	int N;
	int elemento;
	int cont = 0;
	cin >> N; //tamanho do vet

	for (i = 0 ; i < N; i++) //estrutura para inserir os elemento
	{
		cin >> elemento;
		vetor [i] = elemento;
	}
	p = vetor;
	for (i = 0 ; i < N; i++)
	{
		if (*p > 0 && *p % 2 == 0)
		{
			cont ++;
		}
		p++;
	}
	cout << cont << endl;
	return 0;
}
