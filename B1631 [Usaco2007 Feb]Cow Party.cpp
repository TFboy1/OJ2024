///*
//��Ŀ����
//���ٵ��ˣ�n ͷţ��Ҫȥ�μ�һ���ڱ��Ϊ x ��ţ��ũ�����е��ɶԣ�ũ��֮���� m ������·��ÿ��·����һ���ĳ��ȡ�
//ÿͷţ�μ����ɶԺ󶼱���ؼң�������ȥ�μ��ɶԻ��ǻؼң�ÿͷţ����ѡ�����·�������� n ͷţ�����·����һ�����أ������һ��·�����ȡ�
//
//�����ʽ
//��һ���������������ֱ��ʾţ������ n����·�� m ���ɶ�ũ����� x��
//
//������ m �У�ÿ���������� u, v, w ��ʾ����һ���� u ͨ�� v �ĳ���Ϊ w �ĵ�·��
//����ȫ���Ĳ��Ե㣬��֤1��x��n��10^3��1��m��10^5 ��1��u,v��n��1��w��10^2����֤���κ�һ�����������ܵ��� x �Ž�㣬�Ҵ� x �������Ե����������нڵ㡣
//
//�����ʽ
//���һ��һ��������ʾ�𰸡�
//
//��������
//4 8 2
//1 2 4
//1 3 2
//1 4 7
//2 1 1
//2 3 5
//3 1 2
//3 4 4
//4 2 3
//
//�������
//10
//
//��ʾ
//����˵��:
//���� 4 ֻ��ţ�μӾۻᣬ�� 8 ��·���ۻ�λ�ڵ� 2 ��ũ��.
//�� 4 ֻ��ţ����ֱ�ӵ��ۻ����ڵ� (���� 3 ʱ��), Ȼ�󷵳�·�߾����� 1 �͵� 3 ��ũ�� (���� 7 ʱ��), �ܹ� 10 ʱ��.
//
//*/
//#include <iostream>
//#include <algorithm>
//
//#define INF 0x3f3f3f3f
//#define MaxN 1024
//
//using namespace std;
//
//int map[MaxN][MaxN], n;
//int way[MaxN], distances[MaxN];
//
//void dijkstra(int x)
//{
//    int visit[MaxN] = { 0 };
//    int min, next = x;
//    for (int i = 1; i <= n; ++i)
//        distances[i] = map[x][i];
//    visit[x] = 1;
//    for (int i = 2; i <= n; ++i)
//    {
//        min = INF;
//        for (int j = 1; j <= n; ++j)
//        {
//            if (!visit[j] && distances[j] < min)
//            {
//                min = distances[j];
//                next = j;
//            }
//        }
//        visit[next] = 1;
//        for (int j = 1; j <= n; ++j)
//        {
//            if (!visit[j] && distances[j] > distances[next] + map[next][j])
//                distances[j] = distances[next] + map[next][j];
//        }
//    }
//}
//
//int main()
//{
//    int m, x;
//    cin >> n >> m >> x;
//    for (int i = 1; i <= n; ++i)
//    {
//        for (int j = 1; j <= n; ++j)
//        {
//            if (i != j)
//                map[i][j] = INF;
//            else
//                map[i][j] = 0;
//        }
//    }
//    int u, v, w;
//    while (m--)
//    {
//        cin >> u >> v >> w;
//        if (w < map[u][v])
//            map[u][v] = w;
//    }
//    dijkstra(x);
//    for (int i = 1; i <= n; ++i)
//        way[i] = distances[i];
//    int ans = 0;
//    for (int i = 1; i <= n; ++i)
//    {
//        for (int j = i + 1; j <= n; ++j)
//        {
//            int temp;
//            temp = map[j][i];
//            map[j][i] = map[i][j];
//            map[i][j] = temp;
//        }
//    }
//    dijkstra(x);
//    for (int i = 1; i <= n; ++i)
//    {
//        if (i != x)
//            ans = max(ans, way[i] + distances[i]);
//    }
//    cout << ans << endl;
//    return 0;
//}