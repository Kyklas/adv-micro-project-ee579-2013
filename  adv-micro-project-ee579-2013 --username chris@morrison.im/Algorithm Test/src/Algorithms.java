
public class Algorithms {
	
	
	
	double left(float a){
		  double b;
		  double m;
		  m = -0.0008;
		  b = m* a;
//		  System.out.println(b);
//		  System.out.println();
//		  System.out.println();
		  b = b + 0.1;
//		  System.out.println(b);
		  b = (a * m) + 0.1;  
		  return b;
		}

	
		double right(float a){
		  double b, m;
		  m = 0.0008; 
		  b = (a * m) - 0.1;
		  return b;
		}


}