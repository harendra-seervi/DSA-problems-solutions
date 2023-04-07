#include<iostream>
using namespace std;
int getbit(int num,int pos){
    return (num&(1<<pos))!=0;
}
int setbit(int num,int position){
    return (num|1<<position);
}
int clearbit(int num,int position){
    return num&~(1<<position);
}
int updatebit(int num,int position,int value){
    int mask=num&~(1<<position);
    return mask|value<<position; 
}
int main(){
    cout<<getbit(5,2)<<endl;
    cout<<setbit(5,2)<<endl;
    cout<<clearbit(5,1)<<endl;
    cout<<updatebit(5,1,0)<<endl;
    return 0;
}
