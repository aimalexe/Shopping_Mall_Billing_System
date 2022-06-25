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
	   tryAgain:
		int select ;
		string email, password;
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
	//	sleep(3);
		goto tryAgain;
	}
	
	void shopping::administrator()
	{
		tryAgain:
		int choice;
		cout<<"\n Administrator Menu";
		cout<<"\n\n___1) Add the product____\n";
		cout<<"\n\n___2) Modify the product____\n";
		cout<<"\n\n___3) Delete the product____\n";
		cout<<"\n\n___4) Back To main Menu____\n";
	
	    cout<<"\n Please enter your choice";
	    switch(choice)
	    {
	    	case 1:
			 add();
	    	 break;
	    	
	    	case 2:
	    	 edit();
	    	 break;
	    	
			case 3:
			 remove();
			 break;
			
			case 4:
			 menu();
			 break;
			
			default:
			 cout<<"Invalid choice";    	
		}
	  goto tryAgain	;
	}
	
	void shopping::buyer(){
		tryAgain:
		int choice;
		cout<<"\n\t Buyer ";
		cout<<"\n\t\v_________";
		cout<<"\t   Buy Product  \n";
		cout<<"\t Go Back  \n";
		cout<<"Enter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				receipt();
				break;
			case 2:
			    menu();
				
			default :
			    cout<<"Invalid Choice ";		
		}
		goto tryAgain;
	}
	
	void shopping::add(){
         fstream data;
		 int c, token=0;
		 float p, d;
		 string n;
		 cout<<"\n\t Add new product \n";
		 cout<<"\n\t Product code of the product ";
		 cin>>productCode;
		 cout<<"\n\t Name of the product "; 
		 cin>>productName;
		 cout<<"\n\t Price of the Product ";
		 cin>>price;
		 cout<<"\n\t Discount on product ";
		 cin>>discount;
		 
		 data.open("database.txt", ios::in);
		 if(!data)
		 {
		 	data.open("database.txt", ios::app|ios::out);
		 	data<<" "<<productCode<<" "<<productName<<" "<<price<<" "<<discount<<" \n";
			data.close();
		 }
		 else
		 {
		 	data>>c>>n>>p>>d;
		 	while(!data.eof())
		 	{
		 		if(c==productCode)
		 		{
		 			token++;
				 }
				 data>>c>>n>>p>>d;
			}
			data.close();

		if(token==1)
		 goto tryAgain;
		 else{
		 	data.open("database.txt", ios::app|ios::out);
		 	data<<" "<<productCode<<" "<<productName<<" "<<discount<<" \n";
		 	data.close();
		 }
}
cout<<"\n\t Record Inserted : ";
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
