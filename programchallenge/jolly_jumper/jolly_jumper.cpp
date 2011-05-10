/*
 * =====================================================================================
 *
 *       Filename:  jolly_jumper.cpp
 *
 *    Description:  chapter data structure
 *
 *        Version:  1.0
 *        Created:  2008-12-24 14:57:13 中国标准时间
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  first_name last_name (fl), fl@my-company.com
 *        Company:  my-company
 *
 * =====================================================================================
 */

#include <iostream>
#include <cmath>
using namespace std;

void init_array(int a[], int len){
	for (int i = 0; i < len; i++){
		a[i] = 0;
	}
}

int main(){
	int count;
	int counter[3000];

	while (cin >> count){
		bool jolly = true;
		init_array(counter, count);

		int num;
		cin >> num;
		int j = count;
		while (--j){
			int old_num = num;
			cin >> num;
			
			int i = abs(num - old_num);
			if (i >= count || i < 1 || counter[i-1] >= 1){
				jolly = false;
			}
			counter[i-1] = 1;
		}
		if (jolly)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;

	}

	return 0;
}
