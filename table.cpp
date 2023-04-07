#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the number to write a table"<<endl;
    cin>>n;
    for(int i=1;i<=10;i++)
    {
        cout<<n<<"*"<<i<<"="<<i*n<<endl;
    }

    return 0;
}