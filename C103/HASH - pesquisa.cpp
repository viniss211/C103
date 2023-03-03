#include <iostream>
using namespace std;
struct dado
{
	int k; // chave
	int status; // 0:vazio, 1:ocupado
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

	cin >> key; //entrada da chave a ser procurada
	int pos; //variavel que guarda posição
	
	pos = hash_search(tabela, m, key); //a partir daqui key guardará a posição que a chave está e gkey terá o elemento daquela posição
	if (pos == -1)
		cout << "Chave " << key << " nao encontrada" << endl;
	else
		cout << "Chave " << key << " encontrada na posicao " << pos << endl;




	return 0;
}
