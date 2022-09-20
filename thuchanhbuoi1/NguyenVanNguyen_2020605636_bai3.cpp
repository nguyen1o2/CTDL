#include <iostream>
#include <string.h>
using namespace std;

void reverse_string(char x[], int start, int end)
{
    char ch;
    if (start >= end)
       return;
    ch = x[start];
    x[start] = x[end];
    x[end] = ch;
    reverse_string(x, ++start, --end);
}

int main()
{
  	char string_array[150];
    cout<<"Nhap vao chuoi: ";
    cin>>string_array;
    reverse_string(string_array, 0, strlen(string_array)-1);
    cout<<"Chuoi dao nguoc la: "<<string_array;
   	cout<<"\n-------------------------------\n";
}
