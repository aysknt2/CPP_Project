#include<iostream>
using namespace std;
 
float sum(float a, float b){
    return a+b;
}
float sub(float a, float b){
    return a-b;
}
float prod(float a, float b){
    return a*b;
}
float div(float a, float b){
    return a/b;
}
float percent (float a, float b){
    return (a*100)/b;
}
int main(){
    float m,n;
    char f;
cout<<"Enter the first number "<<endl;
cin>>m;
cout<<"Enter the operation [+, -, *, /, % ] "<<endl;
cin>>f;
cout<<"Enter the second number "<<endl;
cin>>n;
if (f == '+'){
    cout<<sum(m,n);
}
else if (f == '-'){
    cout<<sub(m,n);
}
else if (f == '*'){
    cout<<prod(m,n);
}
else if (f == '/'){
    cout<<div(m,n);
}
else if (f == '%'){
    cout<<percent(m,n)<<"5";
}
else
{
    cout<<"Invaliid Operation";
}
return 0;
}
