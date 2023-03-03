#include <iostream>
#include <list>//biblioteca para o uso de lista
using namespace std; //insere e mostra elementos de uma fila

int main()
{
	list<int>fila1; //ponteiro para a lista ligada 1
	list<int>fila2; //ponteiro para a lista ligada 2
	list<int>fila3; //ponteiro para a lista ligada 3
	list <int> :: iterator p1; //usaremos para percorrer a lista 1
	list <int> :: iterator p2; //usaremos para percorrer a lista 2
	list <int> :: iterator p3; //usaremos para percorrer a lista 3
	int x; //variavel auxiliar para a inserção de elementos na lista

	cin >> x;
	while (x != 0)//estrutura para entrada da fila 1
	{
		fila1.push_back(x);
		cin >> x;
	}

	cin >> x;
	while (x != 0) //estrutura para entrada da fila 2
	{
		fila2.push_back(x);
		cin >> x;
	}



	for (p1 = fila1.begin(), p2 = fila2.begin(); p1 != fila1.end(), p2 != fila2.end(); )
	{
		if (*p1 == *p2)
		{
			if (p1!=fila1.end() && p2!=fila2.end() )
			{
				fila3.push_back(*p1);
				p2++;
				p1++;
			}
		}
		if (*p1 > *p2)
		{
			if (p2!=fila2.end())
			{
				fila3.push_back(*p2);
				p2++;
			}
		}
		if (*p1 < *p2)
		{
			if (p1!=fila1.end())
			{
				fila3.push_back(*p1);
				p1++;
			}
		}

	}

	for (p3 = fila3.begin(); p3 != fila3.end(); p3++) //estrutura para mostra todos elementos da lista 3
		cout << *p3 << endl;


	while(!fila1.empty()) //NAO ESQUECER DISSO
		fila1.pop_front(); //remove o primeiro elemento da fila

	while(!fila2.empty()) //NAO ESQUECER DISSO
		fila2.pop_front(); //remove o primeiro elemento da fila

	while(!fila3.empty()) //NAO ESQUECER DISSO
		fila3.pop_front(); //remove o primeiro elemento da fila
	return 0;
}
