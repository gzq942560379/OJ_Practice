#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job
{
    long long p;
    long long f;
};

long long jobSchedule(vector<Job> &jobs)
{
    sort(jobs.begin(), jobs.end(), [](const Job &ja, const Job &jb) { return ja.f > jb.f; });
    long long super = 0;
    long long pc = 0;
    for (size_t i = 0, ie = jobs.size(); i < ie; ++i)
    {
        super += jobs[i].p;
        pc = max(pc - jobs[i].p, jobs[i].f);
    }
    return super + pc;
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    vector<Job> jobs;
    size_t i = 0;
    long long temp;
    while (cin >> temp)
    {
        ++i;
        jobs.push_back(Job{.p = temp, .f = 0});
        if (cin.get() == '\n')
            break;
    }
    i = 0;
    while (cin >> temp)
    {
        jobs[i].f = temp;
        ++i;
        if (cin.get() == '\n')
            break;
    }
    cout << jobSchedule(jobs);
    return 0;
}
