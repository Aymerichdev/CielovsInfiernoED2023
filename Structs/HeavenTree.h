struct HeavenTree{
    HumanWorld* world;
    Inferno* inferno;
    AngelNode* root;
    vector<string>* angelNames;
    HeavenHashTable* hashTable= new HeavenHashTable();
    int contdelogs = 1;
    int conthumans= 0;
    int size;
    HeavenTree(){
        world = NULL;
        inferno = NULL;
        root = NULL;
        size = 0;
    }

    HeavenTree(HumanWorld* _world, Inferno* _inferno){
        world = _world;
        inferno = _inferno;
        root = NULL;
        size = 0;
    }

    HeavenTree(HumanWorld* _world, Inferno* _inferno, AngelNode* _root){
        world = _world;
        inferno = _inferno;
        root = _root;
        size = 0;
    }

    AngelNode* getRoot(){
        return root;
    }

    void start(){
        size = 0;
        root = new AngelNode(new Angel(world, inferno, NULL, "God", 1, size++));
        root->setLeft(new AngelNode(new Angel(world, inferno, NULL, "Seraphim", 1, size)));
        root->setCenter(new AngelNode(new Angel(world, inferno, NULL, "Cherub", 2, size)));
        root->setRight(new AngelNode(new Angel(world, inferno, NULL, "Throne", 3, size)));
        angelNames = readFileIntoArray("Data/angelNames.txt", 10);
    }

    void insert(Angel* _angel){
        insert(_angel, root);
    }

    bool insert(Angel* _angel, AngelNode* _node){
        if (_node == NULL)
            return true;
        else if (_node->getAngel()->generation == _angel->generation - 1){
            return _node->insertEmpty(_angel);
        }else{
            return insert(_angel, _node->getLeft()) || insert(_angel, _node->getCenter()) || insert(_angel, _node->getRight());
        }       
    }

    vector<Angel*> fillLevel(){
        vector <Angel*> angels = {};
        int newlevel = pow(3, size);
        for(int i = 0; i < newlevel; i++){
            Angel* angel = new Angel(world, inferno, NULL, angelNames->at((rand() % 10)), size + 1, size);
            angels.push_back(angel);
            insert(angel);  
        }
        return angels;
    }

    void salvacion(){
        size++;
        vector<Angel*> angels = fillLevel();
        int newlevel = pow(3, size);
        string str = "\tLog de salvacion\n\n\tSe salvaran " + to_string(newlevel) + " humanos\n\n";
        
        for(int i = 0; i < angels.size(); i++){
        
        Human* human = inferno->getmaximunsinner();

        if (human == NULL){
            cout << "No hay humanos en el infierno, un humano dio nulo" << endl;
            str += HoraSistema() + " " + "la salvacion se detuvo en " + to_string(i) + " por falta de humanos en el infierno\n";
            break;
        }

        int sin = human->sinininferno;
        
        vector<HumanSinHeap*> humansheap = (*inferno->Demons[sin]);
        if (humansheap.size() == 0){
        cout << "No hay humanos en el infierno, dio 0 el size" << endl;
        str += HoraSistema() + " " + "la salvacion se detuvo en " + to_string(i) + " por falta de humanos en el infierno\n";
        break;
        }

        HumanSinHeap* heap = humansheap[human->heapPosition];
        if (heap->isEmpty()){
        cout << "No hay humanos en el infierno, me dieron un heap vacio " << endl;
        str += HoraSistema() + " " + "la salvacion se detuvo en " + to_string(i) + " por falta de humanos en el infierno\n";
        break;
        }
        
        
        heap->deleteHuman(human);
        Angel* angel = angels.at(i);
        angel->saveHuman(human);
        hashTable->insert(human);
        str += HoraSistema() + " " + angel->name +" generacion "+ to_string(size) + " salvo a " + human->getinfo() +  " por " + to_string(human->totalsins) +" pecados" +  "\n";
        }
        //crea el archivo S
        ofstream file;
        file.open("Logs/Salvacion"+ to_string(contdelogs++) +".txt");
        file << str;
        file.close();
    }
    
    void createlog(){
        string str = "";
        conthumans = 0;
        for (int i = 0; i <= 999; i++){
            int j = hashTable->table[i]->key;
            if (j != 0){
                conthumans+= sizeavl(hashTable->table[i]);
                str += "\t\t\tBucket " + to_string(i) + "\n\n" +stringforarchive(hashTable->table[i]); + "\n\n";
            }
        }
        //crea el archivo S
        ofstream file;
        file.open("Logs/HeavenLog.txt");
        file << "\t\t\t El cielo\n";
        file << "\t\tCantidad de humanos salvados: " << conthumans << "\n\n";
        file << str;
        file.close();
        
    }
};