#include <iostream>
#include <list>
#include <climits>  //biblioteca para usar o valor máximo (INT_max)
using namespace std;

struct no  //struct que axilia a guardar os vertices do grafo
{
	int v; // vertice adjacente
	int peso; // peso da aresta
};

void cria_aresta(list<no>adj[], int u, int v, int p, int orientado)
{
	//função responsável por determinar as arestas do grafo
	//declaração de variáveis
	no aux;  //var aux

	//criando as arestas
	aux.peso = p;
	aux.v = v;
	adj[u].push_back(aux);  //criação das fila
	if(orientado == 0)  //não orientado
	{
		//fazendo a volta do vetor
		aux.v = u;
		adj[v].push_back(aux);
	}
}

void dijkstra(list<no>adj[], int nVertices, int start, int end)
{
	/*
	-> FUNÇÃO RESPONSÁVEL POR DEFINIR O MENOR CAMINHO ENTRE DOIS VERTICES A PARTIR
	DAS INFORMAÇÕES DADAS (pesos das arestas e se são orientadas ou não)
	-> TAMBÉM DEFINE O CUSTO DO CAMINHO PERCORRIDO (sendo assim, o caminho que ele definir
	terá o menor custo entre dois vertices)
	*/
	bool intree[50];  //dirá se o vertice já foi ou não adicionado na arvore geradora minima
	int u;  //var aux
	int distance[50];  //vetor que guarda a distância de um vertice a outro
	int parent[50];  //pai - de onde um vetor se origina ao ser descoberto
	/* quando o pai for igual a -1 para determinado vertice quer dizer
	que o mesmo não possui um pai, ou seja, o vertice ainda não foi
	descoberto e por isso não possui "origem"*/
	int v;  //var aux
	int destino;  //var aux para avaliar o destino
	int weight;  //var auxiliar para avaliar o peso
	int dist;  //var aux para ajudar a encontrar
	list<no> :: iterator p;  /*interator auxiliar para varrer a lista de adjacência
							 de um vertice*/
 	list<int> caminho;  //fila auxiliar para mostrar o menor caminho

	//inicialização inicial do código
	for(u = 0; u < nVertices; u++)
	{
		intree[u] = false;  //nenhum vertice adicionado na arvore minima
		distance[u] = INT_MAX;  //distância de todos como infinito até descobrir uma distância ideal0
		parent[u] = -1;  //marcando os vertices como sem origem
	}
	distance[start] = 0;  //distância do vertice inicial como 0
	v = start;  //definir um vertice parâmetro

	//aqui começa a varrer as arrestas em busca de um caminho com o menor custo
	while(intree[v] == false)
	{
		intree[v] = true;  //vertice parâmetro adicionado na lista
		for(p = adj[v].begin(); p != adj[v].end(); p++)
		{
			destino = p->v;
			weight = p->peso;
			if(distance[destino] > distance[v] + weight)
			{
				/*caso seja percebido um caminho e o vertice ainda não foi adicionado
				na lista como um caminho alternativo (menor) ele é adicinado agora*/
				distance[destino] = distance[v] + weight;
				parent[destino] = v;
			}
		}
		v = 0;
		dist = INT_MAX;  //definição de distância parâmetro
		for(u = 0; u < nVertices; u++)
		{
			if(intree[u] == false && dist > distance[u])
			{
				dist = distance[u];  //distância mais curta encontrada
				v = u;  //redefinição do vertice parâmetro
			}
		}
	}
	
	/*aqui ocorre a varredura dos vertices para fazer a determinação do menor
	caminho percorrido*/
	caminho.push_front(end);  //criando uma fila com inicio no vertice de destino
    u = parent[end];
	while(u != start)  //o while para quando o caminho chegar no vertice de incio
	{
		caminho.push_front(u);
		u = parent[u];
	}
	caminho.push_front(u);
	
	//saida do menor caminho entre os vertices start e end
	cout << "Menor caminho: ";
	while(!caminho.empty())  //varrendo a lista auxiliar
	{
		u = *caminho.begin();
		cout << u << " ";  //saida do vertice do caminho
		caminho.pop_front();  //"limpando" a lista
	}
	cout << endl;
	
	//saida do menor custo entre os vertices
	cout << "Custo: " << distance[end] << endl;
	/*distance[end] é o custo feito para chegar até o vertice de destino, sendo 
	esse o menor caminho, tem também o menor custo*/
}

int main()
{
	//declaração de variáveis
	int nVertices;  //quantidade de vertices do grafo
	int orientado;  // 0 -> não orientado	1 -> orientado
	int start;  //vertice inicial do caminho
	int u;  //vertice de origem da aresta
	int v;  //vertice de destino da aresta
	int p;  //peso da aresta
	int end;  //vertice de destino do caminho
	list<no> adj[20];  //lista de adjacência

	//entrada dos dados iniciais (Número de vertices, orientado, vertice inicial)
	cin >> nVertices >> orientado >> start >> end;

	//entrada do vertice de origem e destino e o peso de sua aresta
	cin >> u >> v >> p;
	while((u != -1) && (v != -1) && (p != -1))  //condição de parada de entrada de dados
	{
		//criação das arestas (função CRIA ARESTA)
		cria_aresta(adj, u, v, p, orientado);
		cin >> u >> v >> p;
	}

	//criação da arvores geradora minima (função PRIM)
	dijkstra(adj, nVertices, start, end);

	return 0;
}