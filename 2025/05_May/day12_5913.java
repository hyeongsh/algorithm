// 문제: 준규와 사과
// 번호: 5913번
// 난이도: 골드4

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class day12_5913 {
	private static class Pair {
		public int a;
		public int b;

		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}

		public boolean equal(Pair other) {
			return (this.a == other.a && this.b == other.b);
		}
	}

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int K;
    static int[][] ground = new int[6][6];
    static int count = 0;
    static int[] da = {0, 0, 1, -1};
    static int[] db = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        input();
		findAnswer();
        bw.flush();
        bw.close();
        br.close();
    }

    private static void input() throws IOException {
        K = Integer.parseInt(br.readLine());
        for (int i = 0; i < K; i++) {
            String[] pos = br.readLine().split(" ");
			ground[Integer.parseInt(pos[0])][Integer.parseInt(pos[1])] = 1;
        }
    }

	private static void findAnswer() throws IOException {
		ground[1][1] = 1;
		dfs(new Pair(1, 1), 24 - K);
		bw.write(count + "\n");
	}

	private static void dfs(Pair p, int leave) {
		// System.out.println(p.a + " " + p.b + " / " + q.a + " " + q.b + " / leave: " + leave);
		if (p.a == 5 && p.b == 5 && leave == 0) {
			count++;
			return ;
		}
		for (int i = 0; i < 4; i++) {
			p.a += da[i];
			p.b += db[i];
			if (p.a >= 1 && p.a <= 5 && p.b >= 1 && p.b <= 5 && ground[p.a][p.b] == 0) {
				ground[p.a][p.b] = 1;
				dfs(p, leave - 1);
				ground[p.a][p.b] = 0;
			}
			p.a -= da[i];
			p.b -= db[i];
		}
	}
}
