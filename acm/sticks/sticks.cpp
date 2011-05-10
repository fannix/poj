#include <iostream>
#include <vector>

using namespace std;

int main(){
	int num = 0;
	while (cin >> num){
		if (num == 0)
			return 0;

		vector<int> input;
		input.clear();
		vector<int> occurence;
		const int MAX_LEN = 50;
		occurence.assign(MAX_LEN, 0);

		int stick_len;
		int sum = 0;
		while (cin>> stick_len){
			input.push_back(stick_len);
			occurence[stick_len - 1] += 1;
			sum += stick_len;
		}

		for (int i = 1; i <= sum; i++){
			if (sum % i == 0){
			}
		}

	}
	return 0;
}
