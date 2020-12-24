package mynewone;
import java.util.Scanner;
public class learn {
	public static void main(String[] arg) {
		// BufferedReader Class for Fast buffer Input
		BufferedReader br = new BufferedReader(
		    new FileReader("input.in"));

		// PrintWriter class prints formatted representations
		// of objects to a text-output stream.
		PrintWriter pw = new PrintWriter(new
		                                 BufferedWriter(new FileWriter("output.in")));

		// Your code goes Here

		pw.flush();
		Scanner sc = new Scanner(System.in);
		String x = sc.nextLine();

		System.out.println("hello world  " + x);
	}

}