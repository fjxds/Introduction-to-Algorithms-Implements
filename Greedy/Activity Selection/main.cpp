#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std; 

vector<int> select(int *s,int *f,int n) // f为排好序的结束时间数组 
{
	int cur=0;
	vector<int> tmp;
	for (int i=0;i<n;i++)
	{
		if (s[i]>=cur)
		{
			tmp.push_back(i);
			cur=f[i];
		}
	}
	return tmp;
}
int main(int argc, char** argv) {
	int n,*s,*f;
	freopen("input.in","r",stdin);
	cin>>n;
	s=new int[n];
	f=new int[n];
	for (int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for (int i=0;i<n;i++)
	{
		cin>>f[i];
	}
	fclose(stdin);
	vector<int> v=select(s,f,n);
	for (int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}
