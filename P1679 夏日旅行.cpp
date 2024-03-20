//////#include<algorithm>
//////#include<iostream>
//////#include<vector>
//////#include <map>
//////using namespace std;
//////class Dot {
//////
//////public:
//////	int x, y, flag;
//////	Dot(int x, int y, int h) {
//////		this->x = x;
//////		this->y = y;
//////		this->flag = h;
//////	}
//////};
//////int dx[] = { 1, -1, 0, 0 };
//////int dy[] = { 0, 0, 1, -1 };
//////int find_height(int x, int y, vector<Dot> dots) {
//////	for (int i = 0; i < dots.size(); i++) {
//////		if (dots[i].x == x && dots[i].y == y) {
//////			return dots[i].flag;
//////		}
//////	}
//////}
//////
//////
//////
//////
//////
//////int find_min_path( int origne[], int dest[], int N, int M, vector<Dot> dots) {
//////	int x, y, length=0;
//////	x = origne[0];
//////	y = origne[1];
//////
//////	if (x == dest[0]&& y == dest[1]) {
//////		return length;
//////	}
//////	else {
//////	
//////	}
//////}
//////
//////int main() {
//////	
//////	int N, M;
//////	cin >> N >> M;
//////	vector<Dot> dots;
//////	for (int i = 1; i <= N; i++) {
//////		for (int j = 1; j <= M; j++) {			
//////			int h;
//////			cin >> h;
//////			Dot dot(i,j,h );
//////			dots.push_back(dot);
//////		}
//////	}
//////	int origne[2], dest[2];
//////	cin >> origne[0] >> origne[1] >> dest[0] >> dest[1];
//////	int length = find_min_path(origne, dest, N, M, dots);
//////	printf("%d", length);
//////
//////}
////#include<algorithm>
////#include<iostream>
////#include<vector>
////#include <map>
////
////using namespace std;
////class Node {
////public:
////	int x,y,flag,block;
////	Node(int x, int y, int block,int flag=0) {
////		this->x = x;
////		this->y = y;
////		this->block = block;
////		this->flag = flag;
////		
////	}
////	Node operator+(Node const & x1) {
////		Node node= Node(this->x+x1.x,this->y+x1.y,this->block);
////		return node;
////	}
////	bool operator==(Node const& x1) {
////		return this->x == x1.x && this->y == x1.y;
////	}
////};
////bool is_valid(int x, int y, int N, int M) {
////	return x >= 1 && x <= N && y >= 1 && y <= M;
////}
////bool has_block(int x, int y, vector <Node> nodes) {
////	for (const auto& node : nodes) {
////		if (node.block == 1) {
////			return true;
////		}
////		else
////			return false;
////	}
////}
////vector <Node> moves= { Node(1,0,0),Node(-1,0,0),Node(0,1,0),Node(0,-1,0) };
////void add_flag(Node origne, vector <Node> nodes) {
////	for (auto& node : nodes) {
////		if (node == origne) {
////			node.flag = 1;
////		}
////	}
////}
////Node find_Node(Node x, vector <Node> nodes) {
////	for (
////		const auto& node : nodes) {
////		if (x ==node ) {
////			return node;
////		}
////	
////	}
////}
////int get_min_length(Node origne, Node dest, vector <Node> nodes, int N, int M) {
////
////
////	if (origne == dest) {
////		return 0;
////	}
////
////	else {
////
////
////	/*	for (int i = 0; i <= 3; i++) {
////			Node x = origne + moves[i];
////			if (has_block(x.x, x.y, nodes) == false && find_Node(x, nodes).flag != 1) {
////				if (is_valid(x.x, x.y, N, M)) {
////					return get_min_length(origne, dest, nodes, N, M);
////				}
////				add_flag(x, nodes);
////				return 1 + get_min_length(x, dest, nodes, N, M);
////			}
////		}*/
////
////
////
////		/*int length1, length2, length3, length4;
////
////		Node x1 = find_Node(origne+moves[0],nodes);
////
////		if (has_block(x1.x, x1.y, nodes) == false&&x1.flag!=1 ) {
////			if (!is_valid(x1.x, x1.y, N, M)) {
////				return get_min_length(origne, dest, nodes, N, M);
////			}
////			 add_flag(x1,nodes);
////			 length1 = 1 + get_min_length(x1, dest, nodes, N, M);
////		}
////
////		Node x2= find_Node(origne + moves[1], nodes);
////		if (has_block(x2.x, x2.y, nodes) == false && x2.flag != 1) {
////			if (is_valid(x2.x, x2.y, N, M)) {
////				return get_min_length(origne, dest, nodes, N, M);
////			}
////			add_flag(x2, nodes);
////			length2 = 1 + get_min_length(x2, dest, nodes, N, M);
////		}
////
////		Node x3 = find_Node(origne + moves[2], nodes);
////		if (has_block(x3.x, x3.y, nodes) == false && x3.flag != 1) {
////			if (is_valid(x3.x, x3.y, N, M)) {
////				return get_min_length(origne, dest, nodes, N, M);
////			}
////			add_flag(x3, nodes);
////			length3 = 1 + get_min_length(x3, dest, nodes, N, M);
////		}
////
////
////		Node x4 = find_Node(origne + moves[3], nodes);
////
////		if (has_block(x4.x, x4.y, nodes) == false && x4.flag != 1) {
////			if (is_valid(x4.x, x4.y, N, M)) {
////				return get_min_length(origne, dest, nodes, N, M);
////			}
////			add_flag(x4, nodes);
////			length4 = 1 + get_min_length(x4, dest, nodes, N, M);
////		}
////
////		return min(length1, min(length2, min(length3, length4)));
////
////
////	}*/
////	}
////}
////int main() {
////		int N, M;
////	cin >> N >> M;
////	vector <Node> nodes;
////	for (int i = 1; i <= N; i++) {
////		for (int j = 1; j <= M; j++) {			
////			int h;
////			cin >> h;
////		    nodes.push_back(Node(i, j, h));
////		}
////	}
////	int x, y, X, Y;
////	cin >> x >> y >> X >> Y;
////	Node origne(x,y,0), dest(X,Y,0);
////
////
////	int length=get_min_length(origne,dest,nodes,N,M);
////	printf("%d", length);
////}
//
//#include <iostream>
//#include<queue>
//using namespace std;
//int v[100][100];
//class Point {
//public:
//	int x, y;
//	
//	Point(int x, int y) {
//		this->x = x;
//		this->y = y;
//	}
//};
//
//queue<Point> myqueue;
//
//int find_length(int x, int y, int X, int Y, int N, int M) {
//    int move[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//
//  
//    myqueue.push(Point(x, y));
//    v[x][y] = -1; // 标记起点为已访问
//    int length = 0;
//
//    while (!myqueue.empty()) {
//        int size = myqueue.size();  // 获取当前层的节点个数
//        for (int i = 0; i < size; i++) {
//            Point front = myqueue.front();
//            myqueue.pop();
//
//            if (front.x == X && front.y == Y) {
//                return length ;  // 减1是因为最开始的时候长度已经加1了
//            }
//
//            for (int j = 0; j < 4; j++) {
//                int newX = front.x + move[j][0];
//                int newY = front.y + move[j][1];
//
//                if (newX > 0 && newX <= N && newY > 0 && newY <= M && v[newX][newY] == 0) {
//                    myqueue.push(Point(newX, newY));
//                    v[newX][newY] = -1;
//                }
//            }
//        }
//        length++;  // 进入下一层，路径长度加1
//    }
//
//    return -1;  // 无法到达目标点
//}
////int find_length(int x, int y,int X,int Y,int N,int M) {
////	int move[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
////	
////	myqueue.push(Point(x,y));
////	while (!myqueue.empty()) {
////		for (int i = 0; i < myqueue.size(); i++) {
////			Point front = myqueue.front();
////			myqueue.pop();
////
////			if (front.x == X && front.y == Y) {
////				return length;
////			}
////
////			for (int i = 0; i < 4; i++) {
////				int newX = x + move[i][0];
////				int newY = y + move[i][1];
////				if (v[newX][newY] == 0 && newX <= N && newY <= M && newX > 0 && newY > 0) {
////					myqueue.push(Point(newX, newY));
////					v[newX][newY] = -1;
////				}
////			}
////		}
////		length++;
////	}
////	
////}
//
//
//int main() {
//		int N, M;
//	cin >> N >> M;
//	
//	
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= M; j++) {			
//			
//			cin >> v[i][j];
//		    
//		}
//	}
//	int x, y, X, Y;
//	cin >> x >> y >> X >> Y;
//
//
//    int len=find_length(x, y, X, Y, N, M);
//	printf("%d", len);
//
//}