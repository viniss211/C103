#include <iostream>
using namespace std;
struct dado
{
	int k; // chave
	int status; // 0:vazio, 1:ocupado , 2:removido
};
int hash_aux(int k, int m)
{
	int res;
	res = k % m;

	if (res < 0)
		res += m;
	return res;

}
//fazendo a sondagem linear
int hash1(int k, int i, int m)
{
	int res = 0;

	res = hash_aux(k + i, m);
	return res;
}


int hash_insert(dado t[], int m, int k)
{

	int j = 0;
	int i = 0;
	do
	{
		j = hash1(k, i, m);
		if(t[j].status != 1)
		{
			t[j].k = k;
			t[j].status = 1;
			return j;
		}
		else
		{
			i += 1;
		}
	}
	while(i != m);
	return -1;
}
int hash_search(dado t[], int m, int k) //hash search pra procurar um elemento na tabela
{
	int i = 0;
	int j;
	do
	{
		j = hash1(k, i, m);
		if (t[j].k == k)
			return j; //retorna a posição
		else
			i += 1;
	}
	while (t[j].status != 0 && i < m);
	return -1;

}
int hash_remove(dado t[], int m, int k) //função que removerá um elemento da tabela hash
{

	int j;
	j = hash_search(t, m, k);
	if (j != -1)
	{
		t[j].status = 2;
		t[j].k = -1;
		return 0 ; //conseguiu remover
	}
	else
		return -1; //k não está na tabela
}
int main()
{
	dado tabela[11]; // tabela hash
	int m; // tamanho da tabela
	int i; // contador
	int k; // var aux para ler os dados da tabela
	int key; //chave a ser procurada
	// Lendo o tamanho da tabela
	cin >> m;

	// Inicializando a tabela
	for(i = 0; i < m; i++)
	{
		tabela[i].k = -1;
		tabela[i].status = 0;
	}

	// Lendo e inserindo dados na tabela
	cin >> k;
	while(k != 0)
	{
		hash_insert(tabela, m, k);
		cin >> k;
	}

	cin >> key; //entrada da chave a ser removida

	hash_remove(tabela, m, key);

	for (i = 0; i < m; i++)
	{
		cout << tabela[i].k << endl;
	}

	return 0;
}
