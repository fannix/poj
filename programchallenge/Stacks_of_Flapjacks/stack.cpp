#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const int MAX = 31;
int len = 0;

int a[MAX];

void swap(int i, int j){
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void reverse(int k){
	cout << len - k << " ";
	int i = 0;
	while (i < k)
		swap(i++, k--);
}

// flip recursively, ensure the k-th number
// is in the correct position
void flip_r(int k){
	if (k == 0)
		return;
	int max = a[0];
	int max_i = 0;
	for (int i = 0; i < k; i++){
		if (a[i] > max){
			max = a[i];
			max_i = i;
		}
	}

	if (max_i != k - 1){
		if (max_i != 0)
			reverse(max_i);
		reverse(k - 1);
	}

	flip_r(k - 1);
}

int main(){
	string s;
	while (getline(cin, s)){
		istringstream is(s);
		int d = 0;
		int i = 0;

		while (is >> d){
			a[i++] = d;
		}
		len = i;
		for(int i = 0; i < len; i++)
			cout << a[i] << " ";
		cout << endl;
		
		flip_r(i);

		//for(int i = 0; i < len; i++)
			//cout << a[i] << " ";
		
		cout << "0" << endl;
	}
	return 0;
}
