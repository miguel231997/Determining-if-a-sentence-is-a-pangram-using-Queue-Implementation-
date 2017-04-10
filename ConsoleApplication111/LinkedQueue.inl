
// LinkedQueue.inl
// Implementation of the Linked Queue


template <class ItemType>
bool LinkedQueue<ItemType>::dequeue()
{
	bool result = false;
	if (!isEmpty())
	{
		// Queue is not empty; remove front
		Node<ItemType>* nodeToDeletePtr = frontPtr;
		if (frontPtr == backPtr)
		{ // Special case: one node in queue
			frontPtr = nullptr;
			backPtr = nullptr;
		}
		else
			frontPtr = frontPtr->getNext();
		// Return deleted node to system
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;
		result = true;
	} // end if
	return result;
} // end dequeue


template <class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
	// Insert the new node
	if (isEmpty())
		frontPtr = newNodePtr; // The queue was empty
	else
		backPtr->setNext(newNodePtr); // The queue was not empty
	backPtr = newNodePtr; // New node is at back
	return true;
} // end enqueue

template <class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const
{
	bool result = false;
	if (frontPtr == nullptr && backPtr == nullptr)
		result = true;
	return result;

}


template <class ItemType>
ItemType LinkedQueue<ItemType>::peekFront() const throw(PrecondViolatedExcept)
{
	if (isEmpty())
		throw PrecondViolatedExcept("peek() called with empty stack");
	else
		return frontPtr->getItem();
}


template <class ItemType>
LinkedQueue<ItemType>::LinkedQueue()
{
	frontPtr = nullptr;
	backPtr = nullptr;

}



template <class ItemType>
LinkedQueue<ItemType>::~LinkedQueue()
{
	while (frontPtr != nullptr && backPtr != nullptr)
	{
		Node<ItemType> * nodeToDelete = frontPtr;
		frontPtr = frontPtr->getNext();
		nodeToDelete->setNext(nullptr);
		delete nodeToDelete;
		nodeToDelete = nullptr;
	}
	

}
