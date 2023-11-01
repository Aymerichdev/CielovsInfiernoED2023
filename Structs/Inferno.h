struct inferno {
    vector<HumanSinHeap>* Demons[7] ;
    //constructor
    inferno() {
        //0 Lucifer Pride 1 Belcebu envy 2 satan wrath 3 abadon lazyness 4 Mammon Greed 5 Beelfegor Gluttony 6 Asmodeo Lust
        for (int i = 0; i < 7; i++) {
            Demons[i] = new vector<HumanSinHeap>();
        }
    }

    //methods
    void Condenation(int choosensin) {
        double a = 0.05;

    }

    void print () {
        for (int i = 0; i < 7; i++) {
            cout << "Demon " << i << endl;
            for (int j = 0; j < Demons[i]->size(); j++) {
                Demons[i]->at(j).print();
            }
        }
    }
};