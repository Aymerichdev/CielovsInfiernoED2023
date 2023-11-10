struct Inferno {
    vector<HumanSinHeap*>* Demons[7] ;
    HumanWorld* world;
    int archivenamecounter[7] = {0,0,0,0,0,0,0};
    int conthumans = 0;
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
        human->sinininferno = choosensin;
        int sin = human->getSin(choosensin);
        vector<HumanSinHeap*>* demon = Demons[choosensin];
        if (demon->size() == 0) {
            demon->push_back(new HumanSinHeap(choosensin, human->getCountry(), human->getSurname()));
            demon->at(0)->insert(human);
            human->heapPosition = 0;
            return;
        }
        for (int i = 0; i < demon->size(); i++) {            
            if ((*demon)[i]->surname == human->getSurname() && (*demon)[i]->country == human->getCountry()) {
                (*demon)[i]->insert(human);
                human->heapPosition = i;
                return;
            }     
        }
        demon->push_back(new HumanSinHeap(choosensin, human->getCountry(), human->getSurname()));
        demon->at(demon->size() - 1)->insert(human);
        human->heapPosition = demon->size() - 1;

    }

    string givedemonname(int choosensin) {
        switch (choosensin) {
            case 0:
                return "Lucifer";
            case 1:
                return "Belcebu";
            case 2:
                return "Satan";
            case 3:
                return "Abadon";
            case 4:
                return "Mammon";
            case 5:
                return "Beelfegor";
            case 6:
                return "Asmodeo";
        }
    }

    string givedemoncondenation(int choosensin) {
        switch (choosensin) {
            case 0:
                return "orgullosos";
            case 1:
                return "envidiosos";
            case 2:
                return "iracundos";
            case 3:
                return "perezosos";
            case 4:
                return "avaros";
            case 5:
                return "glotones";
            case 6:
                return "lujuriosos";
        }
    }

    int overallsins() {
        int res = 0;
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < Demons[i]->size(); j++) {
                res += Demons[i]->at(j)->getallints();
            }
        }
        return res;
    }
        

    void condenation(int choosensin) {
        if (world->humansCount == 0) {
            cout << "No hay humanos en el mundo" << endl;
            return;
        }
        string bitacora= "\tBitacora de condenacion\n\tDemonio: ";
        int totalhuman = world->humansCount;
        int Sinners = totalhuman * 0.05 -1; 
        bitacora += givedemonname(choosensin) + " condena a "+ to_string(Sinners+1) + " " + givedemoncondenation(choosensin) + "\n\t";
        
    
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
        if (Sinners > NuevaListaOrdenada->size()) {
            Sinners = NuevaListaOrdenada->size();

        }
        Pecadores->assign(NuevaListaOrdenada->begin(), NuevaListaOrdenada->begin() + Sinners+1);
        for (int i = 0; i < Pecadores->size(); i++) {
            if (NuevaListaOrdenada->size() == 0) {
                break;
            }
            cout << NuevaListaOrdenada->size() << endl;
            NuevaListaOrdenada->erase(NuevaListaOrdenada->begin());
        }

        bitacora+= "\tFue posible condenar a " + to_string(Pecadores->size()) + "\n" ;
        //Kills the humans and send them to the Inferno
        for (int i = 0; i < Pecadores->size(); i++) {
            killhuman(Pecadores->at(i), choosensin);
            bitacora += "\t\t" + Pecadores->at(i)->getSurname() + " " + Pecadores->at(i)->getName() + " " + Pecadores->at(i)->getCountry() + "\n\t";
            bitacora += HoraSistema() + " condenado por " + to_string(Pecadores->at(i)->getSin(choosensin)) + " pecados\n\n";
        }
        
        //Creacion del log de condenacion
        ofstream log;
        
        log.open("Logs/" + givedemonname(choosensin) + to_string(archivenamecounter[choosensin]++) + ".txt");
               
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
    bool infernempty() {
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < Demons[i]->size(); j++) {
                if (!Demons[i]->at(j)->isEmpty()) {
                    return false;
                }
            }
        }
        return true;
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

    void createlog() {
        string str = "";
        if (infernempty()) {
            str += "No hay humanos en el infierno\n";
            ofstream file;
            file.open("Logs/InfernoLog.txt");
            file << "\t El infierno\n";
            file << str;
            file.close();
            return;
        }

        conthumans = 0;
        for(int i = 0; i < 7; i++){
            str += "\tDemonio " + givedemonname(i) + "\n";
            for (int j = 0; j < Demons[i]->size(); j++) {
                if (Demons[i]->at(j)->isEmpty()) {
                    continue;
                }
                str += " Heap de la familia " + (*Demons[i])[j]->surname + " " + (*Demons[i])[j]->country + "\n";
                for (int k = 0; k < Demons[i]->at(j)->getSize(); k++) {
                str += Demons[i]->at(j)->heap[k]->getinfo() + " " + Demons[i]->at(j)->heap[k]->getfriendsstring() + "\n condenado por " + to_string(Demons[i]->at(j)->heap[k]->sins[i]) + "\n\n";
                conthumans++;
                }
            }
        }
        str += "\nTotal de pecadores: " + to_string(conthumans) + "\n";
        str += "Total de pecados: " + to_string(overallsins()) + "\n";
        str += "Promedio de pecados por pecador: " + to_string(overallsins() / conthumans) + "\n";
        Human * human = getmaxsinnerofall();
        str += "Mayor pecador: " + human->getinfo() +" con "+ to_string(human->sins[human->sinininferno]) + " pecados de "+ givedemonname(human->sinininferno) +"\n";


        //crea el archivo S
        ofstream file;
        file.open("Logs/InfernoLog.txt");
        file << "\t El infierno\n";
        file << str;
        file.close();
    }
    
};