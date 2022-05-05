#include<iostream>
#include<string>
using namespace std;

char keyMatrix[5][5];

void createKeyMatrix(string text)
{
	int len = text.length();
	char charArray[len];        
	int n = 0;
	for(int i =0;i<len;i++)
	{
		if(text[i]==' ')
		{
			continue;
		}
		charArray[n] = toupper(text[i]);
		n++;
	}
	
	//array of alphabets
	char alphabets[26];
	for(int i=0;i<26;i++)
	{
		alphabets[i] = i+65;
	}
	
	char oneD[26];
	int p = 0;
	oneD[0] = charArray[0];
	
	for(int i=1;i<n;i++)
	{
		bool duplicate = false;
		for(int j=0;j<i;j++)
		{
			if(charArray[i]==charArray[j])   //avoid duplicates
			{
				duplicate = true;
				break;	
			}	
		}
		if(duplicate==false)
		{
			oneD[++p] = charArray[i];
		}
	
	}
	if(p<26)
	{
		for(int i=0;i<26;i++)
		{
			bool duplicate = false;
			for(int j=0;j<p;j++)
			{
				if(alphabets[i]==oneD[j])
				{
					duplicate = true;
					break;
				}
			}
			if(duplicate==false)
			{
				oneD[++p] = alphabets[i];
			}
		}
				
		p = 0;		
		for(int i= 0;i<5;i++)
		{
			for(int j= 0;j<5;j++)
			{
				if(oneD[p]=='J')		//exclude J
				{ 
					p++;
				}
				keyMatrix[i][j] = oneD[p];
				p++;
			}
		}
		cout<<"\n\n ->  The Key Matrix for Playfair Cipher for given Key is : \n\n";
		for(int i=0;i<5;i++)
		{
			cout<<"		   ";
			for(int j=0;j<5;j++)
			{
				cout<<keyMatrix[i][j]<<" ";
			}
			cout<<"\n";
		}

	}	
}

string getBigrams(string msg)
{
	int len = msg.length();
	char a[len]; 
	int n = 0;
	char bigrams[len];
	for(int i=0;i<len;i++)
	{
		if(msg[i]==' ')   //ignore space
		{	
			continue;
		}
		else if(msg[i]=='j'||msg[i]=='J')
		{
			a[n] = 'I'; 	//replace j or J  with I
			n++;	
		}
		else
		{
			a[n] = toupper(msg[i]); 
			n++;
		}
		
	}
	
	// to handle repeated alphabets like balloon == ba lx lo on 
	int k = 0;
	char filler = 'X';
	bool filled = false;
	for(int i=0;i<n;i+=2 )
	{
		bigrams[k] = a[i];
		k++;
		if(i+1!=n)
		{
			if(a[i]==a[i+1] && filled== false)
			{
				bigrams[k] = filler;
				k++;
				bigrams[k] = a[i+1];
				k++;
				filled = true;
				continue;
			}
			else
			{
				bigrams[k]=a[i+1];
				k++;
			}
		}
	}
	if(k%2!=0)	
	{
	 	bigrams[k] = filler;
	 	bigrams[k+1 ] ='\0';
	}
	else
	{
	 	bigrams[k] = '\0';
	}
	return bigrams;
}
	
void getPosition(char a,char b,int &a_row,int &a_column,int &b_row, int &b_column) 
{
	bool match_a = false;
	bool match_b = false;
	for(int i=0;i<5;i++)
	{
		for(int j =0;j<5;j++)
		{
			if(keyMatrix[i][j]==a && match_a!=true)
			{
				a_row = i;
				a_column = j;
				match_a = true;
			}
			if(keyMatrix[i][j]==b && match_b!=true)
			{
				b_row = i;
				b_column = j;
				match_b = true;	
			}	
		}
		if(match_a && match_b)
		{
			break;
		}
	}
}


int mod(int a, int b)   // to handle module operation 
{
	int c = a%b;
	if(c>=0)
	{
		return c;
	}
	else
	{
		return b+c;
	}
}	



void Encrypt(string msg, string key)
{
	createKeyMatrix(key);
 	cout<<"\n\n 	 ||||  Encryption Process  |||| \n";
 	string bg = getBigrams(msg);
 	int n = bg.length();
 	char ct[n];     //to store cipher text
 	int x = 0;
 	while(x<n)
 	{
 		int a_row=0,a_col=0,b_row=0,b_col=0;
 		char ca=' ',cb=' ';
 	 	getPosition(bg[x],bg[x+1],a_row,a_col,b_row,b_col);
 	 	if(a_row==b_row)
 	 	{
 	 		ca= keyMatrix[a_row][mod((a_col+1),5)];
 	 		cb=	keyMatrix[b_row][mod((b_col+1),5)];
		}
		else if(a_col==b_col)
		{
			ca= keyMatrix[mod((a_row+1),5)][a_col];
			cb=	keyMatrix[mod((b_row+1),5)][b_col];
		}
		else
		{
			ca= keyMatrix[a_row][b_col];
			cb= keyMatrix[b_row][a_col];
		}
		cout<<"\n	   	  "<<bg[x]<<bg[x+1]<<" ---> "<<ca<<cb;
		ct[x] = ca;
		ct[x+1] = cb;
		x+=2;
 	}
	cout<<"\n\n\n\n ->  The Cipher Text  : " ;
 	for(int i=0;i<n;i++)
 	{
		ct[i] = tolower(ct[i]);
		cout<<ct[i];
	}
}

	
void Decrypt(string msg, string key)
{
	createKeyMatrix(key);
 	cout<<"\n\n 	 ||||  Decryption Process  |||| \n";
 	string bg = getBigrams(msg);
 	int n = bg.length();
 	char pt[n];				//to store plain text
 	int x=0;
 	while(x<n)
 	{
 		int a_row=0,a_col=0,b_row=0,b_col=0;
 		char pa = ' ', pb = ' ';
 		char c1 = toupper(bg[x]);
 		char c2 = toupper(bg[x+1]);
 	 	getPosition(c1,c2,a_row,a_col,b_row,b_col);
 	 	//cout<<a_row<<","<<a_col<<","<<b_row<<","<<b_col;
 	 	if(a_row==b_row)
 	 	{
 	 		pa= keyMatrix[a_row][mod((a_col-1),5)];
 	 		pb=	keyMatrix[b_row][mod((b_col-1),5)];
		}
		else if(a_col==b_col)
		{
			pa= keyMatrix[mod((a_row-1),5)][a_col];
			pb=	keyMatrix[mod((b_row-1),5)][b_col];
			
		}
		else
		{
			pa= keyMatrix[a_row][b_col];
			pb= keyMatrix[b_row][a_col];
			
		}
		cout<<"\n	   	  "<<bg[x]<<bg[x+1]<<" --->"<<pa<<pb;
		pt[x] = pa;
		pt[x+1] = pb;
		x += 2;
 	}
	cout<<"\n\n\n\n ->  The Plain Text  : " ;
 	for(int i=0;i<n;i++)
 	{
		pt[i] = tolower(pt[i]);
 		cout<<pt[i];
	}
		
}	




int main()
{		
	char ch;
	int choice;

	string key, text;
	
	do
	{
		cout<<"\n		 	 ||||||||    Playfair Cipher    |||||||||";
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
						 Encrypt(text,key);
						 break;
					 }
					 
			case 2 : {
						 cout<<"\n Enter the Cipher text to Decrpyt : "; 
						 cin.ignore();
						 getline(cin, text);
						 cout<<"\n Enter the Key : ";
						 cin>>key;
						 Decrypt(text,key);
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
