// Includes all necessary libraries, this will be "inherit" by all files that include this file or files included in this file.
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <cctype>

// Declare namespace
using namespace std;

// Global variables (if needed)

// Struct headers
struct Human;
struct HumanNode;
struct TreeOfLife;
struct Inferno;
struct Maxheap;
struct HumanWorld;
struct Angel;
struct AngelNode;
struct AvlTree;
struct HeavenHashTable;
struct HeavenTree;
struct FunctionsMenu;
struct Menu;

// Function headers
vector<string>* readFileIntoArray(string filepath, int lines);
string randomBirthdate();
string HoraSistema();
void Familysearch(string, string, HumanWorld*);
int NumberCoversion(string number);
void winner(Inferno* infern, HumanWorld* world, HeavenTree* Heaven);
string Uppercase(string str);
// Structs
#include "Human.h"

#include "HumanNode.h"

#include "TreeOfLife.h"

#include "HumanSinHeap.h"

#include "HumanWorld.h"

#include "Inferno.h"

#include "Angel.h"

#include "AngelNode.h"

#include "AvlTree.h"

#include "HeavenHashTable.h"

#include "HeavenTree.h"

#include "FunctionsMenu.h"

#include "Menu.h"
// Function logic
string HoraSistema(){
    // Retorna la hora y fecha del sistema
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string hora = to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
    string fecha = to_string(ltm->tm_mday) + "/" + to_string(ltm->tm_mon) + "/" + to_string(1900 + ltm->tm_year);
    return fecha + " " + hora;
}
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

void winner(Inferno* infern, HumanWorld* world, HeavenTree* Heaven){
    string res = "\t Se decidira el ganador de la lucha entre el bien y el mal\n\n";
    int humantotal = world->humansCount;
    int pecadores = infern->conthumans;
    int salvados = Heaven->conthumans;
    int humanosvivos = humantotal - pecadores - salvados;
    
    res += "\tHumanos totales: " + to_string(humantotal) + "\n";
    res += "\tHumanos muertos: " + to_string(pecadores + salvados) + "\n";
    res += "\tHumanos vivos: " + to_string(humanosvivos) + "\n";
    res += "\tHumanos en el cielo: " + to_string(salvados) + "\n";
    res += "\tHumanos en el infierno: " + to_string(pecadores) + "\n\n";

    //Winner
    if (salvados > pecadores)
        res += "\tEl bien ha ganado la batalla\n\n";
    else if (salvados < pecadores)
        res += "\tEl mal ha ganado la batalla\n\n";
    else 
        res += "\tLa batalla ha terminado en empate\n\n";

    //archive creation
    ofstream myfile;
    myfile.open("Logs/Ganador.txt");
    myfile << res;
    myfile.close();
}

void Familysearch(string surname, string country, HumanWorld* world){
    int pecadores = 0;
    int salvados = 0;
    int vivos= 0;
    int total = 0;
    string res = "\tBusqueda de familiares " + surname + " "+ country + "\n\n";
    for (int i = 0; i < world->humansCount-1; i++){
        Human* human = world->humans[i];
        if (human->getSurname() == surname && human->getCountry() == country){
            if (human->getState() == 1){
                pecadores++;
                res += "\t" + human->getinfo() + " esta en el infierno\n\n";
            }
            else if (human->getState() == 2){
                salvados++;
                res += "\t" + human->getinfo() + " esta en el cielo\n\n";
            }
            else{
                vivos++;
                res += "\t" + human->getinfo() + " esta vivo\n\n";
            }
        }
    }
    total = pecadores + salvados + vivos;
    res += "\n\tSe encontraron " + to_string(total)+ "\n";
    
    //porcentaje de pecadores
    res+= "\tPecadores " + to_string(pecadores) + "\n";
    float porcentaje = (float)pecadores / (float)total;
    res += "\tPorcentaje de pecadores: " + to_string(porcentaje*100) + "%\n\n";

    //porcentaje de salvados
    res+= "\tSalvados " + to_string(salvados) + "\n";
    porcentaje = (float)salvados / (float)total;
    res += "\tPorcentaje de salvados: " + to_string(porcentaje*100) + "%\n\n";
    //porcentaje de vivos
    res+= "\tVivos " + to_string(vivos) + "\n";
    porcentaje = (float)vivos / (float)total;
    res += "\tPorcentaje de vivos: " + to_string(porcentaje*100) + "%\n\n";

    //creacion del archivo
    ofstream myfile;
    myfile.open("Logs/BusquedaFamiliares" + surname + country +".txt");
    myfile << res;
    myfile.close();
}

int NumberCoversion(string number){
    try {
        return stoi(number);
    }
    catch (exception e){
        cout << "Ingrese un numero valido" << endl;
        return -1;
    }
}

string Uppercase(string str){
    string res = "";
    for (int i = 0; i < str.length(); i++){
        res += toupper(str[i]);
    }
    return res;
}
