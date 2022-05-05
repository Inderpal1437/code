#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class monoalphabeticcipher{
	string text;					//Variable for plain text, encrypted text and decrypted text
	char alphabets[26]={'A','B','C','D','E','F','G','H','I', 'J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	char cipheralphabets[26]={'G','N','E','L','F','M','D','U','O','I','X','K','J','B','V','H','C','W','P','A','Z','Y','Q','T','R','S'};
	
	public:
	
	int indexval(char a, int choice){
		int retval=0;
		if (choice == 1){
			for (int i=0; i<26; i++){
				if(a == alphabets[i]){
					retval = i;	
				}	
			}
		}
		else{
			for (int i=0; i<26; i++){
				if(a == cipheralphabets[i]){
					retval = i;	
				}	
			}
		}
		
		return retval;	
	}
	
	string cleantext(string text){
		int l = text.length();
		int c = count(text.begin(), text.end(), ' '); 
		remove(text.begin(), text.end(), ' '); 
		text.resize(l-c); 
	
		l = text.length();
		for (int i=0; i<l; i++){
			text[i] = toupper(text[i]);
		}
		
		return text;		
	}
	
	void encryption(){
		//Enter plain text
		cout<<"Enter text: ";
		getline(cin, text);
		cout<<endl<<endl;
		
		
		//This function is used to generalise the string text to shorten the algorithm without effecting the meaning of the plain text
		text = cleantext(text);
		
		int len = text.length();
		
		for (int i=0; i<len; i++){
			int index = indexval(text[i],1);
			text[i] = cipheralphabets[index];
		}
		
		cout<<"Encrypted Message: "<<text<<endl;
		
	}
	
	
	//Function to decrypt the encoded text message
	void decryption(){
		int len = text.length();
		for (int i=0; i<len; i++){
			int index = indexval(text[i],2);
			text[i] = alphabets[index];
		}
		
		cout<<"Decrypted Message: "<<text<<endl;	
	}
};


int main(){
	monoalphabeticcipher obj;
	obj.encryption();
	cout<<"Encryption successfull"<<endl<<endl;
	
	obj.decryption();
	cout<<"Encryption successfull"<<endl<<endl;


	return 0;
}

