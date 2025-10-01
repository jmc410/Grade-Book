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
        cout << "Something went wrong when opening the file." << endl;
        return 1;
    }

    int numStudents = readData(inFile, names, scores);
    computeAverages(scores, numStudents, averages);

    printReport(names, averages, numStudents);

    return 0;
  }

  int readData(ifstream& inFile, string names[], int scores[][NUM_TESTS]) {
      int studentCount = 0;
      while (inFile >> names[studentCount]) {
          for (int i = 0; i < NUM_TESTS; i++) {
              inFile >> scores[studentCount][i];
          }
          studentCount++;
      }
      return studentCount;
  }

  void computeAverages(int scores[][NUM_TESTS], int numStudents, double averages[]) {
      for (int i = 0; i < numStudents; i++) {
          int sum = 0;
          for (int j = 0; j < NUM_TESTS; j++) {
              sum += scores[i][j];
          }
          averages[i] = static_cast<double>(sum) / NUM_TESTS;
      }
  }

  char getLetterGrade(double avg) {
      if (avg >= 90)
          return 'A';
      else if (avg >= 80)
          return 'B';
      else if (avg >= 70)
          return 'C';
      else if (avg >= 60)
          return 'D';
      else
          return 'F';
  }

  void printReport(string names[], double averages[], int numStudents) {
      cout << left << setw(12) << "Name"
           << setw(10) << "Average"
           << setw(6) << "Grade" << endl;
      cout << "——————————————————————————" << endl;

      for (int i = 0; i < numStudents; i++) {
          char grade = getLetterGrade(averages[i]);

          cout << left << setw(12) << names[i]
               << setw(10) << fixed << setprecision(1) << averages[i]
               << setw(6) << grade << endl;
      }
  }