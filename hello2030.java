import java.util.Scanner;




public class hello2030 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("첫번째 원의 중심과 반지름 입력");
	    float x1 = scanner.nextFloat();
	    float y1 = scanner.nextFloat();
	    float r1 = scanner.nextFloat();
	    
	    System.out.print("두번째 원의 중심과 반지름 입력");
	    float x2 = scanner.nextFloat();
	    float y2 = scanner.nextFloat();
	    float r2 = scanner.nextFloat();
	    
	    if(Math.sqrt(Math.pow((x2 - x1), 2) + Math.pow((y2 - y1), 2)) < (r2+r1)) {
	    	System.out.print("두 원은 서로 겹친다.");
	    }
	    else {
	    	System.out.print("두 원은 겹치지 않는다.");
	    }
	    scanner.close();
	
	
	}
}
