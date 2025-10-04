#include "Solution.cpp"
#include <iostream>
using namespace std;
int main(){
    Solution s;
    cout << s.convertDateToBinary("2023-02-05") << endl;
    cout << s.convertDateToBinary("2123-10-05") << endl;
    return 0;
}