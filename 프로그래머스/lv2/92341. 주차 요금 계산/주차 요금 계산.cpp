#include <bits/stdc++.h>
using namespace std;

struct infotag
{
    string time, number, state;
};

int subTime(string s, string e)
{
    string eh, sh;
    eh = e[0];
    eh += e[1];
    sh = s[0];
    sh += s[1];
    int h = stoi(eh) - stoi(sh);

    string em, sm;
    em = e[3];
    em += e[4];
    sm = s[3];
    sm += s[4];
    int m = stoi(em) - stoi(sm);

    if (m < 0)
    {
        h -= 1;
        m += 60;
    }
    return h * 60 + m;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    // 분할
    vector<infotag> infos(records.size());
    int idx = 0;
    for (auto& record : records)
    {
        stringstream ss;
        ss.str(record);
        string s;
        for (int i = 0; i < 3; i++)
        {
            ss >> s;
            if (i == 0) infos[idx].time = s;
            else if (i == 1) infos[idx].number = s;
            else infos[idx].state = s;
        }
        idx++;
    }

    // 시간 기록
    map<string, int> dic;    // 번호, 시간
    map<string, string> dicForStrStartTime; // 번호 스트링형태로 스타트 타임 저장
    map<string, string> dicForStrEndTime; // 엔드 타임
    for (auto& info : infos)
    {
        if (info.state == "IN")
        {
            dicForStrStartTime[info.number] = info.time;
            dicForStrEndTime[info.number] = "23:59";
        }
        else
        {
            dic[info.number] += subTime(dicForStrStartTime[info.number], info.time);
            dicForStrEndTime[info.number] = info.time;
        }
    }
    // 마지막 출차 안 한 차량 처리
    for (auto& elem : dicForStrEndTime)
    {
        if (elem.second == "23:59")
        {
            dic[elem.first] += subTime(dicForStrStartTime[elem.first], "23:59");
        }
    }

    // 요금 계산
    vector<int> answer;
    for (auto& elem : dic)
    {
        int ret = 0;
        if (elem.second <= fees[0]) answer.push_back(fees[1]);
        else
        {
            ret += fees[1];
            int overTime = elem.second - fees[0];
            int overPerTime = ceil((float)overTime / fees[2]);
            ret += overPerTime * fees[3];
            answer.push_back(ret);
        }
    }

    return answer;
}