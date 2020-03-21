#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
struct Node
{
	int x;
	int y;
	Node (int a=0,int b=0)
	{
		x=a;
		y=b;
	}
};
bool cmp(Node a,Node b)
{
	return a.x<b.x;
}
double dis(Node a,Node b)
{
	double d=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	return d;
}
vector<Node> v;
double **c;
int main(int argc, char** argv) {
	freopen("input.in","r",stdin);
	int n,x,y;
	cin>>n;
	c=new double*[n];
	for (int i=0;i<n;i++)
	{
		c[i]=new double[n];
		cin>>x>>y;
		v.push_back(Node(x,y));
		for (int j=0;j<n;j++)
		c[i][j]=INT_MAX;
	}
	fclose(stdin);
	sort(v.begin(),v.end(),cmp);
	c[0][1]=dis(v[0],v[1]);
	c[0][0]=0;
	for (int j=2;j<n;j++)
	{
		for (int i=0;i<=j-2;i++)
		{
			c[i][j]=c[i][j-1]+dis(v[j-1],v[j]);
		}
		for (int k=0;k<j-1;k++)
		{
			if (c[j-1][j]>c[k][j-1]+dis(v[k],v[j]))
			c[j-1][j]=c[k][j-1]+dis(v[k],v[j]);
		}
	}
	c[n-1][n-1]=c[n-2][n-1]+dis(v[n-2],v[n-1]);
	cout<<c[n-1][n-1]<<endl;
	return 0;
}
