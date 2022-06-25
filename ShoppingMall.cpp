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
		int select ;
		string email, password;
	   tryAgain:
	   	system("cls");
		cout<<"\n\t\t______Supermarket Main Menu______ \n\n";
		cout<<"\n\t|\t1) Administartor  |\n";
		cout<<"\n\t|\t2) Buyer          |\n";
		cout<<"\n\t|\t3) Exit           |\n";
		cout<<"\n\tPlease Select! any from above: ";
		cin>>select;
		
		switch(select){
			case 1:
				cout<<"\tHi! Please Login \n";
				cout<<"\tEnter Email: ";
				cin>>email;
				cout<<"\tEnter Your Password: ";
				cin>>password;
					if(email=="uetp@gmail.com" && password== "uetp")
						administrator();
					else
						cout<<"\n\tSorry! Invalid Credentials! ";
				break;
            case 2:
		   			buyer();
		   			break;
			case 3:
					system("exit");
					break;
			default:
				cout<<"You have Entered an Invalid Option!\n" <<
					"Please select from the given menue again.";
		}
		sleep(3);
		goto tryAgain;
	}
	
	void shopping::administrator(){
		cout<<"Just for testing.....\nRemove it...\nadministration\n";
	}
	
	void shopping::buyer(){
		cout<<"Just for testing.....\nRemove it...\buyer\n";
	}
	
	void shopping::add(){
		cout<<"Just for testing.....\nRemove it...\nadd\n";
	}

	void shopping ::edit(){
		int productKey, token = 0, productNewCode;
		string productName;
		fstream data, data1;
		
		cout<<"Modify The Record\n";
		cout<<"Product code? ";
		cin>>productKey;
		
		data.open("database.txt", ios::in);
		if (!data){
			cout<<"\nFile doesn't Found!!! ";
			
		}else{
			data.open("database1.txt", ios::app|ios::out);
		}
	}
	
	void shopping::remove(){
		cout<<"Just for testing.....\nRemove it...\nremove\n";
	}
	
	void shopping::list(){
		cout<<"Just for testing.....\nRemove it...\nlist\n";
	}
	
	void shopping::receipt(){
		cout<<"Just for testing.....\nRemove it...\nreceipt\n";
	}

	int main(){
		shopping s;
		s.menu();
		return 0;
	}
