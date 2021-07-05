#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#define filename "lab_records.csv"

using namespace std;

struct Student
{
    string ID;
    int scores[14];
};

vector<Student> generateStu();
int randomInt(int low, int up);
void question2(vector<Student> &students);
void question3(vector<Student> &students);

int main()
{
    cout << "=============================Question 1=============================" << endl;
    vector<Student> students = generateStu();
    cout << students.size() << endl;
    cout << "=============================Question 2=============================" << endl;
    question2(students);
    cout << "=============================Question 3=============================" << endl;
    question3(students);
    cout << "A file named lab_records.csv is created." << endl;
    return 0;
}

vector<Student> generateStu()
{
    vector<Student> students;
    set<string> IDset;
    int n;
    cout << "Please input the number of students: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Student stu;
        do
        {
            stu.ID = to_string(randomInt(2000, 2020) * 10000 + randomInt(0, 9999));
        } while (!IDset.insert(stu.ID).second);
        cout << stu.ID << " :";
        for (int i = 0; i < 13; i++)
        {
            stu.scores[i] = randomInt(0, 5);
            cout << stu.scores[i] << ", ";
        }
        stu.scores[13] = randomInt(0, 5);
        cout << stu.scores[13];
        students.push_back(stu);
        cout << endl;
    }
    return students;
}

int randomInt(int low, int up)
{
    // generate random Int from [1,5];
    return (low + rand() % (up - low + 1));
}

void question2(vector<Student> &students)
{
    int count;
    cout << "the SID of the students whose absent time equal or exceed 2: " << endl;
    for (Student &stu : students)
    {
        count = 0;
        for (int &score : stu.scores)
        {
            if (score == 0)
            {
                count++;
            }
            if (count >= 2)
            {
                cout << stu.ID << endl;
                break;
            }
        }
    }
}

void question3(vector<Student> &students)
{
    ofstream myfile(filename);
    if (!myfile.is_open())
    {
        cout << "Can not open " << filename << endl;
        exit(0);
    }
    for (Student &stu : students)
    {
        myfile << stu.ID;
        for (int &score : stu.scores)
        {
            myfile << "," << score;
        }
        myfile << "\n";
    }
    myfile.close();
}
