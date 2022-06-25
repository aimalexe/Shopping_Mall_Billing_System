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
			void remov();
			void list();
			void receipt();
};
	void shopping :: menu(){
		int select ;
		string email, password;
		tryAgain:
		   	system("cls");
			cout<<"\n\t\t*~*~*~*~*~* Supermarket Main Menu *~*~*~*~*~*\n\n";
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
				case -1:		//this is just for checking a function easily. later on we'll remove it.
						list();
						break;
				default:
					cout<<"You have Entered an Invalid Option!\n" <<
						"Please select from the given menue again.";
					sleep(3);
					goto tryAgain;
			}
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

	void shopping::edit(){
		int productKey, token = 0, productNewCode;
		float newPrice, newDiscount;
		string newProductName;
		fstream data, data1;
		
		cout<<"\n\n\t~~* Modify The Record *~~\n";
		cout<<"\n\tProduct code? ";
		cin>>productKey;
		
		data.open("database.txt", ios::in);
		if (!data)
			cout<<"\n\tFile doesn't Found!!! ";
		else{
			data1.open("database1.txt", ios::app|ios::out);
			data>>productCode>>productName>>price>>discount;
			while(data.eof()){
				if (productKey == productCode){
					cout<<"\n\tProduct/ new code? ";
					cin>>productNewCode;
					cout<<"\n\tName of product? ";
					cin>>newProductName;
					cout<<"\n\tPrice of product? ";
					cin>>price;
					cout<<"\n\tDiscount if any? ";
					cin>>discount ;
					
					data1<<" "<<productNewCode<<" "<<newProductName<<" "<<newPrice<<" "<<newDiscount<<endl;
				}
				else
					data1<<" "<<productCode<<" "<<productName<<" "<<price<<" "<<discount<<endl;
				
				data>>productCode>>productName>>price>>discount;
			}
			data.close();
			data1.close();
			remove("database.txt");
			rename("database1.txt", "database.txt");
			if(token == 0)
				cout<<"\n\tRecord not found!";		
		}
	}
	
	void shopping::remov(){
		fstream data, data1;
		int productKey, token = 0;
		
		cout<<"\n\n\t~~* Delete Products *~~\n";
		data.open("database.txt", ios::in);
		if(!data)
			cout<<"\n\tFile doesn't exists!";
		else{
			data1.open("database1.txt", ios::app|ios::out);
			data>>productCode>>productName>>price>>discount;
			while(data.eof()){
				if (productCode == productKey){
					cout<<"\n\tProduct Deleted Successfully!";
					token++;
				}
				else
					data1<<" "<<productCode<<" "<<productName<<" "<<price<<" "<<discount<<endl;
				
				data>>productCode>>productName>>price>>discount;
			}
			data.close();
			data1.close();
			remove("database.txt");
			rename("database1.txt", "database.txt");
			if(token == 0)
				cout<<"\n\tRecord not found!";		
		}
	}
	
	void shopping::list(){
		fstream data;
		data.open("database.txt", ios::in);
		cout<<"\n\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
		cout<<"\t\tproNo\t\tName\t\tPrice\n";
		cout<<"\n\t______________________________________________________________\n";
		data>>productCode>>productName>>price>>discount;
		while (!data.eof()){
			cout<<"\t\t"<<productCode<<"\t\t"<<productName<<"\t\t"<<price<<"\n";
			data>>productCode>>productName>>price>>discount;
		}
		data.close();
	}
	
	void shopping::receipt(){
		cout<<"Just for testing.....\nRemove it...\nreceipt\n";
	}

	int main(){
		shopping s;
		s.menu();
		return 0;
	}
