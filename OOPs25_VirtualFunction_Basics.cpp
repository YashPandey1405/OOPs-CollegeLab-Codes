#include<iostream>
using namespace std;

class Alpha{
    private:
        int Num1;
    public:
        Alpha(){}   // Default Contructor Of Class Alpha..........
        Alpha(int Num1){
            cout<<"CONSTRUCTOR OF CLASS ALPHA IS BEEN CALLED......."<<endl;
            this->Num1=Num1;
        }
        void Display(void){   //Virtual Function
            cout<<"VALUE OF DATA MEMBER OF CLASS ALPHA IS ::: "<<Num1<<endl;
        }     
        // virtual void Display(void)=0; --> Pure Virtual Function SYNTAX.......
};

class Betta : virtual public Alpha{
    private:
        int Num2;
    public:
        Betta(){}   // Default Contructor Of Class Betta..........
        Betta(int Num2) : Alpha(10*Num2){  // Use Of Initialization List......
            cout<<"CONSTRUCTOR OF CLASS BETTA IS BEEN CALLED......."<<endl;
            this->Num2=Num2;
        }
        void Display(void){   
            cout<<"VALUE OF DATA MEMBER OF CLASS BETTA IS ::: "<<Num2<<endl;
        }  
};

class Gamma : virtual public Alpha{
    private:
        int Num3;
    public:
        Gamma(){}   // Default Contructor Of Class Gamma..........
        Gamma(int Num3) : Alpha(20*Num3) {   // Use Of Initialization List......
            cout<<"CONSTRUCTOR OF CLASS GAMMA IS BEEN CALLED......."<<endl;
            this->Num3=Num3;
        }
        void Display(void){
            cout<<"VALUE OF DATA MEMBER OF CLASS GAMMA IS ::: "<<Num3<<endl;
        }
};

class Delta : public Betta , public Gamma{
    private:
        int Num4;
    public:
        Delta(int Num4) : Alpha(30*Num4) , Betta(20*Num4) , Gamma(10*Num4){
            cout<<"CONSTRUCTOR OF CLASS DELTA IS BEEN CALLED......."<<endl;
            this->Num4=Num4;
        }
        void Display(void){
            cout<<"VALUE OF DATA MEMBER OF CLASS DELTA IS ::: "<<Num4<<endl;
        }
};

int main(){

    // Case 1 --> Creating Object Of Class Alpha.........
    // Alpha a(10);
    // a.Display();
    // a.Betta::Display();  --> This Will Cause Error.......
    // a.Gamma::Display();  --> This Will Cause Error.......
    // a.Delta::Display();  --> This Will Cause Error.......
    
    // Case 2 --> Creating Object Of Class Betta.........
    // Betta b(10);
    // b.Display();  // Same As --> b.Betta::Display();
    // b.Alpha::Display();

    // Case 3 --> Creating Object Of Class Gamma.........
    // Gamma g(10);
    // g.Display();  // Same As --> g.Gamma::Display();
    // g.Alpha::Display();

    // Case 4 --> Creating Object Of Class Delta.........
    // Delta d(10);
    // d.Display();
    // d.Alpha::Display();  // Same As --> d.Delta::Display();
    // d.Betta::Display();
    // d.Gamma::Display();

    // Case 5 --> Creating Pointer Of Class Alpha.....
    
    return 0;
}