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
	bool in;
	edgeNode *next;
	edgeNode(int b=-1, int e=-1, int w=INT_MIN,bool i=false,edgeNode *n=NULL)
	{
		begin=b;
		end=e;
		next=n;
		weight=w;
		in=i;
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
int *flag;
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
void dfs(int s,vector<vector<edgeNode> > &maxx,int cur)
{
	edgeNode *p=v[cur].root;
	while (p)
	{
		if (maxx[s][p->end].weight==INT_MIN&&p->end!=s)
		{
			maxx[s][p->end]=maxx[s][p->begin].weight>=p->weight? maxx[s][p->begin]:*p;
			dfs(s,maxx,p->end);
		}
		p=p->next;
	}
}
void remove(int x,int y)
{
	if(v[x].root->end==y)
	v[x].root=v[x].root->next;
	else
	{
		edgeNode *p=v[x].root;
		edgeNode *q=p->next;
		while (q&&q->end!=y)
		{
			q=q->next;
			p=p->next;
		}
		p->next=q->next;
	}
}
void dfs(int cur)
{
	flag[cur]=1;
	edgeNode *p=v[cur].root;
	while (p)
	{
		if (flag[p->end]==0)
		{
			cout<<cur<<"->"<<p->end<<": "<<p->weight<<endl;
			dfs(p->end);
		}
		p=p->next;
	}
}

int main(int argc, char** argv) {
	freopen("input.in","r",stdin);
	int n,m,b,e,w;
	vector<edgeNode> res;
	cin>>n>>m;
	u=new int[n];
	flag=new int[n];
	for (int i=0;i<n;i++)
	{
		v.push_back(verNode(i));
		u[i]=-1;
		flag[i]=0;
	}
	for (int i=0;i<m;i++)
	{
		cin>>b>>e>>w;
		E.push_back(edgeNode(b,e,w));
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
			E[i].in=true;
			res.push_back(E[i]);
			sum+=E[i].weight;
			count++;
			merge(b,e);
		}
	}
	for (int i=0;i<res.size();i++)
	{
		v[res[i].begin].root=new edgeNode(res[i].begin,res[i].end,res[i].weight,true,v[res[i].begin].root);
		v[res[i].end].root=new edgeNode(res[i].end,res[i].begin,res[i].weight,true,v[res[i].end].root);
	}
	vector<vector<edgeNode> > maxx;
	for (int i=0;i<n;i++)
	{
		maxx.push_back(vector<edgeNode>(n));
	}
	for (int i=0;i<n;i++)
	{
		dfs(i,maxx,i);
	}
	for (int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<maxx[i][j].weight<<" ";
		}
		cout<<endl;
	 } 
	edgeNode current;
	edgeNode minn;
	for (int i=0;i<E.size();i++)
	{
		if (E[i].in==false)
		{
			if (current.weight==INT_MIN||E[i].weight-maxx[E[i].begin][E[i].end].weight<minn.weight-current.weight)
			{
				current=maxx[E[i].begin][E[i].end];
				minn=E[i];
			}
		}
	}
	cout<<current.begin<<" "<<current.end<<endl;
	cout<<minn.begin<<" "<<minn.end<<endl;
	remove(current.begin,current.end);
	remove(current.end,current.begin);
	v[minn.begin].root=new edgeNode(minn.begin,minn.end,minn.weight,true,v[minn.begin].root);
	v[minn.end].root=new edgeNode(minn.end,minn.begin,minn.weight,true,v[minn.end].root);
	dfs(0); 
	return 0;
}
