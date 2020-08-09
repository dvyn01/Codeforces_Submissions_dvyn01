#include<bits/stdc++.h>
using namespace std;
 
int main(){
    
    int t,a[2000],n;
    int sum=0;
    int count=0;
    
    cin>>t;
    while(t--)
    {
           cin>>n;
    for(int i=0;i<n;i++)
    {
        
        cin>>a[i];
        
        if(a[i]%2!=0)
        {
          //count=1;
          count++;
        }
        
        sum = sum+a[i];
            
        }
        
            
        if(sum%2 == 0){
                
                if(count !=0 && count != n)
                 cout<<"YES"<< endl;
                 
                else
                cout<<"NO"<< endl;
                
            }
         else{
                cout<<"YES"<< endl;
                
            }
            
            sum =0;
            count=0;
        }
       
        
        return 0;
    
       }