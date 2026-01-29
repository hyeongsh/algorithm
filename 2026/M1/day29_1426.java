package M1;

import java.io.*;
import java.util.*;

public class day29_1426 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        String[] strs = new String[N];
        for (int i = 0; i < N; i++) {
            strs[i] = br.readLine();
        }
        Arrays.sort(strs);

        int answer = 0;
        for (int i = 0; i < M; i++) {
            String str = br.readLine();
            int start = 0;
            int end = N - 1;
            while (start <= end) {
                int mid = (start + end) / 2;
                if (strs[mid].startsWith(str)) {
                    answer++;
                    break ;
                } else if (strs[mid].compareTo(str) < 0) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        bw.write(answer + "\n");

        bw.flush();
        bw.close();
        br.close();
    }
}