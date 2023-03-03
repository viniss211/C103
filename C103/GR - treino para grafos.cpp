#include <iostream>
#include <list>
using namespace std;

struct no
{
	int v;//destino
	int p;//peso
};

int main() //introdu��o grafo
{
	list<no> adj[10];//lista de adjacencia do grafo
	int u; //origem da aresta
	int v; //destino da aresta
	int p;//peso da aresta
	no aux;//var aux p/ armazenar as arestas em adj (adjacencia)
	int nVertices = 4; //numero de vertices dografo
	int i; //contador
	list<no>:: iterator q; //iterador para andar na lista
	int orientado=0; //variavel pra ver se � orientado ou n�o ( 1 : orientado , 0 : nao orientado)
	//GRAFO ORIENTADO � O QUE N�O VOLTA E O N�O ORIENTADO ELE VAI E VOLTA
	u = 0; //origem
	v = 1; //destino
	p = 2; //peso
	aux.v = v;
	aux.p = p;
	adj[u].push_back(aux);
	//verifica se � orientado ou n�o
	if (orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}

	u = 0; //origem
	v = 3; //destino
	p = 7; //peso
	aux.v = v;
	aux.p = p;
	adj[u].push_back(aux);
	//verifica se � orientado ou n�o
	if (orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}
	u = 1; //origem
	v = 2; //destino
	p = 5; //peso
	aux.v = v;
	aux.p = p;
	adj[u].push_back(aux);
	//verifica se � orientado ou n�o
	if (orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}

	u = 1; //origem
	v = 3; //destino
	p = 1; //peso
	aux.v = v;
	aux.p = p;
	adj[u].push_back(aux);
	//verifica se � orientado ou n�o
	if (orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}

	//n�o coloca denovo o 1 pro 0 pq ja fez

	u = 2; //origem
	v = 3; //destino
	p = 4; //peso
	aux.v = v;
	aux.p = p;
	adj[u].push_back(aux);
	//verifica se � orientado ou n�o
	if (orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}

	//n�o coloca denovo o 3 pro resto pq ja fez

	//mostrando a lista de adjacencia
	for (i = 0; i < nVertices; i++)
		for ( q = adj[i].begin(); q != adj[i].end(); q++)
		{
			cout << "origens: " << i;
			cout << " destino: " << q->v;
			cout << " peso: " << q ->p << endl;
		}
	return 0;
}
