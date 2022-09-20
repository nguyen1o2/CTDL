#include<iostream>
using namespace std;

long sum(int a[],int n,int left,int right){
    if(left==right) return a[left];
    else {
    	return sum(a,n,left,(left+right)/2)+sum(a,n,((left+right)/2)+1,right);
	}
}

int main(){
	int n,a[100];
	cout<<"Nhap n= ";cin>>n;
	for(int i=0;i<n;i++){
		cout<<"a["<<i<<"]=";
		cin>>a[i];
	}
	cout<<"Tong cua day so la: "<<sum(a,n,0,n-1);
	return 0;
}
/* sum(a[],n,l,r) { a[l] neu l=r
                    sum(a,n,l,(l+r)/2)+sum(a,n,(l+r)/2+1,r) th con lai