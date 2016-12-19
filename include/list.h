#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

template<class T>

class list {

public:
	struct _node {
		_node *next;
		T data;
		_node(T _data):
			data(_data)
			{}
	};

private:
	_node *head;
	
private:
	void deleteList();

public:
	list():head(nullptr) {
	}
	~list() {
		deleteList();
	}
	T popFront() {
		if(head == nullptr) return -1;
		_node *node = head;
		head = head->next;
		T val = node->data;
		delete node;
		return val;
	}
	void pushFront(T data);
	void pushBack(T data);
	void print();
	void createCycle();
	bool detectCycle();
	void sortList();
	void sortedInsert(_node **head, _node *node);
};
template<class T>
void list<T>::sortedInsert(_node **head, _node *node) {
	if(*head == nullptr) {
		node->next = *head;
		*head = node;
		return;
	}

	if((*head)->data > node->data) {
		node->next = *head;
		*head = node;
	} else {
		_node *cur = *head;
		while(cur->next != nullptr && (cur->next->data < node->data))
			cur = cur->next;
		node->next = cur->next;
		cur->next = node;
	}
}
template<class T>
void list<T>::sortList() {

	_node *node = head;
	_node *next = nullptr;
	_node *sorted = nullptr;

	while(node != nullptr) {

		next = node->next;
		sortedInsert(&sorted, node);
		node = next;		
	}
	head = sorted;
}
template<class T>
void list<T>::createCycle() {
	_node *cur = head;
	_node *cycle = nullptr;
	int i=0;

	 while(cur && cur->next) {
	 	if( i++ == 10) {
			cycle = cur;
		}
	 	cur = cur->next;
	}
	cur->next = cycle;
}
template<class T>
void list<T>::print() {
	_node *cur= head;
	while(cur != nullptr) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}
template<class T>
void list<T>::deleteList() {
	while(head) {
		_node *tmp = head;
		head = head->next;
		delete tmp;
	}
	head = nullptr;
}
template<class T>
void list<T>::pushFront(T data) {
	_node *nnode = new _node(data);
	nnode->next = head;
	head = nnode;
}
template<class T>
void list<T>::pushBack( T data) {
	_node *nnode = new _node(data);
	if(head == nullptr) {
		nnode->next = head;
		head = nnode;
	} else {
		_node *cur = head;
		while(cur->next != nullptr) cur = cur->next;
		nnode->next = cur->next;
		cur->next = nnode;
	}
}
template<class T>
bool list<T>::detectCycle(){
	if(head == nullptr) return false;
	_node *slow = head;
	_node *fast = head->next;
	while(fast != nullptr && fast->next != nullptr) {
		if(slow == fast) {
			fast->next=nullptr;
			cout << fast->data << endl;
			return true;
		}
		fast = fast->next->next;
		slow = slow->next;
	}
	return false;
}

