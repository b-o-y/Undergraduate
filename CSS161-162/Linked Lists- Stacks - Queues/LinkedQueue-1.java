/*
 * DataStructures Homework
 * CSS 162
 * Travis Henderson
 * 
 * This is a linked queue class.  It stores
 * data where ever in ram, rather than in
 * an array through java.  The nodes are 
 * what maintain the order, as they are just
 * pointers to the objects stored in the list.
 * 
 * Works like a queue, first in first out.
 * This class inherits from LinkedList
 * 
 * udemy
 */
public class LinkedQueue extends LinkedList {
	/*
	 * enqueue adds an object to the end of the
	 * list always, starting from the zero index.
	 */
	public void enqueue(Object next) {
		super.insert(next, super.size());
	}
	
	/*
	 * This overrides insert so that it calls
	 * enqueue. No funny business.
	 */
	@Override
	public void insert(Object next, int index) {
		enqueue(next);
	}
	
	/*
	 * Dequeue will remove the first thing
	 * that was added to the queue. In this
	 * case that will always be zero, because
	 * we always add objects after one another
	 * starting 0, 1, 2, etc.
	 */
	public Object dequeue() {
		return super.remove(0);
	}
	
	/*
	 * This overrides remove so that it calls
	 * dequeue. No funny business.
	 */
	@Override
	public Object remove(int index) {
		return dequeue();
	}
	
}
