#include "low.h"
using namespace std;
vector<verNode> v;
int *flag;
int cunt;
int mask;
int target;
int *previous;
int find(int n)
{
	edgeNode *p=v[n].root;
	int min=INT_MAX;
	while (p)
	{
		if (flag[p->end]&&previous[n]!=p->end)
		{
			if (min>v[p->end].d)
			min=v[p->end].d;
		}
	}
	return min;
}
void init_dfs(int n,int prev)
{
	previous[n]=prev;
	flag[n]=1;
	v[n].d=++cunt;
	v[n].low=cunt;
	edgeNode *p=v[n].root;
	while (p)
	{
		if (flag[p->end]==0)
		{
			init_dfs(p->end,n);
		}
		p=p->next;
	}
	p=v[n].root;
	while (p)
	{
		if (flag[p->end]&&p->end!=prev)
		{
			if (v[p->end].low<v[n].low)
			v[n].low=v[p->end].low;
		}
		p=p->next;
	}
}

