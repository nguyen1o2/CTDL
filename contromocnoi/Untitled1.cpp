#include<bits/stdc++.h>
using namespace std;

struct Node{
	int infor;
	Node *left,*right;
};

typedef Node *TRO;

void Create(TRO &root){
	 root==NULL;
}

int insert(TRO &root,int k){
	if(root==NULL){
		root=new Node;
		root->infor=k;
		root->left=root->right=NULL;
		return 1;
	}
	else if(root->infor==k){
		return 0;
	}
	else if(root->infor>k){
		return insert(root->left,k);
	}
	else{
		return insert(root->right,k);
	}
}

void CreateNode(Node *&root,int a[],int n){
	for(int i=1;i<=n;i++){
		if(root==NULL){
			Node *q;
			q=new Node;
			q->infor=a[i];
			q->left=q->right=NULL;
			root=q;
		}
		else{
			if(a[i]<root->infor){
				insert(root->left,a[i]);
			}
			else if(a[i]>root->infor){
				insert(root->right,a[i]);
			}
		}
	}
}

int main(){
	TRO root;
	Create(root);
	int n,a[50];
	cout<<"Nhap so luong node: ";cin>>n;
	CreateNode(root,a,n);
	return 0;
}
