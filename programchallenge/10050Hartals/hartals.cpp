/*
 * =====================================================================================
 *
 *       Filename:  hartals.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2011年04月13日 16时42分05秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

void output_nlosts(){
    int ndays = 0;
    int nparties = 0;
    cin >> ndays;
    cin >> nparties;

    vector<int> strike(ndays, 0);

    while (nparties --){
        int param = 0;
        cin >> param;
        for (int i = -1; i < ndays; i += param){
            if (((i-5)%7 != 0) && ((i-6)%7 != 0))
                strike[i] = 1;
        }
    }

    int nstrikes = 0;
    for (int i = 0; i < strike.size(); i++){
        if (strike[i] == 1)
            nstrikes++;
    }
    cout << nstrikes << endl;
}

int main(){
    int ncases = 0;
    cin >> ncases;
    while (ncases --){
        output_nlosts();
    }
    return 0;
}
