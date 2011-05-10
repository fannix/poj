#include <iostream>
using namespace std;

#define N 6

bool a [N];

void print(){
	for (int i = 0; i < N; i++){
		if (a[i])
			cout << i;
	}
	cout << endl;
}

void next(int d){
	if (d == N){
		print();
		return;
	}

	a[d] = true;
	next(d+1);
	a[d] = false;
	next(d+1);
}

int main(){
	next(0);
	return 0;
}
