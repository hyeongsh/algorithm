// 문제: 단어 뒤집기
// 번호: 9093
// 난이도: 브론즈 1

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;

public class day09_9093 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static Stack<Character> st = new Stack<>();

    public static void main(String[] main) throws IOException {
        input();
        bw.close();
        br.close();
    }

    private static void input() throws IOException {
        String line = br.readLine();
        int t = Integer.parseInt(line);
        for (int i = 0; i < t; i++) {
            line = br.readLine();
            findAnswer(line);
        }
    }

    private static void findAnswer(String line) throws IOException {
        int size = line.length();
        for (int i = 0; i < size; i++) {
            if (line.charAt(i) == ' ') {
                while (!st.empty()) {
                    bw.write(st.peek());
                    st.pop();
                }
                bw.write(line.charAt(i));
            } else {
                st.push(line.charAt(i));
            }
        }
        while (!st.empty()) {
            bw.write(st.peek());
            st.pop();
        }
        bw.write('\n');
        bw.flush();
    }
}
