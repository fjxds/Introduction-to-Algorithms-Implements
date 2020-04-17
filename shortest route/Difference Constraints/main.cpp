#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct edgeNode
{
	int begin;
	int end;
	int weight;
	edgeNode *next;
	edgeNode(int b,int e,int w,edgeNode *n=NULL)
	{
		begin=b;
		end=e;
		weight=w;
		next=n;
	}
};
struct verNode
{
	int val;
	edgeNode *root;
	verNode(int v,edgeNode *r=NULL)
	{
		val=v;
		root=r;
	}
};
vector<verNode> v;
int *dis;

bool bellmanFord(int n)
{
	for (int i=1;i<n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			edgeNode *tmp=v[j].root;
			while (tmp)
			{
				//cout<<tmp->begin<<"->"<<tmp->end<<": "<<tmp->weight<<endl;
				if (dis[tmp->begin]!=INT_MAX&&dis[tmp->begin]+tmp->weight<dis[tmp->end])
				{
					dis[tmp->end]=dis[tmp->begin]+tmp->weight;
				}
				tmp=tmp->next;
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		edgeNode *tmp=v[i].root;
		while (tmp)
		{
			if (dis[tmp->begin]!=INT_MAX&&dis[tmp->begin]+tmp->weight<dis[tmp->end])
			return false;
			tmp=tmp->next;
		}
	}
	return true;
}

int main(int argc, char** argv) {
	freopen("input.in","r",stdin);
	int n,m,b,e,w;
	cin>>n>>m;
	dis=new int[n+1];
	for (int i=0;i<=n;i++)
	{
		dis[i]=INT_MAX;
		v.push_back(verNode(i));
		if (i!=0)
		v[0].root=new edgeNode(0,i,0,v[0].root);
	}
	dis[1]=0;
	for (int i=0;i<m;i++)
	{
		cin>>b>>e>>w;
		v[b].root=new edgeNode(b,e,w,v[b].root);
	}
	bool flag=bellmanFord(n);
	if (flag)
	{
		for (int i=1;i<=n;i++)
		cout<<dis[i]<<" ";
	}
	cout<<endl;
	return 0;
}
