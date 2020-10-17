package lib;
import java.util.Scanner;
import java.util.Vector;


class Nation{
	String country, capital;
	
	public Nation(String country, String capital) {
		this.country = country;
		this.capital = capital;
	}
}
public class Quiz7 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int choice;
		Vector<Nation> n = new Vector<Nation>();
		
		do {
			System.out.println("**** ���� ���߱� ������ �����մϴ�. ****");
			System.out.println("�Է�: 1, ����: 2, ����: 3 >>");
			choice = scanner.nextInt();
			switch(choice) {
			case 1:
				System.out.println("���� " + n.size() + "�� ����� ������ �ԷµǾ� �ֽ��ϴ�.");
				for(int i = n.size();   ; i++) {
					System.out.println("����� ���� �Է�"+ (i+1) + ">>");
					String country = scanner.next();
					if(country.equals("�׸�")) break;
					String capital = scanner.next();
					if(n.contains(new Nation(country, capital))) {
						System.out.println(country+ "�� �̹� �ֽ��ϴ�!");
						i--;
					}
					else
						n.add(new Nation(country, capital));
				}
				break;
			case 2:
				String answer;
				while(true) {
					if(n.size() == 0) {
						System.out.println("�Է��� ���� �����ϴ�.");
						break;
					}
					int randomindex = (int)(Math.random()*n.size());
					Nation p = n.get(randomindex);
					System.out.println(p.country + " �� ������?");
					answer = scanner.next();
					if(answer.equals("�׸�")) break;
					
					if(answer.equals(p.capital)) 
						System.out.println("����!!");
					else
						System.out.println("�ƴմϴ�!!");
						
				}
				break;
				
			case 3:
				System.out.print("������ �����մϴ�.");
				break;
			}
		}while(choice != 3);
		
		scanner.close();
		
	}
	
}
