// 문제: 1
// 번호: 4375
// 난이도: 실버 3

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class day02_4375 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        input();
        bw.flush();
        bw.close();
        br.close();
    }

    private static void input() throws IOException {
		String line = br.readLine();
		while (line != null) {
			int n = Integer.parseInt(line);
			findAnswer(n);
			line = br.readLine();
		}
    }

	private static void findAnswer(int n) throws IOException {
		long mul = 1;
		for (int i = 1; i <= n; i++) {
			if (mul % n == 0) {
				bw.write(i + "\n");
				break ;
			}
			mul = (mul * 10 + 1) % n;
		}
	}
}

