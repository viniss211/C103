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
//fazendo a sondagem quadratica
int hash2(int k, int i, int m,int c1,int c2)
{
	int res = 0;

	res = (hash_aux(k , m)+c1*i+c2*(i*i))%m;
	return res;
}

int main() //hash é uma ferramenta de busca
{
	int m ; 
	int i = 0;//número de tentativas
	int k;//
	int c1,c2; //constantes 1 e 2
	cin >> k;
	cin >> m;
	cin>> c1;
	cin >> c2;
	//executando sondagem quadratica
	while (i<m) //está mostrando as posições que a função tentou guardar o elemento
	{
		if(i-1==m)
			cout<< hash2(k,i,m,c1,c2)<< endl;
		else
			cout<< hash2(k,i,m,c1,c2)<< " ";
		i++;
	}

	
	return 0;
}
