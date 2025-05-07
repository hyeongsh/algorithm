import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class day07_2683 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			int[] arr = new int[10];
			String[] str = br.readLine().split(" ");
			for (int i = 0; i < 10; i++) {
				arr[i] = Integer.parseInt(str[i]);
			}
			Arrays.sort(arr);
			bw.write(arr[7] + "\n");
		}

		bw.flush();
		bw.close();
		br.close();
	}
	
}
