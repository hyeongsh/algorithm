// Plane (8370) - 브론즈 5

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class day23_8370 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine());
		int bRow = Integer.parseInt(st.nextToken());
		int bCol = Integer.parseInt(st.nextToken());
		int eRow = Integer.parseInt(st.nextToken());
		int eCol = Integer.parseInt(st.nextToken());

		bw.write(bRow * bCol + eRow * eCol + "\n");
		bw.flush();
	}
}