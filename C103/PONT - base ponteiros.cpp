#include <iostream>
using namespace std;

int main() //ponteiro aponta para o endereço de uma variavel e vc pode fzr o *ponteiro ter o msm valor q tem no endereço
{
	int a; //uma variável int
	int *b = NULL; //um ponteiro pra int / uma boa prática é iniciar o ponteiro iniciar com NULL
	//o NULL evita apontar pra lugares indesejados

	a = 2;
	b = &a; //b recebe o endereço de
	*b = 3; //o valor que está no endereço que b aponta recebe 3
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "b = " << *b << endl; //vai la e mostra o q tem nesse endereço

	return 0;
}
