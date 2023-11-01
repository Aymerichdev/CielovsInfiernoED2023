struct Family{
    vector<Human*> family;
   
    //constructor 
    Family(){
        family = vector<Human*>();
    }

    void addHuman(Human* _human){
        family.push_back(_human);
    }

};