// 문제: 이친수
// 번호: 2193번
// 난이도: 실버 3

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;

public class day30_2193 {
	static long[] arr = new long[91];

    public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int n = Integer.parseInt(br.readLine());

		arr[1] = 1;
		arr[2] = 1;
		long count = fibo(n);

		bw.write(count + "\n");
		bw.flush();
		bw.close();
		br.close();
	}

	public static long fibo(int n) {
		if (arr[n] != 0) {
			return arr[n];
		}
		arr[n] = fibo(n - 1) + fibo(n - 2);
		return arr[n];
	}
}

// 1 : 1 -> 1
// 2 : 10 -> 1
// 3 : 100 101 -> 2
// 4 : 1000 1001 1010 -> 3
// 5 : 10000 10001 10010 10100 10101 -> 5
// 6 : 100000 100001 100010 100100 100101 101000 101001 101010 -> 8
