#include<iostream> 
#include<string> 
using namespace std; 
#define MAX 100 
int XOR(int a, int b) 
{ 
 int value = 1; 
 if(a==b) 
 { 
 value = 0; 
 } 
 return value; 
} 
 
void encryption() 
{ 
 int text[MAX]; 
 int key[MAX]; 
 int len; 
 
 cout<<"Enter the length of the text : "; 
 cin>>len; 
 
 cout<<" Enter Plain text :"; 
 for (int i=0; i<len; i++) 
 { 
 
 cin>>text[i]; 
 } 
 
 cout<<"\n Enter key values : "; 
 for (int i=0; i<len; i++) 
 { 
 
 cin>>key[i]; 
 } 
 
 for (int i=0; i<len; i++) 
 { 
 text[i] = XOR(text[i], key[i]); 
 } 
 
 cout<<"\n Encrypted Message : "; 
 for (int i=0; i<len; i++) 
 { 
 cout<<text[i]<<" "; 
 } 
 cout<<endl; 
} 
void decryption() 
{ 
 int text[MAX]; 
 int key[MAX]; 
 int len; 
 
 cout<<"\n\n Enter the length of the text : "; 
 cin>>len; 
 
 cout<<"\n Enter Cipher text : "; 
 for (int i=0; i<len; i++) 
 { 
 
 cin>>text[i]; 
 } 
 
 cout<<"\n Enter key values :"; 
 for (int i=0; i<len; i++) 
 { 
 
 cin>>key[i]; 
 } 
 
 for (int i=0; i<len; i++) 
 { 
 text[i] = XOR(text[i], key[i]); 
 } 
 
 cout<<"\nDecrypted Message : "; 
 for (int i=0; i<len; i++) 
 { 
 cout<<text[i]<<" "; 
 } 
 cout<<endl; 
} 
 
int main() 
{ 
 
 encryption(); 
 
 decryption(); 
 return 0; 
} 