struct HeavenTree{
    HumanWorld* world;
    Inferno* inferno;
    AngelNode* root;
    vector<string>* angelNames;
    HeavenHashTable* hashTable= new HeavenHashTable();

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
        vector <Angel*> angels;
        for(int i = 0; i < pow(3, size); i++){
            Angel* angel = new Angel(world, inferno, NULL, angelNames->at((rand() % 10)), size + 1, size);
            angels.push_back(angel);
            insert(angel);  
        }
        return angels;
    }

    void salvacion(){
        size++;
        vector<Angel*> angels = fillLevel();
        for(int i = 0; i < angels.size(); i++){
        Human* human = inferno->getmaxsinnerofall();
        human->printHuman();
        if (human == NULL)
            break;
        int sin = human->getbiggersinposition();
        vector<HumanSinHeap*> humansheap = (*inferno->Demons[sin]);
        HumanSinHeap* heap = humansheap[human->heapPosition];
        heap->print();
        heap->deleteHuman(human);
        heap->print();
        Angel* angel = angels.at(i);
        angel->saveHuman(human);
        hashTable->insert(human);   
        }
        
    }
    
    void createlog(){
        string str = "\t El cielo\n";
        for (int i = 0; 0 < 1000; i++){
            if (hashTable->table[i] != NULL){
                str += stringforarchive(hashTable->table[i], str);
            }
        }

        //crea el archivo S
        ofstream file;
        file.open("Logs/HeavenLog.txt");
        file << str;
        file.close();
    }
};