#include <iostream>
#include <list>
using namespace std;
struct no
{
	int v;//destino (vertice adjacente)
	int p;//peso da aresta

};
void cria_aresta(list<no>adj[], int u, int v, int orientado)
{


	no aux;//var aux p/ armazenar as arestas em adj (adjacencia)

	aux.v = v;

	adj[u].push_back(aux);
	//verifica se é orientado ou não

	if (orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}

}

void bfs(list<no>adj[], int nVertices, int s)
{
	list <no>::iterator p;
	int v;
	list <int> Q;
	int pai[10];
	int u;
	int cont=0; //contador para ver se é conexo ou não
	char state [10];
	for (u = 0 ; u < nVertices; u++)
	{
		if ( u != s)
		{
			state[u] = 'u'; //undicovered
			pai[u] = -1; //sem pais
		}
	}
	state[s] = 'd'; //discovered
	pai[s] = -1;
	Q.push_back(s);

	while(!Q.empty())
	{
		u = *Q.begin();
		cont++;
		Q.pop_front();
		
		for (p = adj[u].begin(); p != adj[u].end(); p++)
		{
			v = p->v;
			
			if (state[v] == 'u')
			{
				state[v] = 'd';
				pai[v] = u;
				Q.push_back(v);
			}

		}
		state[u] = 'p';
	}
	if (nVertices==cont){
		cout << "Conexo" <<endl;
	}
	else
		cout << "Nao Conexo" <<endl;
}

int main() //introdução grafo
{
	list<no> adj[10];//lista de adjacencia do grafo
	int u; //origem da aresta
	int v; //destino da aresta
	int nVertices; //numero de vertices dografo
	list<no>:: iterator q; //iterador para andar na lista
	int vOrigem;

	cin >> nVertices >> vOrigem; //entrada do numero de vertices e vértice de origem

	cin >> u >> v;
	while(u != -1 && v != -1)
	{
		cria_aresta(adj, u, v,0);
		cin >> u >> v;
	}
	
	bfs(adj, nVertices, vOrigem);
	

	return 0 ;
}
