#include <bits/stdc++.h>
using namespace std;


double f(double x){
    return pow(x, 3)-2*x-5;
}

double Bisection(double a, double b){
    if(f(a)*f(b) >= 0){
        cout<<"Invalid Range"<<endl;
        return INT_MIN;
    }
    double mid = 0;
    for(int i = 1;i <=50;i++){
        mid = (a+b)/2;
        if(1e-6 >= abs(a-b)){
            cout<<"Limit Reached";
            break;
        }
        if(f(mid) == 0){
            return mid;
        }else if(f(a) * f(mid) < 0){
            b = mid;
        }else{
            a = mid;
        }
    }
    return mid;
}

int main(){
    int a1 = 2;
    int b1 = 3;
    double ans = Bisection(a1, b1);
    cout << "The Root is: " << ans << endl;
    return 0;
}
