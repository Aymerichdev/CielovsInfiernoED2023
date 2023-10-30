struct Family{
    vector<Human*> family;
    vector<Maxheap> HeapList; // 0 pride, 1 envy, 2 wrath, 3 sloth, 4 greed, 5 gluttony, 6 lust 
   
    //constructor 
    Family(){
        family = vector<Human*>();
        HeapList = vector<Maxheap>();
    }

    void addHuman(Human* _human){
        family.push_back(_human);
    }

};