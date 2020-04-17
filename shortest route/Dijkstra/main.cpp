#include <iostream>
#include <vector>
#include <queue>
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
	int dis;
	edgeNode *root;
	verNode(int v,edgeNode *r=NULL)
	{
		val=v;
		dis=INT_MAX;
		root=r;
	}
};
vector<verNode> v;
int *dis;
struct cmp
{
	bool operator()(const verNode &a,const verNode &b) const
	{
		return a.dis>b.dis;
	}
};
int *flag;

int main(int argc, char** argv) {
	freopen("input.in","r",stdin);
	int n,m,b,e,w;
	cin>>n>>m;
	dis=new int[n];
	flag=new int[n];
	for (int i=0;i<n;i++)
	{
		v.push_back(verNode(i));
		flag[i]=0;
	}
	for (int i=0;i<m;i++)
	{
		cin>>b>>e>>w;
		v[b].root=new edgeNode(b,e,w,v[b].root);
	}
	v[0].dis=0;
	priority_queue<verNode,vector<verNode>,cmp> q;
	for (int i=0;i<n;i++)
	q.push(v[i]);
	for (int i=0;i<n;i++)
	{
		verNode tmp=q.top();
		q.pop();
		flag[tmp.val]=1;
		edgeNode *e=tmp.root;
		while (e)
		{
			if (v[e->begin].dis!=INT_MAX&&v[e->end].dis>v[e->begin].dis+e->weight)
			v[e->end].dis=v[e->begin].dis+e->weight;
			e=e->next;
		}
		while (!q.empty())
		q.pop();
		for (int j=0;j<n;j++)
		if (flag[j]==0)
		q.push(v[j]);
	}
	for (int i=0;i<n;i++)
	cout<<v[i].dis<<" ";
	cout<<endl;
	
	
	return 0;
}
