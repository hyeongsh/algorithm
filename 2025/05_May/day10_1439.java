// 문제: 뒤집기
// 번호: 1439번
// 난이도: 실버5

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class day10_1439 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        findAnswer();

        bw.flush();
        bw.close();
        br.close();
    }

    static void findAnswer() throws IOException {
        int zero = 0;
        int one = 0;

        String str = br.readLine();
        int flag = -1;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '0' && flag != 0) {
                flag = 0;
                zero++;
            } else if (str.charAt(i) == '1' && flag != 1) {
                flag = 1;
                one++;
            }
        }
        bw.write(Math.min(zero, one) + "\n");
    }
}
