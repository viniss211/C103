#include <iostream>
using namespace std;

int main() //ponteiro aponta para o endere�o de uma variavel e vc pode fzr o *ponteiro ter o msm valor q tem no endere�o
{
	int a; //uma vari�vel int
	int *b = NULL; //um ponteiro pra int / uma boa pr�tica � iniciar o ponteiro iniciar com NULL
	//o NULL evita apontar pra lugares indesejados

	a = 2;
	b = &a; //b recebe o endere�o de
	*b = 3; //o valor que est� no endere�o que b aponta recebe 3
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "b = " << *b << endl; //vai la e mostra o q tem nesse endere�o

	return 0;
}
