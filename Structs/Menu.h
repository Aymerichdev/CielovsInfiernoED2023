TreeOfLife* tree = new TreeOfLife();
HumanWorld* world = new HumanWorld(tree);
Inferno* hell = new Inferno(world);
HeavenTree* heaven = new HeavenTree(world, hell);

void Menu(HumanWorld* world, HeavenTree* heaven, Inferno* hell){
    heaven->start();
    bool IsRunning = 1;
    heaven->start();
    while (IsRunning){
    cout << "\nBienvenido a la batalla entre el infierno y el cielo" << endl;
    cout << "Escoja una opcion" << endl;
    cout << "1. Agregar humanos al mundo" << endl;
    cout << "2. Publicaciones en redes" << endl;
    cout << "3. Buscar humano por id" << endl;
    cout << "4. Busqueda por familia" << endl;
    cout << "5. Condenacion" << endl;
    cout << "6. Salvacion" << endl;
    cout << "7. Ver infierno" << endl;
    cout << "8. Ver cielo" << endl;
    cout << "9. Determinar ganador" << endl;
    cout << "10. Ver el ultimo nivel del arbol de la vida" << endl;
    cout << "11. Salir\n\n" << endl;

    string preopcion;
    getline(cin, preopcion);
    int opcion = NumberCoversion(preopcion);
    if (opcion == -1)
        Menu(world, heaven, hell);
    switch (opcion){
        case 1:
        Addhumans(world);
        break;

        case 2:
        publication(world);
        break;

        case 3:
        searchHuman(world);
        break;

        case 4:
        SearchFamily(world);
        break;

        case 5: 
        condenation(hell);
        break;

        case 6:
        salvation(heaven);
        break;

        case 7:
        hell->createlog();
        cout << "Se ha creado el log del infierno" << endl;
        break;

        case 8:
        heaven->createlog();
        cout << "Se ha creado el log del cielo" << endl;
        break;

        case 9:
        hell->createlog();
        heaven->createlog();
        winner(hell, world, heaven);
        cout << "Se ha creado el archivo con toda la informacion de la batalla" << endl;
        break;

        case 10:
        world->treeOfLife->treeInformation();
        world->printHumansSize();
        break;

        case 11:
        IsRunning = 0;
        break;

    }
    


    
    }
}