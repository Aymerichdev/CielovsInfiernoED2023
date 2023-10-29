// Includes all necessary libraries, this will be "inherit" by all files that include this file or files included in this file.
#include <iostream>
#include <vector>

// Declare namespace
using namespace std;

// Global variables (if needed)

// Struct headers
struct Human;

// Function headers

// Structs
struct Human{
    // Attributes
    int id;
    // TODO: check if it would be better to use an int index for country, belief and job
    string name, surname, country, belief, job, email, birthdate;
    int sins[7];
    vector<Human*> friends;
    int socialNetworks[7];

    // Constructors
    Human(){
        id = 0;
        name = "";
        surname = "";
        country = "";
        belief = "";
        job = "";
        email = "";
        birthdate = "";
        for(int i = 0; i < 7; i++){
            sins[i] = 0;
            socialNetworks[i] = 0;
        }
    }

    Human(int _id, string _name, string _surname, string _country, string _belief, string _job, string _email, string _birthdate, vector<Human*> _friends){
        // TODO: check if int _friends is correct or if it should be filled within this struct (in other words, it should recieve the human vector and randomize it here)
        id = _id;
        name = _name;
        surname = _surname;
        country = _country;
        belief = _belief;
        job = _job;
        email = _email;
        birthdate = _birthdate;
        for(int i = 0; i < 7; i++){
            sins[i] = 0;
            socialNetworks[i] = 0;
        }
        friends = _friends;
    }

    // Getters & Setters
    int getId(){
        return id;
    }

    string getName(){
        return name;
    }

    string getSurname(){
        return surname;
    }

    string getCountry(){
        return country;
    }

    string getBelief(){
        return belief;
    }

    string getJob(){
        return job;
    }

    string getEmail(){
        return email;
    }

    string getBirthdate(){
        return birthdate;
    }

    int getSin(int index){
        return sins[index];
    }

    int getSocialNetwork(int index){
        return socialNetworks[index];
    }

    vector<Human*> getFriends(){
        return friends;
    }

    void addSin(int index, int value){
        sins[index] += value;
    }

    void addSocialNetwork(int index, int value){
        socialNetworks[index] += value;
    }

    void addFriend(Human * friendToAdd){
        friends.push_back(friendToAdd);
    }
};

// Includes of structs that use this one as sort of a "base struct"

// Function logic
