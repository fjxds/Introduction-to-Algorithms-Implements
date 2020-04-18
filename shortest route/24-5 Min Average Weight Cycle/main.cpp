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
void build(int cur,int n,int **a)
{
	if (cur==n)
	return;
	for (int i=0;i<n;i++)
	{
		if (a[cur][i]!=INT_MAX)
		{
			edgeNode *tmp=v[i].root;
			while (tmp)
			{
				if (a[cur+1][tmp->end]>a[cur][tmp->begin]+tmp->weight)
				a[cur+1][tmp->end]=a[cur][tmp->begin]+tmp->weight;
				tmp=tmp->next;
			}
		}
	}
	build(cur+1,n,a);
}
double cal(int n,int **a)
{
	double ans=double(INT_MAX);
	for (int i=0;i<n;i++)
	{
		double res=double(INT_MIN);
		if (a[n][i]==INT_MAX)
		continue;
		for (int j=0;j<n;j++)
		{
			if (a[j][i]!=INT_MAX&&double((a[n][i]-a[j][i]))/(n-j)>res)
			res=double((a[n][i]-a[j][i]))/(n-j);
		}
		if (ans>res)
		ans=res;
	}
	return ans;
}


int main(int argc, char** argv) {
	freopen("input.in","r",stdin);
	int n,m,b,e,w;
	cin>>n>>m;
	int **store;
	store=new int*[n+1];
	for (int i=0;i<n;i++)
	{
		v.push_back(verNode(i));
		store[i]=new int[n];
		for (int j=0;j<n;j++)
		{
			store[i][j]=INT_MAX;
		}
	}
	store[n]=new int[n];
	for (int j=0;j<n;j++)
	store[n][j]=INT_MAX;
	for (int i=0;i<m;i++)
	{
		cin>>b>>e>>w;
		v[b].root=new edgeNode(b,e,w,v[b].root);
	}
	store[0][0]=0;
	build(0,n,store);
	double ans=cal(n,store);
	cout<<ans<<endl;
	
	return 0;
}
