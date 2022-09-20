#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Nhap n= ";cin>>n;
	char a[n][20],tg[20];
    for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"mang vua nhap la"<<endl;
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	for (int i=0;i<n-1;i++) {
        int m = i; 
    for (int j=i+1;j<n;j++){
        if (strcmp(a[j],a[m])>0)
        m = j;
		}
        if(m!=i){
        strcpy(tg,a[m]);
        strcpy(a[m],a[i]);
        strcpy(a[i],tg);
		}
    }
	cout<<endl<<"mang sau khi sap xep la"<<endl;
    for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
