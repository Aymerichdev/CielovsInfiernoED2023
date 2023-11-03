struct HeavenTree{
    HumanWorld* world;
    Inferno* inferno;
    AngelNode* root;
    vector<string>* angelNames;
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

    void fillLevel(){
        for(int i = 0; i < pow(3, size); i++)
            insert(new Angel(world, inferno, NULL, angelNames->at((rand() % 10)), i + 1, size));
    }

    void salvacion(){
        size++;
        fillLevel();
        // Add search of most sinned human and save it for each angel
    }
};