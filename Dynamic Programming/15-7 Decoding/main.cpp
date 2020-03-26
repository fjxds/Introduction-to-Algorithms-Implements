#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std; 

struct edgeNode
{
	int begin;
	int end;
	int weight;
	double pos;
	edgeNode *next;
	edgeNode(int b, int e,int w,double p,edgeNode *n=NULL)
	{
		begin=b;
		end=e;
		weight=w;
		pos=p;
		next=n;
	}
};
struct verNode
{
	int val;
	edgeNode *root;
	verNode(int v=0,edgeNode *r=NULL)
	{
		val=v;
		root=r;
	}
};
vector<verNode> v;
vector<int> s;
queue<pair<vector<int>,double> > findMax(int cur,queue<pair<vector<int>,double> > q)
{
	if (cur==s.size())
	return q;
	if (q.empty())
	return q;
	queue<pair<vector<int>,double> > tmp;
	while (!q.empty())
	{
		vector<int> vec=q.front().first;
		double posb=q.front().second;
		q.pop();
		verNode v_cur=v[vec[vec.size()-1]];
		edgeNode *edge=v_cur.root;
		while (edge!=NULL)
		{
			if (edge->weight==s[cur])
			{
				vector<int> vec_now=vec; 
				vec_now.push_back(edge->end);
				tmp.push(make_pair(vec_now,posb*edge->pos));
			}
			edge=edge->next;
		}
	}
	return findMax(cur+1,tmp);
}
int main(int argc, char** argv) {
	freopen("input.in","r",stdin);
	int n,m,b,e,w,nq,v0;
	double p;
	cin>>n>>m;
	for (int i=0;i<n;i++)
	{
		v.push_back(verNode(i));
	}
	for (int i=0;i<m;i++)
	{
		cin>>b>>e>>w>>p;
		v[b].root=new edgeNode(b,e,w,p,v[b].root);
	}
	cin>>v0;
	cin>>nq;
	for (int i=0;i<nq;i++)
	{
		cin>>b;
		s.push_back(b);
	}
	fclose(stdin);
	queue<pair<vector<int>,double> >q;
	vector<int> tmp;
	tmp.push_back(v0);
	q.push(make_pair(tmp,double(1)));
	q=findMax(0,q);
	double optimal=0;
	vector<int> res;
	while(!q.empty())
	{
		vector<int> vec=q.front().first;
		double posb=q.front().second;
		if (posb>optimal)
		{
			res=vec;
			optimal=posb;
		}
		q.pop();
	}
	for (int i=0;i<res.size();i++)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl;
	cout<<optimal<<endl;
	
	return 0;
}
