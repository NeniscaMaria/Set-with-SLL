#pragma once
#include "SetIterator.h"
#include "Set.h"
#include <iostream>

SetIterator::SetIterator(const Set& c): set(c){
	this->node = this->set.elements->head;
	//theta(1)
}

//sets the iterator to the first element of the container
void SetIterator::first() {
	this->node = this->set.elements->head;
	//theta(1)
}

//moves the iterator to the next element
//throws exception if the iterator is not valid
void SetIterator::next() {
	if (this->valid()) {
		this->node = this->node->nextNode;
	}
	else {
		throw std::invalid_argument("");
	}
	//theta(1)
}
//checks if the iterator is valid
bool SetIterator::valid() const {
	return this->node->nextNode != NULL;
	//theta(1)
}

//returns the value of the current element from the iterator
// throws exception if the iterator is not valid
TElem SetIterator::getCurrent() const {
	if (this->valid()) {
		return this->node->information;
	}
	else {
		throw std::invalid_argument("");
	}
	//theta(1)
}