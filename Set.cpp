#pragma once
#include "Set.h"
#include "SetIterator.h"
#include "SLL.h"
#include <iostream>
using namespace std;

//implicit constructor
Set::Set() {
	this->sizeSet = 0;
	this->elements = new SLL;
	//theta(1)
}

//adds an element to the  set
//if the element was added, the operation returns true, otherwise (if the element was already in the set) 
//it returns false
bool Set::add(TElem e) {
	if (this->elements->search(e) != NULL)
		return false;
	this->elements->addToBeginning(e);
	this->sizeSet++;
	return true;
	//O(n)
}

//removes an element from the set
//if the element was removed, it returns true, otherwise false
bool Set::remove(TElem e) {
	if (this->elements->search(e) == NULL)
		return false;
	this->elements->deleteValue(e);
	this->sizeSet--;
	return true;
	//O(n)
}

//checks if an element is in the  set
bool Set::search(TElem elem) const {
	if (this->elements->search(elem) != NULL)
		return true;
	return false;
}

//returns the number of elements;
int Set::size() const {
	return this->sizeSet;
	//theta(1)
}

//checks if the set is empty
bool Set::isEmpty() const {
	return this->sizeSet == 0;
	//theta(1);
}

//returns an iterator for the set
SetIterator Set::iterator() const {
	return SetIterator(*this);
	//theta(1)
}

//destructor
Set::~Set() {
	SetIterator it = this->iterator();
	while (it.valid()) {
		this->elements->deleteValue(it.getCurrent());
		it.next();
	}
	delete this->elements;
	//Theta(n)
}

int Set::getRange() const {
	if (this->sizeSet == 0)
		return -1;
	TElem minimum = INT_MAX, maximum = INT_MIN;
	for (int i = 0; i < this->sizeSet; i++)
		if (this->elements->getElement(i)->information < minimum)
			minimum = this->elements->getElement(i)->information;
		else
			if (this->elements->getElement(i)->information >maximum)
				maximum = this->elements->getElement(i)->information;
	return maximum - minimum;
	//BC-theta(1)
	//WC-theta(n)
	//AC-theta(n)
	//O(n)
}
