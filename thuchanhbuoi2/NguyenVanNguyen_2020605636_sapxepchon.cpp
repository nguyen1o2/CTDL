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

void sapxepchon(int *a,int n){
for (int i=0; i<n-1; i++) {
        int m = i; 
    for (int j=i+1; j<n; j++){
        if (a[j] > a[m])
        m = j;
		}
        if(m!=i){
        int tg = a[m];
        a[m] = a[i];
        a[i] = tg;
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
	sapxepchon(a,n);
	cout<<endl<<"mang sau khi sap xep la"<<endl;
	xuat(a,n);
}
