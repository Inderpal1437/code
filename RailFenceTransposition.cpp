#include<iostream>
#include<string>
using namespace std;

#define MAX 10
char railMatrix[MAX][MAX];

void Encrypt(string text, int depth)
{
	// creating a matrix to encrypt text with depth 
	int	nrow = depth;
	int	ncol = text.length();
	int len = text.length();
	char railMatrix[nrow][ncol]; 
	  
	// filling the rail matrix with * symbol 
	for(int i=0;i<nrow;i++) 
	{
		for(int j=0;j<ncol;j++)
	    {
	        railMatrix[i][j] = '*'; 
		}
	}
	
	// to find the direction 
	bool downward = false; 
	int r = 0, c = 0; 
	string ciphertext; 
	  
	for(int i=0;i<len;i++) 
	{
		// checking  the direction of flow 
		// reverse the direction if the top or bottom rail is just filled 
	    if(r==0 || r==depth-1) 
	    {
			downward = !downward; 
		}
	    
	    // filling  with  characters in the plaintext 
	    railMatrix[r][c++] = text[i]; 
	  
	    // find the next row using direction 
	    downward ?r++ : r--; 
	 } 
	 
	 // Print the rail matrix
	 cout<<"\n\n -> Here is Rail Matrix look like :  \n\n\n";
	 for(int i=0;i<nrow;i++) 
	 {
		 cout<<"		";
	     for(int j=0;j<ncol;j++)
	     {
	         cout<< railMatrix[i][j]<<"  "; 
		 }
		 cout<<"\n";
	 }
	 
	 // Generating  the ciphertext using the railMatrix 
	 for(int i=0;i<depth;i++) 
	 {
	     for (int j=0;j<len;j++) 
	     {
	          if(railMatrix[i][j]!='*') 
	          {
	             ciphertext.push_back(railMatrix[i][j]); //Appending a character
			  }
		 }
	 }
	 cout<<"\n\n -> The Cipher text :  "<<ciphertext<<"\n";
}

void Decrypt(string text, int depth)
{
	// creating a matrix to encrypt text with depth 
	int	nrow= depth;
	int	ncol= text.length();
	int len = text.length();
	char railMatrix[nrow][ncol]; 
	string plaintext;
	  
	// filling the rail matrix with * symbol 
	for(int i=0; i < nrow; i++) 
	{
		for(int j = 0; j < ncol; j++)
		{
			railMatrix[i][j] ='*'; 
		}
	}
	
	// to find the direction 
	bool downward; 
	int r = 0, c= 0; 
	  
	
	for(int i=0; i < len; i++) 
	{
		// check the direction of flow 
		if (r == 0) 
		{
			downward = true; 
		}
		if (r == depth-1) 
		{
			downward = false; 
		}
		// place the marker 
		railMatrix[r][c++] = '~'; 
	  
		// find the next row using direction flag 
		downward?r++ : r--; 
	} 
	  
	// filling  the rail matrix 
	int indx = 0; 
	for(int i=0; i<depth; i++) 
	{
		for(int j=0; j<len; j++) 
		{
			if(railMatrix[i][j] == '~' && indx<len) 
			{
				railMatrix[i][j] = text[indx++]; 
			}
	    }
	}   
	        
	//  Reading  the matrix in zig-zag order to get the plaintext  
	r = 0, c = 0; 
	for(int i=0; i< len; i++) 
	{ 
		// check the direction of flow 
		if(r == 0)
		{ 
			downward = true; 
		}
		if (r == depth-1)
		{ 
			downward = false; 
		}
		
		// checking  the marker 
		if(railMatrix[r][c] != '~') 
		{
			plaintext.push_back(railMatrix[r][c++]); //Appending 
		}
		// finding  the next row using direction flag 
		downward?r++: r--; 
	} 
	cout<<"\n\n -> The Plain text : "<<plaintext<<"\n";		
}


int main()
{		
	char ch;
	int choice;
	string text;
	int depth;
	
	do
	{
		cout<<"\n		 	 ||||||||    Rail Fence transposition Cipher    |||||||||";
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
						 cout<<"\n Enter the Depth : ";
						 cin>>depth;
						 Encrypt(text,depth);
						 break;
					 }
					 
			case 2 : {
						 cout<<"\n Enter the Cipher text to Decrpyt : "; 
						 cin.ignore();
						 getline(cin, text);
						 cout<<"\n Enter the depth : ";
						 cin>>depth;
						 Decrypt(text,depth);
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
