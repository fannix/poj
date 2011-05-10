#include <map>
#include <iostream>
#include <string>
using namespace std;

void mapstring(string line, map<char, char> & charmap){
	int len = line.size();
	for (int i = 1; i < len; i++){
		charmap[line[i]] = line[i-1];
	}
}

int main(){
	string lines[] = {
		"`1234567890-=",
		"QWERTYUIOP[]\\",
		"ASDFGHJKL;'",
		"ZXCVBNM,./"
	};

	map<char, char> charmap;

	for (int i = 0; i < 4; i++)
		mapstring(lines[i], charmap);

	//for (map<char, char>::iterator it = charmap.begin(); it != charmap.end(); it++)
		//cout << it->first << " " << it->second << endl;
	string input;
	while (getline(cin, input)){
		int len = input.size();

		for (int i = 0; i < len; i++){
			if(charmap.find(input[i]) == charmap.end())
				cout << input[i];
			else
				cout << charmap[input[i]];
		}
		cout << endl;
	}
	return 0;
}
