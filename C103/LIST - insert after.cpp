#include <iostream>
#include <list>//biblioteca para o uso de lista
using namespace std; //insere e mostra elementos de uma fila


int main()
{
	list<int>pilha; //ponteiro para a lista ligada
	list <int> :: iterator p; //usaremos para percorrer a lista
	int n; //variavel auxiliar para a inserção de elementos na lista
	int x;
	int y;
	p = pilha.begin();
	cin >> n;
	while (n != -1)
	{
		pilha.push_front(n);
		cin >> n;
	}

	cin >> x;
	cin >> y;
	
	for (p = pilha.begin(); p != pilha.end(); p++)
		if (*p == x)
		{
			p++;
			pilha.insert (p, y);
		}
	
	for (p = pilha.begin(); p != pilha.end(); p++) //estrutura para mostra todos elementos da lista
		cout << *p << endl;

	while(!pilha.empty()) //NAO ESQUECER DISSO
		pilha.pop_front(); //remove o primeiro elemento da fila
	return 0;
}
