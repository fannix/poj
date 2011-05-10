#include <vector>
#include <iostream>
#include <stack>
using namespace std;

struct xy{
	int x;
	int y;
	xy(int x, int y){
		this->x = x;
		this->y = y;
	}
};

void swap(vector<int> &vec1, int i, int j){
	int temp = vec1[i];
	vec1[i] = vec1[j];
	vec1[j] = temp; 
}

int sweep(vector<int> &vec1, int start, int end){
	int j = start + 1;
	for (int k = start+1; k <= end; k++){
		if (vec1[k] < vec1[start]){
			swap(vec1, j, k);
			j++;
		}
	}
	swap(vec1, start, j-1);
	return j-1;
}

void quick_sort(vector<int> &vec1){
	stack<xy> stack1;
	int start = 0;
	int end = 0;
	stack1.push(xy(0, vec1.size()-1));

	while (!stack1.empty()|| start != end){
		if (start == end){
			xy xy1 = stack1.top();
			stack1.pop();
			start = xy1.x;
			end = xy1.y;
		}
		int partition = sweep(vec1, start, end);
		if (end - partition > 1)
			stack1.push(xy(partition+1, end));
		start = start;
		end = partition;
		
	}
}

int main(){
	int a[] = {21, 2, 3};

	vector<int> vec1(a, a + sizeof(a)/sizeof(int));

	quick_sort(vec1);
	for (int i = 0; i < vec1.size(); i++)
		cout << vec1[i] << " ";
	cout << endl;
	getchar();
	return 0;
}

