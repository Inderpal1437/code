#include<iostream>
#include<string>
using namespace std;

#define MAX 50

int XOR(int a, int b)
{
	int value = 1;
	if(a==b)
	{
		value = 0; 
	}
	return value;
}
	
void Encrypt()
{
	int text[MAX];			
	int key[MAX];
	int len;				
	
	cout<<"\n Enter the length of the text : ";
	cin>>len;
	
	cout<<"\n Enter Plain text : \n";
	for (int i=0; i<len; i++)
	{
		cout<<"		    ";
		cin>>text[i];	
	}
	
	cout<<"\n Enter key values : \n";
	for (int i=0; i<len; i++)
	{
		cout<<"		    ";
		cin>>key[i];	
	}
	
	for (int i=0; i<len; i++)
	{
		text[i] = XOR(text[i], key[i]);	
	}
		
	cout<<"\n\n -> Encrypted Message : ";		
	for (int i=0; i<len; i++)
	{
		cout<<text[i]<<" ";	
	}
	cout<<endl;
}


void Decrypt()
{
	int text[MAX];			
	int key[MAX];
	int len;				      	
	
	cout<<"\n Enter the length of the text : ";
	cin>>len;
		
	cout<<"\n Enter Cipher text : \n";
	for (int i=0; i<len; i++)
	{
		cout<<"		    ";
		cin>>text[i];	
	}
		
	cout<<"\n Enter key values : \n";
	for (int i=0; i<len; i++)
	{
		cout<<"		    ";
		cin>>key[i];	
	}
	
	for (int i=0; i<len; i++)
	{
		text[i] = XOR(text[i], key[i]);	
	}
		
	cout<<"\n\n -> Decrypted Message : ";		
	for (int i=0; i<len; i++)
	{
		cout<<text[i]<<" ";	
	}
	cout<<endl;
}



		


int main()
{		
	char ch;
	int choice;

	string key, text;
	
	do
	{
		cout<<"\n		 	 ||||||||    Stream Cipher    |||||||||";
		cout<<"\n\n\n 1. Encryption to Decryption";
		cout<<"\n 2. Decryption to Encryption";
		cout<<"\n\n Enter Your Choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1 : {
						 
						 Encrypt();
						 break;
					 }
					 
			case 2 : {
						 
						 Decrypt();
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
