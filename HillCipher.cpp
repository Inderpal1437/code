#include<iostream>
#include<string>
#include<math.h>

using namespace std;

// ENCRYPTION FUNCTION
void Encrypt(string PlainText, string key)
{
	int size = PlainText.length();
	int KeyMatrix[size][size];
	int k = 0;
	
	// KEY MATRIX 
	cout<<"\n Key Matrix : \n";
	for(int i=0;i<size;i++)
	{	
		cout<<"			";
		for(int j=0;j<size;j++)
		{
			KeyMatrix[i][j] = (key[k]) % 65;
			k++;
			cout<<" "<<KeyMatrix[i][j];
		}
		cout<<endl;
	}
	
	// DECLARE PLAIN TEXT VECTOR
	int PlainTextMatrix[size][1];
	
	cout<<"\n Plain Text Vector  : ";
	for(int i=0;i<size;i++)
	{
		cout<<"\n				";
		for(int j=0;j<1;j++)
		{
			PlainTextMatrix[i][0] = (PlainText[i]) % 65;
			cout<<PlainTextMatrix[i][j];
		}
		
	}
	
	// DECLARE CIPHER TEXT VECTOR
	int CipherTextMatrix[size][1];
	for(int i=0;i<size;i++)
	{	
		for(int j=0;j<1;j++)
		{
			CipherTextMatrix[i][j] = 0;
			for(int k=0;k<size;k++)
			{
				CipherTextMatrix[i][j] += KeyMatrix[i][k] * PlainTextMatrix[k][j];
			}
			
			CipherTextMatrix[i][j] = CipherTextMatrix[i][j] % 26;
		}
	}
	
	cout<<"\n\n After Multiplication of Key Matrix and Plaintext Vector, Then (mod 26) of it, ";
	cout<<"\n Cipher Text Vector : ";
	for(int i=0;i<size;i++)
	{
		cout<<"\n				";
		for(int j=0;j<1;j++)
		{
			cout<<CipherTextMatrix[i][j];
		}
	}
	
	// DECLARE CIPHER TEXT STRING FOR STORE CIPHER TEXT
	string CipherText;
	for(int i=0;i<size;i++)
	{
		CipherText += CipherTextMatrix[i][0] + 65;
	}
	
	cout<<"\n\n ->  Cipher Text After Encryption : "<<CipherText;
		
}

int mod(int a, int b)   // TO HANDLE MODULUS OPERATION
{
	int c = fmod(a,b);
	if(c>=0)
	{
		return c;
	}
	else
	{
		return b+c;
	}
}	

// WE ARE FINDING INVERSE WITH HELP OF MULTIPLICATIVE INVERSE SO THERE WILL BE NO NEGATIVE VALUE OR FLOAT VALUE 
// THAT'S WHY WE ARE USING INT TYPE 

int MutInverse(int detmod)  // FIND MULTIPLICATIVE INVERSE 
{
	int val, val2;
	int i, Dm;
	Dm = detmod;
	for(i=1;i<i+1;i++)
	{
		val = Dm * i;
		val2 = val % 26;
		if(val2==1)
		{
			break;
		}
	}
	return i;
}


// DECRYPTION FUNCTION
void Decrypt(string CipherText, string key)
{
	int size = CipherText.length();
	int KeyMatrix[size][size];
	
	
	// IF MATRIX IS 2*2
	if(size==2)	
	{
		int k = 0;
		// KEY MATRIX
		cout<<"\n Key Matrix : \n";
		for(int i=0;i<size;i++)
		{	
			cout<<"		  ";
			for(int j=0;j<size;j++)
			{
				KeyMatrix[i][j] = (key[k]) % 65;
				k++;
				cout<<" "<<KeyMatrix[i][j];
			}
			cout<<endl;
		}
		
		
		// WE ARE FINDING INVERSE WITH HELP OF MULTIPLICATIVE INVERSE SO THERE WILL BE NO NEGATIVE VALUE OR FLOAT VALUE 
		// THAT'S WHY WE ARE USING INT TYPE 
		// DECLARE OF INVERSE MATRIX, DETERMINANT, ADUJGATE MATRIX ETC.
		int inv[size][size];
		int AdjugateMat[size][size];
		int det = 0;
		det = (KeyMatrix[0][0]*KeyMatrix[1][1])-(KeyMatrix[0][1]*KeyMatrix[1][0]);
	
		cout<<"\n Determinant : "<<det;
		int DetMod = mod(det,26);
		cout<<"\n\n Determinant (mod 26) : "<<DetMod;
	
		int MutInv;
		MutInv = MutInverse(DetMod);
		cout<<"\n\n Multiplicative Inverse : "<<MutInv;
	
		cout<<"\n\n Adjugate Matrix of Key Matrix (mod 26) : ";
	
		AdjugateMat[0][0] = KeyMatrix[1][1];
		AdjugateMat[1][1] = KeyMatrix[0][0];
		AdjugateMat[0][1] = -KeyMatrix[0][1];
		AdjugateMat[1][0] = -KeyMatrix[1][0];
    
		for(int i = 0; i < size; i++)
		{
			cout<<"\n					";
			for(int j = 0; j < size; j++)
			{
				AdjugateMat[i][j] = mod(AdjugateMat[i][j],26);
				cout<<" "<<AdjugateMat[i][j];
			}
		}
		for(int i = 0; i < size; i++)
		{
			for(int j = 0; j < size; j++)
			{
				inv[i][j] = AdjugateMat[i][j] * MutInv;
				inv[i][j] = mod(inv[i][j],26);
			}
		}
		
		// PRINT INVERSE OF KEY MATRIX
		cout<<"\n\n Inverse of Matrix (Multiplicative Inverse * Adujgate Matrix), Then (mod 26) of it : \n";
		for(int i = 0; i < size; i++)
		{
			cout<<"\n				";
			for(int j = 0; j < size; j++)
			{
				cout<<" "<<inv[i][j];
			}
		}
    
		// DECLARE CIPHER TEXT VECTOR
		float CipherTextMatrix[size][1];
		cout<<"\n\n Cipher Text Vector : \n";
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<1;j++)
			{
				CipherTextMatrix[i][0] = (CipherText[i]) % 65;
				cout<<"			  "<<CipherTextMatrix[i][j];
			}	
			cout<<endl;
		}
	
		
		// DECLARE PLAIN TEXT VECTOR
		int PlainTextMatrix[size][1];
		for(int i=0;i<size;i++)
		{	
			for(int j=0;j<1;j++)
			{
				PlainTextMatrix[i][j] = 0;
				for(int k=0;k<size;k++)
				{
					PlainTextMatrix[i][j] += inv[i][k] * CipherTextMatrix[k][j];
				}
				PlainTextMatrix[i][j] = mod(PlainTextMatrix[i][j],26);
			}
		}
	
		cout<<"\n After Multiplication of Inverse and Ciphertext Vector, Then (mod 26) of it, ";
		cout<<"\n Plain Text Vector  : ";
		for(int i=0;i<size;i++)
		{
			cout<<"\n			  ";
			for(int j=0;j<1;j++)
			{
				cout<<" "<<PlainTextMatrix[i][j];
			}
		}
		
		// DECLARE PLAIN TEXT STRING TO STORE PLAIN TEXT
		string PlainText;
		for(int i=0;i<size;i++)
		{
			PlainText += PlainTextMatrix[i][0] + 65;
		}
	
		cout<<"\n\n ->  Plain Text After Decryption : "<<PlainText;
	}
	
	
	//  ELSE PART WILL RUN WHEN MATRIX IS 3*3
	else
	{
		int k = 0;
	
		cout<<"\n Key Matrix : \n";
		for(int i=0;i<size;i++)
		{	
			cout<<"		  ";
			for(int j=0;j<size;j++)
			{
				KeyMatrix[i][j] = (key[k]) % 65;
				k++;
				cout<<" "<<KeyMatrix[i][j];
			}
			cout<<endl;
		}
	
		// WE ARE FINDING INVERSE WITH HELP OF MULTIPLICATIVE INVERSE SO THERE WILL BE NO NEGATIVE VALUE OR FLOAT VALUE 
		// THAT'S WHY WE ARE USING INT TYPE 
		// DECLARE OF INVERSE MATRIX, DETERMINANT, ADUJGATE MATRIX ETC.
		int inv[size][size];
		int AdjugateMat[size][size];
		int det = 0;
		for(int i=0;i<size; i++)
		{
			det +=  (KeyMatrix[0][i] * (KeyMatrix[1][(i+1)%3] * KeyMatrix[2][(i+2)%3] - KeyMatrix[1][(i+2)%3] * KeyMatrix[2][(i+1)%3]));
		}

		cout<<"\n Determinant : "<<det;
		int DetMod = mod(det,26);
		cout<<"\n\n Determinant (mod 26) : "<<DetMod;
    
		int MutInv;
		MutInv = MutInverse(DetMod);
		cout<<"\n\n Multiplicative Inverse : "<<MutInv;
    
		cout<<"\n\n Adjugate Matrix of Key Matrix (mod 26) : ";
    
		for(int i = 0; i < size; i++)
		{
			cout<<"\n					";
			for(int j = 0; j < size; j++)
			{
				AdjugateMat[i][j] = ((KeyMatrix[(j+1)%3][(i+1)%3] * KeyMatrix[(j+2)%3][(i+2)%3]) - (KeyMatrix[(j+1)%3][(i+2)%3] * KeyMatrix[(j+2)%3][(i+1)%3]));
				AdjugateMat[i][j] = mod(AdjugateMat[i][j],26);
				cout<<" "<<AdjugateMat[i][j];
			}
		}    
	
		for(int i = 0; i < size; i++)
		{
			for(int j = 0; j < size; j++)
			{
				inv[i][j] = AdjugateMat[i][j] * MutInv;
				inv[i][j] = mod(inv[i][j],26);
			}
		}
	
		cout<<"\n\n Inverse of Matrix (Multiplicative Inverse * Adujgate Matrix), Then (mod 26) of it : \n";
		for(int i = 0; i < size; i++)
		{
			cout<<"\n				";
			for(int j = 0; j < size; j++)
			{
				cout<<" "<<inv[i][j];
			}
		}   
	
		// DECLARE CIPHER TEXT VECTOR
		float CipherTextMatrix[size][1];
		cout<<"\n\n Cipher Text Vector : \n";
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<1;j++)
			{
				CipherTextMatrix[i][0] = (CipherText[i]) % 65;
				cout<<"			  "<<CipherTextMatrix[i][j];
			}
			cout<<endl;
		}
	
		// DECLARE PLAIN TEXT VECTOR
		int PlainTextMatrix[size][1];
		for(int i=0;i<size;i++)
		{	
			for(int j=0;j<1;j++)
			{
				PlainTextMatrix[i][j] = 0;
				for(int k=0;k<size;k++)
				{
					PlainTextMatrix[i][j] += inv[i][k] * CipherTextMatrix[k][j];
				}
				PlainTextMatrix[i][j] = mod(PlainTextMatrix[i][j],26);
			}		
		}
		
		cout<<"\n After Multiplication of Inverse and Ciphertext Vector, Then (mod 26) of it, ";
		cout<<"\n Plain Text Vector  : ";
		for(int i=0;i<size;i++)
		{
			cout<<"\n			  ";
			for(int j=0;j<1;j++)
			{
				cout<<" "<<PlainTextMatrix[i][j];
			}
		}
		
		// DECLARE PLAIN TEXT STRING TO STORE PLAIN TEXT 
		string PlainText;
		for(int i=0;i<size;i++)
		{
			PlainText += PlainTextMatrix[i][0] + 65;
		}
	
		cout<<"\n\n ->  Plain Text After Decryption : "<<PlainText;
	}
	
}

	


int main()
{		
	char ch;
	int choice;

	string key, PlainText, CipherText;
	
	do
	{
		cout<<"\n		 	 ||||||||     Hill Cipher     |||||||||";
		cout<<"\n\n\n 1. Encryption to Decryption";
		cout<<"\n 2. Decryption to Encryption";
		cout<<"\n\n Enter Your Choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1 : {
						 cout<<"\n Enter the Plain Text to Encrpyt : "; 
						 cin.ignore();
						 getline(cin, PlainText);
						 cout<<"\n Enter the Key : ";
						 cin>>key;
						 Encrypt(PlainText,key);
						 break;
					 }
					 
			case 2 : {
						 cout<<"\n Enter the Cipher text to Decrpyt : "; 
						 cin.ignore();
						 getline(cin, CipherText);
						 cout<<"\n Enter the Key : ";
						 cin>>key;
						 Decrypt(CipherText,key);
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
