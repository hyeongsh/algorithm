// 문제: 사탕게임
// 번호: 3085
// 난이도: 실버2

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.IOException;

public class day25_3085 {
    public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int n = Integer.parseInt(br.readLine());
		Integer[][] board = new Integer[50][50];

		for (int i = 0; i < n; i++) {
			String line = br.readLine();
			for (int j = 0; j < n; j++) {
				if (line.charAt(j) == 'C') {
					board[i][j] = 1;
				} else if (line.charAt(j) == 'P') {
					board[i][j] = 2;
				} else if (line.charAt(j) == 'Z') {
					board[i][j] = 3;
				} else if (line.charAt(j) == 'Y') {
					board[i][j] = 4;
				}
			}
		}

		int max = 0;
		Integer[][] direct = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
		for (int i = 0; i < n ; i++) {
			for (int j = 0; j < n ; j++) {
				for (int k = 0; k < 4; k++) {
					if (i + direct[k][0] >= n || i + direct[k][0] < 0 || j + direct[k][1] >= n || j + direct[k][1] < 0) {
						continue ;
					}
					int tmp = board[i][j];
					board[i][j] = board[i + direct[k][0]][j + direct[k][1]];
					board[i + direct[k][0]][j + direct[k][1]] = tmp;
					int con = checkBoard(board, i, j, n);
					if (max < con) {
						max = con;
					}
					board[i + direct[k][0]][j + direct[k][1]] = board[i][j];
					board[i][j] = tmp;
				}
			}
		}
		bw.write(max + "\n");
		bw.flush();
		br.close();
		bw.close();
	}

	private static int checkBoard(Integer[][] board, int row, int col, int n) {
		int rowSize = 0;
		int colSize = 0;
		for (int i = col; i < n; i++) {
			if (board[row][i] == board[row][col]) {
				rowSize++;
			} else {
				break ;
			}
		}
		for (int i = col - 1; i >= 0; i--) {
			if (board[row][i] == board[row][col]) {
				rowSize++;
			} else {
				break ;
			}
		}
		for (int i = row; i < n; i++) {
			if (board[i][col] == board[row][col]) {
				colSize++;
			} else {
				break ;
			}
		}
		for (int i = row - 1; i >= 0; i--) {
			if (board[i][col] == board[row][col]) {
				colSize++;
			} else {
				break ;
			}
		}
		return Math.max(rowSize, colSize);
	}
}

