#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
struct Node
{
	char c;
	int pos;
	Node *left,*right;
	Node(char ch='\0',int p=0,Node *l=NULL,Node *r=NULL)
	{
		c=ch;
		pos=p;
		left=l;
		right=r;
	}
};
bool cmp(Node *a, Node *b)
{
	return a->pos>b->pos;
}
Node* huffman(vector<Node*> v)
{
	vector<Node*> p=v;
	sort(p.begin(),p.end(),cmp);
	while (!p.empty())
	{
		Node *l=p[p.size()-1];
		p.pop_back();
		if (p.empty())
		{
			return l;
		}
		Node *r=p[p.size()-1];
		p.pop_back();
		Node *tmp=new Node;
		tmp->left=l;
		tmp->right=r;
		tmp->pos=l->pos+r->pos;
		p.push_back(tmp);
		sort(p.begin(),p.end(),cmp);
	}
}
void dfs(Node *root)
{
	if (root==NULL)
	return;
	if (root->c!='\0')
	cout<<root->c<<endl;
	else
	{
		dfs(root->left);
		dfs(root->right);
	}
}

int main(int argc, char** argv) {
	freopen("input.in","r",stdin);
	int n;
	cin>>n;
	vector<Node*> v;
	char c;
	int ps;
	for (int i=0;i<n;i++)
	{
		cin>>c>>ps;
		Node *tmp;
		tmp=new Node;
		tmp->c=c;
		tmp->pos=ps;
		v.push_back(tmp);
	}
	fclose(stdin);
	sort(v.begin(),v.end(),cmp);
	Node *root;
	root=huffman(v);
	dfs(root);
	return 0;
}
