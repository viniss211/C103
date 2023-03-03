#include <iostream>

using namespace std;

// função para retornar o resto da chave em relacao a tabela
int h1(int k, int m)
{
	int res;

	res = k % m;

	if(res < 0)
		res += m;

	return res;
}

// auxiliar para o double hashing
int h2(int k, int m)
{
	int res;

    res = 1 + (k % (m - 1));

	if(res < 0)
		res += m;

	return res;
}

// double hashing
int dhash(int k, int m, int i)
{
	return ((h1(k, m) + i * h2(k, m)) % m);
}

int main()
{
	int k; // chave
	int m; // tamanho da tabela
	
	cin >> k >> m;
	
	// loop para chamar a funcao e retornar a posicao na tabela em todas as posicoes de i
	for(int i = 0; i < m; i++)
	{
		if(i - 1 == m)
			cout << dhash(k, m, i) << endl;
		else
			cout << dhash(k, m, i) << " ";
	}

	return 0;
}