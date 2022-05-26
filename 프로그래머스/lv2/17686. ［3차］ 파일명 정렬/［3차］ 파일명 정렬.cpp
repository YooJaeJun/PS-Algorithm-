#include <bits/stdc++.h>
using namespace std;

struct filetag
{
    string head, number, tail;
};

int compareNumber(string s1, string s2)
{
    int n1 = stoi(s1);
    int n2 = stoi(s2);
    if (n1 < n2) return 1;
    else if (n1 > n2) return 0;
    return -1;  // 다 같음
}

bool compareFiletag(filetag f1, filetag f2)
{
    // head 비교
    string s1 = f1.head;
    string s2 = f2.head;
    for(auto& ch : s1)
        if (ch >= 'A' && ch <= 'Z') // 소문자로 통일
            ch += ('a' - 'A');
    for(auto& ch : s2)
        if (ch >= 'A' && ch <= 'Z') // 소문자로 통일
            ch += ('a' - 'A');
    if (s1 < s2) return true;
    else if (s1 > s2) return false;
    
    // number 비교
    int res = compareNumber(f1.number, f2.number);
    if (res == 1) return true;
    else return false;  // 0 이거나 -1이면
}

vector<string> solution(vector<string> files) {
    // 분리
    vector<filetag> f(files.size());
    int idx = 0;
    for(auto& file : files)
    {
        string tmpStr;
        int state = 0;  // 0:head, 1:number, 2:tail
        for(auto& ch : file)
        {
            // 분류
            if (state == 0 && ch >= '0' && ch <= '9')
            {
                f[idx].head = tmpStr;
                tmpStr = ch;
                state = 1;
            }
            else if (state == 1 && (ch < '0' || ch > '9'))
            {
                f[idx].number = tmpStr;
                tmpStr = ch;
                state = 2;
            }
            else
            {
                tmpStr += ch;
            }
        }
        // 맨끝
        if (state == 1) f[idx].number += tmpStr;
        if (state == 2) f[idx].tail += tmpStr;
        
        idx++;
    }
    
    // 정렬
    stable_sort(f.begin(), f.end(), compareFiletag);
    
    // 병합
    vector<string> ans;
    for(auto& elem : f)
    {
        string s;
        s += elem.head; s += elem.number; s += elem.tail;
        ans.push_back(s);
    }
    
    return ans;
}