#include <iostream>
#include <string>
using namespace std;

void sub(string &input, string& s, int k){
	int n = input.size();
	int m = s.size();
	int j = 0;
	for (int i = 0; i < n; i++){
		if (input[i] == s[j]){
			// note here: segmentation fault
			input[i] = s[(j + m*k - k) % m];
			j++;
		}
	}

}

bool group1(char c){
	return ('i' >= c && c >= 'a');
}

bool group2(char c){
	return ('r' >= c && c >= 'j');
}

bool group3(char c){
	return (c == '_' || 'z' >= c && c >= 's');
}

void subgroup(string &input, int k, bool (* group)(char)){
	string s("");
	int n = input.size();
	for(int i = 0; i < n; i++){
		if (group(input[i])){
			s += input[i];
		}
	}
	sub(input, s, k);

}

int main(){
	int k1, k2, k3;
	while (cin >> k1 >> k2 >> k3){
		if (k1 == 0 && k2 == 0 && k3 == 0)
			return 0;
		string s;
		cin >> s;

		subgroup(s, k1, group1);
		subgroup(s, k2, group2);
		subgroup(s, k3, group3);

		cout << s << endl;
	}
	return 0;
}
