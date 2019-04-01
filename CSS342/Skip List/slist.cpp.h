#include <stdlib.h>

template<class Object>
SList<Object>::SList() {
	init();
}

template<class Object>
SList<Object>::SList(const SList &rhs) {
	init();
	*this = rhs;                                   // then assign rhs to this.
}

template<class Object>
void SList<Object>::init() {
	for (int i = 0; i < LEVEL; i++) {  // for each level
									   // create the left most dummy nodes;
		header[i] = new SListNode<Object>;
		header[i]->prev = NULL;
		header[i]->down = (i > 0) ? header[i - 1] : NULL;
		header[i]->up = NULL;
		if (i > 0) header[i - 1]->up = header[i];

		// create the right most dummy nodes;
		header[i]->next = new SListNode<Object>;
		header[i]->next->next = NULL;
		header[i]->next->prev = header[i];
		header[i]->next->down = (i > 0) ? header[i - 1]->next : NULL;
		header[i]->next->up = NULL;
		if (i > 0) header[i - 1]->next->up = header[i]->next;
	}

	// reset cost.
	cost = 0;
}

template<class Object>
SList<Object>::~SList() {
	clear();                                      // delete items starting 1st
	for (int i = 0; i < LEVEL; i++) {
		delete header[i]->next;                      // delete the right most dummy
		delete header[i];                            // delete the left most dummy
	}
}

template<class Object>
bool SList<Object>::isEmpty() const {
	return (header[0]->next->next == NULL);
}

template<class Object>
int SList<Object>::size() const {
	SListNode<Object> *p = header[0]->next; // at least the right most dummy
	int size = 0;

	for (; p->next != NULL; p = p->next, ++size);
	return size;
}

template<class Object>
void SList<Object>::clear() {
	for (int i = 0; i < LEVEL; i++) {        // for each level
		SListNode<Object> *p = header[i]->next;  // get the 1st item 
		while (p->next != NULL) {              // if this is not the left most
			SListNode<Object> *del = p;
			p = p->next;                           // get the next item
			delete del;                            // delete the current item
		}

		header[i]->next = p;                     // p now points to the left most 
	}                                          // let the right most point to it
}

template<class Object>
void SList<Object>::insert(const Object &obj) {
	// right points to the level-0 item before which a new object is inserted.
	SListNode<Object> *right = searchPointer(obj);  // return the pointer to an item >= a given object.
	SListNode<Object> *up = NULL;

	if (right->next != NULL && right->item == obj)
		// there is an identical object
		return;

	// Implement the rest by yourself /////////////////////////////////////////
	
	// The block of code immediately below is for inserting on the very bottom level.
		SListNode<Object> *currentNode = new SListNode<Object>; // This will be the node that will contain obj information
		currentNode->item = obj; // The object in in the node.
		currentNode->next = right;  // currentNode's next now points to the node greater than it.
		currentNode->prev = right->prev; // currentNode's previous now points to the node that once was behind right.
		right->prev->next = currentNode; // What once was pointing at the greater node, is now pointing to the currentNode
		right->prev = currentNode;  // node greater than CurrentNode has it's previous point at currentNode
		currentNode->down = NULL; // Since we're on the bottom level, down points to nothing.


	int buildUp = rand() % 2;
	int height = 0;  // the running total for height on the current node so far.
	

	while ((buildUp == 1) && (height != (LEVEL - 1)))  // Now we build up the skip list.
	{
		SListNode<Object> *tNode = currentNode; // This is where we start traversing from to build up. tnode means transverse node.
		SListNode<Object> *start = currentNode; // This will always just be a reference to where we started.

		do
		{
			tNode = tNode->prev;
		} while (tNode->prev != NULL && tNode->up == NULL); // Make sure that there is something there to insert on.
		tNode = tNode->up; // We now point to where we are going to insert.

		SListNode<Object> *nextNode = new SListNode<Object>;  // This will be the node that will be inserted above.
		nextNode->item = obj; // This chunk of code from this line and below do all the necessary pointer connections so nothing is lost.
		nextNode->down = start;
		start->up = nextNode;
		nextNode->prev = tNode;
		nextNode->next = tNode->next;
		tNode->next->prev = nextNode;
		tNode->next = nextNode;

		currentNode = currentNode->up;
		buildUp = rand() % 2;  //  Roll again to see if to build up.
		height++;  // Increment the height

	}
	
}

template<class Object>
bool SList<Object>::find(const Object &obj) {
	// p oints to the level-0 item close to a given object
	SListNode<Object> *p = searchPointer(obj);

	return (p->next != NULL && p->item == obj);     // true if obj was found
}

template<class Object>
SListNode<Object> *SList<Object>::searchPointer(const Object &obj) {
	SListNode<Object> *p = header[LEVEL - 1];     // start from the top left
	while (p->down != NULL) {                   // toward level 0
		p = p->down;                                // shift down once
		cost++;

		if (p->prev == NULL) {                    // at the left most item
			if (p->next->next == NULL)              // no intermediate items  WHY NEXT NEXT
				continue;
			else {                                    // some intermadiate items
				if (p->next->item <= obj)             // if 1st item <= obj
					p = p->next;                          // shift right to item 1
				cost++;
			}
		}

		while (p->next->next != NULL && p->next->item <= obj) {
			// shift right through intermediate items as far as the item value <= obj
			p = p->next;
			cost++;
		}
	}

	// now reached the bottom. shift right once if the current item < obj
	if (p->prev == NULL || p->item < obj) {
		p = p->next;
		cost++;
	}
	return p; // return the pointer to an item >= a given object.
}

template<class Object>
void SList<Object>::remove(const Object &obj) {
	// p points to the level-0 item to delete
	SListNode<Object> *p = searchPointer(obj);

	// validate if p is not the left most or right most and exactly contains the
	// item to delete
	if (p->prev == NULL || p->next == NULL || p->item != obj)
		return;

	// Implement the rest by yourself /////////////////////////////////////////
	do
	{
		p->next->prev = p->prev; // The node in front of deleted has it's previous point to the node behind deleted.
		p->prev->next = p->next; // The node in behind deleted has it's next point to the node in front of deleted.
		p = p->up; // Set p to the above line.
		delete p->down; // Delete that previous node.
	} while (p->up != NULL);  // Make sure there's actually something there.
	

}

template<class Object>
const SList<Object> &SList<Object>::operator=(const SList &rhs) {
	if (this != &rhs) { // avoid self-assignment
		clear();           // deallocate old items

		int index;
		SListNode<Object> *rnode;
		for (index = 0, rnode = rhs.header[0]->next; rnode->next != NULL;
			rnode = rnode->next, ++index)
			insert(rnode->item);

		cost = rhs.cost;
	}
	return *this;
}

template<class Object>
int SList<Object>::getCost() const {
	return cost;
}

template<class Object>
void SList<Object>::show() const {
	cout << "contents:" << endl;
	for (SListNode<Object> *col = header[0]; col != NULL; col = col->next) {
		SListNode<Object> *row = col;
		for (int level = 0; row != NULL && level < LEVEL; level++) {
			if (row->prev == NULL)
				cout << "-inf\t";
			else if (row->next == NULL)
				cout << "+inf\t";
			else
				cout << row->item << "\t";
			row = row->up;
		}
		cout << endl;
	}
}

