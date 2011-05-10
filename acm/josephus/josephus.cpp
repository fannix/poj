#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
	int value;
	node * prev;
	node * next;
};

int main(){
	int n, m;
	while (cin >> n >> m){
		if (n == 0 && m == 0)
			return 0;

		node * head = new node;
		head->value = 1;
		head->prev = NULL;
		head->next = NULL;
		
		node * prev = head;
		node * new_node = NULL;
		for (int i = 2; i <=n; i++){
			new_node = new node;
			new_node->value = i;
			new_node->prev = prev;
			prev->next = new_node;
			prev = new_node;
		}
		if (new_node != NULL){
			new_node->next = head;
			head->prev = new_node;
		}

		node * cur = head;
		while ( n > 1){
			for (int i = 1; i < m; i++){
				cur = cur->next;
			}
			//cout << cur->value << endl;
			node * temp = cur->next;
			if (n > 2){
				cur->prev->next = cur->next;
				cur->next->prev = cur->prev;
				delete cur;
			}
			else{
				cur->next->prev = NULL;
				cur->next->next = NULL;
				delete cur;
			}
			cur = temp;
			n--;
		}

		cout << cur->value << endl;
		delete cur;
	}


	return 0;
}
