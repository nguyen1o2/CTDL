#include<iostream>
using namespace std;

int main(){
	int menhgia[5]={10000,5000,2000,1000,500};
	int sotien;
	int sototien;
	do{
	cout<<"Nhap vao so tien can doi: ";
	cin>>sotien;
	}while(sotien<0);
	
		for(int i=0;i<5;i++){
			sototien=sotien/menhgia[i];
			if(sototien!=0){
				cout<<"Co "<<sototien<<" to "<<menhgia[i]<<endl;
			}
			sotien = sotien%menhgia[i];
	    }	
	
	return 0;
}