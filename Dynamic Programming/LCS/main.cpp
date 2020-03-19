#include <iostream>
#include <string>
#include <vector>
using namespace std; 

void LCS(string s1, string s2, int **c, int **b)
{
	int l1=s1.length();
	int l2=s2.length();
	for (int i=0;i<l1;i++)
	{
		if (s1[i]==s2[0])
		c[i][0]=1;
	}
	for (int i=0;i<l2;i++)
	{
		if (s2[i]==s1[0])
		c[0][i]=1;
	}
	for (int i=1;i<l1;i++)
	{
		for (int j=1;j<l2;j++)
		{
			if (s1[i]==s2[j])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=1;  // 1表示指向左上方 
			}
			else
			{
				if (c[i-1][j]>=c[i][j-1])
				{
					c[i][j]=c[i-1][j];
					b[i][j]=2; //2表示向上 
				}
				else
				{
					c[i][j]=c[i][j-1];
					b[i][j]=3; //3表示向左 
				}
			}
		}
	}
}

int main(int argc, char** argv) {
	string s1,s2;
	cin>>s1>>s2;
	int l1,l2;
	l1=s1.length();
	l2=s2.length();
	int **b,**c;
	b=new int*[l1];
	c=new int*[l1];
	for (int i=0;i<l1;i++)
	{
		b[i]=new int[l2];
		c[i]=new int[l2];
		for (int j=0;j<l2;j++)
		{
			b[i][j]=-1;
			c[i][j]=0;
		}
	}
	LCS(s1,s2,c,b);
	for (int i=0;i<l1;i++)
	{
		for (int j=0;j<l2;j++)
		{
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for (int i=0;i<l1;i++)
	{
		for (int j=0;j<l2;j++)
		{
			cout<<b[i][j]<<" ";
		 }
		cout<<endl; 
	}
	return 0;
}
