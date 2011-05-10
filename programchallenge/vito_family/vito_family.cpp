/*
 * =====================================================================================
 *
 *       Filename:  vito_family.cpp
 *
 *    Description:  chapter: sort
 *
 *        Version:  1.0
 *        Created:  2008-12-24 14:11:53 中国标准时间
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  first_name last_name (fl), fl@my-company.com
 *        Company:  my-company
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool comp_int(int i, int j){
	return i < j;
}

int main(){
	int n;
	cin >> n;

	while (n--){
		vector<int> distance;
		int count;
		cin >> count;
		int pos;
		while (count --){
			cin >> pos;
			distance.push_back(pos);
		}

		sort(distance.begin(), distance.end(), comp_int);

		int optimal = distance[distance.size()/2];
		int overall_distance = 0;
		for (int i = 0; i < distance.size(); i++){
			overall_distance += abs(distance[i] - optimal);
		}

		cout << overall_distance << endl;

	}
	return 0;
}
