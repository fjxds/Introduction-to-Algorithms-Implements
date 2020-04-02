#include "low.h"
using namespace std;
void Biconnected(int cur,int t)
{
	flag[cur]=1;
	edgeNode *p=v[cur].root;
	while (p)
	{
		if (p->bri==false)
		{
			p->tag=t;
			if (flag[p->end]==0)
			Biconnected(p->end,t);
		}
		else
		{
			if (flag[p->end]==0)
			Biconnected(p->end,t+1);
		}
		p=p->next;
	}
}

