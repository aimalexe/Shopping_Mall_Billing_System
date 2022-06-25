#include <iostream>
#include <stdio.h>
#include <windows.h>
using namespace std;

void shoping ::edit(){
	int productKey, token = 0, productNewCode;
	string productName;
	
	cout<<"Modify The Record\n";
	cout<<"Product code? ";
	cin>>productKey;
	
	data.open("database.txt", ios::in);
	if (!data){
		cout<<"\nFile doesn't Found!!! ";
		
	}else{
		Data.open("database1.txt", ios::app|ios::out);
		data >> 
	}
}

int main(){
	shoping s;
	s.menue();
	return 0;
}
