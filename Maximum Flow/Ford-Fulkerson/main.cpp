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
	int flow;
	edgeNode *next;
	edgeNode(int b,int e,int w,edgeNode *n=NULL)
	{
		begin=b;
		end=e;
		weight=w;
		flow=0;
		next=n;
	}
};
vector<edgeNode*> ans;
int maxx;
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
int *flag;
void maxflow(int n,vector<verNode> res,vector<edgeNode*> path,int f)
{
	if (n==res.size()-1)
	{
		if (maxx<f)
		{
			maxx=f;
			ans=path;
		}
		return;
	}
	flag[n]=1;
	edgeNode *tmp=res[n].root;
	while (tmp)
	{
		if (flag[tmp->end]==0)
		{
			vector<edgeNode*> temp=path;
			temp.push_back(tmp);
			maxflow(tmp->end,res,temp,min(tmp->weight,f));
		}
		tmp=tmp->next;
	}
	flag[n]=0;
}
void process(edgeNode* a,int n)
{
	edgeNode* tmp=v[a->begin].root;
	while (tmp)
	{
		if (tmp->begin==a->begin&&tmp->end==a->end)
		{
			tmp->flow+=n;
			break;
		}
		if (tmp->begin==a->end&&tmp->end==a->begin)
		{
			tmp->flow-=n;
			break;
		}
		tmp=tmp->next; 
	}
}
int main(int argc, char** argv) {
	int n,m,b,e,w;
	freopen("input.in","r",stdin);
	cin>>n>>m;
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
	vector<verNode> res=v;
	while (true)
	{
		maxx=0;
		ans=vector<edgeNode*>();
		vector<edgeNode*> temp;
		maxflow(0,res,temp,INT_MAX);
		if (maxx==0)
		break; 
		for (int i=0;i<ans.size();i++)
		{
			process(ans[i],maxx);
		}
		res.clear();
		for (int i=0;i<n;i++)
		{
			res.push_back(verNode(i));
		}
		for (int i=0;i<n;i++)
		{
			edgeNode *tmp=v[i].root;
			while (tmp)
			{
				if (tmp->flow>0)
				{
					res[tmp->end].root=new edgeNode(tmp->end,tmp->begin,tmp->flow,res[tmp->end].root);
				}
				if (tmp->weight-tmp->flow>0)
				{
					res[tmp->begin].root=new edgeNode(tmp->begin,tmp->end,tmp->weight-tmp->flow,res[tmp->begin].root);
				}
				tmp=tmp->next;
			}
		}
	}
	int sum=0;
	edgeNode *tmp=v[0].root;
	while(tmp)
	{
		sum+=tmp->flow;
		tmp=tmp->next;
	}
	cout<<sum<<endl;
	for (int i=0;i<n;i++)
	{
		edgeNode *tmp=res[i].root;
		while (tmp)
		{
			cout<<tmp->begin<<"->"<<tmp->end<<": "<<tmp->weight<<endl;
			tmp=tmp->next;
		}
	}
	cout<<endl;
	for (int i=0;i<n;i++)
	{
		edgeNode *tmp=v[i].root;
		while (tmp)
		{
			cout<<tmp->begin<<"->"<<tmp->end<<": "<<tmp->flow<<"/"<<tmp->weight<<endl;
			tmp=tmp->next;
		}
	}
	return 0;
}
