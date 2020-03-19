#include <iostream>
#include <vector>
#include <string>
using namespace std;
int **c;
int maxx;
int start;
void preprocess(string s)
{
	for (int i=0;i<s.length();i++)
	{
		c[i][1]=1;
		if (i<s.length()-1&&s[i]==s[i+1])
		{
			c[i][2]=1;
			maxx=2;
			start=i;
		}
	}
}
void longest(string s)
{
	for (int l=3;l<=s.length();l++)
	{
		for (int i=0;i<=s.length()-l;i++)
		{
			int j=l+i-1;
			if (s[i]==s[j]&&c[i+1][l-2]==1)
			{
				c[i][l]=1;
				maxx=l;
				start=i;
			}
		}
	}
}

int main(int argc, char** argv) {
	freopen("input.in","r",stdin);
	string s;
	cin>>s;
	fclose(stdin);
	c=new int*[s.length()];
	for (int i=0;i<s.length();i++)
	{
		c[i]=new int[s.length()+1];
		for (int j=0;j<=s.length();j++)
		c[i][j]=0;
		c[i][1]=1;
	}
	preprocess(s);
	longest(s);
	cout<<s.substr(start,maxx)<<endl;
	return 0;
}
