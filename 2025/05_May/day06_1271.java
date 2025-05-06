import java.util.Scanner;
import java.math.BigInteger;

public class day06_1271 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		BigInteger total = in.nextBigInteger();
		BigInteger people = in.nextBigInteger();
		System.out.println(total.divide(people));
		System.out.println(total.remainder(people));
		in.close();
	}
}