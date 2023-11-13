struct Angel{
    HumanWorld* world;
    Inferno* inferno;
    Human* savedHuman;
    string name;
    int version;
    int generation;

    Angel(){
        world = NULL;
        inferno = NULL;
        savedHuman = NULL;
        name = "";
        version = generation = 0;
    }

    Angel(int templateValue){
        switch (templateValue){
            case 0:
                name = "God";
                break;
            case 1:
                name = "Seraphim";
                break;
            case 2:
                name = "Cherub";
                break;
            case 3:
                name = "Throne";
                break;
            default:
                name = "Angel";
                break;
        }
        version = 1;
        generation = 1;
    }

    Angel(HumanWorld* _world, Inferno* _inferno, Human* _savedHuman, string _name, int _version, int _generation){
        world = _world;
        inferno = _inferno;
        savedHuman = _savedHuman;
        name = _name;
        version = _version;
        generation = _generation;
    }

    bool saveHuman(Human* human){
        if (human->getState() == 1){
            savedHuman = human;
            human->setState(2);
            human->angel = this;
            return true;
        }
        return false;
    }
};