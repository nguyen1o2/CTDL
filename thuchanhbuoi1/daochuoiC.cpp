#include<iostream>
#include<stdio.h>
using namespace std;

void daochuoi(){
	char c;
    scanf("%c",&c);
    if(c!='\n'){
    	daochuoi();
    	printf("%c",c);
	}
}
int main(){         
	cout<<"Nhap chuoi: ";
	daochuoi();
    return 0;
}           