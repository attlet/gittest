import java.util.Scanner;




public class hello2030 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("ù��° ���� �߽ɰ� ������ �Է�");
	    float x1 = scanner.nextFloat();
	    float y1 = scanner.nextFloat();
	    float r1 = scanner.nextFloat();
	    
	    System.out.print("�ι�° ���� �߽ɰ� ������ �Է�");
	    float x2 = scanner.nextFloat();
	    float y2 = scanner.nextFloat();
	    float r2 = scanner.nextFloat();
	    
	    if(Math.sqrt(Math.pow((x2 - x1), 2) + Math.pow((y2 - y1), 2)) < (r2+r1)) {
	    	System.out.print("�� ���� ���� ��ģ��.");
	    }
	    else {
	    	System.out.print("�� ���� ��ġ�� �ʴ´�.");
	    }
	    scanner.close();
	
	
	}
}
