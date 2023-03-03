#include <iostream>
using namespace std;


int main() //ponteiro aponta para o endereço de uma variavel e vc pode fzr o *ponteiro ter o msm valor q tem no endereço
{
	float vetor[5];
	int i; //contador
	float *p = NULL; //ponteiro aux
	int N;
	float cont =0;
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
		cont += *p;
		p++;
	}
	cout << cont/N << endl;
	return 0;
}
