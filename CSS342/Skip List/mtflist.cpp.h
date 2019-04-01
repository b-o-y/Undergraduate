template<class Object>
int MtfList<Object>::find(const Object &obj) {
	DListNode<Object> *top = DList<Object>::header->next;
	DListNode<Object> *found = top;

	for (; found != NULL && found->item != obj; found = found->next)
		++DList<Object>::cost;

	if (found == NULL)
		return -1; // not found

	if (found == top)
		return 0;  // no need to move to front     

				   
				   
	this->remove(obj);  // remove found from the current position
	this->insert(obj, 0);  // insert found between header and top

	return 0;

}