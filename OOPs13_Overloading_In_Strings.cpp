#include<iostream>
#include<string.h>
using namespace std;

class String{
    public:
        char* ptr;
        int Length;
        String(){ Length=0; ptr=NULL;}  //Default Constructor.....
        String(string str){  //Parameterized Constructor.....
            char* s=&str[0];
            Length = strlen(s);
            ptr=new char[Length+1];
            strcpy(ptr,s);
        }
        String(String &s1){  //Copy Constructor.....
            Length = s1.Length;
            ptr = new char[Length+1];
            strcpy(ptr,s1.ptr);
        }
        String operator+(String &str1){
            String temp;
            temp.Length = Length + str1.Length;
            temp.ptr=new char[temp.Length +1];
            strcpy(temp.ptr,ptr);
            strcat(temp.ptr,str1.ptr);
            return temp;
        }
        void operator==(String &str1){
            Length=str1.Length;
            ptr=new char[Length+1];
            strcpy(ptr,str1.ptr);
        }
        int operator<= (String &s1){
            int First_str=Length;
            int Second_str=s1.Length;
            return (First_str <= Second_str);
        }
        friend void Display(String);
};

void Display(String str){
    cout<<"THE STRING IS ::: "<<str.ptr<<endl;
}

int main(){
    cout<<endl;
    String str1("Yash_");
    String str2("Pandey");
    Display(str1); 
    Display(str2);
    String str3;
    str3=str1+str2;
    cout<<"After operater+ () Function , ";
    Display(str3);
    String str4;
    str4==str3;
    cout<<"COPYING DATA OF str3->str4 , ";
    Display(str4);
    int compare=str1<=str2;
    cout<<"COMPAIRING str1 <= str2 ::: "<<compare<<endl;
    cout<<endl;
    cout<<endl;
    return 0;
}