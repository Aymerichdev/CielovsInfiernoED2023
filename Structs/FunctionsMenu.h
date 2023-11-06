
void Addhumans(HumanWorld* world){
    cout << "Actualmente hay "<< world->humansCount << " humanos" << endl;
    cout << "Ingrese la cantidad de humanos que desea crear" << endl;
    cout << "Recuerde que el maximo son 100000" << endl;
    int cantidad;
    string res = "";
    getline(cin, res);
    cantidad = NumberCoversion(res);
    if (cantidad == -1){
        Addhumans(world);
        return;
    }
    world->generateRandomHumans(cantidad);
    cout << "Se han creado " << cantidad << " humanos" << endl;
}

void SearchFamily(HumanWorld* world){
    string apellido, pais;
    cout << "Esta opcion le permite buscar a una familia por su apellido y pais de origen" << endl;
    cout << "Ponga el apellido" << endl;
    getline(cin, apellido);
    cout << "Ponga el pais" << endl;
    getline(cin, pais);
    Familysearch(apellido, pais, world);
    cout << "Se creo el archivo de la familia" + apellido + " " + pais << endl;
}

void condenation(Inferno* hell){
    cout << "Condenacion" << endl;
        cout << "Escoja el demonio que condenara" << endl;
        cout << "1. Lucifer el orgulloso" << endl;
        cout << "2. Belcebu el envidioso" << endl;
        cout << "3. Satan el furioso" << endl;
        cout << "4. Abadon el vago" << endl;
        cout << "5. Mammon el avaro" << endl;
        cout << "6. Belfegor el gloton" << endl;
        cout << "7. Asmodeo el morboso" << endl;
        string preopcion;
        getline(cin, preopcion);
        int opcion = NumberCoversion(preopcion);
        if (opcion == -1){
            condenation(hell);
            return;
        }
        hell->condenation(opcion-1);
}

void salvation(HeavenTree* heaven){
    cout << "Salvacion" << endl;
    cout << "Han habido " << heaven->size - 2 << " salvaciones" << endl;
    cout << "Seguro que desea salvar a los humanos? (y/n)" << endl;
    string res;
    getline(cin, res);
    const char minires = toupper(res[0]);
    if (minires == 'Y'){
        heaven->salvacion();
        cout << "Se han salvado los humanos" << endl;
        cout << "Han habido " << heaven->size - 2 << " salvaciones" << endl;
    }
    else if (res == "n"){
        cout << "No se han salvado los humanos" << endl;
        return;
    }
    else{
        cout << "No se ha entendido la respuesta" << endl;
        salvation(heaven);
    }

}