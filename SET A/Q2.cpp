#include<iostream>
using namespace std;
int main()
{
    int num;
    cout << "Enter a number :-"<<endl;
    cin >> num;
    cout <<"Table of "<<num<<" is :-"<<endl;
    for(int i=1;i<=10;i++)
    {
        cout << num<<"X"<<i<<"="<<num*i<<endl;
    }
    return 0;
}