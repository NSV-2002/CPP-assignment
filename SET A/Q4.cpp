#include<iostream>
using namespace std;
int main()
{
    int num, remainder,reverse=0 ,key;
    cout << "Enter a number to check if its palindrome :-" << endl;
    cin >>num;
    key = num;
    for(int i=0;i<num;i++)
    {
       remainder = num%10;
       reverse = (reverse*10)+remainder;
       num = num/10;
    }
    reverse =(reverse*10)+num;
    if(reverse == key)
    cout << "the number is palindrome"<<endl;
    else
    cout <<"The number not a palindrome"<<endl;
    return 0;
}