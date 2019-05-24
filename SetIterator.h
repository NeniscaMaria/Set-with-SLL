#pragma once
#include "Set.h"

typedef int TElem;
class SetIterator {

	friend class Set;
	friend class SLL;
private:
	SLLNode* node;
	const Set& set;
public:
	SetIterator(const Set& c);
	
	//sets the iterator to the first element of the container
	void first();

	//moves the iterator to the next element
	//throws exception if the iterator is not valid
	void next();

	//checks if the iterator is valid
	bool valid() const;

	//returns the value of the current element from the iterator
	// throws exception if the iterator is not valid
	TElem getCurrent() const;




};


