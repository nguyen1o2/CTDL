#include<iostream>
using namespace std;
void nhap(int *a,int n){
	for(int i=0;i<n;i++){
		cout<<"Nhap a["<<i<<"]=";
		cin>>a[i];
	}
}

void xuat(int *a,int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}

void sapxepchen(int *a,int n){
    for (int i=1; i<n; i++){
        int tam = a[i];
        int j = i-1; 
    while (j>-1 && a[j]<tam){
        a[j+1] =a[j];
        j--;
        }
    a[j+1] = tam;
    }
}

int main(){
	int n,*a;
	cout<<"Nhap n= ";cin>>n;
	a=new int [n];
	nhap(a,n);
	cout<<"mang vua nhap la"<<endl;
	xuat(a,n);
	sapxepchen(a,n);
	cout<<endl<<"mang sau khi sap xep la"<<endl;
	xuat(a,n);
}