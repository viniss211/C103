#include <iostream>
#include <string.h>

using namespace std;
struct dados
{
	char nome [100];
	char curso[100];
};
int main()
{
	dados x[100]; //variavel x do tipos dados
	int vetor[100]; //vetor de id do aluno
	char procura[100];//id a ser procurado
	int aux = 0; //auxiliar
	int aux1; //auxiliar que guadara tamannho do vetor
	int aux2 = 0; //auxiliar para caso procura nao seja encontrado
	int n; //número de alunos
	bool achou=false;

	cin >> n; //entrada numero de alunos

	for (aux = 0; aux < n; aux++) //estrada do id dos alunos
	{
		cin.ignore();
		cin.getline(x[aux].nome, 100); //nome
		cin.getline(x[aux].curso, 100); //curso
		cin >> vetor[aux];

	}
	cin.ignore();
	cin.getline (procura, 100); //entrada da variavel procura que será usada para achar o nome do aluno

	for(aux1 = 0; aux1 < aux; aux1++) //estrutura de repeticao que vasculhara o vetor para encontrar o aluno
	{
		if (strcmp(x[aux1].nome, procura) == 0)
		{
			achou = true;
			cout << x[aux1].nome << endl;
			cout << x[aux1].curso << endl;
			cout << vetor[aux1] << endl;
			
		}
		if(strcmp(x[aux].nome, procura) != 0)
			aux2++;

	}
	if(achou==false)
		cout  << "Aluno nao localizado" << endl;


	return 0;
}
