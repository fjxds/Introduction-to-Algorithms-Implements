#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
	int f;
	verNode(int v,edgeNode *r=NULL)
	{
		val=v;
		root=r;
	}
};
vector<verNode> v;
vector<verNode> v1;
bool cmp(verNode a,verNode b)
{
	return a.f>b.f;
}
int cunt;
int *flag;
void init_dfs(int n)
{
	flag[n]=1;
	verNode tmp=v[n];
	edgeNode *p=tmp.root;
	while (p)
	{
		if (flag[p->end]==0)
		{
			cunt++;
			init_dfs(p->end);
		}
		p=p->next;
	}
	cunt++;
	v[n].f=cunt;
	v1[n].f=cunt;
}
void dfs(int n)
{
	cout<<n<<" ";
	flag[n]=1;
	verNode tmp=v1[n];
	edgeNode *p=tmp.root;
	while (p)
	{
		if (flag[p->end]==0)
		{
			dfs(p->end);
		}
		p=p->next;
	}
}
int main(int argc, char** argv) {
	cunt=0;
	freopen("input.in","r",stdin);
	int n,m;
	cin>>n>>m;
	flag=new int[n];
	int b,e,w;
	for (int i=0;i<n;i++)
	{
		v.push_back(verNode(i));
		v1.push_back(verNode(i));
		flag[i]=0;
	}
	for (int i=0;i<m;i++)
	{
		cin>>b>>e>>w;
		v[b].root=new edgeNode(b,e,w,v[b].root); 
		v1[e].root=new edgeNode(e,b,w,v1[e].root);
	}
	fclose(stdin);
	for (int i=0;i<n;i++)
	{
		if (flag[i]==0)
		init_dfs(i);
	}
	for (int i=0;i<n;i++)
	{
		flag[i]=0;
	}
	sort(v.begin(),v.end(),cmp);
	vector<verNode>::iterator it;
	for (it=v.begin();it!=v.end();it++)
	{
		if (flag[it->val]==0)
		{
			dfs(it->val);
			cout<<endl;
		}
	}
	return 0;
}
