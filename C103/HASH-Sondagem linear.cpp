#include <iostream>
using namespace std;

int hash_aux(int k, int m)
{
	int res;
	res = k % m;

	if (res < 0)
		res += m;
	return res;

}

//fazendo a sondagem linear
int hash1(int k, int i, int m)
{
	int res = 0;

	res = (hash_aux(k , m)+i)%m; //!!!!!!!!!!!!!!!
	return res;
}



int main() //hash é uma ferramenta de busca
{
	int m ; 
	int i = 0;//número de tentativas
	int k;//
	
	cin >> k;
	cin >> m;
	//executando sondagem linear
	while (i<m) //está mostrando as posições que a função tentou guardar o elemento
	{
		if(i==m-1)
			cout<< hash1(k,i,m)<< endl;
		else
			cout<< hash1(k,i,m)<< " ";
		i++;
	}

	
	return 0;
}
