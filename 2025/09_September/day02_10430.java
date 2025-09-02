// 문제: 나머지
// 번호: 10430
// 난이도: 브론즈 5

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class day02_10430 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static String line;

    public static void main(String[] args) throws IOException {
        input();
		findAnswer();
        bw.flush();
        bw.close();
        br.close();
    }

    private static void input() throws IOException {
        line = br.readLine();
    }

	private static void findAnswer() throws IOException {
		StringTokenizer st = new StringTokenizer(line);
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		bw.write(((a + b) % c) + "\n");
		bw.write((((a % c) + (b % c)) % c) + "\n");
		bw.write(((a * b) % c) + "\n");
		bw.write((((a % c) * (b % c)) % c) + "\n");
	}
}

