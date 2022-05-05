
//    Caeser Cipher  //

#include<iostream>
#include<string>
using namespace std;

int main()
{		
	char ch;
	int choice;
	string text = "";
	int key;
	
	
	do
	{
		cout<<"\n		 	 ||||||||    Caeser Cipher    |||||||||";
		cout<<"\n\n\n 1. Encryption to Decryption";
		cout<<"\n 2. Decryption to Encryption";
		cout<<"\n\n Enter Your Choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1 : {
						 cout<<"\n Enter the Plain Text to Encrpyt : "; 
						 cin.ignore();
						 getline(cin, text);
						 cout<<"\n Enter the Key : ";
						 cin>>key;
						 int len = text.length();
						 for (int i=0; i<len; i++)
						 {
							 char temp1 = text[i];
							 char temp2 = char(((int(temp1)) + key)%128);
							 text[i] = temp2;
						 }
						 cout<<"\n Encryption successful. !!!!!";
						 cout<<"\n\n -> Cipher Text : "<<text;
						 break;
					 }
					 
			case 2 : {
						 cout<<"\n Enter the Cipher text to Decrpyt : "; 
						 cin.ignore();
						 getline(cin, text);
						 cout<<"\n Enter the Key : ";
						 cin>>key;
						 int len = text.length();
						 for (int i=0; i<len; i++)
						 {
							 char temp1 = text[i];
							 char temp2 = char(((int(temp1)) - key)%128);
							 text[i] = temp2;
						 }
						 cout<<"\n Decryption successful. !!!!!";
						 cout<<"\n\n -> Plain Text : "<<text;
						 break;
					 }
			default : cout<<"\n You have entered Wrong Choice ";	
					  break;
		}
		
		cout<<"\n\n\n Press 'Y' for try again and To Exit Press 'N' : ";
		cin>>ch;
		cout<<endl<<endl;
	}while(ch=='Y'||ch=='y');
	
		
	return 0;
}
