#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int **W;
int **pi;

int main(int argc, char** argv) {
	int n,m,b,e,w;
	freopen("input.in","r",stdin);
	cin>>n>>m;
	W=new int*[n];
	pi=new int*[n];
	for (int i=0;i<n;i++)
	{
		W[i]=new int[n];
		pi[i]=new int[n];
		for (int j=0;j<n;j++)
		{
			W[i][j]=INT_MAX;
			pi[i][j]=-1;
		}
		W[i][i]=0;
	}
	for (int i=0;i<m;i++)
	{
		cin>>b>>e>>w;
		W[b][e]=w;
		pi[b][e]=b;
	}
	for (int k=0;k<n;k++)
	{
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				if (W[i][k]!=INT_MAX&&W[k][j]!=INT_MAX&&W[i][j]>W[i][k]+W[k][j])
				{
					W[i][j]=W[i][k]+W[k][j];
					pi[i][j]=pi[k][j];
				}
				
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			cout<<W[i][j]<<" ";
		}
		cout<<endl;
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			cout<<pi[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
