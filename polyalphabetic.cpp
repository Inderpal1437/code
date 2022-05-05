#include<iostream>
#include <string.h>
#define MAX 100 

using namespace std; 

class polyalphabeticcipher{
	char text[MAX], key[MAX];
	
	public:
	
	void encryption(){
		cout<<"Enter plain text: ";
		cin.getline(text,1000);
		cout<<endl<<"Enter key: ";
		cin.getline(key,1000);
		cout<<endl<<endl;
			
		int len = strlen(text);
		
		cout<<"Encrypted text: ";
		for(int i=0;i<len;i++){
			int p=text[i];
			int k=key[i];
			p-=97; 
			k-=97;
			text[i]=char(((p+k)%26) + 97);
			cout<<text[i];
		}
		cout<<endl<<endl;
	}
	
	void decryption(){	
		cout<<"Enter key: ";
		cin.getline(key,1000);
		int len = strlen(text);
		cout<<endl<<endl;
		
		cout<<"Decrypted text: ";
		for(int i=0;i<len;i++){
			int c=text[i];
			int k=key[i];
			c-=97; 
			k-=97;
			int p=c-k;
			if(p<0)
			p+=26;
			text[i]=char(p + 97);
			cout<<text[i];
		}
	}
};

int main(){	
	polyalphabeticcipher obj;
	obj.encryption();
	
	obj.decryption();

	
	return 0;
}
