/*
 * =====================================================================================
 *
 *       Filename:  common_permutation.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009-5-5 17:30:41 中国标准时间
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  first_name last_name (fl), fl@my-company.com
 *        Company:  my-company
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	string string1;
	string string2;
	while (getline(cin, string1)){
		getline(cin, string2);

		sort(string1.begin(), string1.end());
		sort(string2.begin(), string2.end());

		int i = 0;
		int j = 0;
		while (i < string1.size() && j < string2.size()){
			if (string1[i] == string2[j]){
				cout << string1[i];
				i++;
				j++;
			}
			else if (string1[i] < string2[j])
				i++;
			else
				j++;
		}
		cout << endl;
	}
	return 0;
}
