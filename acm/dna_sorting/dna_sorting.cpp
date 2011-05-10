#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

struct elem{
	string s;
	int ninversion;
};

int cmp(const elem & e1, const elem & e2){
	return e1.ninversion < e2.ninversion;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<elem> input;
	while (m--){
		string s;
		cin >> s;

		int sum = 0;
		for (int i = 0; i < n-1; i++)
			for (int j = i+1; j < n; j++)
				if (s[i] > s[j])
					sum++;
		elem e;
		e.s = s;
		e.ninversion = sum;
		input.push_back(e);
	}
	stable_sort(input.begin(), input.end(), cmp);

	for (int i = 0; i < input.size(); i++)
		cout << input[i].s << endl;

	return 0;
}
