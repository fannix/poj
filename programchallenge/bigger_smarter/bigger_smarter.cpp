#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct elephant {
	int weight;
	int iq;
	int index;
};

void read(vector<elephant> & elephants){
	int i = 1;
	elephant e;
	while (scanf("%d %d", &e.weight, &e.iq) == 2){
		e.index = i++;
		elephants.push_back(e);
	}
}

void write(elephant & e){
	cout << e.weight << " " << e.iq <<  " " << e.index << endl;
}

bool lighter(elephant e1, elephant e2){
	return e1.weight < e2.weight;
}

bool fooler(elephant & e1, elephant & e2){
	return e1.iq < e2.iq && e1.weight != e2.weight;
}

void write_int(int e){
	cout << e << " ";
}

bool smaller(int i, int j){
	return i < j;
}

// find longest decreased sequence about iq
void find_LDS(vector<elephant> & elephants){
	int len = elephants.size();
	vector<int> max_len_vec(len, 1);
	vector<int> parent_vec(len, -1);

	if (len > 0){
		max_len_vec[0] = 1;
		parent_vec[0] = -1;
	}

	for (int i = 0; i < len; i++){
		for (int j = i - 1; j >= 0; j--){
			if (fooler(elephants[i], elephants[j])){
				if (max_len_vec[i] < max_len_vec[j] + 1){
					max_len_vec[i] = max_len_vec[j] + 1;
					parent_vec[i] = j;
				}
			}
		}
	}

	//for_each(max_len_vec.begin(), max_len_vec.end(), write_int);
	//cout << endl;
	//for_each(parent_vec.begin(), parent_vec.end(), write_int);
	//cout << endl;
	
	//int max_element_ind = max_element(max_len_vec.begin(), max_len_vec.end(), smaller) - max_len_vec.begin();
	//cout << max_element_ind << endl;
	
	int max_element_ind = len - 1;

	for (int i = max_element_ind; i > 0; i--){
		if (max_len_vec[i] > max_len_vec[max_element_ind]){
			max_element_ind = i;
		}
	}

	vector<int> results;
	for (int i = max_element_ind; i != -1;){
		results.push_back(elephants[i].index);
		i = parent_vec[i];
	}

	cout << results.size() << endl;
	while (!results.empty()){
		cout << results.back() << endl;
		results.pop_back();
	}
}

int main(){
	vector<elephant> elephants;
	read(elephants);
	sort(elephants.begin(), elephants.end(), lighter);
	//for_each(elephants.begin(), elephants.end(), write);
	find_LDS(elephants);
	return 0;
}
