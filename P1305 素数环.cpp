//#include <cstdio>
//#include <iostream>
//#include <cstring>
//using namespace std;
//bool isprime[40];//�����ж��Ƿ�Ϊ����
//bool isused[20];//�����ж��Ƿ��ظ�ʹ�á�
//int n;//���ָ���
//int ans[20];//������¼��
//void dfs(int cnt);//dfsѰ�Ҵ𰸡��ݹ鱩��ö��
//int main(void) {
//    //Ԥ������Ϊ����ֻ��0-16��С��Ҫ��������ֱ��ö�ٱ�����
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
//    ans[1] = 1;//��������1��ʼ������ֱ����д��1
//    int i = 1;//����case�ļ���
//    while (cin >> n) {//��������
//        memset(isused, 0, sizeof(isused));//�ж��ظ�������ա���ʼ����
//        printf("Case %d:\n", i++);//�ȴ����ʽ
//        dfs(2);//�ӵڶ�λ��ʼ��������д�𰸡�
//        printf("\n");//�����Ҫ©�ˣ���Ȼ��WA�������ġ�
//    }
//    return 0;
//}
//void dfs(int cnt) {
//    if (cnt == n + 1) {//�ݹ�С���ڡ�
//        for (int i = 1; i <= n; i++) {
//            if (i == n) printf("%d\n", ans[i]);//���治�����ո�
//            else printf("%d ", ans[i]);
//        }
//        return;
//    }
//    else if (cnt == n) {//���һλ�Ƚ����⣬����Ҫ�����жϡ�
//        for (int i = 2; i <= n; i++) {
//            if (!isused[i] && isprime[i + ans[cnt - 1]] && isprime[i + ans[1]]) {//�ж������Ƿ����������
//                isused[i] = 1;//���ʹ�ù�
//                ans[cnt] = i;//��д��
//                dfs(cnt + 1);//����һ����
//                isused[i] = 0;//����
//            }
//        }
//    }
//    else {
//        for (int i = 2; i <= n; i++) {
//            if (!isused[i] && isprime[i + ans[cnt - 1]]) {//�ж������Ƿ����������
//                isused[i] = 1;//���ʹ�ù�
//                ans[cnt] = i;//��д��
//                dfs(cnt + 1);//����һ����
//                isused[i] = 0;//����
//            }
//        }
//    }
//}
