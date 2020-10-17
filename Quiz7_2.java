package lib;
import java.util.Scanner;
import java.util.Vector;
import java.util.HashMap;
import java.util.Set;
import java.util.Iterator;

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
		HashMap<String, String> map = new HashMap<>();
		Vector<Nation> n = new Vector<Nation>();
		
		do {
			System.out.println("**** ���� ���߱� ������ �����մϴ�. ****");
			System.out.println("�Է�: 1, ����: 2, ����: 3 >>");
			choice = scanner.nextInt();
			switch(choice) {
			case 1:
				System.out.println("���� " + map.size() + "�� ����� ������ �ԷµǾ� �ֽ��ϴ�.");
				for(int i = map.size();   ; i++) {
					System.out.println("����� ���� �Է�"+ (i+1) + ">>");
					String country = scanner.next();
					if(country.equals("�׸�")) break;
					if(map.containsKey(country)) {
						System.out.println(country+ "�� �̹� �ֽ��ϴ�!");
						i--;
					}
					String capital = scanner.next();
					map.put(country, capital);
				    
						
				}
				break;
			case 2:
				String answer;
				Set<String> keys = map.keySet();
				Iterator<String> it = keys.iterator();
				
				while(it.hasNext()) {
					String key = it.next();
					if(map.isEmpty()) {
						System.out.println("�Է��� ���� �����ϴ�.");
						break;
					}
					System.out.println(key + " �� ������?");
					answer = scanner.next();
					if(answer.equals("�׸�")) break;
					
					if(answer.equals(map.get(key))) 
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
