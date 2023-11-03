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
        for (int i = 0; i < Pecadores->size(); i++) {
            NuevaListaOrdenada->erase(NuevaListaOrdenada->begin());
        }

        //Kills the humans and send them to the Inferno
        for (int i = 0; i < Pecadores->size(); i++) {
            cout << Pecadores->at(i)->getSurname() << endl;
            killhuman(Pecadores->at(i), choosensin);
        }
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