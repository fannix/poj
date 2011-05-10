#include <iostream>
#include <string>
using namespace std;

int states[10][7] = {
	{1, 1, 1, 0, 1, 1, 1},
	{0, 0, 1, 0, 0, 1, 0},
	{1, 0, 1, 1, 1, 0, 1},
	{1, 0, 1, 1, 0, 1, 1},
	{0, 1, 1, 1, 0, 1, 0},
	{1, 1, 0, 1, 0, 1, 1},
	{1, 1, 0, 1, 1, 1, 1},
	{1, 0, 1, 0, 0, 1, 0},
	{1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 0, 1, 1}
};

void horizon(int state, int repeat){
	cout << " ";
	for (int i = 0; i < repeat; i++){
		if (state == 1)
			cout << "-";
		else
			cout << " ";
	}
	cout << "  ";
}

void vertical(int state1, int state2, int nrepeat){
	if (state1 == 1)
		cout << "|";
	else
		cout << " ";

	for (int i = 0; i < nrepeat; i++)
		cout << " ";

	if (state2 == 1)
		cout << "|";
	else
		cout << " ";
	cout << " ";
}

void ver(string num,  int nrepeat, int istate1, int istate2){
	for (int j = 0; j < nrepeat; j++){
		for (int i = 0; i < num.size(); i++){
			int n = num[i] - '0';
			vertical(states[n][istate1], states[n][istate2], nrepeat);
		}
		cout << endl;
	}
}

void hor(string num, int nrepeat, int state){
	for (int i = 0; i < num.size(); i++){
		int n = num[i] - '0';
		horizon(states[n][state], nrepeat);
	}
	cout << endl;
}

int main(){
	int nrepeat;
	string num;
	while (cin >> nrepeat >> num){
		if (nrepeat == 0)
			return 0;
		hor(num, nrepeat, 0);
		ver(num, nrepeat, 1, 2);
		hor(num, nrepeat, 3);
		ver(num, nrepeat, 4, 5);
		hor(num, nrepeat, 6);
		cout << endl;
	}

	return 0;
}
