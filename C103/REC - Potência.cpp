#include <iostream>
using namespace std;

int pot (int a, int n) //função recursiva que chama a si  mesma para calcular a potência
{
	if (n == 0)
		return 1;
	else if (n > 0)
		return a * pot (a, n - 1);
}

int main()
{
	int a , n;
	int p ; //potência
	cin >> a >> n;

	p = pot (a, n);

	cout << p << endl;
	return 0;
}
