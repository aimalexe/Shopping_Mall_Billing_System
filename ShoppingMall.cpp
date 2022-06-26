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
		int select ;
		string name, password;
		tryAgain:
		   	system("cls");
			cout<<"\n\t\t~*~*~*~*~*~*~*~*~*~*~*~* Supermarket Main Menu ~*~*~*~*~*~*~*~*~*~*~*~*\n\n";
			cout<<"\n\t1) Administartor";
			cout<<"\n\t2) Buyer";
			cout<<"\n\t3) Exit";
			cout<<"\n\tPlease Select! any from above: ";
			cin>>select;
			
			switch(select){
				case 1:
					cout<<"\n\tHi! Please Login";
					cout<<"\n\tEnter Name: ";
					cin>>name;
					cout<<"\tEnter Your Password: ";
					cin>>password;
						if(name=="admin" && password== "0000")
							administrator();
						else{
							cout<<"\n\tSorry! Invalid Admin Credentials!";
							sleep(2);
						}
					break;
				case 2:
			   			buyer();
			   			break;
				case 3:
						system("exit");
						break;
				case 4:
					edit();
					break;
					
				default:
					cout<<"\n\tYou have Entered an Invalid Option!\n\t" <<
						"Please select from the given menue again.";
					sleep(2);
			}
		goto tryAgain;
		
	}
	
	void shopping::administrator(){
		int choice;
		selectAgain:
			cout<<"\n\n\t~~* Administrator Menu *~~\n";
			cout<<"\n\t1) Add the product";
			cout<<"\n\t2) Modify the product";
			cout<<"\n\t3) Delete the product";
			cout<<"\n\t4) Back To main Menu";
		
		    cout<<"\n\tPlease select the correct one: ";
		    cin>>choice;
		    switch(choice){
		    	case 1:
					add();
		    		break;
		    	
		    	case 2:
		    		edit();
		    		break;
		    	
				case 3:
					remov();
					break;
				
				case 4:
					menu();
					break;
				
				default:
					cout<<"\n\tInvalid Selection!";						
					sleep(2);    	
			}
	  goto selectAgain;
	}
	
	void shopping::add(){
         fstream data;
		 int c, token=0;
		 float p, d;
		 string n;
		 cout<<"\n\n\t~~* Add a New Product *~~\n";
		 cout<<"\n\tCode of the product: ";
		 cin>>productCode;
		 cout<<"\tName of the product: "; 
		 cin>>productName;
		 cout<<"\tPrice of the Product: ";
		 cin>>price;
		 cout<<"\tDiscount on product: ";
		 cin>>discount;
		 
		 data.open("ProductList.txt", ios::in);
		 if(!data){
		 	data.open("ProductList.txt", ios::app|ios::out);
		 	data<<"\t"<<productCode<<"\t"<<productName<<"\t"<<price<<"\t"<<discount<<"\n";
			data.close();
		 }else{
		 	data>>c>>n>>p>>d;
		 	while(!data.eof()){
		 		if(c==productCode)
		 			token++;
				data>>c>>n>>p>>d;
			}
			data.close();
			if(token==1){
				cout<<"\n\tThis product already exists!";
				sleep(2);
				administrator();
			}
			else{
			 	data.open("ProductList.txt", ios::app|ios::out);
			 	data<<"\t"<<productCode<<"\t"<<productName<<"\t"<<price<<"\t"<<discount<<"\n";
			 	data.close();
			}
		}
		cout<<"\n\tRecord Successfuly Inserted!";
	}
	
	void shopping::edit(){
		int productKey, token = 0, productNewCode;
		float newPrice, newDiscount;
		string newProductName, insertingMore;
		fstream data, data1;
		
		cout<<"\n\n\t~~* Modify The Record *~~\n";
		cout<<"\n\tProduct code? ";
		cin>>productKey;
		
		data.open("ProductList.txt", ios::in);
		if (!data)
			cout<<"\n\tFile doesn't Found!!! ";
		else{
			data1.open("ProductList1.txt", ios::app|ios::out);
			data>>productCode>>productName>>price>>discount;
			while(!data.eof()){
				if (productKey == productCode){
					cout<<"\n\tProduct new code? ";
					cin>>productNewCode;
					cout<<"\tNew name of product? ";
					cin>>newProductName;
					cout<<"\tPrice of product? ";
					cin>>price;
					cout<<"\tDiscount if any? ";
					cin>>discount ;
					token++;
					
					data1<<"\t"<<productNewCode<<"\t"<<newProductName<<"\t"<<newPrice<<"\t"<<newDiscount<<endl;
				}
				else
					data1<<"\t"<<productCode<<"\t"<<productName<<"\t"<<price<<"\t"<<discount<<endl;
				data>>productCode>>productName>>price>>discount;
			}
			data.close();
			data1.close();
			remove("ProductList.txt");
			rename("ProductList1.txt", "ProductList.txt");
			if(token == 0)
				cout<<"\n\tRecord not found!";
			else
				cout<<"\n\tRecord Modefied Successfully!";
		}

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
