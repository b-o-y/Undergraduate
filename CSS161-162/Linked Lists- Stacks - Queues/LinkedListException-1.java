/*
 * DataStructures Homework
 * CSS 162
 * Travis Henderson
 * 
 * This is a runtime exception for the linked list class.
 * 
 */
public class LinkedListException extends RuntimeException {
	LinkedListException() {
		super("There was an error.");
	}

	LinkedListException(String msg) {
		super(msg);
		System.exit(0);
	}
}
