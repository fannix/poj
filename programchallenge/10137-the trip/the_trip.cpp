#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int expense [1000];

int main(){
    int n;

    while (cin >> n){
        if (n == 0)
            return 0;
        double d;
        double sum = 0;
        int m = n; 
        while(m--){
            cin >> d;
            sum += d;
            expense[n-m-1] = (d + 0.0001) * 100;
        }


        sum = sum * 100;
        // if 0.0001 is omitted, the cast would be wrong.
        int all = sum + 0.0001;
        int mean = sum/ n;

        int b = (all - n * mean);
        int a = n - b;
        //cout << a << " "  << b  << " " << all <<" " << mean << endl;

        double exchange = 0;
        m = n;
        while(m--){
            if (expense[n-m-1] > mean){
                if (b > 0){
                    exchange += expense[n-m-1] - mean - 1; 
                    b--;
                }
                else
                    exchange += expense[n-m-1] - mean; 

            }
        }

        cout << setiosflags(ios::fixed)<<setprecision(2);
        cout << "$" << exchange/100 << endl;
    }
    return 0;
}
