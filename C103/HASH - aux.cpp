#include <iostream>
using namespace std;

int hash_aux(int k, int m) //hash aux que que procura uma posição na lista
{
	int res;
	res = k % m;

	if (res < 0)
		res += m;
	return res;

}

int main() //hash é uma ferramenta de busca
{
	int m ;
	int k;
	int res;
	cin >> k;
	cin >> m;
	while (k != 0 && m != 0) //estrutura para mostrar a pos que a hash aux tentou guardar
	{
		res = hash_aux(k, m);
		cout << res << endl;
		cin >> k;
		cin >> m;
	}



		return 0;
}
