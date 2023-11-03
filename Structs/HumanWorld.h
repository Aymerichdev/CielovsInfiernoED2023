struct HumanWorld{
    // Attributes
    // Sorted by id
    Human* humans[100000];
    vector<int> humansIds;
    int humansCount;
    TreeOfLife* treeOfLife;

    // Human data
    vector<string>* names;
    vector<string>* surnames;
    vector<string>* countries;
    vector<string>* beliefs;
    vector<string>* jobs;

    HumanWorld(){
        humansCount = 0;
        srand(time(0));
        for (int i = 0; i < 100000; i++){
            humans[i] = NULL;
            humansIds.push_back(i);
        }
        treeOfLife = new TreeOfLife();
        loadHumanData();
    }

    HumanWorld(TreeOfLife* _treeOfLife){
        humansCount = 0;
        srand(time(0));
        for (int i = 0; i < 100000; i++){
            humans[i] = NULL;
            humansIds.push_back(i);
        }
        treeOfLife = _treeOfLife;
        loadHumanData();
    }

    void loadHumanData(){
        names = readFileIntoArray("Data/names.txt", 30);
        surnames = readFileIntoArray("Data/surnames.txt", 5);
        countries = readFileIntoArray("Data/countries.txt", 5);
        beliefs = readFileIntoArray("Data/beliefs.txt", 10);
        jobs = readFileIntoArray("Data/jobs.txt", 10);
    }

    void addHuman(Human* humanToAdd){
        if (humansCount == 0){
            humans[0] = humanToAdd;
            humanToAdd -> setArrayPosition(0);
            humansCount++;
            return;
        }
        int id = humanToAdd -> getId();
        for (int i = 0; i < humansCount; i++){
            if (humans[i]->getId() < id){
                continue;
            }else if (humans[i]->getId() > id){
                for (int j = humansCount; j > i; j--){
                    humans[j] = humans[j - 1];
                    humans[j] -> setArrayPosition(j);
                }
                humans[i] = humanToAdd;
                humanToAdd -> setArrayPosition(i);
                humansCount++;
                return;
            }
        }
        humans[humansCount++] = humanToAdd;
    }

    Human* getHuman(int id){
        for (int i = 0; i < humansCount; i++){
            if (humans[i]->getId() == id){
                return humans[i];
            }
        }
        return NULL;
    }

    Human* generateRandomHuman(){
        // TODO: has to be changed to generate a random human, including all attributes
        int randIndex = rand() % humansIds.size();
        // ID
        int idHuman = humansIds[randIndex];
        humansIds.erase(humansIds.begin() + randIndex);
        // Name
        randIndex = rand() % names->size();
        string nameHuman = names->at(randIndex);
        // Surname
        randIndex = rand() % surnames->size();
        string surnameHuman = surnames->at(randIndex);
        // Country
        randIndex = rand() % countries->size();
        string countryHuman = countries->at(randIndex);
        // Belief
        randIndex = rand() % beliefs->size();
        string beliefHuman = beliefs->at(randIndex);
        // Job
        randIndex = rand() % jobs->size();
        string jobHuman = jobs->at(randIndex);
        // Birthdate
        string birthdateHuman = randomBirthdate();
        return new Human(idHuman, nameHuman, surnameHuman, countryHuman, beliefHuman, jobHuman, birthdateHuman);
    }

    int getTreeSize(){
        int treeSize = humansCount * 0.01;
        while (!(treeSize && (0 == (treeSize & (treeSize - 1)))))
            treeSize++;
        if (treeSize != 1) treeSize--;
        cout << "Tree size: " << treeSize << endl;
        return treeSize;
    }

    void insertTree(Human* humanArray[], int start, int end, int size, int levelMax, int level = 0){
        if (levelMax == 1){
            treeOfLife->insert(humanArray[(humansCount - 1) / 2]);
            return;
        }
        if (start >= end || level >= levelMax){
            if (treeOfLife->getRoot() == NULL || treeOfLife->getRoot()->getHuman() == NULL)
                treeOfLife->insert(humanArray[start]);
            return;
        }
        int middle = (start + end) / 2;
        // Check if the middle is a valid human, in other words, if it is not in hell or heaven
        while (humanArray[middle]->getState() != 0){
            middle--;
            if (middle < start){
                return;
            }
        }
        treeOfLife->insert(humanArray[middle]);
        level++;
        insertTree(humanArray, start, middle, size, levelMax, level);
        insertTree(humanArray, middle + 1, end, size, levelMax, level);
    }

    void buildTree(){
        treeOfLife->emptyTree();
        int treeSize = getTreeSize();
        insertTree(humans, 0, humansCount - 1, treeSize, (int)log2(treeSize + 1));
    }

    void generateRandomHumans(int amount){
        if (amount + humansCount > 100000){
            cout << "Not enough space for " << amount << " humans" << endl;
            return;
        }
        for (int i = 0; i < amount; i++){
            addHuman(generateRandomHuman());
        }
        buildTree();
    }

    void printHumans(){
        for (int i = 0; i < humansCount; i++){
            if (humans[i] == NULL){
                break;
            }else{
                humans[i]->printHuman();
            }
        }
        cout << endl;
    }
};