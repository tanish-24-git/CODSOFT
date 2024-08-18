#include <iostream>
using namespace std;
void addition(int a, int b)
{
 int sum = a+b;
 cout<<"addition is "<<sum;
}
void subtraction(int a, int b)
{
    int sum= a-b;
    cout<<"substraction is "<<sum;

}
void multiplication(int a, int b)
{
    int sum= a*b;
    cout<<"multiplication is "<<sum;

}
void division(int a,int b)
{
    int sum= a/b;
    cout<<"division is "<<sum;

}

int main()
{
    cout<<"************** welcome to calculator ****************";
    cout<<endl<<" *you can perform* ";

    cout<<endl<<"1.addition"<<endl;
    cout<<"2.subtraction"<<endl;
    cout<<"3.multiplication"<<endl;
    cout<<"4.division"<<endl;
    int num1,num2;
    cout<<"enter the number 1 for operation = ";
    cin>>num1;
    cout<<"enter the number 2 for operation = ";
    cin>>num2;
    cout<<endl<<"number you enter are "<<num1<<","<<num2;
    int ch;
    cout<<endl<<"enter your choice=";
    cin>>ch;

 switch(ch)
 {
 case 1: 
         addition(num1,num2);
         
 break;
 case 2: 

     subtraction(num1,num2);
 
 break;
 case 3:
 
     multiplication(num1,num2);
 
 break;
 case 4:

     division(num1,num2);

 break;

}
if(ch>4)
{
    cout<<"invalid choice";
}
}
