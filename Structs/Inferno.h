struct Inferno {
    vector<HumanSinHeap*>* Demons[7] ;
    HumanWorld* world;
    int archivenamecounter[7] = {0,0,0,0,0,0,0};
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
            human->heapPosition = 0;
            return;
        }
        for (int i = 0; i < demon->size(); i++) {            
            if ((*demon)[i]->heap[0]->getSurname() == human->getSurname() && (*demon)[i]->heap[0]->getCountry() == human->getCountry()) {
                (*demon)[i]->insert(human);
                human->heapPosition = i;
                return;
            }     
        }
        demon->push_back(new HumanSinHeap(choosensin));
        demon->at(demon->size() - 1)->insert(human);
        human->heapPosition = demon->size() - 1;

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
            if (world->humans[i]->getState() != 0) {
                continue;
            }
            if (world->humans[i]->getSin(choosensin) == 0) {
                continue;
            }
            insert(world->humans[i], NuevaListaOrdenada, choosensin);
        }
        
        //Crea la lista de pecadores
        vector<Human*>* Pecadores= new vector<Human*>;
        Pecadores->assign(NuevaListaOrdenada->begin(), NuevaListaOrdenada->begin() + Sinners);
        cout << Pecadores->size() << endl;
        for (int i = 0; i < Sinners; i++) {
            if (NuevaListaOrdenada->size() == 0) {
                break;
            }
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
                log.open("Logs/Lucifer" + to_string(archivenamecounter[0]++) + ".txt");
                break;
            case 1:
                log.open("Logs/Belcebu" + to_string(archivenamecounter[1]++) + ".txt");
                break;
            case 2:
                log.open("Logs/Satan" + to_string(archivenamecounter[2]++) + ".txt");
                break;
            case 3:
                log.open("Logs/Abadon" + to_string(archivenamecounter[3]++) + ".txt");
                break;
            case 4:
                log.open("Logs/Mammon" + to_string(archivenamecounter[4]++) + ".txt");
                break;
            case 5:
                log.open("Logs/Beelfegor" + to_string(archivenamecounter[5]++) + ".txt");    
                break;
            case 6:
                log.open("Logs/Asmodeo" + to_string(archivenamecounter[6]++) + ".txt");
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
        if (Demons[choosensin]->size() == 0) {
            return 0;
        }
        int res = Demons[choosensin]->at(0)->getmin();
        for (int i = 0; i < Demons[choosensin]->size(); i++) {
            if (Demons[choosensin]->at(i)->getmin() < res) {
                res = Demons[choosensin]->at(i)->getmin();
            }
        }
        return res;
    }

    Human * getminsinnerofallsins() {
        int cont = getminsin(0);
        Human * res; 
        for (int i = 0; i < 7; i++) {
            if (getminsin(i) < cont) {
                cont = getminsin(i);
                res = Demons[i]->at(0)->heap[0];
            }
        }
        return res;
    }

    int getmaxsinposition(int choosensin) {
        if (Demons[choosensin]->size() == 0) {
            return 0;
        }
        int res = 0;
        for (int i = 0; i < Demons[choosensin]->size(); i++) {
            if (Demons[choosensin]->at(i)->isEmpty()) {
                continue;
            }
            if (Demons[choosensin]->at(i)->getMax() > Demons[choosensin]->at(res)->getMax()) 
                res = i;
            
        }
        return res;
    }

    int getmaxsin(int choosensin) {
        if (Demons[choosensin]->size() == 0) {
            return 0;
        }

        int res = 0;
        for (int i = 0; i < Demons[choosensin]->size(); i++) {
            if (Demons[choosensin]->at(i)->isEmpty()) {
                continue;
            }
            if (Demons[choosensin]->at(i)->getMax() > res) 
                res = Demons[choosensin]->at(i)->getMax();
            
        }
        return res;
    }

    Human * getmaxsinnerofall() {
        int cont = 0;
        Human * res = NULL; 
        for (int i = 0; i < 7; i++) {
            if (Demons[i]->size() == 0) {
                continue;
            }

            if (!Demons[i]->at(getmaxsinposition(i))->isEmpty() && getmaxsin(i) > cont) {
                cont = getmaxsin(i);
                int pos = getmaxsinposition(i);
                res = Demons[i]->at(pos)->heap[0];
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
    
    void print() {
    for (int i = 0; i < 7; i++) {
        cout << "Demon " << i << endl;
        if (Demons[i] == nullptr) {
            cout << "Demons[" << i << "] is nullptr." << endl;
        } else {
            for (int j = 0; j < Demons[i]->size(); j++) {
                cout << "Heap " << j << endl;
                if (Demons[i]->at(j) == nullptr) {
                    cout << "Demons[" << i << "]->at(" << j << ") is nullptr." << endl;
                } else {
                    Demons[i]->at(j)->print();
                }
            }
        }
    }
}
    
};