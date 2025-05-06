import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class day06_11655 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		for (char c : br.readLine().toCharArray()) {
			bw.write(rot13(c) + "");
		}
		bw.write('\n');
		bw.flush();
		bw.close();
		br.close();
	}

	private static char rot13(int c) {
		if (Character.isUpperCase(c)) {
			c = 'A' + ((c + 13 - 'A') % 26);
		} else if (Character.isLowerCase(c)) {
			c = 'a' + ((c + 13 - 'a') % 26);
		}
		return (char)c;
	}
}