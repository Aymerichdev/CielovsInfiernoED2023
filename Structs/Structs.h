// Includes all necessary libraries, this will be "inherit" by all files that include this file or files included in this file.
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

// Declare namespace
using namespace std;

// Global variables (if needed)

// Struct headers
struct Human;
struct HumanNode;
struct TreeOfLife;
struct Maxheap;
struct HumanWorld;

// Function headers
vector<string>* readFileIntoArray(string filepath, int lines);
string randomBirthdate();

// Structs
#include "Human.h"

#include "HumanNode.h"

#include "TreeOfLife.h"

#include "HumansInHeap.h"

#include "HumanWorld.h"

#include "Inferno.h"

// Function logic
vector<string>* readFileIntoArray(string filepath, int lines){
    vector<string>* array = new vector<string>();
    string line;
    ifstream myfile(filepath);
    if (myfile.is_open()){
        for (int i = 0; i < lines; i++){
            getline(myfile, line);
            array->push_back(line);
        }
        myfile.close();
    }else{
        cout << "Unable to open file";
    }
    return array;
}

string randomBirthdate(){
    int day = rand() % 28 + 1;
    int month = rand() % 12 + 1;
    int year = rand() % 60 + 1960;
    string dayString = to_string(day);
    string monthString = to_string(month);
    string yearString = to_string(year);
    if (day < 10) dayString = "0" + dayString;
    if (month < 10) monthString = "0" + monthString;
    return dayString + "/" + monthString + "/" + yearString;
}