#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <map>
using namespace std;

vector<int> v;
int **c;
map<pair<int,int>,int>a;
void optimal(int left,int right,int mid,int nl,int nr,int nm)
{
	if (nm<=nl+1)
	{
		c[left][mid]=0;
	}
	if (nr<=nm+1)
	{
		c[mid+1][right]=0;
	}
	if (c[left][mid]==INT_MAX)
	{
		int cur=INT_MAX;
		int tmp=-1;
		for (int i=nl+1;i<nm;i++)
		{
			optimal(left,mid,v[i],nl,nm,i);
			if (c[left][v[i]]+c[v[i]+1][mid]<cur)
			{
				cur=c[left][v[i]]+c[v[i]+1][mid];
				tmp=v[i];
			}
			
		}
		if (c[left][mid]>mid-left+1+cur)
		{
			c[left][mid]=mid-left+1+cur;
			a[make_pair(left,mid)]=tmp;
		}
		
	}
	if (c[mid+1][right]==INT_MAX)
	{
		int cur=INT_MAX;
		int tmp=-1;
		for (int i=nm+1;i<nr;i++)
		{
			optimal(mid+1,right,v[i],nm,nr,i);
			if (c[mid+1][v[i]]+c[v[i]+1][right]<cur)
			{
				cur=c[mid+1][v[i]]+c[v[i]+1][right];
				tmp=v[i];
			}
			
		}
		if (c[mid+1][right]>right-mid+cur)
		{
			c[mid+1][right]=right-mid+cur;
			a[make_pair(mid+1,right)]=tmp;
		}
		
	}
	if (c[left][right]>c[left][mid]+c[mid+1][right]+right-left+1)
	{
		c[left][right]=c[left][mid]+c[mid+1][right]+right-left+1;
		a[make_pair(left,right)]=mid;
	}
	
}
void show(int left,int right)
{
	if (a[make_pair(left,right)])
	{
		int mid=a[make_pair(left,right)];
		cout<<mid<<" ";
		show(left,mid);
		show(mid+1,right);
	}
}
int main(int argc, char** argv) {
	freopen("input.in","r",stdin);
	int m,tmp;
	string s;
	v.push_back(0);
	cin>>s;
	cin>>m;
	for (int i=0;i<m;i++)
	{
		cin>>tmp;
		v.push_back(tmp);
	}
	fclose(stdin);
	v.push_back(s.length()-1);
	c=new int*[s.length()];
	for (int i=0;i<s.length();i++)
	{
		c[i]=new int[s.length()];
		for (int j=0;j<s.length();j++)
		c[i][j]=INT_MAX;
	}
	for (int i=1;i<=m;i++)
	{
		optimal(0,s.length()-1,v[i],0,v.size()-1,i);
	}
	cout<<c[0][s.length()-1]<<endl;
	show(0,s.length()-1);
	cout<<endl;
}
