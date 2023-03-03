#include <iostream>
#include <cstring>
using namespace std;
int calcula_chave (char palavra[]) //função pega palavra e transforma em número
{
	int tamanho ; //comprimento da palavra
	int k = 0; //chave
	int i; //contador
	tamanho = strlen(palavra);
	for (i = 0; i < tamanho; i++)
		k += (int)palavra[i];
	return k ;
}
struct dado
{
	int k; // chave
	int status; // 0:vazio, 1:ocupado , 2:removido
	char info[50]; // informacao
};
int hash_aux(int k, int m)
{
	int res;
	res = k % m;

	if (res < 0)
		res += m;
	return res;

}
// auxiliar para o double hashing
int hash2(int k, int m)
{
	int res;

	res = 1 + k % (m - 1);

	if(res < 0)
		res += m;

	return res;
}
//fazendo a sondagem linear


// double hashing
int dhash(int k, int m, int i)
{
	return ((hash_aux(k, m) + i * hash2(k, m)) % m);
}
//DAQUI PRA CIMA TA TUDO DE BOA ,NÃO MEXER!!!!!!!!!!!!!!!!!!!!!!!!
int hash_insert(dado t[], int m, int k) //esta hash insert usa dhash no lugar de sondagem linear
{

	int j = 0;
	int i = 0;
	do
	{
		j = dhash( k,  m,  i); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
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
		j = dhash( k,  m, i);
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
		return j ; //conseguiu remover
	}
	else
		return -1; //k não está na tabela
}

int main()
{
	dado tabela[11]; // tabela hash
	char palavra[50];
	int m; // tamanho da tabela
	int i; // contador
	int caso; //variavel para ver os casos do switch
	int k; //chave a ser procurada
	int h; //guarda a posição da chave para guardar o nome na pos certa
	// Lendo o tamanho da tabela
	cin >> m;

	// Inicializando a tabela
	for(i = 0; i < m; i++)
	{
		strcpy(tabela[i].info , "vazio");
		tabela[i].k = -1;
		tabela[i].status = 0;
	}

	cin >> caso;

	while (caso != 5)
	{
		switch(caso)
		{
		case 1: //caso de inserção da palavra

			cin.ignore();

			cin.getline(palavra, 50); //insere a palavra
			k = calcula_chave(palavra);
			h = hash_insert(tabela, m, k);
			if (h != -1)
			{
				strcpy(tabela[h].info, palavra);
			}
			break;

		case 2: //caso de pesquisa de posição do elemento

			cin.ignore();
			cin.getline(palavra, 50); //insere a palavra
			int pos; //variavel que guarda posição
			k = calcula_chave(palavra);
			pos = hash_search(tabela, m, k);

			if (pos == -1)
				cout << palavra << " nao encontrado" << endl; //caso a chave não estiver na tabela, o retorno será -1
			else
				cout << palavra << " encontrado na posicao " << pos << endl; //posição que está o elemento que foi procurado

			break;

		case 3://caso de remoção de elemento

			cin.ignore();
			cin.getline(palavra, 50); //insere a palavra
			k = calcula_chave(palavra);
			h=hash_remove(tabela, m, k);
			if (h != -1)
			{
				strcpy(tabela[h].info, "vazio");
			}
			break;

		case 4: //caso mostra tabela

			for(i = 0; i < m; i++)// Mostrando a tabela
			{
				cout << tabela[i].info << " " ;
			}

			break;
		}

		cin >> caso;

	}



	return 0;
}
