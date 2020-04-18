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
	edgeNode(int b,int e,edgeNode *n=NULL)
	{
		begin=b;
		end=e;
		next=n;
	}
};
struct Box
{
	int val;
	vector<int> dim;
	edgeNode *root;
	Box(int v,edgeNode *r=NULL)
	{
		val=v;
		root=r;
	}
};
bool cmp(Box a,Box b)
{
	for (int i=0;i<a.dim.size();i++)
	{
		if (a.dim[i]>b.dim[i])
		return false;
	}
	return true;
}
vector<Box> v;
vector<Box> ans;
int *flag;
int cunt;
int *in; 
void dfs(int n,int d,vector<Box> vec)
{
	cout<<vec.size()<<endl;
	if (d>cunt)
	ans=vec;
	flag[n]=1;
	edgeNode *tmp=v[n].root;
	while (tmp)
	{
		if (flag[tmp->end]==0)
		{
			vector<Box> temp=vec;
			temp.push_back(v[tmp->end]);
			dfs(tmp->end,d+1,temp);
		}
		tmp=tmp->next;
	}
	flag[n]=0;
}

int main(int argc, char** argv) {
	freopen("input.in","r",stdin);
	int n,m,tmp;
	cin>>n>>m;
	in=new int[n];
	flag=new int[n];
	cunt=0;
	for (int i=0;i<n;i++)
	{
		v.push_back(Box(i));	
		for (int j=0;j<m;j++)
		{
			cin>>tmp;
			v[i].dim.push_back(tmp);
		}
		in[i]=0;
		flag[i]=0;
		sort(v[i].dim.begin(),v[i].dim.end());
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (i!=j&&cmp(v[i],v[j]))
			{
				v[i].root=new edgeNode(i,j,v[i].root);
				in[j]++;
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		if (in[i]==0)
		{
			vector<Box> temp;
			temp.push_back(v[i]);
			dfs(i,1,temp);
		}
	}
	for (int i=0;i<ans.size();i++)
	cout<<ans[i].val<<endl;
	return 0;
}
