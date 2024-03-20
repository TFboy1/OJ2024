//#include<iostream>
//#include<algorithm>
//#include<string>
//#include<vector>
////用1-9，添加+或-或空格，使得=100成立
//using namespace std;
//vector<string> nums;
//
//int sum_nums() {
//		int sum = 0;
//		int temp;
//		vector<string> temps;
//		temps=nums;
//		for (int i = 0; i < temps.size(); i++) {
//			if (temps.back() != "+" && temps.back() != "-") {
//			temp = stoi(temps.back());
//			temps.pop_back();
//			}
//				
//			else if (temps.back() == "+") {
//			sum += temp;
//			temps.pop_back();
//			}
//				
//			else {
//			sum -= temp;
//			temps.pop_back();
//			}
//				
//	}
//	return sum;
//
//}
//int find_num(int n,int j) {
//	if(sum_nums()==100)
//		return 1;
//	else {
//	while (true) {
//		for (int i = 2; i <= n; i++) {
//				if (j >=3) {
//				j = 0;
//				}
//				else if (j == 0) {
//					nums.push_back("+");
//					
//				}
//				else if (j == 1) {
//					nums.push_back("-");
//						
//					}
//						
//				
//				else if(j==2) {
//					
//					nums.push_back(to_string(i * 10 + (i + 1)));
//					if (sum_nums() == 100)
//						return 1;
//					else {
//						find_num(n - (i - 1), j + 1);
//						nums.pop_back();
//					}
//					}
//						
//				}
//			
//		}
//	}
//	}
//
//	
//	
//int main() {
//	nums.push_back("1");
//	find_num(9,0);
//	printf("%s", nums[0].c_str());
//}