//////#include<iostream>
//////#define MAXNUM 1000
//////using namespace std;
//////int loc = -1;
//////int k = 1;
//////int find_loc(int v[MAXNUM][MAXNUM], int x, int y, int N) {
//////	if (x == N || y == N) return;
//////	
//////	for (int i = x; i < N; i++) {
//////		for (int j = y; j < N; j++) {
//////			if (v[i][j] == 0) {
//////				v[i][j] = 2;
//////				k++;
//////				for (int t = j+1; t <= N; t++) {
//////					v[i][t] = 1;
//////				}
//////				for (int t = i+1; t <= N; t++) {
//////					v[t][j] = 1;
//////				}
//////				int tempx = i, tempy = j;
//////				while (tempx < N && tempy < N) {
//////					v[tempx++][tempy--] = 1;
//////
//////				}
//////				int tempx = i, tempy = j;
//////				while (tempx < N && tempy < N) {
//////					v[tempx++][tempy++] = 1;
//////
//////				}
//////				int tempx = i, tempy = j;
//////				while (tempx < N && tempy < N) {
//////					v[tempx--][tempy++] = 1;
//////				}
//////				int tempx = i, tempy = j;
//////				while (tempx < N && tempy < N) {
//////					v[tempx--][tempy--] = 1;
//////
//////				}
//////				find_loc(v, x + 1, y + 1, N);
//////			}
//////			else {
//////				continue;
//////			}
//////		}
//////	}
//////}
//////int main() {
//////	int v[MAXNUM][MAXNUM] = { 0 };
//////	int N;
//////	cin >> N;
//////	for (int i = 0; i < N; i++) {
//////		for (int j = 0; j < N; j++) {
//////			cin >> v[i][j];
//////		}
//////	}
//////	find_loc(v, 0, 0, N);
//////}
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int k = 0; // ��ʼ��Ϊ0����Ϊ��ʼʱû�з��ûʺ�
//
//// ��鵱ǰλ���Ƿ���Է��ûʺ�
//bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
//
//    // ���ͬһ���Ƿ��лʺ�
//    for (int i = 0; i < row; i++) {
//        if (board[i][col] == 2) {
//            return false;
//        }
//    }
//    // ���ͬһ���Ƿ��лʺ�
//    for (int j = 0; j < col; j++) {
//        if (board[row][j] == 2) {
//            return false;
//        }
//    }
//    // ������϶Խ����Ƿ��лʺ�
//    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
//        if (board[i][j] == 2) {
//            return false;
//        }
//    }
//    //// ������¶Խ����Ƿ��лʺ�
//    //for (int i = row, j = col; i < N && j < N; i++, j++) {
//    //    if (board[i][j] == 2) {
//    //        return false;
//    //    }
//    //}
//    // ������϶Խ����Ƿ��лʺ�
//    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
//        if (board[i][j] == 2) {
//            return false;
//        }
//    }
//    //// ������¶Խ����Ƿ��лʺ�
//    //for (int i = row, j = col; i < N && j >= 0; i++, j--) {
//    //    if (board[i][j] == 2) {
//    //        return false;
//    //    }
//    //}
//    return true;
//}
//
//// �ݹ��������п��ܵĽ�
//void find_loc(vector<vector<int>>& board, int row,int N) {
//  
//    if (row == N) { // �ҵ���һ����
//        k++;
//        return;
//    }
//    // �����ڵ�ǰ�е�ÿ��λ�÷��ûʺ�
//    for (int col = 0; col < N; col++) {
//        if (isSafe(board, row, col, N)&&board[row][col] == 0) {
//            board[row][col] = 2; // ���ûʺ�
//            find_loc(board, row + 1,N); // �ݹ�������һ��
//            board[row][col] = 0; // ���ݣ���������λ��
//        }
//    }
//}
//
//int main() {
//    int N;
//    cin >> N;
//    vector<vector<int>> board(N, vector<int>(N, 0)); // ����һ����̬��ά����
//    // �������
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            cin >> board[i][j];
//        }
//    }
//    find_loc(board, 0,N); // �ӵ�һ�п�ʼ����
//    cout << k << endl;
//    return 0;
//}
