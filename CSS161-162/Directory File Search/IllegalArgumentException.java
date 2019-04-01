public class IllegalArgumentException extends RuntimeException
{
    IllegalArgumentException()
    {
	super("ERROR: Illegal directory name.");
    }

    IllegalArgumentException(String msg)
    {
	super(msg);
    }
}
