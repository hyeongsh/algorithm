// 문제: 핑거 스냅
// 번호: 17394번
// 난이도: 골드5

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Queue;

public class day11_17394 {
    static class Pair {
        Integer num;
        Integer time;

        public Pair(Integer num, Integer time) {
            this.num = num;
            this.time = time;
        }

        public Integer getNum() {
            return num;
        }

        public Integer getTime() {
            return time;
        }
    }

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int T;
    static int N;
    static int A;
    static int B;
    static int[] primeNum;

    public static void main(String[] args) throws IOException {
        primeNum = new int[1000001];
        for (int i = 2; i < 1000001; i++) {
            if (primeNum[i] == 0) {
                for (int j = i + i; j < 1000001; j += i) {
                    primeNum[j] = 1;
                }
            }
        }
        input();
        bw.flush();
        bw.close();
        br.close();
    }
    
    private static void input() throws IOException {
        T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            String[] str = br.readLine().split(" ");
            N = Integer.parseInt(str[0]);
            A = Integer.parseInt(str[1]);
            B = Integer.parseInt(str[2]);
            findAnswer();
        }
    }

	private static void findAnswer() throws IOException {
        int[] vis = new int[1000001];
        Queue<Pair> que = new ArrayDeque<>();
        que.offer(new Pair(N, 0));
        vis[N] = 1;
        while (!que.isEmpty()) {
            int curNum = que.peek().getNum();
            int curTime = que.peek().getTime();
            que.poll();
            if (primeNum[curNum] == 0 && A <= curNum && B >= curNum) {
                bw.write(curTime + "\n");
                return ;
            } else {
                int nextNum;
                nextNum = curNum / 2;
                if (vis[nextNum] == 0) {
                    vis[nextNum] = 1;
                    que.offer(new Pair(nextNum, curTime + 1));
                }
                nextNum = curNum / 3;
                if (vis[nextNum] == 0) {
                    vis[nextNum] = 1;
                    que.offer(new Pair(nextNum, curTime + 1));
                }
                nextNum = curNum - 1;
                if (nextNum >= 0 && vis[nextNum] == 0) {
                    vis[nextNum] = 1;
                    que.offer(new Pair(nextNum, curTime + 1));
                }
                nextNum = curNum + 1;
                if (nextNum < 1000000 && vis[nextNum] == 0) {
                    vis[nextNum] = 1;
                    que.offer(new Pair(nextNum, curTime + 1));
                }
            }
        }
        bw.write("-1\n");
	}

}

// 우선순위 결정
// -> 소수를 찾느냐?
// -> 나눠가며 찾느냐?
// 9
// 4 3 8 10