#include<iostream>
#include<math.h>
using namespace std;

class HINHTRON{
	private:
	    float r;
	public:
		void nhap();
		float CV(){
		 	return 2*M_PI*r;
		}
		float DT(){
			return M_PI*r*r;
		}
		void xuat();
};
void HINHTRON::nhap(){
	cout<<"Nhap ban kinh: ";cin>>r;
}

void HINHTRON::xuat(){
	cout<<"Chu vi hinh tron: "<<CV()<<endl;
//	cout<<"Dien tich hinh tron: "<<DT();
}
int main(){
	HINHTRON ht1;
	ht1.nhap();
	ht1.xuat();
	cout<<"Dien tich hinh tron: "<<ht1.DT();
}