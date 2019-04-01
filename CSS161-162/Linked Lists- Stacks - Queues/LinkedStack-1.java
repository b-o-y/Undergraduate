/*
 * DataStructures Homework
 * CSS 162
 * Travis Henderson
 * 
 * This is a linked list class.  It stores
 * data where ever in ram, rather than in
 * an array through java.  The nodes are 
 * what maintain the order, as they are just
 * pointers to the objects stored in the list.
 * 
 * Works like a stack, last in first out.
 * This class inherits from LinkedList
 * 
 */
public class LinkedStack extends LinkedList {

	/*
	 * Push something onto the stack, it really isn't
	 * that much different than how an object is added to linkedlist,
	 * so just inherit and use super! Everything is always
	 * inserted at zero, so everything is PUSHED back.
	 */
	public void push(Object next) {
		super.insert(next, 0);
	}

	/*
	 * Pop just needs to return whatever was pushed in last.
	 * With the way this program works, that's always index 0.
	 * 
	 * And head is kept track of in the linked list, so nothing
	 * needs to be done here.	 * 
	 */

	/*
	 * This overrides insert so that it calls
	 * push. No funny business.
	 */
	@Override
	public void insert(Object next, int index) {
		push(next);
	}

	public Object pop() {
		return super.remove(0);
	}

	/*
	 * This overrides remove so that it calls
	 * pop. No funny business.
	 */
	@Override
	public Object remove(int index) {
		return pop();
	}
}
