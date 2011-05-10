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
#include<vector>
#include<algorithm>
using namespace std;

bool reverse_order(int i, int j){
    return (i > j);
}

int main(){
    vector<int> tian(1001, 0);
    vector<int> qi(1001, 0);
    int nhorse = 0;

    cin >> nhorse;
    while (nhorse != 0){
        for(int i = 0; i < nhorse; i++){
            cin >> tian[i];
        }
        for(int i = 0; i < nhorse; i++){
            cin >> qi[i];
        }
        sort(tian.begin(), tian.begin()+nhorse, reverse_order);
        sort(qi.begin(), qi.begin()+nhorse, reverse_order);

        
        int max = -1000000;
        int temp_max = 0;
        for (int k = 0; k < nhorse; k++){
            if (tian[k] - qi[k] > 0) 
                temp_max+= 200;
            else if (tian[k] - qi[k] < 0)
                temp_max-=200;
        }
        if (temp_max > max)
            max = temp_max;

        for (int i = 0; i < nhorse - 1; i++){
            int slow = nhorse - 1;
            int temp = tian[i];
            tian[i] = tian[slow];
            int j = nhorse;
            for (j = nhorse; j > i+1; j--){
                tian[j] = tian[j-1];
            }
            tian[j] = temp;

            int temp_max = 0;
            for (int k = 0; k < nhorse; k++){
                if (tian[k] - qi[k] > 0) 
                    temp_max+= 200;
                else if (tian[k] - qi[k] < 0)
                    temp_max-=200;
            }
            if (temp_max > max)
                max = temp_max;
            // early stopping, timeout otherwise
            else if(temp_max < max)
                break;
        }
        cout << max << endl;

        //for(int i = 0; i < nhorse; i++)
            //cout << tian[i] << " ";
        //cout << endl;
        //for(int i = 0; i < nhorse; i++)
            //cout << qi[i] << " " ;
        cin >> nhorse;
    }
    return 0;
}
