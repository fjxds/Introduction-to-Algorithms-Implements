#include <iostream>
#include <string>
using namespace std;
void preprocessing(string p, int*pre)
{
	int k=-1;
	pre[0]=-1;
	for (int i=0;i<p.length()-1;i++)
	{
		if (k<0||p[i+1]==p[k+1])
		{
			k++;
		}
		while (k>=0&&p[i+1]!=p[k])
		k=pre[k];
		pre[i+1]=k;
	}
}

int main(int argc, char** argv) {
	string s;
	cin>>s;
	int *pre;
	int *r;
	pre=new int[s.length()];
	r=new int[s.length()];
	preprocessing(s,pre);
	for (int i=0;i<s.length();i++)
	{
		if (pre[i]==-1)
		r[i]=1;
		else
		{
			if ((i+1)%(i-pre[i])==0)
			{
				r[i]=(i+1)/(i-pre[i]);
			}
			else
			r[i]=1;
		}
		cout<<r[i]<<" ";
	}
	cout<<endl;
	return 0;
}
