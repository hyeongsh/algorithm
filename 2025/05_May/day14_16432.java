// 문제: 떡장수와 호랑이
// 번호: 16432번
// 난이도: 골드 4

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class day14_16432 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N;
    static int[][] arr = new int[1001][10];
    static int[][] vis = new int[1001][10];

    public static void main(String[] args) throws IOException {
        input();
		findAnswer();
        bw.flush();
        bw.close();
        br.close();
    }

    private static void input() throws IOException {
        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            String[] str = br.readLine().split(" ");
            for (int j = 0; j < str.length; j++) {
                arr[i][j] = Integer.parseInt(str[j]);
            }
        }
    }

	private static void findAnswer() throws IOException {
        int[] cakes = new int[N];
        for (int i = 1; i <= arr[0][0]; i++) {
            cakes[0] = arr[0][i];
            if (dfs(cakes, 1) == 1) {
                return ;
            }
        }
        bw.write("-1\n");
	}

    private static int dfs(int[] cakes, int cur) throws IOException {
        if (cur == N) {
            for (int cake : cakes) {
                bw.write(cake + "\n");
            }
            return 1;
        }
        for (int i = 1; i <= arr[cur][0]; i++) {
            if (cakes[cur - 1] != arr[cur][i] && vis[cur][i] == 0) {
                vis[cur][i] = 1;
                cakes[cur] = arr[cur][i];
                if (dfs(cakes, cur + 1) == 1) {
                    return 1;
                }
            }
        }
        return 0;
    }
}
