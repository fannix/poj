#include <iostream>
#include <string>
using namespace std;

const int MAX_LEN = 2000;

int read(int weight [], int iq[]){
	// format:
	// weight iq
	int i = 0;	
	while (cin >> weight[i] >> iq[i]){
		i ++;
	}
	return i;
}

void write(int weight[] , int iq[], int len){
	for (int i = 0; i < len; i ++){
		cout << weight[i] << " " << iq[i] << endl;
	}
}

// if i is bigger but fooler than j ?
bool bigger_fooler(int weight[], int iq[], int i, int j){
	return (weight[i] > weight[j] && iq[i] < iq[j]);
}

// find longest increase sequence
void findLIS(int weight[], int iq[], int len){
	int max_LIS_len[MAX_LEN];
	int parent_LIS[MAX_LEN];

	max_LIS_len[0] = 1;
	parent_LIS[0] = -1;

	for (int i = 0; i < len; i++){
		for (int j = i - 1; j >= 0; j--){
			// find an elephant bigger but fooler than i
			if (bigger_fooler(weight, iq, i, j)){
				max_LIS_len[i] = max_LIS_len[j] + 1;
				parent_LIS[i] = j;
				break;
			}
			//if not found
			max_LIS_len[i]  = 1;
			parent_LIS[i] = -1;
		}
	}

	//for (int i = 0; i < len; i++){
		//cout << max_LIS_len[i] << " ";
	//}
	//cout << endl;
	//for (int i = 0; i < len; i++){
		//cout << parent_LIS[i] << " ";
	//}
	
	int max_len = -1;
	int max_len_end = -1;

	for (int i = 0; i < len; i++){
		if (max_len < max_LIS_len[i]){
			max_len = max_LIS_len[i];
			max_len_end = i;
		}
	}
	
	// output the desired result
	cout << max_len << endl;
	for (int i = max_len_end; i != -1;){
		cout << i << endl;
		i = parent_LIS[i];
	}
}


int main(){
	int weight[MAX_LEN];
	int iq[MAX_LEN];

	int len = read(weight, iq);
	findLIS(weight, iq, len);

	return 0;
}
