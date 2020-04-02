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
		v[b].root=new edgeNode(b,e,v[b].root);
		v[e].root=new edgeNode(e,b,v[e].root);
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
	return 0;
} 
