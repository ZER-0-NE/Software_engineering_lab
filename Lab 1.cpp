#include<bits/stdc++.h>
using namespace std;

class graph{
	int V;
	vector<int>*adj;
	void printallpathsutil(int s,int d,bool visited[],int path[],int &path_index);
public:
    graph(int V);
	void addedge(int u,int v);
	void printallpaths(int s,int d);
	void printgraph();
	int pred();
	
		
};
graph::graph(int V)
{
	this->V=V;
	adj=new vector<int>[V];
}
void graph::addedge(int u,int v)
{
	adj[u].push_back(v);
}
void graph:: printgraph()
{
	vector<int>::iterator itr;
	for(int v=0;v<V;v++)
	{
		if(adj[v].size()==0){
			continue;
		}
		for(itr=adj[v].begin();itr!=adj[v].end();itr++){
			cout<<v<<"->"<<*itr;
			cout<<endl;
		}
		
	}
}
void graph::printallpaths(int s,int d)
{
	bool *visited=new bool[V];
	int *path=new int[V];
    int path_index=0;
	for(int i=0;i<V;i++){
		visited[i]=false;
	}
	printallpathsutil(s,d,visited,path,path_index);
}
int graph::pred()
{

	int predicatenode=0;
	for(int v=0;v<V;v++)
	{
		if(adj[v].size()>=2)
		{
			cout<<"predicate node:"<<v<<endl;
			predicatenode++;
		}
	}
   return predicatenode;
}

void graph:: printallpathsutil(int u,int d,bool visited[],int path[],int &path_index){
	visited[u]=true;
	path[path_index]=u;
	path_index++;
	if(u==d){
		cout<<"printing independent path:"<<endl;
		for(int i=0;i<path_index;i++)
		{
			cout<<path[i]<<" ";
		}
		cout<<endl;
	}
	else
	{
		vector<int>::iterator itr;
		for(itr = adj[u].begin();itr!=adj[u].end();itr++){
			if(!visited[*itr])
			{
				printallpathsutil(*itr,d,visited,path,path_index);
			}
		}
	}
	path_index--;
	visited[u]=false;
}
int main()
{
	int vertices,edges=0;
	cout<<"enter no of nodes:";
	cin>>vertices;
	graph g(vertices);
	while(true)
	{
		int u,v;
		cout<<"enter 1 to add n edge"<<endl;
		int n;
		cin>>n;
		if(n!=1)
		{
			break;
		}
		cout<<"enter the nodes to be connected"<<endl;
		cin>>u>>v;
		g.addedge(u,v);
		edges++;		
	}
	g.printgraph();
    int s,d;
    cin>>s>>d;
    g.printallpaths(s,d);
    cout<<"no of bounded regions:"<<edges-vertices+1<<endl;
int k = g.pred();

	cout<<"No .of predicate nodes:"<<k;
	return 0;
	
}
