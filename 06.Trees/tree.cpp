#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int val;
	Node* right;
	Node* left ;

	//constructor
	Node(int val)
	{
		this->val = val;
		this->right = NULL;
		this->left = NULL;
	}

};

void display(Node* root)
{
	if(root == NULL) return;
	cout<<root->val<<" ";
	display(root->left);
	display(root->right);
}

int sum(Node* root)
{
	if(root == NULL) return 0;
	return root->val + sum(root->left) + sum(root->right);
}

int sizeoftree(Node* root)
{
	if(root == NULL) return 0;
	return 1 + sizeoftree(root->left) + sizeoftree(root->right);
	
}

int maxintree(Node* root)
{
	if(root == NULL) return INT_MIN;
	return max(root->val, max(maxintree(root->left), maxintree(root->right)));
	
}

int minintree(Node* root)
{
	if(root == NULL) return INT_MAX;
	return min(root->val, min(minintree(root->left), minintree(root->right)));
	
}

int height(Node* root)
{
	if(root == NULL) return 0;
	return 1 + max(height(root->left), height(root->right));
}

int main()
{
	Node* a = new Node(-9093);
	Node* b = new Node(2);
	Node* c = new Node(3);
	Node* d = new Node(4);
	Node* e = new Node(15);
	Node* f = new Node(6);
	Node* g = new Node(7);
	Node *h = new Node(8);
	

	a->left = b;
	a->right = c;
	
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;
	
	g->left = h;

	display(a);

	cout<<endl<<sum(a);
	cout<<endl<<sizeoftree(a);
	cout<<endl<<maxintree(a);
	cout<<endl<<minintree(a);
	cout<<endl<<height(a);
	
}