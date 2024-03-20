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
//int k = 0; // 初始化为0，因为初始时没有放置皇后
//
//// 检查当前位置是否可以放置皇后
//bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
//
//    // 检查同一列是否有皇后
//    for (int i = 0; i < row; i++) {
//        if (board[i][col] == 2) {
//            return false;
//        }
//    }
//    // 检查同一行是否有皇后
//    for (int j = 0; j < col; j++) {
//        if (board[row][j] == 2) {
//            return false;
//        }
//    }
//    // 检查左上对角线是否有皇后
//    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
//        if (board[i][j] == 2) {
//            return false;
//        }
//    }
//    //// 检查左下对角线是否有皇后
//    //for (int i = row, j = col; i < N && j < N; i++, j++) {
//    //    if (board[i][j] == 2) {
//    //        return false;
//    //    }
//    //}
//    // 检查右上对角线是否有皇后
//    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
//        if (board[i][j] == 2) {
//            return false;
//        }
//    }
//    //// 检查右下对角线是否有皇后
//    //for (int i = row, j = col; i < N && j >= 0; i++, j--) {
//    //    if (board[i][j] == 2) {
//    //        return false;
//    //    }
//    //}
//    return true;
//}
//
//// 递归搜索所有可能的解
//void find_loc(vector<vector<int>>& board, int row,int N) {
//  
//    if (row == N) { // 找到了一个解
//        k++;
//        return;
//    }
//    // 尝试在当前行的每个位置放置皇后
//    for (int col = 0; col < N; col++) {
//        if (isSafe(board, row, col, N)&&board[row][col] == 0) {
//            board[row][col] = 2; // 放置皇后
//            find_loc(board, row + 1,N); // 递归搜索下一行
//            board[row][col] = 0; // 回溯，尝试其他位置
//        }
//    }
//}
//
//int main() {
//    int N;
//    cin >> N;
//    vector<vector<int>> board(N, vector<int>(N, 0)); // 创建一个动态二维数组
//    // 输入矩阵
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            cin >> board[i][j];
//        }
//    }
//    find_loc(board, 0,N); // 从第一行开始搜索
//    cout << k << endl;
//    return 0;
//}
