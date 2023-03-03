#include <iostream>
#include <list>//biblioteca para o uso de lista
using namespace std; //insere e mostra elementos de uma fila

bool encontrar(list<int> lista, int x)
{
	list <int> :: iterator p; //usaremos para mostra a lista
	for (p = lista.begin(); p != lista.end(); p++)
	{
		if (x == *p)
			return true;
	}
	return false;

}

int main()
{
	list<int>fila; //ponteiro para a lista ligada
	list <int> :: iterator p; //usaremos para percorrer a lista
	int x; //variavel auxiliar para a inserção de elementos na lista
	int key;//chave a ser procurada

	cin >> x;
	while (x != 0)
	{
		fila.push_back(x);
		cin >> x;
	}

	cin >> key;
	if (encontrar(fila, key))
		cout << "Encontrado" << endl;
	else
	{
		cout << "Nao Encontrado" << endl;
	}
	while(!fila.empty()) //NAO ESQUECER DISSO
		fila.pop_front(); //remove o primeiro elementoda fila
	return 0;
}
