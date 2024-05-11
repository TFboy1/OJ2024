///* ��Ŀ����
//Professor Alex will organize students to attend an academic conference.
//
//Alex ���ڽ�Ҫ��֯ѧ���μ�ѧ�����顣
//
//Alex has n excellent students, and he decides to select some of them (possibly none) to attend the conference. They form a group. Some pairs of them are friends.
//
//Alex �� n ���ܺõĵ�ѧ����������ѡһЩ��Ҳ���ܲ�ѡ��������ȥ���ᣬ���������һ��С�飬��Щѧ�����������ѡ�
//
//The friendly value of the group is initially 0. For each couple of friends (x,y), if both of them attend the conference, the friendly value of the group will increase 1, and if only one of them attends the conference, the friendly value of the group will decrease 1. If num students attend the conference, the friendly value of the group will decrease num.
//
//С��� ���Ѱ�ֵ�� ��ʼ�� 0������ÿһ�Ժ����� (x,y)��������Ƕ��μӻ����ˣ����Ѱ�ֵ�� �ͻ����� 1�����һ�Ժ�����ֻ��һ����ȥ�μӻ��飬�Ѱ�ֵ�ͻ���� 1������� num ��ѧ���μ��˻��飬�Ѱ�ֵ����� num ��
//
//Alex wants to manume the group more friendly. Please output the maximum friendly value of the group.
//
//Alex �������С����а�������������Ѱ�ֵ�Ƕ��١�
//
//��������
//The first line of the input gives the number of test cases, T (1��T��10^4). T test cases follow.
//
//T �����ݡ�
//
//For each test case, the first line contains two integers n (1��n��3��10^5) and m (1��m��10^6), where n is the number of students and m is the number of couples of friends.
//
//n ��ѧ����m �����ѡ�
//
//Each of the following m lines contains two integers xi,yi(1��xi,yi��n,xi��yi), representing student xi and student yi are friends. It guaranteed that unordered pairs (xi,yi) are distinct.
//
//m �У� ÿһ���������֣����������������ѡ�
//
//The sum of n in all test cases doesn't exceed 10^6, and the sum of m in all test cases doesn't exceed 2��10^6.
//
//n ���ܺͲ����� 1e6��m ���ܺͲ����� 2e6��
//
//�������
//For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1), and y is the maximum friendly value of the group.
//ÿ�������� "Case #x: y" ����ʽ�����
//
//��������
//
//2
//4 5
//1 2
//1 3
//1 4
//2 3
//3 4
//2 1
//1 2
//�������
//
//Case #1: 1
//Case #2: 0 */
//
//#include <iostream>
//
//using namespace std;
//
//const int MAXN = 3e5 + 10;
//int t, n, m, num, ans;
//int f[MAXN], a[MAXN], b[MAXN];
//
//int getf(int x)
//{
//    if (f[x] == x)
//        return x;
//    return f[x] = getf(f[x]);
//}
//
//int main()
//{
//    cin >> t;
//    num = 0;
//    while (t--)
//    {
//        cin >> n >> m;
//        for (int i = 1; i <= n; i++)
//        {
//            f[i] = i;
//            a[i] = 0;
//            b[i] = 1;
//        }
//        for (int i = 1; i <= m; i++)
//        {
//            int t1, t2;
//            cin >> t1 >> t2;
//            int u = getf(t1);
//            int v = getf(t2);
//            if (u == v)
//                a[u]++;
//            else
//            {
//                f[v] = u;
//                a[u] += a[v] + 1;
//                b[u] += b[v];
//            }
//        }
//        ans = 0;
//        for (int i = 1; i <= n; i++)
//        {
//            if (i == f[i] && a[i] - b[i] > 0)
//                ans += a[i] - b[i];
//        }
//        cout << "Case #" << ++num << ": " << ans << endl;
//    }
//    return 0;
//}