import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class day07_24416 {
	private static int recurTime = 0;
	private static int dpTime = 0;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		fib(n);
		fibonacci(n);
		bw.write(recurTime + " " + dpTime + "\n");
		bw.flush();
		bw.close();
		br.close();
	}

	private static int fib(int n) {
		if (n == 1 || n == 2) {
			recurTime++;
			return 1;
		} else {
			return (fib(n - 1) + fib(n - 2));
		}
	}
	
	private static int fibonacci(int n) {
		int[] f = new int[41];
		f[1] = 1;
		f[2] = 1;
		for (int i = 3; i <= n; i++) {
			dpTime++;
			f[i] = f[i - 1] + f[i - 2];
		}
		return f[n];
	}
}
