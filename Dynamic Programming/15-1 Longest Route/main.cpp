#include <iostream>
#include <vector>
using namespace std;

struct edgeNode
{
	int begin;
	int end;
	int weight;
	edgeNode *next;
	edgeNode(int b=0,int e=0,int w=0,edgeNode *n=NULL)
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
	verNode(int v=0,edgeNode*n=NULL)
	{
		val=v;
		root=n;
	}
};
int *flag;
int **c;
void LR(vector<verNode> v,int b, int e)
{
	edgeNode *tmp;
	tmp=v[b].root;
	while (tmp!=NULL)
	{
		if (c[tmp->end][e]!=-1) // 备忘 
		{
			if (c[b][e]<c[tmp->end][e]+tmp->weight) //参考子问题 
			{
				c[b][e]=c[tmp->end][e]+tmp->weight;//更新距离 
				flag[b]=tmp->end; //记录路径 
			}
		}
		else // 子问题尚未求解 
		{
			LR(v,tmp->end,e); // 求解子问题 
		}
		tmp=tmp->next;
	}
}

int main(int argc, char** argv) {
	freopen("input.in","r",stdin);
	int n,v,b,e,w;
	cin>>n>>v;
	flag=new int[n];
	c=new int*[n];
	vector<verNode> vers;
	for (int i=0;i<n;i++)
	{
		flag[i]=-1;
		c[i]=new int[n];
		vers.push_back(verNode(i,NULL));
		for (int j=0;j<n;j++)
		{
			c[i][j]=-1;
		}
	}
	for (int i=0;i<v;i++)
	{
		cin>>b>>e>>w;
		vers[b].root=new edgeNode(b,e,w,vers[b].root);
	}
	cin>>b>>e;
	cout<<"input done"<<endl;
	cout<<"calculating "<<b<<" to "<<e<<endl;
	fclose(stdin);
	c[e][e]=0;
	LR(vers,b,e);
	cout<<"maximum distance: "<<c[b][e]<<endl;
	cout<<"route: "<<b;
	while (flag[b]!=e&&flag[b]!=-1)
	{
		cout<<"->"<<flag[b];
		b=flag[b];
	}
	cout<<"->"<<e<<endl;
	
	return 0;
}
