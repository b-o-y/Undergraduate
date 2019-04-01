
public class LinkedList {
	/*DataStructures Homework
	 * CSS162
	 * Travis Henderson
	 * 
	 * This is a linked list class.  It stores
	 * data where ever in ram, rather than in
	 * an array through java.  The nodes are 
	 * what maintain the order, as they are just
	 * pointers to the objects stored in the list.
	 * 
	 * You can insert anywhere and remove from anywhere
	 * in the list
	 */

	private Node head = null;

	/*
	 * checking if index is zero, head always
	 * points to zero. lose head, you lose everything.
	 * 
	 * 
	 * Inserts objects into the list, at whatever
	 * index passed in.
	 */
	public void insert(Object next, int index) {
		Node current = head; //This gives current a place to start and traverse through the list.
		Node previous = head;  //This gives previous a place to start and traverse through the list.
		if (index <= this.size()) { //maybe one up.
			if (this.size() == 0) { //This is the condition for if the list is empty.
				head = new Node(next, null);
			} else if (this.size() >= 1) { //This is the condition if there are other elements in the list.
				if (index == 0) {
					head = new Node(next, current);
					/*
					 * but now there is a new head that points to what is being inserted at zero.
					 * when this head is created, it's leash is going to point to current, which was
					 * the previous head. Therefore the order/links of the list is maintained.
					 */
				} else if (index > 0) {
					current = head; 
					int count = 0;
					
					while(count < index) { //This while loop is the actual traversing, and stops at the object right before the one we want to insert at.
						current = current.next; //current is now a leash pointing to where to insert at.
						count++;
					}
					count = 0;
					while(count < index - 1) {
						previous = previous.next; //Previous is now a leash pointing to what comes before where the object is being inserted at.
						count++;
					}
					/*
					 * current is now a leash pointing to where to insert at.
					 * This then allows the new node to be added to the list and have it point to what used to be at the index (which in effect is like
					 * the array list and moving everything to the right of the index by 1.)
					 */
					Node insert = new Node(next, current);
					previous.next = insert; //This connects everything before what is being inserted to the new object.
				}
			} 
		} else {
			//ERROR
			throw new LinkedListException();
		}

	}
	
	/*
	 * removes object at whatever index.
	 */
	public Object remove(int index) {
		Object returned;
		Node current = head; //This gives current a place to start and traverse through the list.
		Node previous = head; //This gives previous a place to start and traverse through the list.
		if (index <= this.size()) { //First check if the index in in bounds.
			if (this.size() == 0) {
				throw new LinkedListException();
			} else if (this.size() >= 1) {
				if (index == 0) { //if we add at zero, then the head is going to change.
					returned = head.data;
					head = head.next; //Now head points to the next object in the list.
					return returned;
				} else if (index >= 0) {
					int count = 0;
					
					while(count < index) { //this traverses through the list to the index we want to return.
						current = current.next; //current is now a leash pointing to where to remove at.
						count++;
					}	
					
					returned = current.data; //what's trying to be returned has been assigned!
					count = 0;
					while(count < index - 1) {
						previous = previous.next; //Previous is now a leash pointing to what comes before where the object is being removed at.
						count++;
					}
					previous.next = current.next; //This completes the chain by pointing the previous to the object after what was removed.
					return returned;
				}
			}
		} else {
			throw new LinkedListException();
			///error
		}
		return -1;
	}
	
	 // returns the size of the list by just counting all the objects till it reaches null.
	public int size() {
		int retVal = 0;
		Node current = head;
		while(current != null ) {
			current = current.next;
			retVal++;
		}
		return retVal;
	}
	
	//returns a string of everything in the list.
	public String toString() {
		String retVal = "";
		Node current = head;
		while(current != null) {//keep adding to retVal until we reach the end/null.|| current.next != null
			retVal += current.data + "\n";
			current = current.next;
		}
		return retVal;
	}
	
	//Searches the list for target and returns the index if it resides in the list
	public int indexOf(Object target) {
		int index = 0;
		Node current = head;
		while(!current.data.equals(target)) {
			current = current.next;
			if (current == null) {  //Couldn't put this in as an && in the while because it would throw nullpointer exception.  Why?
				break;
			}
			index++;
		}
		if (current == null) {
			throw new LinkedListException();//ERROR
		} else {
			return index;
		}
	}
	
	//Tells you if the list is empty.
	public boolean isEmpty() {
		return head == null;
	}


	 // Node class, keeps track of what's in the list.  Makes all the links in the chains, so to speak.
	private class Node {
		private Object data;
		private Node next;


		public Node (Object d, Node n) {
			data = d; //This is the object being stored itself.
			next = n; //Next points to the next object.
		}
	}
	

}
