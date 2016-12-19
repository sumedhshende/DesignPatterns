#include "../include/list.h"
#include <iostream>
#include <string>
#include <cstdlib>

template<class T>
class Stack {
	list<T> _list;

		public:
		void push( T item) {
			_list.pushFront(item);
		}
		T pop() {
			return _list.popFront();
		}

};

int main() {
	Stack<int> gStack;
	
	for(int i=0;i<10;i++){
//		int r = rand() % 10;
//		if(r%2 ==0)
		gStack.push(i);

	}
	for(int i=0;i<10;i++){
		cout << gStack.pop() << " ";
	}
	return 0;
}
