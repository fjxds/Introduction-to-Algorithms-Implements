#ifndef LOW_H
#define LOW_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#pragma once
using namespace std;
struct edgeNode
{
	int begin;
	int end;
	int tag;
	bool bri;
	edgeNode *next;
	edgeNode(int b, int e, edgeNode *n=NULL,int t=0,bool brid=false)
	{
		begin=b;
		end=e;
		next=n;
		tag=t;
		bri=brid;
	}
};
struct verNode
{
	int val;
	int d;
	int low;
	bool art;
	edgeNode *root;
	verNode(int v,int dis=0,int l=0, bool a=false, edgeNode *r=NULL)
	{
		val=v;
		d=dis;
		low=l;
		art=a;
		root=r;
	}
};
extern vector<verNode> v;
extern int *flag;
extern int cunt;
extern int mask;
extern int target;
extern int *previous;
int find(int n);
void init_dfs(int n,int prev);
vector<int> Articulated(); 
vector<edgeNode*> Bridge();
void Biconnected(int cur,int t);
#endif
