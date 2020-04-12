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
void match(string s, string p, int*pre)
{
	int k=-1;
	if (s[0]==p[0])
	k=0;
	for (int i=0;i<s.length()-1;i++)
	{
		if (k==p.length()-1)
		{
			cout<<i-k<<endl;
			k=pre[k];
		}
		if (k<0||s[i+1]==p[k+1])
		{
			k++;
		}	
		while (k>=0&&s[i+1]!=p[k])
		k=pre[k];
	}
	if (k==p.length()-1)
	cout<<s.length()-1-k<<endl;
}

int main(int argc, char** argv) {
	freopen("input.in","r",stdin);
	string s,p;
	cin>>s>>p;
	cout<<s<<endl;
	cout<<p<<endl;
	int *pre;
	pre=new int[p.length()];
	preprocessing(p,pre);
	match(s,p,pre);
	return 0;
}
