#pragma once

typedef int TElem;

typedef struct _SLLNode{
	TElem information;
	_SLLNode* nextNode;
}SLLNode;

class SLL {
	friend class SetIterator;
private:
	SLLNode* head;
	SLLNode* tail;
public:
	SLL(TElem);
	SLL();
	~SLL();
	SLLNode* search(TElem);
	void addToBeginning(TElem);
	void addToEnd(TElem);
	void addToPosition(TElem,int);
	void addAfterValue(TElem, TElem);
	void deleteFirst();
	void deleteLast();
	void deleteFromPosition(int);
	SLLNode* deleteValue(TElem);
	SLLNode* getElement(int);
};