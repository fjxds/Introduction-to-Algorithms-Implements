#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

struct edgeNode
{
	int begin;
	int end;
	int weight;
	edgeNode *next;
	edgeNode(int b, int e, int w,edgeNode *n=NULL)
	{
		begin=b;
		end=e;
		next=n;
		weight=w;
	}
};
struct verNode
{
	int val;
	edgeNode *root;
	verNode(int v, edgeNode *r=NULL)
	{
		val=v;
		root=r;
	}
};
vector<verNode> v;
vector<edgeNode> E;
int *u;
bool cmp(edgeNode a, edgeNode b)
{
	return a.weight<b.weight;
}
int find(int n)
{
	if (u[n]<0)
	return n;
	else
	return u[n]=find(u[n]);
}
void merge(int a,int b)
{
	int x=find(a);
	int y=find(b);
	if (u[x]<u[y])
	{
		u[x]+=u[y];
		u[y]=x;
	}
	else
	{
		u[y]+=u[x];
		u[x]=y;
	}
}

int main(int argc, char** argv) {
	freopen("input.in","r",stdin);
	int n,m,b,e,w;
	vector<edgeNode> res;
	cin>>n>>m;
	u=new int[n];
	for (int i=0;i<n;i++)
	{
		v.push_back(verNode(i));
		u[i]=-1;
	}
	for (int i=0;i<m;i++)
	{
		cin>>b>>e>>w;
		v[b].root=new edgeNode(b,e,w,v[b].root);
		v[e].root=new edgeNode(e,b,w,v[e].root);
		E.push_back(edgeNode(b,e,w));
		E.push_back(edgeNode(e,b,w));
	}
	sort(E.begin(),E.end(),cmp);
	int sum=0;
	int count=0;
	for (int i=0;i<E.size();i++)
	{
		b=E[i].begin;
		e=E[i].end;
		if (find(b)!=find(e))
		{
			res.push_back(E[i]);
			sum+=E[i].weight;
			count++;
			merge(b,e);
		}
	}
	for (int i=0;i<res.size();i++)
	{
		cout<<res[i].begin<<"->"<<res[i].end<<": "<<res[i].weight<<endl;
	}
	cout<<sum<<endl;
	return 0;
}
