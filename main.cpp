#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

using namespace std;
struct Problem
{
	string name;
	string speciality;
    int hour;
	int duration;
	int priority;
};
struct Doctor
{
	string name;
    int doctors_nr;
	vector<string> speciality;
};
bool operator<(const Problem& p1, const Problem& p2)
{
	if (p1.hour == p2.hour)
		return p1.priority > p2.priority;
    else
	return p1.hour< p2.hour;
}


int main()
{
    ifstream inFile("input4_bonus.txt");
    int no_problems, no_doctors;


    inFile >> no_problems;

    vector<Problem> problems;


    for (int i = 0; i < no_problems; i++)
    {
        Problem p;
        inFile >> p.name;
        inFile >> p.speciality;
        inFile >> p.hour;
        inFile >> p.duration;
        inFile >> p.priority;
        problems.push_back(p);
    }


    inFile >> no_doctors;

    vector<Doctor> doctors(no_doctors);

    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> doctors[i].name;
        inFile >> doctors[i].doctors_nr;
        for (int j = 0; j < doctors[i].doctors_nr; j++) {
            string x;
            inFile >> x;
            doctors[i].speciality.push_back(x);
        }
    }

    for (int i = 0; i < no_doctors; i++) {

        int time = 8;

        set<Problem> pq;

        for (int j = 0; j < no_problems; j++) {

            auto it = find_if(problems.begin(), problems.end(), [&](Problem p) {
                return find(doctors[i].speciality.begin(), doctors[i].speciality.end(), p.speciality) != doctors[i].speciality.end();
                });

            if (it != problems.end()) {
                pq.insert(*it);
                problems.erase(it);


            }
        }
        if (pq.size()>0) {
        vector<string> temp;
        vector<int> temp2;
        int hourspend = pq.begin()->hour;
        while (!pq.empty()) {
            if (time - pq.begin()->duration >= 0&&pq.begin()->hour>=hourspend) {
                temp.push_back(pq.begin()->name);
                time -= pq.begin()->duration;
                temp2.push_back(pq.begin()->hour);
				hourspend = hourspend + pq.begin()->duration;
                pq.erase(pq.begin());
            }
            else {
                problems.push_back(*pq.begin());
                pq.erase(pq.begin());
            }
        }
      
            cout << doctors[i].name << " " << temp.size() << " ";

            for (auto i = 0; i < temp.size(); i++) {
                cout << temp[i] << " ";
                cout << temp2[i] << " ";
            }

            cout << endl;
        }
    }



    return 0;
}
