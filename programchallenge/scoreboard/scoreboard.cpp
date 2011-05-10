#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int penalty_time[100][9];
int solved[100][9];
bool submit[100];

struct contest {
	int number;
	int solvednum;
	int penalty;
	bool submit;
};

int comp1(contest con1, contest con2){

	if (con1.solvednum > con2.solvednum)
		return 1;
	else if (con1.solvednum < con2.solvednum)
		return 0;
	else if (con1.penalty < con2.penalty)
		return 1;
	else
		return 0;
}

int main(){
	int num;
	cin >> num;

	string line;
	getline(cin, line);
	getline(cin, line);
	while (num--){
		getline(cin, line);
		while (line.size() != 0){
			//cout << line;
			istringstream is(line);
			int contestant;
			int problem;
			int time;
			string status;
			is >> contestant >> problem >> time >> status;
			submit[contestant - 1] = true;

			if (solved[contestant-1][problem - 1] == 0){
				if (status ==  "C"){
					penalty_time[contestant-1][problem - 1] += time;
					solved[contestant-1][problem - 1] = 1;
				}
				else if (status == "I")
						penalty_time[contestant-1][problem - 1] += 20;
			}

			getline(cin, line);
		}

		vector<contest> vec;
		vec.clear();

		for (int i = 0; i < 100;  i++){
			contest contest1;
			contest1.number = i;
			contest1.penalty = 0;
			contest1.solvednum = 0;
			contest1.submit = submit[i];
			for (int j = 0; j < 9; j++){
				if (solved[i][j])
					contest1.penalty += penalty_time[i][j];
				contest1.solvednum += solved[i][j];
			}
			vec.push_back(contest1);
		}

		stable_sort(vec.begin(), vec.end(), comp1);

		for (int i = 0; i < vec.size(); i++){
			if (vec[i].submit){
				cout << vec[i].number  + 1<< " " << vec[i].solvednum << " " << vec[i].penalty << endl;
			}
		}
		if (num > 0)
			cout << endl;

		for (int i = 0; i < 100; i++){
			submit[i] = false;
			for (int j = 0; j < 9; j++){
				solved[i][j] = penalty_time[i][j] = 0;
			}
		}
	}

	return 0;
}
