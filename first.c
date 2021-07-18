/*
    @vasu 1910990395
    Program to find square root of number upto 9 decimal places.
    
*/
#include <stdio.h>
int power(int number,int k) // program to calculate power
{
    int ans=1; // temporary answer
    
    while(k!=0){
         ans*=number;
         k--;
    }
    
    return ans; // return power
}
double binary_search(long long int number,long long int k) // function to find square root of number n.
{
    long long int temp_power=power(10,k); // using power function
    int low=1; // lower index
    int high=number; // higher index
    double ans=0; // store answer
    
    while(low<=high)
    {
        double mid=(low + high)/2;  // find mid element
          if(mid*mid<= number)
          {
              ans=mid;  // store temporary answer 
              low=mid+1; // increase lower index to mid  + 1
          }
         else
          high=mid-1; // if value is more than desire value decrease higher index
    }
    
    low=0; // reset point to find decimal expression
    high=temp_power; // reset point to find decimal expression
    double temp=ans; // ans storing int value of current for ex -- 10 -- 3
    double x=0; // x is to store final answer
    while(low<=high)
    {
        double m=(low + high)/2;
        temp=ans + (double)((double)(m)/temp_power); // finding best square root till (ans+m)
        
        if(temp*temp <= number)
        {
            x=ans + (m)/temp_power; // storing value of final answer
            low=m + 1;
        }
        else
        high=m - 1;
    }
    return x; // return answer
}
int main() {
	int n,k; // input n and k
    scanf("%d %d",&n,&k); 
	double x=binary_search(n,k); // storing answer
	printf("%0.9f",x); // output answer
	return 0;
}