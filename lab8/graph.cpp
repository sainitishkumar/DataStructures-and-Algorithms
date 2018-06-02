//#include "graph.h"
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
		void assign_weights(int p,int s);
		void dijkstra(int i);
};

void Graph :: assign_weights(int p,int s)
{
	
}

void Graph :: dijkstra(int i)
{
	int dist[vertices_count()];
	
}

int Graph :: vertices_count()
{
	return graph_size;
}

void Graph :: dfs(int x)
{
	flag[x] = true;
	cout<<x+1<<" ";
	list<int> B=adj(x);
	list<int>::iterator i;
	for(i = B.begin();i!=B.end();i++)
  	{
    	if(flag[*i] == false)   
    	{   
    		dfs(*i);   
    	}
  	}
  	return;
}

void Graph :: DFS(int i)
{
	for(int i=0;i<graph_size;i++)
    {
      flag[i]=false;
    }
    dfs(i-1);
}

list<int> Graph :: adj(int x)                              // finding the adjacent vertices of a vertex
{
	list<int> B;
   	for(int i=0;i<graph_size;i++)
   	{
		if(adjacency_matrix[i][x]->val==1)  
		{  
			B.push_front(i);  
		} 
   	}
  	return B;
}

void Graph :: remove_vertex(int i1)
{
	int i=graph_size,j=graph_size;
	int k,l;
	for(int tep1=0;tep1<i;tep1++)
	{
		for(int tep2=0;tep2<j;tep2++)
		{
			if(adjacency_matrix[tep1][tep2]->index == i1)
			{
				k=tep2;
				adjacency_matrix[tep1].erase(adjacency_matrix[tep1].begin()+tep2);
			}
		}
	}
	// for(int tep1=0;tep1<i;tep1++)
	// {

	// }
}

void Graph :: remove_edge(int i1,int i2)
{
	int i=graph_size,j=graph_size;
	int k,l;
	for(int tep1=0;tep1<i;tep1++)
	{
		for(int tep2=0;tep2<j;tep2++)
		{
			if(adjacency_matrix[tep1][tep2]->index == i1)
			{
				k=tep2;
			}
		}
	}
	for(int tep1=0;tep1<i;tep1++)
	{
		for(int tep2=0;tep2<j;tep2++)
		{
			if(adjacency_matrix[tep1][tep2]->index == i2)
			{
				l=tep2;
			}
		}
	}
	if(adjacency_matrix[k][l]->val == 1) 
	{
		adjacency_matrix[k][l]->val = 0;
		adjacency_matrix[l][k]->val = 0;
		tot_edges--;
	}
	else
	{
		cout << "no edge";
	}
}

bool Graph :: is_connected(int i1,int i2)
{
	int i=graph_size,j=graph_size;
	int k,l;
	for(int tep1=0;tep1<i;tep1++)
	{
		for(int tep2=0;tep2<j;tep2++)
		{
			if(adjacency_matrix[tep1][tep2]->index == i1)
			{
				k=tep2;
			}
		}
	}
	for(int tep1=0;tep1<i;tep1++)
	{
		for(int tep2=0;tep2<j;tep2++)
		{
			if(adjacency_matrix[tep1][tep2]->index == i2)
			{
				l=tep2;
			}
		}
	}
	if(adjacency_matrix[k][l]->val!=1) return false;
	return true;
}

bool Graph :: isfull()
{
	if(tot_edges == graph_size*(graph_size-1)) 
	{
		return true;
	}
	return false;
}

void Graph :: neighbours(int qwe)
{
	int i=graph_size,j=graph_size,k;
	for(int tep1=0;tep1<i;tep1++)
    {
        for(int tep2=0;tep2<j;tep2++)
        {
                if(adjacency_matrix[tep1][tep2]->index == qwe)
                {
                        k=tep2;
                }
        }
    }
	for(int l=0;l<i;l++)
	{
		//cout<<adjacency_matrix[k][l]->index<<" ";
		if(adjacency_matrix[k][l]->val==1) cout<<adjacency_matrix[k][l]->index<<" ";
	}
	cout<<endl;
}

void Graph :: add_edge(int i1,int i2)
{
	int i=graph_size,j=graph_size;
	int k,l;
	for(int tep1=0;tep1<i;tep1++)
	{
		for(int tep2=0;tep2<j;tep2++)
		{
			if(adjacency_matrix[tep1][tep2]->index == i1)
			{
				k=tep2;
			}
		}
	}
	for(int tep1=0;tep1<i;tep1++)
	{
		for(int tep2=0;tep2<j;tep2++)
		{
			if(adjacency_matrix[tep1][tep2]->index == i2)
			{
				l=tep2;
			}
		}
	}
	if(adjacency_matrix[k][l]->val!=1)
	{
		adjacency_matrix[k][l]->val=1;
		adjacency_matrix[l][k]->val=1;
		tot_edges++;
	}
}

void Graph :: add_vertex(int index)
{
	vector<node* > temp_vec;
	for (int i = 0; i <= graph_size; i++)
	{		
		temp_vec.push_back(NULL);
	}
	adjacency_matrix.push_back(temp_vec);
	for (int i = 0; i <= graph_size; i++)
	{
		adjacency_matrix[i].push_back(NULL);
	}
	for (int i = 0; i <= graph_size; i++)
	{
		adjacency_matrix[i][graph_size] = new node;
		adjacency_matrix[i][graph_size]->val = 0;
		adjacency_matrix[i][graph_size]->index = index;
	}
	for (int i = 0; i <= graph_size; i++)
	{
		adjacency_matrix[graph_size][i] = new node;
		adjacency_matrix[graph_size][i]->val = 0;
		adjacency_matrix[graph_size][i]->index = i+1;	
	}	
	graph_size++;
}

void Graph :: initialise(int* array,int i,int j)
{
	for(int tep1=0;tep1<i;tep1++)
	{
		for(int tep2=0;tep2<j;tep2++)
		{
			adjacency_matrix[tep1][tep2] = new node;
			adjacency_matrix[tep1][tep2]->val = *((array+tep1*j)+tep2);
			adjacency_matrix[tep1][tep2]->index = tep2+1;
			if(adjacency_matrix[tep1][tep2]->val == 1)
			{
				tot_edges++;
			}
		}
	}
}

void Graph :: print(int i,int j)
{
	for(int tep1=0;tep1<i;tep1++)
	{
		for(int tep2=0;tep2<j;tep2++)
		{
			cout << adjacency_matrix[tep1][tep2]->val<<" ";
		}
		cout<<"\n";
	}
	// for(int tep1=0;tep1<i;tep1++)
	// {
	// 	for(int tep2=0;tep2<j;tep2++)
	// 	{
	// 		cout << adjacency_matrix[tep1][tep2]->index<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	//cout<<tot_edges;
}

int main()
{
	Graph g(4);
	int arr[][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	g.initialise((int*)arr,4,4);
	g.add_vertex(5);
	g.add_vertex(6);
	g.add_edge(5,2);
	g.add_edge(5,3);
	g.add_edge(5,4);
	g.add_edge(4,1);
	//g.neighbours(5);
	g.DFS(1);
	cout<<endl;
	//g.print(6,6);

}