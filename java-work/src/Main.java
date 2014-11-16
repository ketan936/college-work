abstract class upper {
	abstract void doSomething();

	public void help() {
		System.out.println("hello");
	}
}

class lower extends upper
{

	@Override
	void doSomething() {
		// TODO Auto-generated method stub
		
	}
	
}

/**
 * @author castle
 *
 */
public class Main {
	public static void main(String[] args){
		
		lower up = new lower();
		up.help();
		
	}
	
}