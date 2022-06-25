#include <iostream>
#include <fstream>
using namespace std;
main(){
	class shopping
	{
		/* Declaring global variable for this class*/
		private:                          
			int productCode;
			float price;
			float discount;
			string productName;
			// Function declartion 
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
	void shopping :: menu()
	{
		m:
		int choice ;
		string email;
		string password;
		
		cout<<"\n______Supermarket Main Menu______ \n\n";
		cout<<"\n|  1) Administartor  |\n";
		cout<<"\n|  2) Buyer  |\n";
		cout<<"\n|  3) Exit  |\n";
		cout<<"\n\n Please Select !";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
			cout<<"Please Login \n";
			cout<<"Enter Email ";
			cin>>email;
			cout<<"Enter Your Password";
			cin>>password;
			if(email=="uetp@gmail.com" && password== "uetp")
			{
				administrator();
			}
			else
			{
				cout<<"Invalid Email/Password";
			}
			break;
		
            case 2:
	        {
		   			buyer();
			}
			case 3:
			{
					exit();
			}
			default:{cout<<"Please Select from the given option"; }
		}
		
goto m;
	}




}
