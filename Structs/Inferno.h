struct Inferno {
    vector<HumanSinHeap*>* Demons[7] ;
    HumanWorld* world;
    //constructor
    Inferno() {
        //0 Lucifer Pride 1 Belcebu envy 2 satan wrath 3 abadon lazyness 4 Mammon Greed 5 Beelfegor Gluttony 6 Asmodeo Lust
        for (int i = 0; i < 7; i++) {
            Demons[i] = new vector<HumanSinHeap*>;
        }
        world = new HumanWorld(new TreeOfLife());
    }

    Inferno(HumanWorld* _world){
        //0 Lucifer Pride 1 Belcebu envy 2 satan wrath 3 abadon lazyness 4 Mammon Greed 5 Beelfegor Gluttony 6 Asmodeo Lust
        for (int i = 0; i < 7; i++) {
            Demons[i] = new vector<HumanSinHeap*>;
        }
        world = _world;
    }

    //methods
    void insert(Human* human, vector<Human*>* HumanList, int choosensin) {
        //Insert a human in a list based of his max sin, in order
        if (HumanList->size() == 0) {
            HumanList->push_back(human);
            return;
        }

        for(int i = 0; i < HumanList->size(); i++) {
            if (human->getSin(choosensin) > (*HumanList)[i]->getSin(choosensin)) {
                HumanList->insert(HumanList->begin(), human);
                break;
            }
            else if (human->getSin(choosensin) == (*HumanList)[i]->getSin(choosensin)) {
                HumanList->insert(HumanList->begin() + i, human);
                break;
            }
            else if (i == HumanList->size() - 1) {
                HumanList->push_back(human);
                break;
            }

        }
    }
    void killhuman(Human* human, int choosensin) {
        //Kill a human and send him to the Inferno
        human->setState(1);
        int sin = human->getSin(choosensin);
        vector<HumanSinHeap*>* demon = Demons[choosensin];
        if (demon->size() == 0) {
            demon->push_back(new HumanSinHeap(choosensin));
            demon->at(0)->insert(human);
            return;
        }
        for (int i = 0; i < demon->size(); i++) {            
            if ((*demon)[i]->heap[0]->getSurname() == human->getSurname() && (*demon)[i]->heap[0]->getCountry() == human->getCountry()) {
                (*demon)[i]->insert(human);
                return;
            }     
        }
        demon->push_back(new HumanSinHeap(choosensin));
        demon->at(demon->size() - 1)->insert(human);

    }

    void condenation(int choosensin) {
        string bitacora= "\tBitacora de condenacion\n\tDemonio: ";
        switch (choosensin) {
            case 0:
                bitacora += "Lucifer\tcondena a los orgullosos\n\n";
                break;
            case 1:
                bitacora += "Belcebu\tcondena a los envidiosos\n\n";
                break;
            case 2:
                bitacora += "Satan\tcondena a los iracundos\n\n";
                break;
            case 3:
                bitacora += "Abadon\tcondena a los perezosos\n\n";
                break;
            case 4:
                bitacora += "Mammon\tcondena a los avaros\n\n";
                break;
            case 5:
                bitacora += "Beelfegor\tcondena a los glotones\n\n";
                break;
            case 6:
                bitacora += "Asmodeo\tcondena a los lujuriosos\n\n";
                break;
        }
        int totalhuman = world->humansCount;
        int Sinners = totalhuman * 0.05 -1; 
        //Crea una nueva lista ordenada de todos los humanos 
        vector<Human*>* NuevaListaOrdenada = new vector<Human*>;
        
        for (int i = 0; i < totalhuman-1; i++) {
            insert(world->humans[i], NuevaListaOrdenada, choosensin);
        }
        
        //Crea la lista de pecadores
        vector<Human*>* Pecadores= new vector<Human*>;
        Pecadores->assign(NuevaListaOrdenada->begin(), NuevaListaOrdenada->begin() + Sinners);
        cout << Pecadores->size() << endl;
        for (int i = 0; i < Sinners; i++) {
            NuevaListaOrdenada->erase(NuevaListaOrdenada->begin());
        }

        //Kills the humans and send them to the Inferno
        for (int i = 0; i < Pecadores->size(); i++) {
            killhuman(Pecadores->at(i), choosensin);
            bitacora += "\t\t" + Pecadores->at(i)->getSurname() + " " + Pecadores->at(i)->getName() + " " + Pecadores->at(i)->getCountry() + "\n\t";
            bitacora += HoraSistema() + " condenado por " + to_string(Pecadores->at(i)->getSin(choosensin)) + " pecados\n\n";
        }

        //Creacion del log de condenacion
        ofstream log;
        switch (choosensin) {
            case 0:
                log.open("Logs/Lucifer.txt");
                break;
            case 1:
                log.open("Logs/Belcebu.txt");
                break;
            case 2:
                log.open("Logs/Satan.txt");
                break;
            case 3:
                log.open("Logs/Abadon.txt");
                break;
            case 4:
                log.open("Logs/Mammon.txt");
                break;
            case 5:
                log.open("Logs/Beelfegor.txt");
                break;
            case 6:
                log.open("Logs/Asmodeo.txt");
                break;
        }
        log << bitacora;
        log.close();
    }
    int getsinners(int choosensin){
        int res = 0;
        for (int i = 0; i < Demons[choosensin]->size(); i++) {
            res += Demons[choosensin]->at(i)->getSize();
        }
        return res;
    }

    int getallthesinners() {
        int res = 0;
        for (int i = 0; i < 7; i++) {
            res += getsinners(i);
        }
        return res;
    }

    int getminsin(int choosensin) {
        int res = Demons[choosensin]->at(0)->getmin();
        for (int i = 0; i < Demons[choosensin]->size(); i++) {
            if (Demons[choosensin]->at(i)->getmin() < res) {
                res = Demons[choosensin]->at(i)->getmin();
            }
        }
        return res;
    }

    int getmaxsin(int choosensin) {
        int res = Demons[choosensin]->at(0)->getMax();
        for (int i = 0; i < Demons[choosensin]->size(); i++) {
            if (Demons[choosensin]->at(i)->getMax() > res) {
                res = Demons[choosensin]->at(i)->getMax();
            }
        }
        return res;
    }

    int getaverage(int choosensin) {
        int res = 0;
        
        for (int i = 0; i < Demons[choosensin]->size(); i++) {
            res += Demons[choosensin]->at(i)->getallints();
        }
        return res / Demons[choosensin]->size();
    }
    
    void print () {
        for (int i = 0; i < 7; i++) {
            cout << "Demon " << i << endl;
            for (int j = 0; j < Demons[i]->size(); j++) {
                cout << "Heap " << j << endl;
                Demons[i]->at(j)->print();
                
                }
            }
        }
    
};