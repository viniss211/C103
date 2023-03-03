#include <iostream>
#include <list>//biblioteca para o uso de lista
using namespace std; //insere e mostra elementos de uma pilha
int main()
{
	list<int>pilha; //ponteiro para a lista ligada
	list <int> :: iterator p; //usaremos para mostra a lista
	int x;
	cin >> x;
	pilha.push_front(x); //insere no inicio (topo da pilha)
	cin >> x;
	pilha.push_front(x); //insere no inicio (topo da pilha)
	cin >> x;
	pilha.push_front(x); //insere no inicio (topo da pilha)
	cin >> x;
	pilha.push_front(x); //insere no inicio (topo da pilha)




	for (p = pilha.begin(); p != pilha.end(); p++) //estrutura para mostra todos elementos da lista
		cout << *p << endl;

	while(!pilha.empty())//NAO ESQUECER DISSO
		pilha.pop_front(); //remove o primeiro elementoda fila
	return 0;
}
