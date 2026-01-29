package M1;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String str = br.readLine();
        int answer = 0;
        int start = 0;
        int end = str.length();
        while (start <= end) {
            int mid = (start + end) / 2;
            Set<String> strSet = new HashSet<>();
            for (int i = 0; i < str.length() - mid + 1; i++) {
                String substring = str.substring(i, i + mid);
                if (strSet.contains(substring)) {
                    start = mid + 1;
                    if (answer < mid) {
                        answer = mid;
                    }
                    strSet.clear();
                    break ;
                } else {
                    strSet.add(substring);
                }
            }
            if (!strSet.isEmpty()) {
                end = mid - 1;
            }
        }

        bw.write(answer + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}