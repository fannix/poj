#include <iostream>
using namespace std;

#define NCATE 13
#define NROUND 13
#define NDICE 5

int score[NROUND][NCATE];
int input[NROUND][NDICE];
int solution[NROUND];

void sum(int num, int i){
	for (int j = 0; j < NDICE; j++){
		if (input[i][j] == num)
			score[i][num-1] += num;
	}
}

void init(){
	for (int i = 0; i < NROUND; i++)
		for (int j = 0; j < NCATE; j++)
			score[i][j] = 0;
	for (int i = 0; i < NROUND; i++)
		for (int j = 0; j < NDICE; j++)
			input[i][j] = 0;
	for (int i = 0; i < NROUND; i++)
		solution[i] = 0;
}

void kind(int i){
	int count[6] = {0};
	for (int j = 0; j < NDICE; j++){
		count[input[i][j] - 1] ++;
	}

	int max = 0;
	for (int j = 0; j < 6; j++){
		if (max < count[j])
			max = count[j];
	}
	int sum = 0;
	for (int j = 0; j < NDICE; j++){
		sum += input[i][j];
	}
	if (max >= 3)
		score[i][7] = sum;
	if (max >= 4)
		score[i][8] = sum;
	if (max >= 5)
		score[i][9] = 50;
}

void print(){
	for (int i = 0; i < NROUND; i++){
		for (int j = 0; j < NCATE; j++)
			cout << score[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

int main(){
	while (true){
		init();
		for (int i = 0; i < NROUND; i++){
			for (int j = 0; j < NDICE; j++)
				if (!(cin >> input[i][j]))
					return 0;
		}

		for (int i = 0; i < NROUND; i++){
			for(int num = 1; num <= 6; num++){
				sum(num, i);
			}

			for (int j = 0; j < NDICE; j++)
				score[i][6] += input[i][j];

			kind(i);
		}
		print();

	}

}
