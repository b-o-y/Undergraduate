/*
 * DataStructures Homework
 * CSS 162
 * Travis Henderson
 * This is a driver for this homework.
 * I don't really no what else to add
 * as comments for this.
 * 
 * For overriding indexOf(), im not quite sure
 * what you're expecting to be returned. it works
 * for all of my classes, but im not sure if b
 * was pushed in and then two more elements are pushed
 * in are you expecting a zero or two back? it makes
 * sense to me that two would come back, but like
 * i said im not quite sure what is expected from
 * indexof for a stack.
 * 
 */
public class LinkedDriver {
	public static void main(String[] args) {
		
		
		//LINKED LIST STUFF
		LinkedList one = new LinkedList();
		
		one.insert('a', 0);
		System.out.println("what's in one: " + one.toString());
		//one.insert('b', 5); //Throws an error.
		one.insert('b', 0);
		System.out.println("what's in one: " + one.toString());
		one.insert('c', 1);
		System.out.println("Where is a " + one.indexOf('a'));
		one.insert('d', 2);
		one.insert(3, 3);
		System.out.println("index of... " + one.indexOf('c'));
		System.out.println("what's in one: " + one.toString());
		one.insert('X', 2);
		System.out.println("what's in one: " + one.toString());
		one.remove(0);
		one.remove(0);
		one.remove(3);
		System.out.println("what's in one: " + one.toString());
		//System.out.println("index of... " + one.indexOf('c')); //Throws an error.
		one.remove(0);
		//one.remove(45); //Throws an error
		one.remove(0);
		one.remove(0);
		//one.remove(0); //Throws an error.
		 
		
		/*
		//LinkedStack STUFF
		LinkedStack two = new LinkedStack();
		two.push('b');
		two.push('o');
		two.insert('t', 10);
		System.out.println(two.isEmpty());
		System.out.println("Where is b " + two.indexOf('b'));
		System.out.println("what's in two: " + two.toString());
		System.out.println(two.pop());
		System.out.println("Where is b " + two.indexOf('b'));
		System.out.println(two.remove(11));
		System.out.println(two.pop());
		System.out.println(two.isEmpty());
		//System.out.println(two.pop()); //pop off of an empty, throws an error
		 */
		
		/*
		//LinkedQueueStuff
		LinkedQueue three = new LinkedQueue();
		three.enqueue('a');
		three.insert('b', 55);
		three.enqueue('c');
		System.out.println(three.isEmpty());
		System.out.println("Where is b? " +three.indexOf('b'));
		System.out.println("what's in three? " + three.toString());
		System.out.println("three dequeue:");
		System.out.println(three.dequeue());
		System.out.println(three.remove(65));
		System.out.println(three.dequeue());
		System.out.println(three.isEmpty());
		//System.out.println(three.dequeue()); //throws an error
		 */
		
		
	}
}
