#pragma once
#include <iostream>
#include <vector>
using namespace std;


template <typename T>
class LinkedList
{
public:
	struct Node
	{
		T data;
		Node* next;
		Node* prev;
		Node(const T& nodeData, Node* nodeNext, Node* nodePrev)
		{
			data = nodeData;
			next = nodeNext;
			prev = nodePrev;
		}
	};

	/*==== Behaviors ====*/
	void PrintForward() const;
	void PrintReverse() const;
	void PrintForwardRecursive(const Node* node) const;
	void PrintReverseRecursive(const Node* node) const;

	/*==== Accessors ====*/
	unsigned int NodeCount() const;
	void FindAll(vector<Node*>& outData, const T& value) const;
	const Node* Find(const T& data) const;
	Node* Find(const T& data);
	const Node* GetNode(unsigned int index) const;
	Node* GetNode(unsigned int index);
	Node* Head();
	const Node* Head() const;
	Node* Tail();
	const Node* Tail() const;

	/*==== Insertion ====*/
	void AddHead(const T& data);
	void AddTail(const T& data);
	void AddNodesHead(const T* data, unsigned int count);
	void AddNodesTail(const T* data, unsigned int count);
	void InsertAfter(Node* node, const T& data);
	void InsertBefore(Node* node, const T& data);
	void InsertAt(const T& data, unsigned int index);

	/*==== Removal ====*/
	bool RemoveHead();
	bool RemoveTail();
	unsigned int Remove(const T& data);
	bool RemoveAt(unsigned int index);
	void Clear();

	/*==== Operators ====*/
	const T& operator[](unsigned int index) const;
	T& operator[](unsigned int index);
	bool operator==(const LinkedList<T> rhs) const;
	LinkedList<T>& operator=(const LinkedList<T>& rhs);

	/*==== Construction / Destruction ====*/
	LinkedList();
	LinkedList(const LinkedList<T>& list);
	~LinkedList();

private:
	Node* head;
	Node* tail;
	unsigned int count;
};


// Member Function Definitions

// Traverses through all of the nodes and print out their values, one a time
template<typename T>
void LinkedList<T>::PrintForward() const
{
	// Starts at the beginning of the list by pointing to the head node
	Node* currentNode = head;

	// Traverses the list while we are not at the last node
	while (currentNode != nullptr) {

		// Outputs data in the current node, then moves to the next node
		cout << currentNode->data << endl;
		currentNode = currentNode->next;
	}
}

// Exactly the same as PrintForward, except completely the opposite
template<typename T>
void LinkedList<T>::PrintReverse() const
{
	// Starts at the end of the list by pointing to the tail node
	Node* currentNode = tail;

	// Traverses the list while we are not at the last node
	while (currentNode != nullptr) {

		// Outputs data in the current node, then moves to the previous node
		cout << currentNode->data << endl;
		currentNode = currentNode->prev;
	}
}

/* This function takes in a pointer to a Node—a starting node.
From that node, recursively visit each node that follows, in forward order, and print their values.
This function MUST be implemented using recursion, or tests using it will be
worth no points.Check your textbook for a reference on recursion. */
template<typename T>
void LinkedList<T>::PrintForwardRecursive(const Node* node) const
{
	if (node != nullptr) {
		// Prints the passed in node's values
		cout << node->data << endl;

		// Calls PrintForwardRecursive to recursively visit each node that follows
		PrintForwardRecursive(node->next);
	}
}

// Same deal as PrintForwardRecursive, but in reverse. 
template<typename T>
void LinkedList<T>::PrintReverseRecursive(const Node* node) const
{
	if (node != nullptr) {
		cout << node->data << endl;
		
		// Calls PrintReverseRecursive to recursively visit each node before the starting node
		PrintReverseRecursive(node->prev);
	
	}
}

// How many things are stored in this list? 
template<typename T>
unsigned int LinkedList<T>::NodeCount() const
{
	return count;
}

// Use of a parameter like this (passing a something in by reference, and storing data for later use) is called an output parameter
template<typename T>
void LinkedList<T>::FindAll(vector<Node*>& outData, const T& value) const
{
	Node* currentNode = head;
	while (currentNode != nullptr) {

		// A pointer to the node that matches the passed in paramter value is stored in the vector outData
		if (currentNode->data == value) {
			outData.push_back(currentNode);
		}

		// Continues to the next node
		currentNode = currentNode->next;
	}
}

template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) const
{
	Node* currentNode = head;
	while (currentNode != nullptr) {

		// Returns a pointer to the node with a data value matching the passed in parameter
		if (currentNode->data == data) {
			return currentNode;
		}

		// Continues to the next node
		currentNode = currentNode->next;
	}

	// Returns nullptr if no matching node is found
	return nullptr;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data)
{
	Node* currentNode = head;
	while (currentNode != nullptr) {

		if (currentNode->data == data) {
			return currentNode;
		}
		currentNode = currentNode->next;
	}
	return nullptr;
}

// Given an index, return a pointer to the node at that index. Const and non-const versions
template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const
{
	// Throws an exception of type out_of_range if the index is out of range (more than count)
	if (index >= count) {
		throw out_of_range("Error: Index out of range.");
	}

	/// Traverses list from the start until a pointer to the node at the given index is found, then returns it
	Node* currentNode = head;
	for (unsigned int i = 0; i < index; i++) {
		currentNode = currentNode->next;
	}
	return currentNode;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index)
{
	if (index >= count) {
		throw out_of_range("Error: Index out of range.");
	}

	Node* currentNode = head;
	for (unsigned int i = 0; i < index; i++) {
		currentNode = currentNode->next;
	}
	return currentNode;
}

// Returns the head pointer. Const and non-const versions.
template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head()
{
	return head;
}

template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Head() const
{
	return head;
}

// Returns the tail pointer. Const and non-const versions.
template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail()
{
	return tail;
}

template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Tail() const
{
	return tail;
}

// Creates a new Node at the front of the list to store the passed in parameter
template<typename T>
void LinkedList<T>::AddHead(const T& data)
{
	// Creates a new Node that includes the passed in parameters of data, head, and nullptr
	Node* newNode = new Node(data, head, nullptr);

	// Makes new Node both the head and tail if the list is empty
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		// Sets the previous pointer of the head to the new Node to be added at the front of the list
		head->prev = newNode;
		head = newNode;
	}

	// Increments the Node count
	count += 1;
}

// Creates a new Node at the end of the list to store the passed in parameter
template<typename T>
void LinkedList<T>::AddTail(const T& data)
{
	Node* newNode = new Node(data, nullptr, tail);
	if (tail == nullptr) {
		head = newNode;
		tail = newNode;
	}

	// Sets the next pointer of the tail to the new Node to be added at the end of the list
	else {
		tail->next = newNode;
		tail = newNode;
	}

	// Sets the next pointer of new Node to null since it is at the end of the list
	newNode->next = nullptr;
	count += 1;
}

// Given an array of values, inserts a node for each of those at the beginning list, maintaining the original order
template<typename T>
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count)
{
	// Traverses through the array and inserts each node at the beginning of the list with the AddHead function
	for (int i = count - 1; i >= 0; i--) {
		AddHead(data[i]);
	}
}

// Ditto, except adds to the end of the list
template<typename T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count)
{
	// Traverses through the array and inserts each node at the end of the list with the AddTail function
	for (unsigned int i = 0; i < count; i++) {
		AddTail(data[i]);
	}
}

// Given a pointer to a node, create a new node to store the passed in value, after the indicated node. 
template<typename T>
void LinkedList<T>::InsertAfter(Node* node, const T& data)
{
	// Creates a new node to store the passed in value
	Node* newNode = new Node(data, head, tail);

	// Checks if the indicated node is the tail of the list, which means the new node will be the new tail
	if (node == tail) {
		newNode->next = nullptr;
		tail = newNode;
	}

	// Otherwise, sets the new node's next pointer to the indicated node's next node 
	else {
		newNode->next = node->next;
	}

	// Inserts the new node after the indicated node
	node->next = newNode;
	newNode->prev = node;
	count += 1;

}

// Ditto, except insert the new node before the indicated node.
template<typename T>
void LinkedList<T>::InsertBefore(Node* node, const T& data)
{
	Node* newNode = new Node(data, head, tail);

	// Checks if the indicated node is the head of the list, which means the new node will be the new head
	if (node == head) {
		newNode->next = head;
		head = newNode;
	}

	// Otherwise, sets the new node's prev pointer to the indicated node's previous node 
	else {
		newNode->prev = node->prev;

		// Sets the next pointer of the node before the indicated node to newNode
		node->prev->next = newNode;
	}

	// Inserts the new node before the indicated node
	node->prev = newNode;
	newNode->next = node;
	count += 1;
}

/* Inserts a new Node to store the first parameter, at the index - th location.
So if you specified 3 as the index, the new Node should have 3 Nodes before it. */
template<typename T>
void LinkedList<T>::InsertAt(const T& data, unsigned int index)
{

	if (index > count) {
		throw out_of_range("Error: Index out of range.");
	}

	// Checks if index equals 0, which means that is at the beginning of the list as a head
	if (index == 0) {
		AddHead(data);
	}

	// Checks if index equals the count number, which means that is at the end of the list as the tail
	else if (index == count) {
		AddTail(data);
	}

	else {
		Node* currentNode = head;

		// Traverses the list until the value before the passed in value is reached 
		for (unsigned int i = 0; i < index - 1; i++) {
			currentNode = currentNode->next;
		}

		// Inserts a new node to store the first parameter 
		Node* newNode = new Node(data, head, tail);

		// Sets the next and prev pointers of the new node to insert and link the new node between two existing nodes
		newNode->next = currentNode->next;
		newNode->prev = currentNode;
		currentNode->next = newNode;

		// Sets the next pointer of the node before the new Node to newNode
		newNode->prev->next = newNode;
		count += 1;
	}
}

// Deletes the first Node in the list. Returns whether or not the Node was removed.
template<typename T>
bool LinkedList<T>::RemoveHead()
{
	// Checks if list is empty, which means the head cannot be removed so return false
	if (head == nullptr) {
		return false;
	}

	// Checks if there is only one node in the list, which should then be removed
	else if (head == tail) {
		delete head;
		head = nullptr;
		tail = nullptr;
		count = 0;
		return true;
	}
	else {
		// Creates and sets the new head node to the node next to the original head
		Node* newHead = head->next;

		// Deletes the original head and sets the new head node to be the new head/first Node of the list
		delete head;
		head = newHead;
		count -= 1;
		return true;
	}
}

// Deletes the last Node, returning whether or not the operation was successful
template<typename T>
bool LinkedList<T>::RemoveTail()
{
	if (tail == nullptr) {
		return false;
	}

	// Checks if there is only one node in the list, which should then be removed
	else if (head == tail) {
		delete tail;
		head = nullptr;
		tail = nullptr;
		count = 0;
		return true;
	}
	else {
		Node* newTail = tail->prev;
		newTail->next = nullptr;
		delete tail;
		tail = newTail;
		count -= 1;
		return true;
	}
}

// Remove ALL Nodes containing values matching that of the passed-in parameter.
//Returns how many instances were removed.
template<typename T>
unsigned int LinkedList<T>::Remove(const T& data)
{
	unsigned int numRemoved = 0;
	Node* currentNode = head;
	while (currentNode != nullptr) {

		// Checks if the node contains a value matching the value of the passed-in parameter
		if (currentNode->data == data) {

			// Points to the next node in order to delete current node and continues to the loop
			Node* nextNode = currentNode->next;

			// Checks if the node to be removed is the head, and if so, assigns the head to the next node
			if (currentNode == head) {
				head = nextNode;
			}

			// Checks if the node to be removed is the tail, and if so, assigns the tail to the previous node
			if (currentNode == tail) {
				tail = currentNode->prev;
			}

			// Updates the next and prev pointers of the surrounding nodes to link the list back together after removal
			if (currentNode->prev != nullptr) {
				currentNode->prev->next = currentNode->next;
			}
			if (currentNode->next != nullptr) {
				currentNode->next->prev = currentNode->prev;
			}
			delete currentNode;
			count -= 1;
			
			// Increments numRemoved to keep track and later return how many instances were removed 
			numRemoved += 1;

			// Updates currentNode to the next node
			currentNode = nextNode;
		}
		else {
			currentNode = currentNode->next;
		}
	}
	return numRemoved;
}

// Deletes the index-th Node from the list, returning whether or not the operation was successful.
template<typename T>
bool LinkedList<T>::RemoveAt(unsigned int index)
{
	if (index >= count) {
		return false;
	}

	// Traverses the list until the index-th Node is found, which is then deleted
	Node* currentNode = head;
	for (unsigned int i = 0; i < index; i++) {
		currentNode = currentNode->next;
	}
	// Updates the pointers of the surrounding nodes
	if (currentNode->prev != nullptr) {
		currentNode->prev->next = currentNode->next;
	}
	if (currentNode->next != nullptr) {
		currentNode->next->prev = currentNode->prev;
	}

	delete currentNode;
	count -= 1;

	return true;
}

// Deletes all Nodes. Don’t forget the node count—how many nodes do you have after you deleted all of them?
template<typename T>
void LinkedList<T>::Clear()
{
	// Traverses the list to delete each node one at a time
	Node* currentNode = head;
	while (currentNode != nullptr) {
		Node* nextNode = currentNode->next;
		delete currentNode;
		currentNode = nextNode;
	}

	// Resets the variables to create an empty list 
	count = 0;
	head = nullptr;
	tail = nullptr;
}

// Overloaded subscript operator. Takes an index, and returns data from the indexth node. Const and nonconst versions
template<typename T>
const T& LinkedList<T>::operator[](unsigned int index) const
{
	// Throws an error if index is higher than the count of the list
	if (index >= count) {
		throw out_of_range("Error: Index out of range.");
	}

	Node* currentNode = head;
	for (unsigned int i = 0; i < index; i++) {
		currentNode = currentNode->next;
	}

	// Returns data from the indexth node
	return currentNode->data;
}

template<typename T>
T& LinkedList<T>::operator[](unsigned int index)
{
	if (index >= count) {
		throw out_of_range("Error: Index out of range.");
	}

	Node* currentNode = head;
	for (unsigned int i = 0; i < index; i++) {
		currentNode = currentNode->next;
	}

	return currentNode->data;
}

/* Overloaded equality operator. Given listAand listB, is listA equal to listB, what
would make one Linked List equal to another? If each of its nodes were equal to the corresponding node of the other.
(Similar to comparing two arrays, just with non - contiguous data). */
template<typename T>
bool LinkedList<T>::operator==(const LinkedList<T> rhs) const
{
	// Checks if the lists have different counts/numbers of nodes, which would mean the lists are not equal
	if (count != rhs.count) {
		return false;
	}

	// Traverses both lists
	Node* currentNode = head;
	Node* otherNode = rhs.head;
	while (currentNode != nullptr) {

		// Checks if the data in the current nodes is different, which would mean the lists are not equal
		if (currentNode->data != otherNode->data) {
			return false;
		}

		// Moves to the next node in each list
		currentNode = currentNode->next;
		otherNode = otherNode->next;
	}

	// Returns true if no differences were found, which would mean the lists are equal
	return true;
}


// Assignment operator. After listA = listB, listA == listB is true. 
// (Hint: Yes. You can utitilize your existing functions to write this one)
template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
	// Checks to not self-assign 
	if (this != &rhs) {

		// Deletes the nodes of the old list one at a time 
		Node* currentNode = head;
		while (currentNode != nullptr) {
			Node* tempNode = currentNode;
			currentNode = currentNode->next;
			delete tempNode;
		}

		// Resets the variables to create an empty list 
		count = 0;
		head = nullptr;
		tail = nullptr;

		// Allocates new memory and copies data from rhs to the empty list with the AddTail function
		Node* newCurrentNode = rhs.head;
		while (newCurrentNode != nullptr) {
			AddTail(newCurrentNode->data);
			newCurrentNode = newCurrentNode->next;
		}
	}

	// Returns a reference to the current object to chain multiple assignments together
	return *this;
}

// Default constructor. 0 nodes in an empty list; head and tail points to nullptr; initialize variables
template <typename T>
LinkedList<T>::LinkedList()
{
	count = 0;
	head = nullptr;
	tail = nullptr;
}

// Copy Constructor. Sets “this” to a copy of the passed in LinkedList
// For example, if the other list has 10 nodes with values of 1-10, “this” should have a copy of that same data
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list)
{
	count = 0;
	head = nullptr;
	tail = nullptr;

	// Copies the data from the passed in parameter list
	Node* currentNode = list.head;
	while (currentNode != nullptr) {

		// Adds the new node to the end of the list with the AddTail function
		AddTail(currentNode->data);
		currentNode = currentNode->next;

	}
}

// Deletes all the nodes created by the list
template<typename T>
LinkedList<T>::~LinkedList()
{
	Node* currentNode = head;
	while (currentNode != nullptr) {

		// Creates a temporary node pointer to the current node, then gets next node
		Node* tempNode = currentNode;
		currentNode = currentNode->next;

		// Deletes the node that the temporary node pointer points to
		delete tempNode;
	}
}
