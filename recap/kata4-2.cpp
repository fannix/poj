/*
 * =====================================================================================
 *
 *       Filename:  kata4-2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009-4-29 16:49:27 中国标准时间
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  first_name last_name (fl), fl@my-company.com
 *        Company:  my-company
 *
 * =====================================================================================
 */


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main(){
	ifstream ifs("football.dat");
	string line;
	int min_diff = 100;
	string team;

	while(getline(ifs, line)){
		istringstream iss(line);
		vector<string> vec;
		string field;
		while(iss >> field)
			vec.push_back(field);

		if (vec.size() == 10){
			int for_g;
			int against_g;

			istringstream(vec[6]) >> for_g;
			istringstream(vec[8]) >> against_g;

			if (abs(for_g - against_g) < min_diff){
				min_diff = abs(for_g - against_g);
				team = vec[1];
			}
		}
	}

	cout << team << " " << min_diff << endl;

	return 0;
}
