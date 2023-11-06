struct Human{
    // Attributes
    int id, arrayPosition, state; // State has three values: 0 = alive, 1 = hell, 2 = heaven
    // TODO: check if it would be better to use an int index for country, belief and job
    string name, surname, country, belief, job, birthdate;
    int sins[7];
    vector<Human*> friends;
    int socialNetworks[7];
    Angel* angel;
    int heapPosition= -1;

    // Constructors
    Human(){
        id = 0;
        arrayPosition = 0;
        state = 0;
        name = "";
        surname = "";
        country = "";
        belief = "";
        job = "";
        birthdate = "";
        for(int i = 0; i < 7; i++){
            sins[i] = 0;
            socialNetworks[i] = 0;
        }
        angel = NULL;  
    }

    // For testing purposes
    Human(int _id){
        id = _id;
        arrayPosition = 0;
        state = 0; // 1 dead 2 saved 
        name = "";
        surname = "";
        country = "";
        belief = "";
        job = "";
        birthdate = "";
        for(int i = 0; i < 7; i++){
            sins[i] = 0;
            socialNetworks[i] = 0;
        }
        angel = NULL;
    }

    Human(int _id, string _name, string _surname, string _country, string _belief, string _job, string _birthdate){
        // TODO: check if int _friends is correct or if it should be filled within this struct (in other words, it should recieve the human vector and randomize it here)
        id = _id;
        arrayPosition = 0;
        state = 0;
        name = _name;
        surname = _surname;
        country = _country;
        belief = _belief;
        job = _job;
        birthdate = _birthdate;
        for(int i = 0; i < 7; i++){
            sins[i] = 0;
            socialNetworks[i] = 0;
        }
    }

    void printHuman(){
        cout << "Human: " << id << endl;
        cout << "State: ";
        switch (state){
        case 0:
            cout << "Alive" << endl; 
            break;
        case 1:
            cout << "Hell" << endl; 
            break;
        case 2:
            cout << "Heaven" << endl; 
            break;
        default:
            break;
        }
        cout << "Name: " << name << " " << surname << endl;
        cout << "Country: " << country << endl;
        cout << "Belief: " << belief << endl;
        cout << "Job: " << job << endl;
        cout << "Birthdate: " << birthdate << endl;
        cout << "Sins: ";
        for (int i = 0; i < 7; i++)
            cout << sins[i] << " ";
        cout << endl << "Social Networks: ";
        for (int i = 0; i < 7; i++)
            cout << socialNetworks[i] << " ";
        cout << endl << "Friends: ";
        for (int i = 0; i < friends.size(); i++)
            cout << friends[i]->getId() << " ";
        cout << endl << endl;
    }

    // Getters & Setters
    int getId(){
        return id;
    }

    int getArrayPosition(){
        return arrayPosition;
    }

    int getState(){
        return state;
    }

    void setState(int _state){
        state = _state;
    }

    void setArrayPosition(int _arrayPosition){
        arrayPosition = _arrayPosition;
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

    string getBirthdate(){
        return birthdate;
    }

    int getbiggersinposition (){
        int res = 0;
        for (int i = 0; i < 7; i++) {
            if (sins[i] > res) {
                res = i;
            }
        }
        return res;
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

    string getstringid(){
        string id = "(" + to_string(this->id) + ")";
        return id;
    }

    string getfriendsstring(){
        string res = "Amigo de: (";
        for (int i = 0; i < friends.size(); i++)
            res += friends[i]->getName() + " " + friends[i]->getSurname() + " " + friends[i]->getstringid() + " "; 
        res += ")";
        return res;

    }
    string getinfo(){
        string res = "";
        res += name + " " + surname + " " + getstringid() + " ";
        return res;
    }

    int getbiggersin(){
        int res = 0;
        for (int i = 0; i < 7; i++) {
            if (sins[i] > res) {
                res = sins[i];
            }
        }
        return res;
    }
};
