#include <iostream>
#include <vector>
using namespace std;
    //first test for o(n)
    int foobar (const std:: vector<std::string> &a, int b) {
        int answer = 0;
        for (int i = 0; i < a.size(); i +=b) {
            answer++;
        }
        return answer;
    }
    
    //second test
    std::vector<int> foo5 (const std:: vector<int> &a, int b) {
        std::vector<int> ret;
        for(int i = 0; i < a.size(); i++) {
            if (a[i] < b) {
                ret.insert(ret.end(),a[i]);
            }
        }
        return ret;



    cout<<"this is the first test with a o(n) runtime"<<endl;
    vector<std::string> aa;
    aa.push_back("10");
    aa.push_back("20");
    aa.push_back("30");
    aa.push_back("40");
    aa.push_back("50");
    
    aa.push_back("60");
    aa.push_back("70");
    aa.push_back("80");
    aa.push_back("90");
    aa.push_back("100");
    
    int bb = 1;
    foobar(aa,bb);
    //foo5(aa,bb);

    




}