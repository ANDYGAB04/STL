#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main()
{
    ifstream inFile("input4_bonus.txt");
    int no_problems, no_doctors, duration;
    string name, speciality;

    inFile >> no_problems;
    vector<tuple<string, string, int>> problems;
    for (int i = 0; i < no_problems; i++)
    {
        inFile >> name;
        inFile >> speciality;
        inFile >> duration;
        problems.push_back(make_tuple(name, speciality, duration));

    }

    inFile >> no_doctors;
    vector<string> docspeciality;
    vector<string> docnames;
    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> name;
        inFile >> speciality;
        docspeciality.push_back(speciality);
        docnames.push_back(name);
    }
    int i = 0, j = 0, s, nr;
    for (auto name = docnames.begin(); name < docnames.end(); name++) {
        s = 8;
        nr = 0;
        bool ok = false;
        vector<string> IdProbleme;
        cout << *name << " ";
        for (auto it = 0; it < problems.size(); it++)
        {

            string spec = get<1>(problems[it]);
            int dur = get<2>(problems[it]);
            string name = get<0>(problems[it]);
            if (docspeciality[0] == spec && s - dur >= 0) {
                s -= dur;
                if (s < 0)
                    break;
                IdProbleme.push_back(name);
                problems.erase(remove(problems.begin(), problems.end(), make_tuple(name, spec, dur)), problems.end());
                it--;

            }
            else if (s - dur < 0) {
                break;
            }


        }
        cout << IdProbleme.size() << " ";
        for (auto i : IdProbleme)
            cout << i << " ";
        cout << endl;
        docspeciality.erase(docspeciality.begin());
        IdProbleme.clear();
    }

    return 0;
}