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
	for (int i=0;i<n-1;i++)
	{
		for (int j=0;j<n;j++)
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
	for (int i=0;i<n;i++)
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
	int n,m,b,e,w;
	cin>>n>>m;
	dis=new int[n];
	for (int i=0;i<n;i++)
	{
		v.push_back(verNode(i));
		dis[i]=INT_MAX;
	}
	for (int i=0;i<m;i++)
	{
		cin>>b>>e>>w;
		v[b].root=new edgeNode(b,e,w,v[b].root);
	}
	dis[0]=0;
	bool flag=bellmanFord(n);
	if (flag==true)
	{
		for (int i=0;i<n;i++)
		cout<<dis[i]<<" ";
		cout<<endl;
	}
	
	return 0;
}
