#include <iostream>
#include <list>//biblioteca para o uso de lista
using namespace std; //insere e mostra elementos de uma fila
int main()
{
	list<int>fila; //ponteiro para a lista ligada
	list <int> :: iterator p; //usaremos para mostra a lista
	int x;
	cin >> x;
	fila.push_back(x);
	cin >> x;
	fila.push_back(x);
	cin >> x;
	fila.push_back(x);
	cin >> x;
	fila.push_back(x);





	for (p = fila.begin(); p != fila.end(); p++) //estrutura para mostra todos elementos da lista
		cout << *p << endl;

	while(!fila.empty()) //NAO ESQUECER DISSO
		fila.pop_front(); //remove o primeiro elementoda fila
	return 0;
}
