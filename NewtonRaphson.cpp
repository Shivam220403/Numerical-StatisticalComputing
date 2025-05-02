#include<bits/stdc++.h>
using namespace std;

double f(double x){
    return pow(x, 3) - 5;
}

double df(double x){
    return 3*pow(x, 2);
}

double N_Raphson(double x){
    while(abs(f(x)) > 1e-6){
        x = x - f(x)/df(x);
    }
    return x;
}

int main(){
    cout<< "The Root is: " << N_Raphson(2);
    return 0;
}