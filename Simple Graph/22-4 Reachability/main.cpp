#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

struct edgeNode
{
	int begin;
	int end;
	edgeNode *next;
	edgeNode(int b, int e, edgeNode* n=NULL)
	{
		begin=b;
		end=e;
		next=n;
	}
};
struct verNode
{
	int val;
	int min;
	int tag;
	edgeNode *root;
	verNode(int v, int m, int t,edgeNode *r=NULL)
	{
		val=v;
		min=m;
		root=r;
		tag=t;
	}
};
vector<verNode> v;
vector<verNode> vec;
int *flag;
bool cmp(verNode a,verNode b)
{
	return a.tag<b.tag;
}
void dfs(int n, int tag)
{
	flag[n]=1;
	vec[n].min=tag;
	edgeNode *p=vec[n].root;
	while (p)
	{
		if (flag[p->end]==0)
		dfs(p->end,tag);
		p=p->next;
	}
}
int main(int argc, char** argv) {
	freopen("input.in","r",stdin);
	int n,m,b,e,tmp;
	cin>>n>>m;
	flag=new int[n];
	for (int i=0;i<n;i++)
	{
		cin>>tmp;
		v.push_back(verNode(i,INT_MAX,tmp));
		vec.push_back(verNode(i,INT_MAX,tmp));
		flag[i]=0;
	}
	for (int i=0;i<m;i++)
	{
		cin>>b>>e;
		v[b].root=new edgeNode(b,e,v[b].root);
		vec[e].root=new edgeNode(e,b,vec[e].root);
	}
	sort(v.begin(),v.end(),cmp);
	for (int i=0;i<n;i++)
	{
		if (flag[v[i].val]==0)
		{
			dfs(v[i].val,v[i].tag);
		}
	}
	for (int i=0;i<n;i++)
	{
		v[i].min=vec[v[i].val].min;
		cout<<i<<": "<<vec[i].min<<endl;
	}
	return 0;
}
