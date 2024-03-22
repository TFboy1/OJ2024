//#include <iostream>
//#include <vector>
//#include <thread>
//#include <mutex>
//
//using namespace std;
//
//int k = 0; // ��ʼ��Ϊ0����Ϊ��ʼʱû�з��ûʺ�
//mutex mtx; // �����������ڱ���ȫ�ֱ��� k
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
//
//// �ݹ��������п��ܵĽ�
//void find_loc(vector<vector<int>>& board, int row, int N) {
//    if (row == N) { // �ҵ���һ����
//        mtx.lock(); // ����
//        k++;
//        mtx.unlock(); // ����
//        return;
//    }
//    // �����ڵ�ǰ�е�ÿ��λ�÷��ûʺ�
//    for (int col = 0; col < N; col++) {
//        if (isSafe(board, row, col, N) && board[row][col] == 0) {
//            board[row][col] = 2; // ���ûʺ�
//            find_loc(board, row + 1, N); // �ݹ�������һ��
//            //board[row][col] = 0; // ���ݣ���������λ��
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
//
//    // ��������߳̽��в�������
//    vector<thread> threads;
//    for (int i = 0; i < N; i++) {
//        threads.push_back(thread(find_loc, ref(board), i, N));
//    }
//    
//    // �ȴ������߳̽���
//    for (auto& t : threads) {
//        t.join();
//    }
//
//    cout << "Number of queens placed: " << k << endl;
//    return 0;
//}
