#pragma once
#include "SLL.h"
#include <iostream>
#include <stdexcept>

SLL::SLL() {
	this->head = new SLLNode;
	this->head->nextNode = NULL;
	this->head->information = INT_MAX;
	//theta(1)
}
SLL::SLL(TElem info=0) {
	this->head = new SLLNode;
	this->head->information = info;
	//theta(1)
}

SLL::~SLL() {
	delete this->head;
	//theta(1)
}

SLLNode* SLL::search(TElem element) {
	/*
	This function searches for a given element (information)
	Returns  returns the node which contains elem as info, or NIL
	*/
	SLLNode* current = this->head;
	while (current != NULL and current->information != element) {
		current = current->nextNode;
	}
	return current;
	//O(n)
}

void SLL::addToBeginning(TElem element) {
	SLLNode* current = this->head;
	while (current != NULL and current->information != element) {
		current = current->nextNode;
	}
	if (current != NULL)
		throw std::invalid_argument("");
	SLLNode* newNode = new SLLNode;
	newNode->information = element;
	newNode->nextNode = this->head;
	this->head = newNode;
	//O(1)
}

void SLL::addToEnd(TElem element) {
	SLLNode* current = this->head;
	while (current != NULL and current->information != element) {
		current = current->nextNode;
	}
	if (current != NULL)
		throw std::invalid_argument("");
	SLLNode* lastNode = this->head;
	while (lastNode != NULL) 
		lastNode = lastNode->nextNode;
	SLLNode* newNode = new SLLNode;
	newNode->information = element;
	newNode->nextNode = NULL;
	lastNode->nextNode = newNode;
	//theta(n)
}

void SLL::addToPosition(TElem element, int position) {
	SLLNode* current = this->head;
	while (current != NULL and current->information != element) {
		current = current->nextNode;
	}
	if (current != NULL)
		throw std::invalid_argument("");
	current = this->getElement(position);
	SLLNode* newNode = new SLLNode;
	newNode->information = element;
	newNode->nextNode = current->nextNode;
	current->nextNode = newNode;
	//O(n)
}

void SLL::addAfterValue(TElem element, TElem value) {
	SLLNode* current = this->head;
	while (current != NULL and current->information != element) {
		current = current->nextNode;
	}
	if (current != NULL)
		throw std::invalid_argument("");
	SLLNode* node = this->search(value);
	if (node != NULL) {
		SLLNode* newNode = new SLLNode;
		newNode->information = element;
		newNode->nextNode = node->nextNode;
		node->nextNode = newNode;
	}
	else
		throw std::invalid_argument("");
	//O(n)
}

void SLL::deleteFirst() {
	this->head = this->head->nextNode;
	//theta(1)
}

void SLL::deleteLast(){
	SLLNode* lastNode = this->head;
	SLLNode* previousNode = NULL;
	while (lastNode != NULL) {
		previousNode = lastNode;
		lastNode = lastNode->nextNode;
	}
	previousNode->nextNode = NULL;
	delete lastNode;
	//O(n)
}

void SLL::deleteFromPosition(int position) {
	if (position < 0)
		throw std::invalid_argument("");
	int counter = 0;
	SLLNode* current = this->head;
	SLLNode* previous = NULL;
	while (counter < position - 1 and current != NULL) {
		previous = current;
		current = current->nextNode;
		counter++;
	}
	if (counter != position)
		throw std::invalid_argument("");
	if (current!= NULL and previous == NULL) {
		this->deleteFirst();
	}
	else{
		previous->nextNode = current->nextNode;
		current->nextNode = NULL;
		delete current;
	}
	//O(n)
}

SLLNode* SLL::deleteValue(TElem element) {
	SLLNode* currentNode = this->head;
	SLLNode* previousNode = NULL;
	while (currentNode != NULL and currentNode->information != element) {
		previousNode = currentNode;
		currentNode = currentNode->nextNode;
	}
	if (currentNode != NULL and previousNode == NULL) {
		this->head = this->head->nextNode;
	}
	else {
		if (currentNode != NULL) {
			previousNode->nextNode = currentNode->nextNode;
			currentNode->nextNode = NULL;
			delete currentNode;
		}
		else {
			throw std::invalid_argument("");
		}
	}
	return currentNode;
	//O(n)
}

SLLNode* SLL::getElement(int position) {
	if (position < 0)
		throw std::invalid_argument("");
	if (position == 0) {
		return this->head;
	}
	int counter = 0;
	SLLNode* current = this->head;
	while (counter < position  and current != NULL) {
		current = current->nextNode;
		counter++;
	}
	if (counter != position)
		throw std::invalid_argument("");
	else
		return current;
	//O(n)
}