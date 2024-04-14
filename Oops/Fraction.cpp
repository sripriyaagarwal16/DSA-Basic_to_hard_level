#include<iostream> 
using namespace std; 
class fraction{
   int numerator;
   int denominator;
   public:
   //Constructor
   fraction(int numerator,int denominator){
    this->numerator=numerator;
    this->denominator=denominator;
   }
   //ADD function
   void add(fraction const & f2){
    int lcm= denominator*f2.denominator;
    int x = lcm/denominator;
    int y= lcm/f2.denominator;
    int num=numerator*x+f2.numerator*y;
    this->numerator=num;
    this->denominator=lcm; 
   }
   //Operator Overloading of + operator
    fraction operator + (fraction const & f2){
    int lcm= denominator*f2.denominator;
    int x = lcm/denominator;
    int y= lcm/f2.denominator;
    int num=numerator*x+f2.numerator*y;
    fraction fnew(num,lcm );
    fnew.simplify();
    return fnew ; 
   }
   //Simplify function
   void simplify(){
    int gcd=1;
    int j =min(this->numerator,this->denominator);
    for(int i =1;i<=j;i++){
        if(numerator%i==0&&denominator%i==0){
            gcd=i;
        }
    }
    this->numerator=numerator/gcd;
    this->denominator=denominator/gcd;
   }
   //Multiply
   void multiply(fraction const & f2){
    this->numerator=numerator*f2.numerator;
    this->denominator=denominator*f2.denominator;
   }
   //Operator overloading of * operator
    fraction operator *  (fraction const & f2){
   
    int num=numerator*f2.numerator;
    int den=denominator*f2.denominator;
    fraction f4(num,den);
    f4.simplify();
   }
   //operator overaloading 
   bool operator ==(fraction const &f2){
    return (numerator==f2.numerator&&denominator==f2.denominator);
   }
   void print(){
    cout<<this->numerator<<"/"<<this->denominator;

   }
   //pre increment
   fraction & operator ++(){  //this is passed
      this->numerator=numerator+denominator;
      simplify();
      return *this;
   }
   //post increment 
   fraction operator++(int){
    fraction fnew(numerator,denominator);
    numerator=numerator+denominator;
    simplify();
    fnew.simplify();
    return fnew;
   }
   //+= operator overloading 
   fraction & operator +=(fraction const  & f2){
    int lcm =denominator*f2.denominator;
    int x = lcm /denominator;
    int y =lcm/f2.denominator;
    int num=x*numerator+(y*f2.numerator);
    numerator=num;
    denominator=lcm;
    simplify();
    return *this;

   }




};