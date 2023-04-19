#include<iostream>
#include<vector>
#include"lists.h"
using namespace std;
void inserAfer(vector<int> v, int firstnum, int secnum) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == firstnum) {
			v[i + 1] = secnum;
		}
	}
}
int main() {
	vector<int> v;
	int num;
	cout << "please enter a number";
	cin >> num;
	v.push_back(num);
	bool flag = true;
	char answer;
	while (flag == true) {
		cout << "do you want to enter another number" << endl;
		cin >> answer;
		if ((answer != 'y' )&& (answer!='n')) {
			cout << "wrong answer";
		}
		else {
			if (answer == 'n') {
				flag = false;
			}
			else {
				if (answer == 'y') {
					cout << "please enter a number";
					cin >> num;
					v.push_back(num);
				}
			}
		}
	}
	
	lists l;
	(l.converttolist(v)).printlist();
	cout << l.sumofnodes((l.converttolist(v)));
	
	vector<int> vv = { 1,2,3,4,5 };
	inserAfer(vv, 2, 7);
	for (int j = 0; j < vv.size(); j++) {
		cout << v[j];
	}

}