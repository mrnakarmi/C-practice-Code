//find the minimum depth of a binary tree
#include <iostream>

using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

node* newNode(int data){
	node *temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

int minDepth(node* root){
	if(root == NULL){
		return 0;
	}
	
	if(root->left == NULL && root->right == NULL){
		return 1;
	}
	
	if(!root->left){
		return minDepth(root->right)+1;
	}
	
	if(!root->right){
		return minDepth(root->left) + 1;
	}
	
	return min(minDepth(root->left),minDepth(root->right))+1;
	
}

int main(){
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	cout<< minDepth(root);
	return 0;
}