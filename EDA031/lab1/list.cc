#include <iostream>
#include "list.h"
using namespace std;

List::List() {
	first = NULL;
}

List::~List() {
	Node* n = first;
	Node* next;
	while(n != NULL){
		next = n->next;
		delete(n);
		n = next;
	}
}

bool List::exists(int d) const {
	Node* n = first;
	while(n!=NULL){
		if(n->value == d){
			return true;
		}
		n = n->next;
	}
	return false;
}

int List::size() const {
	if(empty()){
		return 0;
	}

	Node* n = first->next;
	int sum = 1;
	while(n != NULL){
		++sum;
		n = n->next;
	}
	return sum;
}

bool List::empty() const {
	return first == NULL;
}

void List::insertFirst(int d) {
	Node* n = new Node(d,first);
	first = n;
}

void List::remove(int d, DeleteFlag df) {

	if(checkDeleteFlag(first->value, d, df)){
		Node* tmp = first;
		first = tmp->next;
		delete(tmp);
	}else{
		Node* n = first->next;
		Node* prev = first;
		while(n!= NULL){
			if(checkDeleteFlag(n->value, d, df)){
				prev->next = n->next;
				delete(n);
				return;
			}else{
				prev = n;
				n = n->next;
			}
		}
	}
}

bool List::checkDeleteFlag(int v, int d, DeleteFlag df) {
	if(df == List::DeleteFlag::LESS){
		if(v < d){
			return true;
		}
	}else if(df == List::DeleteFlag::EQUAL){
		if(v == d){
			return true;
		}
	}else{
		if(v > d){
			return true;
		}
	}
	return false;
}

void List::print() const {
	if(empty()){
		return;
	}

	Node* n = first;
	while(n != NULL){
		cout << n->value << endl;
		n = n->next;
	}
}

