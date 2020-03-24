#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int **c;
int **flag;
vector<pair<string,int> > rollBack(string a, string b)
{
	int m=a.length();
	int n=b.length();
	vector<pair<string,int> > tmp;
	while (flag[m][n]!=-1)
	{
		tmp.push_back(make_pair(b.substr(0,n),flag[m][n]));
		if (flag[m][n]==0)
		{
			m--;
			n--;
			continue;
		}
		if (flag[m][n]==1)
		{
			m--;
			n--;
			continue;
		}
		if (flag[m][n]==2)
		{
			m--;
			continue;
		}
		if (flag[m][n]==3)
		{
			n--;
			continue;
		}
		if (flag[m][n]==4)
		{
			m-=2;
			n-=2;
			continue;
		}
		
	}
	return tmp;
}
int main(int argc, char** argv) {
	freopen("input.in","r",stdin);
	int m,n;
	string a,b;
	cin>>a>>b;
	fclose(stdin);
	m=a.length();
	n=b.length();
	c=new int*[m+1];
	flag=new int*[m+1];
	for (int i=0;i<=m;i++)
	{
		c[i]=new int[n+1];
		flag[i]=new int[n+1];
		for (int j=0;j<=n;j++)
		{
			c[i][j]=INT_MAX;
			c[0][j]=j;
			flag[i][j]=-1;
		}
		c[i][0]=i;
	}
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (c[i+1][j+1]>c[i][j+1]+1)
			{
				c[i+1][j+1]=c[i][j+1]+1;
				flag[i+1][j+1]=2;
			}
			if (c[i+1][j+1]>c[i+1][j]+1)
			{
				c[i+1][j+1]=c[i+1][j]+1;
				flag[i+1][j+1]=3;
			}
			if (a[i]==b[j]&&c[i][j]<c[i+1][j+1])
			{
				c[i+1][j+1]=c[i][j];
				flag[i+1][j+1]=0;
			}
			if (a[i]!=b[j]&&c[i][j]+1<c[i+1][j+1])
			{
				c[i+1][j+1]=c[i][j]+1;
				flag[i+1][j+1]=1;
			}
			if (i>0&&j>0&&a[i-1]==b[j]&&b[j-1]==a[i])
			{
				if (c[i+1][j+1]>c[i-1][j-1])
				{
					c[i+1][j+1]=c[i-1][j-1];
					flag[i+1][j+1]=4;
				}
			}
			
		}
	}
	cout<<c[m][n]<<endl;
	vector<pair<string,int> > v=rollBack(a,b);
	reverse(v.begin(),v.end());
	string s[]={"¸´ÖÆ","Ìæ»»","É¾³ý","²åÈë","Ðý×ª"};
	for (int i=0;i<v.size();i++)
	{
		cout<<s[v[i].second]<<" "<<v[i].first<<endl;
	} 
}
