#include <iostream>
#include <list>//biblioteca para o uso de lista

using namespace std;
int main()
{
	list<int>fila; //ponteiro para a lista ligada
	list <int> :: iterator p; //ponteiro aux
	list<int>pilha; //ponteiro para a lista ligada
	int N;
	int i = 0; //var aux
	int caso;
	int x; //var auuxiliar para inserção
	cin >> N; //numero de operações

	for (i = 0; i < N; i++)
	{
		cin >> caso;
		switch(caso)
		{
		case 1:
			cin >> x;
			fila.push_back(x); //insere no inicio (topo da fila)

			break;
		case 2:
			p = fila.begin();
			pilha.push_front(*p);
			fila.pop_front(); //retira o elemento do fila
			break;
		}
	}
	cout << "Estoque: " << endl;
	for (p = fila.begin(); p != fila.end(); p++) //estrutura para mostra todos elementos da fila
		cout <<  *p << endl;
	cout << "Venda: " << endl;
	for (p = pilha.begin(); p != pilha.end(); p++) //estrutura para mostra todos elementos da pilha
		cout  << *p << endl;

		while(!pilha.empty())//NAO ESQUECER DISSO
		pilha.pop_front(); //remove o primeiro elementoda fila
		while(!fila.empty()) //NAO ESQUECER DISSO
		fila.pop_front(); //remove o primeiro elementoda fila
		return 0;
	}
