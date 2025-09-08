// 문제: 스택
// 번호: 10828
// 난이도: 실버 4

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;

public class day08_10828 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static Stack<Integer> st = new Stack<>();

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
            findAnswer(line.split(" "));
        }
        
    }

	private static void findAnswer(String[] command) throws IOException {
        switch (command[0]) {
            case "push":
                st.push(Integer.parseInt(command[1]));
                break ;
            case "pop":
                if (st.empty()) {
                    bw.write("-1\n");
                } else {
                    bw.write(st.peek() + "\n");
                    st.pop();
                }
                break ;
            case "top":
                if (st.empty()) {
                    bw.write("-1\n");
                } else {
                    bw.write(st.peek() + "\n");
                }
                break ;
            case "size":
                bw.write(st.size() + "\n");
                break ;
            case "empty":
                if (st.empty()) {
                    bw.write("1\n");
                } else {
                    bw.write("0\n");
                }
                break ;
        }
	}
}

