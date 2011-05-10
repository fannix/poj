/*
 * =====================================================================================
 *
 *       Filename:  poj.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2010年12月29日 17时18分14秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include<iostream>
#include <cassert>
#include<vector>
#include<algorithm>
#include <cmath>
using namespace std;

int main(int argc, const char *argv[])
{
    int n;
    cin >> n;
    char c;
    cin >> c;
    int m;
    cin >> m;

    const int MAX=100000001;
    //const int MAX=1001;
    vector<int> ndivisor(MAX, 0);

    ndivisor[1] = 1;
    ndivisor[2] = 2;
    ndivisor[3] = 2;

    for (int i = 4; i < m; i++) {
        int max_prime = sqrt(i);
        bool is_prime = true;
        for (int j = 2; j <= max_prime + 1; j++) {
            if ((ndivisor[j] == 2) && (i % j == 0) ){
                int k = 1;
                long long divisor = j*j;
                while(i % divisor == 0){
                    divisor *= j;
                    k++;
                }
                is_prime = false;
                divisor /= j;
                //assert( i % divisor == 0);
                ndivisor[i] = ndivisor[i / divisor] * (k+1);
                //cout << "i " << i <<  " divisor " << divisor << " k " << k << " n " << ndivisor[i] << endl;
                break;
            }
        }
        if (is_prime){
            ndivisor[i] = 2;
        }
    }

    //for (int i = 0; i < MAX; i++) {
        //cout << i << " " << ndivisor[i] << endl;
    //}
    

    vector<int> inv_primes;
    int larger = 0;
    for (int i = 1; i < m+1; i++) {
        if (larger < ndivisor[i]){
            larger = ndivisor[i];
            //cout << larger << " " << i << endl;
            inv_primes.push_back(i);
        }
    }

    int length = inv_primes.size();
    bool is_no = true;
    for (int i = 0; i < length; i++) {
        if (inv_primes[i] >=  n){
            cout << inv_primes[i];
            is_no = false;
        }
        if (inv_primes[i] >=  n && i < length - 1)
            cout << ",";
    }
    if (is_no)
        cout << "NO";
    cout << endl;
    return 0;
}

