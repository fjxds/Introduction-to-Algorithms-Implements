#include "low.h"
using namespace std;
int main(int argc, char** argv) {
	freopen("input.in","r",stdin);
	int n,m,b,e;
	cin>>n>>m;
	previous=new int[n];
	cunt=0;
	mask=-1;
	target=-1;
	flag=new int[n];
	for (int i=0;i<n;i++)
	{
		v.push_back(verNode(i));
		flag[i]=0;
	}
	for (int i=0;i<m;i++)
	{
		cin>>b>>e;
		v[b].root=new edgeNode(b,e,v[b].root,0,false);
		v[e].root=new edgeNode(e,b,v[e].root,0,false);
	}
	cout<<"id: low d"<<endl;
	init_dfs(0,-1);
	for (int i=0;i<n;i++)
	{
		cout<<i<<": "<<v[i].low<<" "<<v[i].d<<endl;
	}
	cout<<"Articulation Points: "<<endl;
	vector<int> res=Articulated();
	for (int i=0;i<res.size();i++)
	cout<<res[i]<<" ";
	cout<<endl;
	cout<<"Bridges: "<<endl;
	vector<edgeNode*> ans=Bridge();
	for (int i=0;i<ans.size();i++)
	cout<<ans[i]->begin<<"->"<<ans[i]->end<<endl;
	cout<<"Biconnected: "<<endl;
	for (int i=0;i<n;i++)
	flag[i]=0;
	Biconnected(0,1);
	for (int i=0;i<n;i++)
	{
		edgeNode *p=v[i].root;
		while (p)
		{
			if (p->bri==false)
			{
				cout<<p->begin<<"->"<<p->end<<": "<<p->tag<<endl;
			}
			p=p->next;
		}
	}
	return 0;
} 
