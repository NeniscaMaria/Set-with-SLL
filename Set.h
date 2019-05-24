#pragma once
#include "SLL.h"

typedef int TElem;
class SetIterator;

class Set {
private:

	friend class SetIterator;
	friend class SLL;
	/* representation of Set*/
	SLL* elements;
	int sizeSet;

public:

	//implicit constructor
	Set();

	//adds an element to the  set
	//if the element was added, the operation returns true, otherwise (if the element was already in the set) 
	//it returns false
	bool add(TElem e);

	//removes an element from the set
	//if the element was removed, it returns true, otherwise false
	bool remove(TElem e);

	//checks if an element is in the  set
	bool search(TElem elem) const;

	//returns the number of elements;
	int size() const;

	//checks if the set is empty
	bool isEmpty() const;

	//returns an iterator for the set
	SetIterator iterator() const;

	//destructor
	~Set();

	//returns the difference between the maximum and the minimum element(assume integere values)
	//if the set is empty, the rage is -1
	int getRange() const;

};











