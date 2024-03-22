//#include <iostream>
//#include <vector>
//#include <thread>
//#include <mutex>
//
//using namespace std;
//
//int k = 0; // 初始化为0，因为初始时没有放置皇后
//mutex mtx; // 互斥锁，用于保护全局变量 k
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
//
//// 递归搜索所有可能的解
//void find_loc(vector<vector<int>>& board, int row, int N) {
//    if (row == N) { // 找到了一个解
//        mtx.lock(); // 加锁
//        k++;
//        mtx.unlock(); // 解锁
//        return;
//    }
//    // 尝试在当前行的每个位置放置皇后
//    for (int col = 0; col < N; col++) {
//        if (isSafe(board, row, col, N) && board[row][col] == 0) {
//            board[row][col] = 2; // 放置皇后
//            find_loc(board, row + 1, N); // 递归搜索下一行
//            //board[row][col] = 0; // 回溯，尝试其他位置
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
//
//    // 创建多个线程进行并行搜索
//    vector<thread> threads;
//    for (int i = 0; i < N; i++) {
//        threads.push_back(thread(find_loc, ref(board), i, N));
//    }
//    
//    // 等待所有线程结束
//    for (auto& t : threads) {
//        t.join();
//    }
//
//    cout << "Number of queens placed: " << k << endl;
//    return 0;
//}
