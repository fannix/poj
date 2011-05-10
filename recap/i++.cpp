#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	int i = 0;
	string s("000");
	while(s[i++] == '0'){
		//i++;
		cout << i << endl;
	}
	cout << i << endl;
	getchar();
}

