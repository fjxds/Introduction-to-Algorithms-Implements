#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int max(int a, int b)
{
	if (a>b)
	return a;
	return b;
} 

int maxCut(vector<int> p,int L) // p表示利润列表，而L表示所要计算的长钢条的长度
{
	if (L==0)
	return 0;
	int margin[L+1];
	memset(margin,0,sizeof(margin));
	margin[1]=p[0];
	for (int i=2;i<=L;i++)
	{
		for (int j=1;j<=p.size()&&j<=i;j++)
		{
			margin[i]=max(margin[i],margin[i-j]+p[j-1]);
		}
	}
	return margin[L];
}
int main()
{
	vector<int>p(10);
	int n,L;
	cin>>n>>L;
	for (int i=0;i<n;i++)
	{
		cin>>p[i];
	}
	cout<<maxCut(p,L)<<endl;
}
