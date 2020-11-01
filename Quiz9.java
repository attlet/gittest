package lib;
import javax.swing.*;
import java.awt.*;


public class MyFrame extends JFrame {
	

	
	public MyFrame() {
		super("open challenge 9");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container contentPane = getContentPane();
		contentPane.setLayout(new BorderLayout());
		
		contentPane.add(new NorthPanel(), BorderLayout.NORTH);
	    contentPane.add(new CenterPanel(), BorderLayout.CENTER);
	
		setSize(300,300);
		setVisible(true);
	}

	public static void main(String[] args) {
		MyFrame frame = new MyFrame();
	}

}

class NorthPanel extends JPanel{
	public NorthPanel() {
		setBackground(Color.LIGHT_GRAY);
		this.add(new JButton("Open"));
        this.add(new JButton("Read"));
        this.add(new JButton("Close"));
	}
}
	
class CenterPanel extends JPanel{
	 CenterPanel(){
	        this.setLayout(null);
	        String text[] = {"Hello", "Java", "Love"};
	        int x;
	        int y;
	        JLabel label;
	        for(int i=0;i<3;i++) {
	            x = (int)(Math.random()*250); 
	            y = (int)(Math.random()*250);
	            label = new JLabel(text[i]);
	            label.setLocation(x, y); 
	            label.setSize(50,10); 
	            this.add(label);
	        }
	 }
}
     

