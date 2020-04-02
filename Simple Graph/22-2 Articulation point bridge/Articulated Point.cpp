#include <iostream> 
#include "low.h"
using namespace std; 

vector<int> Articulated()
{
	vector<int> res;
	int count=0;
	for (int i=0;i<v.size();i++)
	if (previous[i]==0)
	count++;
	if (count>1)
	res.push_back(0);
	for (int i=1;i<v.size();i++)
	{
		bool ff=false;
		bool equal=true;
		edgeNode *p=v[i].root;
		count=0;
		while (p)
		{
			verNode tmp=v[p->end];
			if (previous[i]==p->end)
			{
				p=p->next;
				continue;
			}
			count++;
			if (v[i].low<tmp.low&&v[i].d<=tmp.low)
			ff=true;
			if (v[i].low<tmp.low&&v[i].d>tmp.low)
			{
				ff=false;
				break;
			}
			if (v[i].low!=tmp.low)
			equal=false;
			p=p->next;
		}
		if (v[i].low!=v[i].d)
		equal=false;
		if (ff||equal)
		if (count>0)
		{
			v[i].art=true;
			res.push_back(i);
		}
	}
	return res;
}

