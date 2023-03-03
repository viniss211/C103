#include <iostream>
using namespace std;
//a função maluca precisa fazer aql chamada por endereço sla alguma coisa assim pergunta dps
int maior (int *vetor, int N)
{
	int i;
	int maior = -99999;
	for (i = 0 ; i < N; i++)
	{
		if (*vetor > maior)
		{
			maior = *vetor;
		}
		vetor++;
	}
	return maior;
}
int main() //ponteiro aponta para o endereço de uma variavel e vc pode fzr o *ponteiro ter o msm valor q tem no endereço
{
	int vetor[5];
	int i; //contador
	int *p = NULL; //ponteiro aux
	int N;

	int elemento;
	cin >> N; //tamanho do vet

	for (i = 0 ; i < N; i++) //estrutura para inserir os elemento
	{
		cin >> elemento;
		vetor [i] = elemento;
	}
	p = vetor;
	cout << maior(p, N) << endl;
	
	
	
	return 0;
}

