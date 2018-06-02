#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
#include"graph.h"
using namespace std;

int main(int argc,char** argv)
{   
	ifstream f;	
	int i,j,n;
	n = atoi(argv[1]);                                             
	Graph g(n);        
	int arr[n][n];   
	f.open(argv[2]);
	for(i=0;i<n;i++)
    {
		for(j=0;j<n;j++)  
		{ 
			f>>arr[i][j]; 
		}
    }
    f.close();
    g.initialise((int*)arr,n,n);   
	g.add_vertex(4);
	g.add_vertex(5);
	g.add_edge(1,2);
	g.add_edge(1,3);
	g.add_edge(2,3);
	g.add_edge(1,5);
	g.add_edge(4,5);
	g.add_edge(4,2);
    //g.print(g.vertices_count(),g.vertices_count());                                                 
    g.DFS(4);   //DFS on vertex 4                                                    
}
