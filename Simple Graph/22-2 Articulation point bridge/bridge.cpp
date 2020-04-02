#include "low.h"
using namespace std;
vector<edgeNode*> Bridge()
{
	vector<edgeNode*> res;
	for (int i=0;i<v.size();i++)
	{
		if (v[i].art==false)
		continue;
		edgeNode *p=v[i].root;
		while (p)
		{
			if (v[p->end].low>v[i].low&&v[p->end].low==v[p->end].d)
			{
				p->bri=true;
				edgeNode *q=v[p->end].root;
				while (q&&q->end!=i)
				q=q->next;
				q->bri=true;
				res.push_back(p);
			}
			p=p->next;
		}
	}
	return res;
}

