#include <iostream>
#include <list>//biblioteca para o uso de lista
using namespace std; //insere e mostra elementos de uma fila

int soma(list<int> lista) //soma os elementos de uma lista
{
	int soma = 0;
	list <int> :: iterator p; //usaremos para mostra a lista
	for (p = lista.begin(); p != lista.end(); p++)
	{
		soma += *p;
	}
	return soma;

}

int main()
{
	list<int>fila; //ponteiro para a lista ligada
	list <int> :: iterator p; //usaremos para percorrer a lista
	int x; //variavel auxiliar para a inserção de elementos na lista

	cin >> x;
	while (x != 0)
	{
		fila.push_back(x);
		cin >> x;
	}

	cout << soma(fila) << endl;
	while(!fila.empty()) //NAO ESQUECER DISSO
		fila.pop_front(); //remove o primeiro elementoda fila
	return 0;
}
