//#include<iostream>
//#include<stack>
//#include<string>
//#include<queue>
//using namespace std;
//int main() {
//	stack<string> forward;
//	stack<string> backword;
//	//queue<string> backword;
//	/*deque<string> deque;*/
//	string s;
//	string s1= "http://www.acm.org/";
//	while (cin >> s) {
//		if(s=="QUIT") break;
//		if (s == "VISIT") {	
//			backword.push(s1);
//			cin >> s1;
//			while (!forward.empty()) {
//				forward.pop();  // Çå¿ÕforwardÕ»
//			}
//			cout << s1 << endl;
//		}
//		if (s == "BACK") {			
//	
//			if (!backword.empty()) {
//				forward.push(s1);
//				s1 = backword.top();
//				backword.pop();
//				cout << s1 << endl;
//			}
//			else {
//				cout << "Ignored" << endl;
//				continue;
//			}
//		}
//		if (s == "FORWARD") {
//					
//			if (!forward.empty()) {
//				/*if (forward.empty()) {
//					cout << "Ignored" << endl;
//					continue;
//				}*/	
//				backword.push(s1);	
//				s1 = forward.top();
//				forward.pop();
//			
//				
//				cout << s1 << endl;
//				
//			}
//			else {
//				cout << "Ignored" << endl;
//				continue;
//			}
//		}
//	}
//}
////#include <iostream>
////#include <deque>
////#include <string>
////
////int main() {
////    std::deque<std::string> history;
////    std::string current = "http://www.acm.org/";
////
////    std::string command;
////    while (std::cin >> command && command != "QUIT") {
////        if (command == "BACK") {
////            if (!history.empty()) {
////                std::string previous = history.back();
////                history.push_front(previous);
////                history.pop_back();
////
////                std::cout << previous << std::endl;
////            }
////            else {
////                std::cout << "Ignored" << std::endl;
////            }
////        }
////        else if (command == "FORWARD") {
////            if (!history.empty()) {
////                std::string next = history.front();
////                history.pop_front();
////                std::cout << next << std::endl;
////            }
////            else {
////                std::cout << "Ignored" << std::endl;
////            }
////        }
////        else if (command == "VISIT") {
////            std::string url;
////            std::cin >> url;
////            history.push_back(current);
////            current = url;
////            
////            std::cout << current << std::endl;
////        }
////    }
////
////    return 0;
////}
////#include <iostream>
////#include <stack>
////#include <string>
////using namespace std;
////int main() {
////    std::stack<std::string> backward;
////    std::stack<std::string> forward;
////    std::string current = "http://www.acm.org/";
////
////    std::string command;
////    while (std::cin >> command && command != "QUIT") {
////        if (command == "BACK") {
////            if (!backward.empty()) {
////                forward.push(current);
////                current = backward.top();
////                backward.pop();
////                std::cout << current << std::endl;
////            }
////            else {
////                std::cout << "Ignored" << std::endl;
////            }
////        }
////        else if (command == "FORWARD") {
////            if (!forward.empty()) {
////                backward.push(current);
////                current = forward.top();
////                forward.pop();
////                std::cout << current << std::endl;
////            }
////            else {
////                std::cout << "Ignored" << std::endl;
////            }
////        }
////        else if (command == "VISIT") {
////            backward.push(current);
////            std::string url;
////            std::cin >> url;
////            current = url;
////            // Çå¿ÕforwardÕ»
////            while (!forward.empty()) {
////                forward.pop();
////            }
////            std::cout << current << std::endl;
////        }
////    }
////
////    return 0;
////}
