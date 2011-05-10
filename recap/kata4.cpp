#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdlib>

using namespace std;

void print_s(string s){
	cout << s << " ";
}


int main(){
	ifstream ifs("weather.dat");
	string line;

	int min_diff = 1000;
	int min_day = 1;
	int max;
	int min;
	while(getline(ifs, line)){
		vector<string> vec;
		istringstream iss(line);
		string field;

		while(iss >> field)
			vec.push_back(field);
		if(14 <= vec.size() && vec.size() <= 16){

			istringstream(vec[1]) >> max;
			istringstream(vec[2]) >> min;

			if (min_diff > max - min){
				min_diff = max - min;
				istringstream(vec[0]) >> min_day;
			}
		}
	}

	cout << min_day << " " << min_diff << endl;

	return 0;
}
