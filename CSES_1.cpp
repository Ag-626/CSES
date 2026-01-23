/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

int main()
{
    long long n;
    std::cin>>n;
    long long num;
    std::cout<<n<<" ";
    while(n!=1){
        if(n%2){
            num = n*3+1;
        }
        else{
            num=n/2;
        }
        std::cout<<num<<" ";
        n=num;
    }

    return 0;
}