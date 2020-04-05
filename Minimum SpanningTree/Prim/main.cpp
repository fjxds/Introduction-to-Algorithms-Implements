#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int *flag;

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
struct distNode
{
	int prev;
	int dist;
	int val;
	distNode(int v,int p=-1,int d=INT_MAX)
	{
		val=v;
		prev=p;
		dist=d;
	}
};
bool cmp(distNode a,distNode b)
{
	return a.dist<b.dist;
}
distNode select(vector<distNode> &vec,int t)
{
	distNode ans(0);
	edgeNode *p=v[t].root;
	while (p)
	{
		if (flag[p->end]==0)
		{
			if (vec[p->end].dist>p->weight)
			{
				vec[p->end].dist=p->weight;
				vec[p->end].prev=t;
			}	
		}
		p=p->next;
	}
	int cur=INT_MAX;
	for (int i=0;i<vec.size();i++)
	{
		if (flag[i]==0&&vec[i].dist<cur)
		{
			cur=vec[i].dist;
			ans=vec[i];
		}
	}
	return ans;
}
int main()
{
	freopen("input.in","r",stdin);
	vector<distNode> dis;
	int n,m,w,e,b,t;
	cin>>n>>m;
	flag=new int[n];
	for (int i=0;i<n;i++)
	{
		v.push_back(verNode(i));
		dis.push_back(distNode(i));
		flag[i]=0;
	}
	for (int i=0;i<m;i++)
	{
		cin>>b>>e>>w;
		v[b].root=new edgeNode(b,e,w,v[b].root);
		v[e].root=new edgeNode(e,b,w,v[e].root);
	}
	cin>>t;
	dis[t].dist=0;
	int sum=0;
	for (int i=0;i<n-1;i++)
	{
		flag[t]=1;
		distNode tmp=select(dis,t);
		cout<<tmp.prev<<"->"<<tmp.val<<": "<<tmp.dist<<endl;
		sum+=tmp.dist;
		t=tmp.val;
	}
	cout<<sum<<endl;
	
}
