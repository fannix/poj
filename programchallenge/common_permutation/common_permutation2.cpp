/*
 * =====================================================================================
 *
 *       Filename:  common_permutation2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009-5-5 21:29:58 中国标准时间
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  first_name last_name (fl), fl@my-company.com
 *        Company:  my-company
 *
 * =====================================================================================
 */


#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
    string a, b;
    int af[27], bf[27];

    while(getline(cin,a))
    {
        getline(cin,b);
         for(int i = 0; i < 27; i++)
         {  af[i] = 0;  bf[i] = 0;  }

         int len = a.size();
         for(int i = 0; i < len; i++)
             af[a[i] - 96]++;

         len = b.size();
         for(int i = 0; i < len; i++)
             bf[b[i] - 96]++;

         for(int i = 1; i <= 26; i++)
         {
             if(af[i] != 0 && bf[i] != 0)
             {
                 if(af[i] < bf[i])
                 {
                     for(int j = 0; j < af[i]; j++)
                         cout << char(i + 96);
                 }
                 else
                 {
                     for(int j = 0; j < bf[i]; j++)
                         cout << char(i + 96);
                 }
             }
         }
         cout << endl;
    }
    return EXIT_SUCCESS;
}

