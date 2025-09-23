// 문제: 비밀번호 찾기
// 번호: 17219
// 난이도: 실버 4

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.StringTokenizer;

public class day23_17219 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static HashMap<String, String> pwMap = new HashMap<>();
    static int n, m;

    public static void main(String[] args) throws IOException {
        input();
		findAnswer();
        bw.flush();
        bw.close();
        br.close();
    }

    private static void input() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            pwMap.put(st.nextToken(), st.nextToken());
        }
    }

	private static void findAnswer() throws IOException {
        for (int i = 0; i < m; i++) {
            String url = br.readLine();
            bw.write(pwMap.get(url));
            bw.write("\n");
        }
	}
}

