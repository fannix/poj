#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

bool match(string pattern, string s, map<char, char> & map1){
	map1.clear();
	map1[' '] = ' ';
	if (pattern.size() != s.size())
		return false;

	for (int i = 0; i < pattern.size(); i++){
		if (map1.find(s[i]) == map1.end())
			map1[s[i]] = pattern[i];
		else if (map1[s[i]] != pattern[i])
			return false;
	}
	if (map1.size() != 27)
		return false;
	return true;
}

int main(){
	string s;
	int num;
	getline(cin, s);
	istringstream is(s);
	is >> num;

	getline(cin, s);
	while (num--){
		vector<string> vec;
		while (getline(cin, s)){
			if (s.size() == 0)
				break;
			vec.push_back(s);
		}

		map<char, char> map1;
		string pattern = "the quick brown fox jumps over the lazy dog";

		bool found = false;
		for(int i = 0; i < vec.size(); i++){
			if (match(pattern, vec[i], map1)){
				found = true;
				break;
			}
		}
		if (!found)
			cout << "No solution." << endl;
		else
			for (int i = 0; i < vec.size(); i++){
				string s1 = vec[i];
				for (int j = 0; j < s1.size(); j++){
					cout << map1[s1[j]];
				}
				cout << endl;
			}
		if (num != 0)
			cout << endl;
	}
	return 0;
}
