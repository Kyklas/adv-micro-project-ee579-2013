
public class Main {
	
	public static void main(String [ ] args){
		
	
		test1();
		
	}
	
	public static void test2(){
		

		Algorithms al = new Algorithms();
		
		
		for(float a = 0;a<=121; a++ ){

			al.left(a);
		}
	}
		
		
		public static void test1(){
			
		
		
		Algorithms al = new Algorithms();
		
		System.err.println("---Go Left---");
		
		delay();
		
		for(int i = 0 ;i < 121; i++){
			if(i == 60){
			System.err.println("-------- Halfway-----------");
			System.out.println(i + ": " + al.left(i));
		}
		else{
			System.out.println(i + ": " + al.left(i));
		}
		}
		
		delay();
		
		System.err.println("---Go Right---");
		
		delay();
		for(int j =134; j< 256; j++){
			if(j == 194){
				System.err.println("-------- Halfway-----------");
				System.out.println(j + ": " + al.right(j));
			}
			else{
				System.out.println(j + ": " + al.right(j));	
			}
			
			
		}
		
		
	}
	
	
	
	public static void delay(){
		
		try 
		{
		Thread.sleep(1000); // do nothing for 1000 miliseconds (1 second)
		} 
		catch(InterruptedException e)
		{
		e.printStackTrace();
		}
	}

	
	

}
