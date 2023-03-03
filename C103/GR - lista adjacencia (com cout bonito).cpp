#include <iostream>
#include <list>
using namespace std;
struct no
{
	int v;//destino (vertice adjacente)
	int p;//peso da aresta
};
void cria_aresta(list<no>adj[], int u, int v, int p, int orientado)
{


	no aux;//var aux p/ armazenar as arestas em adj (adjacencia)

	aux.v = v;
	aux.p = p;
	adj[u].push_back(aux);
	//verifica se é orientado ou não
	
	if (orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}
	
}

int main() //introdução grafo
{
	list<no> adj[10];//lista de adjacencia do grafo
	int u; //origem da aresta
	int v; //destino da aresta
	int p;//peso da aresta
	no aux;//var aux p/ armazenar as arestas em adj (adjacencia)
	int nVertices; //numero de vertices dografo
	int i; //contador
	list<no>:: iterator q; //iterador para andar na lista
	int orientado; //variavel pra ver se é orientado ou não ( 1 : orientado , 0 : nao orientado)

	cin >> nVertices >> orientado; //entrada do numero de vertices e se ele é orientado ou não

	cin >> u >> v >> p;
	while(u != -1 && v != -1 && p != -1)
	{
		cria_aresta(adj, u, v,  p, orientado);
		cin >> u >> v >> p;
		
	}
	
		for (i = 0; i < nVertices; i++)
		for ( q = adj[i].begin(); q != adj[i].end(); q++)
		{
			cout << "origens: " << i;
			cout << " destino: " << q->v;
			cout << " peso: " << q ->p << endl;
		}
	return 0 ;
}
