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

void sapxepnoibot(int *a,int n){
	for(int i=1;i<n;i++){
		for(int j=n-1;j>=i;j--){
			if(a[j]<a[j-1]){
				int tg=a[j];
			    a[j]=a[j-1];
			    a[j-1]=tg;	
			}
		}
	}
}

int main(){
	int n,*a;
	cout<<"Nhap n= ";cin>>n;
	a=new int [n];
	nhap(a,n);
	cout<<"mang vua nhap la"<<endl;
	xuat(a,n);
	sapxep(a,n);
	cout<<endl<<"mang sau khi sap xep la"<<endl;
	xuat(a,n);
}