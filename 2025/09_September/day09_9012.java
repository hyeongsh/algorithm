// 문제: 괄호
// 번호: 9012
// 난이도: 실버 4

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;

public class day09_9012 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static Stack<Character> st = new Stack<>();

    public static void main(String[] args) throws IOException {
        input();
        bw.flush();
        bw.close();
        br.close();
    }

    private static void input() throws IOException {
        String line = br.readLine();
        int n = Integer.parseInt(line);
        for (int i = 0; i < n; i++) {
            line = br.readLine();
            findAnswer(line);
        }
    }

	private static void findAnswer(String line) throws IOException {
        int size = line.length();
        for (int i = 0; i < size; i++) {
            if (line.charAt(i) == '(') {
                st.push('(');
            } else {
                if (st.empty()) {
                    st.push('(');
                    break ;
                }
                st.pop();
            }
        }
        if (st.empty()) {
            bw.write("YES\n");
        } else {
            bw.write("NO\n");
        }
        st.clear();
	}
}

