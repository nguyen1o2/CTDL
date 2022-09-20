#include<iostream>
using namespace std;

void nhap(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<"a["<<i<<"]=";
		cin>>arr[i];
	}
}

void xuat(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"\t";
	}
}

void sapxep(int arr[],int n){
	for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if(arr[i]>arr[j]){
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
        }
}

int banerySearch(int arr[],int n,int l,int r,int x){
	int mid;
        while(l<=r){
            mid=(l+r)/2;
            if(arr[mid]>x) r=mid-1;
            else if(arr[mid]<x) l=mid+1;
            else if (arr[mid]==x) return mid;
        }
        return -1;
}

int main(){
	int arr[100];
	int n,x;
        cout<<"Nhap n: ";
		cin>>n;
        nhap(arr,n);
        xuat(arr,n);
        sapxep(arr,n);
        cout<<endl;
        xuat(arr,n);
        cout<<"Nhap x = ";cin>>x;
        cout<<banerySearch(arr,n,0,n-1,x);
}