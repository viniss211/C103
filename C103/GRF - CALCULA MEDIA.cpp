#include <iostream>
#include <list>//biblioteca para o uso de lista
#include <iomanip>
using namespace std; //insere e mostra elementos de uma fila

float calcMedia(list<int> lista) //soma os elementos de uma lista
{
	int soma = 0;
	int cont = 0;//contador auxiliar
	list <int> :: iterator p; //usaremos para mostra a lista
	for (p = lista.begin(); p != lista.end(); p++)
	{
		soma += *p;
		cont++;
	}
	return soma / cont;

}



int main()
{
	list<int>fila; //ponteiro para a lista ligada
	list <int> :: iterator p; //usaremos para percorrer a lista
	int x; //variavel auxiliar para a inserção de elementos na lista
	cout << fixed << setprecision(2);
	cin >> x;
	while (x != 0)
	{
		fila.push_back(x);
		cin >> x;
	}

	cout << calcMedia(fila) << endl;
	while(!fila.empty()) //NAO ESQUECER DISSO
		fila.pop_front(); //remove o primeiro elementoda fila
	return 0;
}
