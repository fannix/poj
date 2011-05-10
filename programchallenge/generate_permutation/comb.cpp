#include <iostream>
#include <string>

using namespace std;

#define MAXN 64
int a[MAXN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int n = 20;
int m = 3;

void swap(int a[], int i, int j){
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void print(){
	for (int i = 0; i < m-1; i++){
		if (a[i] > a[i+1])
			return;
	}
	for (int i = 0; i < m; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}



void next(int d){
	if (d == m)
		print();
	else{
		for (int i = d; i < n; i++){
			swap(a, i, d);
			next(d + 1);
			swap(a, i, d);
		}
	}
}

void init(){
	for (int i = 0; i < MAXN; i++){
		a[i] = i+1;
	}
}

int main(){
	init();
	next(0);
	test();
	return 0;
}

