#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
struct Problem
{
	string name;
	string speciality;
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
	return p1.priority < p2.priority;
}

int main()
{
    ifstream inFile("input.txt");
    int no_problems, no_doctors;


    inFile >> no_problems;

    vector<Problem> problems(no_problems);

    for (int i = 0; i < no_problems; i++)
    {
        inFile >> problems[i].name;
        inFile >> problems[i].speciality;
        inFile >> problems[i].duration;
		inFile >> problems[i].priority;
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

		priority_queue<Problem> pq;

        for (int j = 0; j < no_problems; j++) {

            auto it = find_if(problems.begin(), problems.end(), [&](Problem p) {
                return find(doctors[i].speciality.begin(), doctors[i].speciality.end(), p.speciality) != doctors[i].speciality.end();
                });

            if (it != problems.end()) {
                pq.push(*it);
				problems.erase(it);
				

            }
        }
            if (!pq.empty()) {

				vector<string> temp;
                vector<int> temp2;

                while (!pq.empty()) {
                    if (time - pq.top().duration >= 0) {
                        temp.push_back(pq.top().name);
                        time -= pq.top().duration; 
                        temp2.push_back(pq.top().duration);
                        pq.pop();
                    }
                    else{
                        problems.push_back(pq.top());
                          pq.pop();
                   }
                }
                int time = 9;
                cout << doctors[i].name << " " << temp.size() << " ";

                for (auto i = 0; i < temp.size();i++) {
                    cout << temp[i] << " ";
                    cout << time << " ";
					time = time + temp2[i];
                }

                cout << endl;
            }
      }
    return 0;
}