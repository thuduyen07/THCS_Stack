#include <iostream>
using namespace std;

typedef struct node Node;
struct node {
	int value;
	Node* next;
};

Node* newNode(int data) {
	Node* node = new Node;
	node->value = data;
	node->next = NULL;
	return node;
}

class stack {
private:
	Node* head;
public:
	stack() {
		head = NULL;
	}
	void push(int data) {
		if (head == NULL) {
			head = newNode(data);
			return;
		}
		Node* node = new Node;
		node->value = data;
		node->next = head;
		head = node;
	}

	int pop() {
		if (head == NULL) {
			return -1;
		}
		int result = head->value;
		Node* temp = head;
		head = head->next;
		delete temp;
		return result;
	}

	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	void printStack() {
		if (head == NULL) {
			cout << "Stack is empty" << endl;
			return;
		}
		Node* temp = head;
		cout << "Stack: ";
		while (temp->next != NULL) {
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << temp->value << endl;
	}
};

int main() {
	stack myStack = stack();
	myStack.printStack();
	
	myStack.push(100);
	myStack.push(200);
	myStack.printStack();

	int value = 0;
	value = myStack.pop();
	cout << "popping stack... value is: " << value << endl;
	myStack.printStack();
	value = myStack.pop();
	cout << "popping stack... value is: " << value << endl;
	myStack.printStack();
	value = myStack.pop();
	cout << "popping stack... value is: " << value << endl;
	cout << "The stack is empty? " << boolalpha << myStack.isEmpty() << endl;
}