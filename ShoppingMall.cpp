#include <iostream>
#include <fstream>
#include <stdio.h>
#include <windows.h>
using namespace std;

class shopping{
		// Declaring global variable for class shoping
		private:                          
			int productCode;
			float price, discount;
			string productName;
		// Declearing Functions 
		public:
			void menu();
			void administrator();
			void buyer();
			void add();
			void edit();
			void remove();
			void list();
			void receipt();
};
	void shopping :: menu(){
		m:
		int choice ;
		string email, password;
		
		cout<<"\n______Supermarket Main Menu______ \n\n";
		cout<<"\n|  1) Administartor  |\n";
		cout<<"\n|  2) Buyer          |\n";
		cout<<"\n|  3) Exit           |\n";
		cout<<"\n\n Please Select !";
		cin>>choice;
		
		switch(choice){
			case 1:
				cout<<"Please Login \n";
				cout<<"Enter Email ";
				cin>>email;
				cout<<"Enter Your Password";
				cin>>password;
					if(email=="uetp@gmail.com" && password== "uetp")
						administrator();
					else
						cout<<"Invalid Credentials! ";
				break;
            case 2:
		   			buyer();
		   			break;
			case 3:
					exit();
					break;
			default:
				cout<<"Please Select from the given option";
		}
		
		goto m;
	}

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
