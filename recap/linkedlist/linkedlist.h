#ifndef  __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
#include <vector>

using namespace std;

class node {
	public:
		int value;
		node * next;

		node(int v){
			this->value = v;
			this->next = NULL;
		}
};

node * create_list(vector<int> &values){
	node * head = NULL;
	if (values.size() >= 1){
		head = new node(values[0]);
	}
	else 
		return NULL;

	node * p = head;
	for (int i = 1; i < values.size(); i++){
		p->next = new node(values[i]);
		p = p->next;
	}
	return head;
}

void print_list(node * head){
	while (head != NULL){
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}

void free_list(node * head){
	node * p = head;
	while (p != NULL){
		node * q = p->next;
		delete p;
		p = q;
	}
}

int main1(){
	int a[] = {1};
	vector<int> vec1(a, a+sizeof(a)/sizeof(a[0]));
	node * head = create_list(vec1);
	print_list(head);
	free_list(head);

	return 0;
}

#endif
