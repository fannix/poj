#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int a[20] = {0, 1, 2, 3, 4, 5};
int n = 4;

void swap(int a[], int i, int j){
	int temp = a[j];
	a[j] = a[i];
	a[i] = temp;
}

void next(int d){
	if (d == n){
		for (int i = 0; i < d; i++){
			cout << a[i] << " "; 
		}
		cout << endl;
	}
	else
		for (int i = d; i < n; i++){
			swap(a, d, i);
			next(d+1);
			swap(a, i, d);
		}
}

int main(){
	next(0);
	getchar();
}

