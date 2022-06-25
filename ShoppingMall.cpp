#include <iostream>
#include <fstream>
#include <stdio.h>
#include <windows.h>
using namespace std;

class shopping{
		// Declaring global variable for class shopping
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
	   tryAgain:
		int select ;
		string email, password;
<<<<<<< HEAD
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
=======
		tryAgain:
		   	system("cls");
			cout<<"\n\t\t*~*~*~*~*~* Supermarket Main Menu *~*~*~*~*~*\n\n";
			cout<<"\n\t|\t1) Administrator  |\n";
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
						receipt();
						break;
				default:
					cout<<"You have Entered an Invalid Option!\n" <<
						"Please select from the given menu again.";
					sleep(3);
					goto tryAgain;
			}
>>>>>>> 2534e41a6c0ebe7fc671be181dd8401d56886354
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
		fstream data;
		int prodCode[100], prodQuantity[100], index=0;
		float amount, purchaseDiscount=0, total=0;
		char buyMore;
		
		cout<<"\n\n\t~~* Receipt *~~\n";
		data.open("database.txt", ios::in);
		if (!data)
			cout<<"\nEmpty Database!";
		else{
			data.close();
			list();
			cout<<"\t\tPlease place the order!";
			
			enterAgain:
				do{
					cout<<"\n\tEnter product code:-";
					cin>>prodCode[index];
					cout<<"\n\tEnter product quantity? ";
					cin>>prodQuantity[index];
					for (int i = 0; i<index; i++)
						if(prodCode[index]==prodCode[i]){
							cout<<"\n\tDuplicate Items/ Product Code! Please try again.";
							goto enterAgain;
						}
					index++;
					cout<<"\n\tDo you want to Buy More?\n\tIf yes Press y! ";
					cin>>buyMore;
				}while(buyMore == 'y' || buyMore == 'Y');
				
				cout<<"\n\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^~~ RECEIPT ~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
				cout<<"\tProduct No.\tName\t\tQuantity\tPrice\tAmount\tAmount with Discount\n";
				cout<<"\n\t__________________________________________________________________________________________\n";
				for (int i = 0; i<index ; i++){
					data.open("database.txt", ios::in);
					data>>productCode>>productName>>price>>discount;
					while(!data.eof()){
						if (productCode == prodCode[i]){
							amount = price * prodQuantity[i];
							discount = amount -  (amount * discount / 100);
							total = amount + discount;
							cout<<"\n\t"<<productCode<<"\t\t"<<productName<<"\t\t"<<prodQuantity[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<discount<<"\n";
						}
						data>>productCode>>productName>>price>>discount;
					}
				}
				data.close();
			}
			cout<<"\n\t__________________________________________________________________________________________\n";
			cout<<"\n\tTotal Amount: "<<total;
	}

	int main(){
		shopping s;
		s.menu();
		return 0;
	}
