#include<iostream>
#include<vector>
#include<list>
using namespace std;

struct node
{
	int index;
	int val;
};

class Graph
{
	private:
		struct node* n;
		struct node* temp;
		int tot_vertices;
		int tot_edges;
		int graph_size;
		vector<vector<node* > > adjacency_matrix;
		bool *flag;
	public:
		Graph(int size)
		{
			flag = new bool[size];
			graph_size = size;
			n=temp=NULL;
			tot_edges=tot_vertices=0;
			vector<node* > temp_vec;
			for (int i = 0; i < size; i++)
			{		
				temp_vec.push_back(NULL);
			}
			for (int i = 0; i < size; i++)
			{
				adjacency_matrix.push_back(temp_vec);
			}
		}
		bool isfull();
		void initialise(int* array,int i,int j);
		void add_vertex(int index);
		void print(int i,int j);
		void add_edge(int i1,int i2); 
		void neighbours(int i);
		bool is_connected(int i1,int i2);
		void remove_edge(int i1,int i2);
		void remove_vertex(int i);
		list<int> adj(int x);
		void dfs(int i);
		void DFS(int i);
		int vertices_count();
};