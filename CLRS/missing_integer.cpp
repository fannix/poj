#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

void find(const vector<string> & vec){
	if (vec.size() == 0)
		return;
	int n = vec.size() + 1;
	int bit_len = vec[0].size();
	int num_zero = n - n/2;
	int num_one = n/2;

	list<int> index;

	for (int i = 0; i < vec.size(); i++){
		index.push_back(i);
	}

	list<int>::iterator it;

	for (int i = bit_len-1; i >= 0; i--){
		for (it = index.begin(); it != index.end();it++){
			if (vec[*it][i] == '0')
				num_zero--;
			else
				num_one--;
		}
		if ((num_zero > 0 && num_one > 0) || (num_zero <= 0 && num_one <= 0)){
			cout << "error" << endl;
			return;
		}

		char to_remove;
		if (num_zero > 0){
			to_remove = '1';
			cout << '0';
		}
		else{
			to_remove = '0';
			cout << '1';
		}

		for (it = index.begin(); it != index.end();){
			if (vec[*it][i] == to_remove)
				it = index.erase(it);
			else
				it++;
		}
		n = index.size() + 1;
		num_zero = n - n/2;
		num_one = n/2;
	}
	cout << endl;
}

void fill_vec(vector<string> & vec){
	string a[] = {"100", "001", "011", "010"};
	for (int i = 0; i < 4; i++){
		vec.push_back(a[i]);
	}
}

int main(){
	vector<string> str_vec;
	fill_vec(str_vec);
	find(str_vec);
	return 0;
}
