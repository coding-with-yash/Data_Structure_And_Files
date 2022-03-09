#include<iostream>
int visited[10];
using namespace std;

class graph
{
	int i,j,min,u,v,mincost,cost[10][10],edge,a,b,n;
    public:
	graph()	
	{
		edge=1;
		mincost=0;
	}
	 void kruskal(int cost[10][10],int n);
	 void read();
};


void graph::read()
{
	cout<<"Enter the vertex:";
	cin>>n;

	cout<<"Enter the Weight of edge: \n";

	for(i=1;i<=n;i++)
	{
			for(j=1; j<=n;j++)
			{
				cin>>cost[i][j];
				if(cost[i][j]==0)
				{
					cost[i][j]=9999;			
				}
			}
		
	}
   kruskal(cost,n);
}

void graph::kruskal(int cost[10][10],int n)
{
	while(edge<n)
	{
	  min=9999;
	
	for(i=1;i<=n;i++)
	{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min)
				{
					min=cost[i][j];
					a=u=i;		
				        b=v=j;
				}		
			}
	}
	
	
	while(visited[u])
		u=visited[u];
	
	while(visited[v])
		v=visited[v];

		if(u!=v)
		{
			edge++;
			cout<<"\n Edge: "<<a<<"->"<<b<<"\t Weight: "<<min<<"\n";
			mincost=mincost+min;
			visited[v]=u;
		}
		cost[a][b]=cost[b][a]=9999;
	}
	cout<<"\n Graph Minimum Cost: "<<mincost<<"\n";
}


int main()
{
	graph g;
	g.read();

return 0;
}
