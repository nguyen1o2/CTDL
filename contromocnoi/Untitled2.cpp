#include<bits/stdc++.h>

using namespace std;

//Khai bao cau truc du lieu cay nhi phan tim kiem

struct NODE
{
    int infor;
    NODE *Left, *Right;
};
NODE *ROOT;


//Khoi tao 1 cay rong

void Khoitao(NODE *&Root)
{
    Root = NULL;
}
typedef NODE*TRO;
//Tao 1 cay voi du lieu nhap tu ban phim
void ThemNut(NODE *&Root, int x)
{
    if (Root == NULL)
    {
        NODE *q;
        q = new NODE;
        q->infor = x;
        q->Left = q->Right = NULL;
        Root = q;
    }
    else
    {
        if (x< Root->infor)
            ThemNut(Root->Left,x);
        else if (x > Root->infor)
            ThemNut(Root->Right,x);
    }
}
void TaoCay(NODE *&Root)
{
    int Data;
    do
    {
        cout<<"Nhap so nguyen, ket thuc nhap -1: ";
        cin>>Data;

        if (Data == -1)
            break;
        ThemNut(Root, Data);
    }
    while(1);
}

TRO Timnut(TRO Root, int x)
{
    TRO Q;
    Q = Root;

    while (Q != NULL && Q->infor != x)
    {
        if (Q->infor > x)
            Q = Q->Left;
        else Q = Q->Right;
    }
    return Q;
}

TRO Timnutcha(TRO Root,int x )
{
    TRO T,Q;
    Q = Timnut(Root, x);
    T = Root;
    while (T != NULL && T->infor!= x)
    {
        if (T->infor > x){
            if(T->Left->infor==x)
                break;
            T = T->Left;
        }
        else
        {
            if(T->Right->infor==x)
                break;
            T = T->Right;
        }
    }
    return T;
}
void NodeTheMang(TRO &X, TRO &Y) // NODE Y l? node th? m?ng cho node c?n x?a - node n?y s? d?m nh?n nhi?m v? t?m ra node tr?i nh?t(T?M NODE TR?I NH?T C?Y CON PH?I) ho?c ph?i nh?t(T?M NODE PH?I NH?T C?A C?Y CON TR?I)
{
    // C?CH 1: T?M NODE TR?I NH?T C?A C?Y CON PH?I
    // duy?t sang b?n tr?i nh?t
    if (Y->Left != NULL)
    {
        NodeTheMang(X, Y->Left);// t?m ra node tr?i nh?t ?
    }
    else // t?m ra du?c node tr?i nh?t r?i nek..
    {
        X->infor = Y->infor; // c?p nh?t c?i data c?a node c?n x?a ch?nh l? data c?a node th? m?ng
        X = Y; // cho node X(l? node m? ch?ng ta s? di x?a sau n?y) tr? d?n node th? m?ng ==> ra kh?i h?m th? ta s? x?a node X
        Y = Y->Right; // b?n ch?t ch? n?y ch?nh l? c?p nh?t l?i m?i li?n k?t cho node cha c?a node th? m?ng(m? ch?ng ta s? x?a) v?i node con c?a node th? m?ng
    }

    /* C?CH 2: T?M NODE PH?I NH?T C?A C?Y CON TR?I
     duy?t sang b?n ph?i
     if (Y->pRight != NULL)
    {
        DiTimNodeTheMang(X, Y->pRight);// t?m ra node ph?i nh?t ?
    }
    else // t?m ra du?c node ph?i nh?t r?i nek..
    {
        X->data = Y->data; // c?p nh?t c?i data c?a node c?n x?a ch?nh l? data c?a node th? m?ng
        X = Y; // cho node X(l? node m? ch?ng ta s? di x?a sau n?y) tr? d?n node th? m?ng ==> ra kh?i h?m th? ta s? x?a node X
Y = Y->pLeft; // b?n ch?t ch? n?y ch?nh l? c?p nh?t l?i m?i li?n k?t cho node cha c?a node th? m?ng(m? ch?ng ta s? x?a) v?i node con c?a node th? m?ng
    } */
}

void XoaNode(TRO &t, int infor) // data ch?nh l? gi? tr? c?a c?i node c?n x?a
{
    // n?u nhu c?y dang r?ng
    if (t == NULL)
    {
        return; // k?t th?c h?m
    }
    else
    {
        // n?u nhu data nh? hon node g?c
        if (infor < t->infor)
        {
            XoaNode(t->Left, infor); // duy?t sang nh?nh tr?i c?a c?y
        }
        else if (infor > t->infor)
        {
            XoaNode(t->Right, infor); // duy?t sang nh?nh ph?i c?a c?y
        }
        else // data == t->data - d? t?m ra c?i node c?n x?a
        {
            NODE *X = t; // node X l? node th? m?ng - t? n?a ch?ng ta s? x?a n?
            // n?u nhu nh?nh tr?i b?ng NULL <=> d?y l? c?y c? 1 con ch?nh l? con ph?i
            if (t->Left == NULL)
            {
                // duy?t sang ph?i c?a c?i node c?n x?a d? c?p nh?t m?i li?n k?t gi?a node
                // cha c?a node c?n x?a v?i node con c?a node c?n x?a
                t = t->Right;
            }
            else if (t->Right == NULL)
            {
                // duy?t sang tr?i c?a c?i node c?n x?a d? c?p nh?t m?i li?n k?t gi?a node
                // cha c?a node c?n x?a v?i node con c?a node c?n x?a
                t = t->Left;
            }
            else // node c?n x?a l? node c? 2 con
            {
                // C?CH 1: T?m node tr?i nh?t c?a c?y con ph?i(c?y con ph?i c?a c?i node c?n x?a)
                NodeTheMang(X, t->Right);
                // C?CH 2: T?m node ph?i nh?t c?a c?y con tr?i(c?y con tr?i c?a c?i node c?n x?a)
                //DiTimNodeTheMang(X, t->pLeft);
            }
            delete X; // x?a node c?n x?a
        }
    }
}

void NLR(NODE *root)
{
    if(root!=NULL)
    {
        if(root!=NULL)
        {
            cout<<root->infor<<" ";
        }
        NLR(root->Left);
        NLR(root->Right);
    }
}
void LNR(NODE *root)
{
    if(root!=NULL)
    {
        LNR(root->Left);
        if(root!=NULL)
        {
            cout<<root->infor<<" ";
        }
        LNR(root->Right);
    }
}
void LRN(NODE *root)
{
    if(root!=NULL)
    {
        LRN(root->Left);
        LRN(root->Right);
        if(root!=NULL)
        {
            cout<<root->infor<<" ";
        }
    }
}
int main()
{
    NODE *Root;
    Khoitao(Root);
    TaoCay(Root);
    cout<<"\nIn thu tu truoc : "<<endl;
    NLR(Root);
    cout<<"\nIn thu tu giua : "<<endl;
    LNR(Root);
    cout<<"\nIn thu tu sau : "<<endl;
    LRN(Root);
    ThemNut(Root,35);
    cout<<"\nCay sau khi chen : "<<endl;
    NLR(Root);
    cout<<"\nNut 48 : "<<endl;
    NLR(Timnut(Root,48));
    cout<<"\nNut cha cua 58 : "<<endl;
    NLR(Timnutcha(Root,58));
    XoaNode(Root,55);
    cout<<"\nCay sau khi xoa: "<<endl;
    NLR(Root);
    return 0;
}