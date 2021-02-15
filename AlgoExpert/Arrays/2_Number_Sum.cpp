#include<iostream>

using namespace std;

int main(){
    int arr[2],sum=0;

    for (int i = 0; i < 2; i++)
    {
        cout<<"\nEnter:   ";
        cin>>arr[i];
        sum+=arr[i];
    }

    cout<<"\nSum is:  "<<sum;
    
}