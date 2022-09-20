#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
typedef Node *Tree;

Node *CreateNode(int init)
{
    Node *p = new Node;
    p->data = init;
    p->left = NULL;
    p->right = NULL;
    return p;
}

//Hàm tạo cây
void CreateTree(Tree &root)
{
    root = NULL;
}

//Phá hủy cây
void DestroyTree(Tree &root)
{
    if (root)
    {
        DestroyTree(root->left);
        DestroyTree(root->right);
        delete root;
    }
}

//Thêm node
void AddNode(Tree &root, Node *node)
{
    if (root)
    {
        if (root->data == node->data)
            return;
        if (node->data < root->data)
            AddNode(root->left, node);
        else
            AddNode(root->right, node);
    }
    else
    {
        root = node;
    }
}

//Tìm node
Node *FindNode(Tree root, int x)
{
    if (root)
    {
        if (root->data == x)
            return root;
        if (x < root->data)
            return FindNode(root->left, x);
        return FindNode(root->right, x);
    }
    return NULL;
}

//Nhập node
void input(Tree &root)
{
	int n;
    cout<<"Nhap so luong : ";
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cout<<"Nhap data cua node "<<i<<" : ";
		cin>>x;
		Node* p=CreateNode(x);
		AddNode(root,p);
	}	
}


//Xuất node
void PrintTree(Tree root)// print tree using LNR
{
    if (root)
    {
        PrintTree(root->left);
        cout << root->data <<" ";
        PrintTree(root->right);
    }
}

//Tiền tố
void NLR(Tree root)
{
    if (root)
    {
        // Xử lý nút gốc (root)
        cout<<root->data<<" ";
        NLR(root->left);
        NLR(root->right);
    }
}

//Giữa
void LNR(Tree root)
{
    if (root)
    {
        LNR(root->left);
        cout<<root->data<<" ";
        // Xử lý nút gốc (root)
        LNR(root->right);
    }
}

//Hậu tố
void LRN(Tree root)
{
    if (root)
    {
        LRN(root->left);
        LRN(root->right);
        cout<<root->data<<" ";
        // Xử lý nút gốc (root)
    }
}

//Tìm và thay thế 1
void FindAndReplace1(Tree &p, Tree &tree)
{
    if (tree->left)
        FindAndReplace1(p, tree->left);
    else
    {
        p->data = tree->data;
        p = tree;
        tree = tree->right;
    }
}

//Tìm và thay thế 2
void FindAndReplace2(Tree &p, Tree &tree)
{
    if (tree->right)
        FindAndReplace2(p, tree->right);
    else
    {
        p->data = tree->data;
        p = tree;
        tree = tree->left;
    }
}

//Xóa node
void DeleteNode(Tree &root, int x)
{
    if (root)
    {
        if (x > root->data)
            DeleteNode(root->right, x);
        else if (x < root->data)
            DeleteNode(root->left, x);
        else
        {
            Node *p = root;
            if (!root->left)
                root = root->right;
            else if (!root->right)
                root = root->left;
            else
                FindAndReplace1(p, root->right);
            //FindAndReplace2(p, rooy->left);
            delete p;
        }
    }
    else{
    	cout<<"Not found!"<<endl;
	}
}

//Tìm kiếm node 48 trên cây
Node *SearchNode(Tree root,int x)
{
	Tree Q;
    Q = root;
    while (Q != NULL && Q->data != x)
    {
        if (Q->data > x)
            Q = Q->left;
        else Q = Q->right;
    }
    return Q;
}

//Tìm kiếm node cha cua node 58
Node *SearchNodeFather(Tree root,int x){
	Tree T,Q;
    Q = SearchNode(root,x);
    T = root;
    while (T != NULL && T->data!= x)
    {
        if (T->data > x){
            if(T->left->data==x)
                break;
            T = T->left;
        }
        else
        {
            if(T->right->data==x)
                break;
            T = T->right;
        }
    }
    return T;
}

//chèn vào số 30
int insert(Tree &root,int k){
	if(root==NULL){
		root=new Node;
		root->data=k;
		root->left=root->right=NULL;
		return 1;
	}
	else if(root->data==k){
		return 2;
	}
	else if(root->data>k){
		return insert(root->left,k);
	}
	else{
		return insert(root->right,k);
	}
}

int main(){
	Tree root;
	CreateTree(root);
	input(root);
	cout<<"Cay vua nhap la: "<<endl;
	PrintTree(root);
	cout<<"\nTien to: ";
	NLR(root);
	cout<<"\nGiua: ";
	LNR(root);
	cout<<"\nHau to: ";
	LRN(root);
	int x;
	cout<<"\nNhap gia tri can xoa: ";cin>>x;
	DeleteNode(root,x);
	PrintTree(root);
	cout<<"\nDia chi node: "<<SearchNode(root,48);
	cout<<"\nDia chi cha cua node 58 la: "<<SearchNodeFather(root,58);
	//chen so 30
	int k,n;
	cout<<"\nNhap node can chen: ";
	cin>>k;
	n=insert(root,k);
	if(n==2){
	    cout<<"Chen khong thanh cong !"<<endl;	
	}
	else{
		cout<<"Chen thanh cong"<<endl;
		PrintTree(root);
	}
	return 0;
}