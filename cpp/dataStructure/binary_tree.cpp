#include <bits/stdc++.h>
using namespace std;
struct node{
	int val;
	node *left;
	node *right;
};

void destroy_tree(node *tree){
	if(tree!=NULL){
		destroy_tree(tree->left);
		destroy_tree(tree->right);
		delete tree;
	}
}

void insert(int key, node *tree){
	// cout << tree->val<<"\n";
	if(key < tree->val){
		if(tree->left!=NULL)
			insert(key, tree->left);
		else{
			tree->left = new node;
			tree->left->val = key;
			tree->left->left = NULL;
			tree->left->right = NULL;
		}
	}
	else{
		if(tree->right!=NULL)
			insert(key, tree->right);
		else{
			tree->right = new node;
			tree->right->val = key;
			tree->right->left = NULL;
			tree->right->right = NULL;
		}
	}
}

node *search(int key, node *tree){
	if(tree!=NULL){
		if(key==tree->val)
			return tree;
		if(key<tree->val)
			return search(key, tree->left);
		else
			return search(key, tree->right);
	}
	else return NULL;
}

// void insert(int key){
// 	if(root!=NULL)
// 		insert(key, root);
// 	else{
// 		root = new node;
// 		root->val = key;
// 		root->left = NULL;
// 		root->right = NULL;
// 	}
// }

void print_tree(node *tree){
	cout<<tree->val<<" ";
	if(tree->left!=NULL)
		print_tree(tree->left);
	if(tree->right!=NULL)
		print_tree(tree->right);
}

int main(){
	freopen("../in.txt","r",stdin);
	int n;
	cin >> n; cout<<n<<"\n";
	node *root = new node;
	int tmp;
	root->val = (cin>>tmp,tmp);
	root->left = NULL;
	root->right = NULL;
	for(int i=1;i<n;i++) {
		// int tmp;
		insert((cin>>tmp,tmp),root);
	}
	print_tree(root);
}