#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int NUM_TESTS = 5;

int readData(ifstream& inFile, string names[], int scores[][NUM_TESTS]);
void computeAverages(int scores[][NUM_TESTS], int numStudents, double averages[]);
char getLetterGrade(double avg);
void printReport(string names[], double averages[], int numStudents);

int main() {
    string names[50];
    int scores[50][NUM_TESTS];
    double averages[50];

    ifstream inFile("StudentGrades.txt");
    if (!inFile) {
        cout << "Error opening file." << endl;
        return 1;
    }

    int numStudents = readData(inFile, names, scores);
    computeAverages(scores, numStudents, averages);

    printReport(names, averages, numStudents);

    return 0;
