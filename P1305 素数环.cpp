//#include <cstdio>
//#include <iostream>
//#include <cstring>
//using namespace std;
//bool isprime[40];//用于判断是否为素数
//bool isused[20];//用于判断是否重复使用。
//int n;//数字个数
//int ans[20];//用来记录答案
//void dfs(int cnt);//dfs寻找答案。递归暴力枚举
//int main(void) {
//    //预处理，因为数据只有0-16，小的要死，所以直接枚举暴力。
//    for (int i = 2; i < 40; i++) {
//        bool flag = true;
//        for (int j = 2; j < i; j++) {
//            if (i % j == 0) {
//                flag = false;
//                break;
//            }
//        }
//        if (flag) isprime[i] = true;
//    }
//    ans[1] = 1;//素数环由1开始，所以直接填写答案1
//    int i = 1;//用于case的计数
//    while (cin >> n) {//多组输入
//        memset(isused, 0, sizeof(isused));//判断重复数组清空。初始化。
//        printf("Case %d:\n", i++);//先打出格式
//        dfs(2);//从第二位开始搜索并填写答案。
//        printf("\n");//这个不要漏了，不然会WA。恶心心。
//    }
//    return 0;
//}
//void dfs(int cnt) {
//    if (cnt == n + 1) {//递归小出口。
//        for (int i = 1; i <= n; i++) {
//            if (i == n) printf("%d\n", ans[i]);//后面不能留空格。
//            else printf("%d ", ans[i]);
//        }
//        return;
//    }
//    else if (cnt == n) {//最后一位比较特殊，所以要单独判断。
//        for (int i = 2; i <= n; i++) {
//            if (!isused[i] && isprime[i + ans[cnt - 1]] && isprime[i + ans[1]]) {//判断数字是否符合条件。
//                isused[i] = 1;//标记使用过
//                ans[cnt] = i;//填写答案
//                dfs(cnt + 1);//找下一个数
//                isused[i] = 0;//回溯
//            }
//        }
//    }
//    else {
//        for (int i = 2; i <= n; i++) {
//            if (!isused[i] && isprime[i + ans[cnt - 1]]) {//判断数字是否符合条件。
//                isused[i] = 1;//标记使用过
//                ans[cnt] = i;//填写答案
//                dfs(cnt + 1);//找下一个数
//                isused[i] = 0;//回溯
//            }
//        }
//    }
//}
