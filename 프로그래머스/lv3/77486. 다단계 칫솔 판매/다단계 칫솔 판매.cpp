#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, 
    vector<string> seller, vector<int> amount) {

    map<string, string> mpParent; // name, parent
    map<string, int> mpAmount; // name, amount
    for (int i = 0; i != enroll.size(); i++) {
        mpParent[enroll[i]] = referral[i];
        mpAmount[enroll[i]] = 0;
    }

    for (int i = 0; i != seller.size(); i++) {
        int price = (amount[i] * 100) * 1 / 10;

        if (price >= 1) {
            string parent = mpParent[seller[i]];
            string child = seller[i];

            mpAmount[parent] += price;
            mpAmount[child] += price * 9;

            while (parent != "-") {
                child = parent;
                parent = mpParent[parent];
                price = price * 1 / 10;
                if (price >= 1) {
                    mpAmount[parent] += price;
                    mpAmount[child] -= price;
                }
                else {
                    mpAmount[child] += price * 10;
                    break;
                }
            }
        }
        else {
            mpAmount[seller[i]] += price * 10;
        }
    }

    vector<int> answer(enroll.size());
    for (int i = 0; i != answer.size(); i++) {
        answer[i] = mpAmount[enroll[i]];
    }
    return answer;
}