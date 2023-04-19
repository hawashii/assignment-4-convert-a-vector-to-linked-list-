#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class lists
{
	struct node {
		int value;
		int counter=1;
		node* next;
		node* prev;
	};
public:
	node* head = NULL;
	node* tail = NULL;
	node* current;
	node* temp;
	void addnode(int v) {
		node* n = new node;
		n->value = v;
		n->next = NULL;
		n->prev = NULL;
		if (head == NULL) {
			head = n;
			tail = n;
		}
		else {
			tail->next = n;
			n->prev = tail;
			tail = n;
			
		}
		
	}

	void deletenode(int v) {
		node* deleteptr = NULL;
		temp = head;
		current = head;
		while (current != NULL && current->value != v) {
			temp = current;
			current = current->next;
		}
		if (current == NULL) {
			cout << "the value was not in the list";
		}
		else {
			deleteptr = current;
			current = current->next;
			temp->next = current;
			delete deleteptr;
			cout << "the value is deleted";

		}

	}
	void printlist() {
		node* trav = head;
		while (trav != NULL) {
			cout << trav->value << endl;
			trav = trav->next;
		}
	}
	void deletethenode() {
		node* current= tail;
		node* deleteptrr = current;
		deleteptrr->prev->next = NULL;
		tail = deleteptrr->prev;
		delete deleteptrr;
	}
	int sumofnodes(lists l) {
		int sum = 0;
		node* trav = l.head ;
		while (trav != NULL) {
			sum = sum + (trav->value * trav->counter);
			trav = trav->next;
		}return sum;
	}
	lists converttolist(vector<int> v) {
		lists l;
		sort(v.begin(), v.end());
		l.addnode(v[0]);
		node* currr = l.head;
		
		for (currr; currr != NULL; currr = currr->next) {
			for (int c = 1; c <= v.size(); c++) {
				if (v[c] == v[c - 1]) {
					currr->counter++;

				}
				else {
					l.addnode(v[c]);
				}
			}
		}

		
		
	
		
	
		
		return l;
	}

	};

