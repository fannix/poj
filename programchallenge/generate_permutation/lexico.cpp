#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int a[20] = {0, 1, 2, 3, 4, 5};
int nperm = 4;

void swap(int a[], int i, int j){
	int temp = a[j];
	a[j] = a[i];
	a[i] = temp;
}

void reverse(int a[], int i, int j){
	while (i < j){
		swap(a, i++, j--);
	}
}

void next(int a[], int n){
	int i = n-2;
	while (i>=0 && a[i] > a[i+1])
		i--;
	int j = n-1;
	while (a[i] > a[j])
		j--;
	swap(a, i, j);
	reverse(a, i+1, n-1);
}

int main(){
	for (int i = 0; i < nperm; i++){
		cout << a[i] << "  ";
	}
	cout << endl;
	for (int i = 0; i < 23; i++){
		next(a, nperm);
		for (int i = 0; i < nperm; i++){
			cout << a[i] << "  ";
		}
		cout << endl;
	}

	getchar();
}

