#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> dic;
    
    for (int i=0; i<players.size(); i++)
    {
        dic[players[i]] = i;
    }
    
    for (auto& calling : callings)
    {
        int index = dic[calling];
        dic[players[index - 1]]++;
        dic[players[index]]--;
        swap(players[index - 1], players[index]);
    }
    return players;
}