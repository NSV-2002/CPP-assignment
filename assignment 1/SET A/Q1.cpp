#include<iostream>
using namespace std;
int main()
{
    int num ,count=1;
    cout <<"enter a number :-";
    cin >> num ;
    cout<<" "<<endl;
    for(int i=1;i<num;i++)
    {
      for(int j=0;j<i;j++)
      {
        cout << count<<" ";
        count++;
      }
      cout<<endl;
    }
    return 0;
}
