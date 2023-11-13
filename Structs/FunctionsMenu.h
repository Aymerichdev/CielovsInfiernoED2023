
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

void searchHuman(HumanWorld* world){
    if (world->humansCount == 0){
        cout << "No hay humanos" << endl;
        return;
    }
    cout << "Busqueda de humano" << endl;
    cout << "Ingrese el id del humano que desea buscar" << endl;
    string preid;
    getline(cin, preid);
    int id = NumberCoversion(preid);
    if (id == -1){
        searchHuman(world);
        return;
    }
    Human* human = world->getHuman(id);
    if (human == NULL){
        cout << "No se encontro el humano" << endl;
        return;
    }
    cout << endl;
    human->printHuman();
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
        string mail = "vaymerich@estudiantec.cr";
        string path = "Logs/" + hell->givedemonname(opcion-1) + to_string(hell->archivenamecounter[opcion-1]++) + ".txt";
        sendmail(path, mail);
}

void salvation(HeavenTree* heaven){
    cout << "Salvacion" << endl;
    cout << "Han habido " + to_string(heaven->size-1) + " salvaciones" << endl;
    cout << "Seguro que desea salvar a los humanos? (y/n)" << endl;
    string res;
    getline(cin, res);
    const char minires = toupper(res[0]);
    if (minires == 'Y'){
        heaven->salvacion();
        cout << "Se han salvado los humanos" << endl;
        cout << "Han habido " + to_string(heaven->size-1) + " salvaciones" << endl;
    }
    else if (minires == 'N'){
        cout << "No se han salvado los humanos" << endl;
        return;
    }
    else{
        cout << "No se ha entendido la respuesta" << endl;
        salvation(heaven);
    }
    string mail = "vaymerich@estudiantec.cr";
    string path = "Logs/Salvacion" + to_string(heaven->contdelogs) + ".txt";
    sendmail(path, mail);

}

void individualpublication(HumanWorld* world){
    cout << "Publicacion indivual" << endl;
    cout << "Escoja la red social en la que se va a publicar" << endl;
    cout << "1. Instagram de orgullosos" << endl;
    cout << "2. Facebook de envidiosos" << endl;
    cout << "3. Twitter de enojados" << endl;
    cout << "4. Netflix de perezosos" << endl;
    cout << "5. Linkedln de avaros" << endl;
    cout << "6. Pedidos ya de glotones" << endl;
    cout << "7. Por... Tinder de lujoriosos" << endl;  
    string preopcion;
    getline(cin, preopcion);
    int opcion = NumberCoversion(preopcion);
    if (opcion == -1){
        individualpublication(world);
        return;
    }


    cout << "Red social escogida" << endl;      
    cout << "Ingrese el id del humano que va a hacer la publicacion" << endl;
    
    string preid;
    getline(cin, preid);
    int id = NumberCoversion(preid);
    if (id == -1){
        individualpublication(world);
        return;
    }

    for (int i = 0; i < world->humansCount; i++){
        if (world->humans[i]->getId() == id){
            if (world->humans[i]->state != 0){
                cout << "El humano esta muerto" << endl;
                individualpublication(world);
                return;
            }
        world->humans[i]->publication(opcion-1);
        cout << "Se ha publicado" << endl;
        return;
            
        }
    }
}
string givebelief(int belief){
    switch(belief){
        case 1:
        return "Cristianismo";
        break;

        case 2:
        return "Judaismo";
        break;

        case 3:
        return "Testigo de Jehova";
        break;

        case 4:
        return "Evangelismo";
        break;

        case 5:
        return "Budismo";
        break;

        case 6:
        return "Ateismo";
        break;

        case 7:
        return "Agnostico";
        break;

        case 8:
        return "Panteismo";
        break;

        case 9:
        return "Hinduismo";
        break;

        case 10:
        return "Islam";
        break;

        default:
        return "No tiene religion";
        break;
    
    }
}

void publicationreligion(HumanWorld* world){
    int cont = 0;
    cout << "Publicacion por religion" << endl;
    cout << "Esta publica en la red social favorita de todos los creyentes de una religion" << endl;
    cout << "Escoja la religion" << endl;
    cout << "1. Cristianismo" << endl;
    cout << "2. Judaismo" << endl;
    cout << "3. Testigo de Jehova" << endl;
    cout << "4. Evangelismo" << endl;
    cout << "5. Budismo" << endl;
    cout << "6. Ateismo" << endl;
    cout << "7. Agnostico" << endl;
    cout << "8. Panteismo" << endl;
    cout << "9. Hinduismo" << endl;
    cout << "10. Islam" << endl;
    string preopcion;
    getline(cin, preopcion);
    int opcion = NumberCoversion(preopcion);
    if (opcion == -1){
        publicationreligion(world);
        return;
    }
    string religion = givebelief(opcion);

    cout << "Religion escogida" << endl;

    for (int i = 0; i < world->humansCount; i++){
        if (world->humans[i]->getBelief() == religion){
            if (world->humans[i]->state != 0)
                continue;
            world->humans[i]->publication(world->humans[i]->getfavoritesocialnetwork());
            cont++;
        }
    }
    cout << "Se han hecho " << cont << " publicaciones" <<endl;
}

void publicationfamily(HumanWorld* world){
    int cont = 0;
    cout << "Publicacion por familia" << endl;
    cout << "Esta publica en la red social favorita de todos los miembros de una familia" << endl;
    cout << "Se le recomienda que confirme la existencia de la familia con el metodo de buscar familia" << endl;
    cout << "Debe escojer un N el cual es la cantidad de redes sociales en las que publicaran basado en su favoritismo" << endl;
    cout << "Debe ser un N entre 1 y 7" << endl;
    string preopcion;
    getline(cin, preopcion);
    int opcion = NumberCoversion(preopcion);
    if (opcion == -1)
        publicationfamily(world);
    if (opcion > 7){
        cout << "Debe ser un N entre 1 y 7" << endl;
        publicationfamily(world);
    }
    cout << "N escogido" << endl;
    cout << "Ingrese el apellido de la familia" << endl;
    string apellido;
    getline(cin, apellido);
    cout << "Ingrese el pais de la familia" << endl;
    string pais;
    getline(cin, pais);
    cout << "Familia escogida" << endl;
    vector <Human*> family;
    for (int i = 0; i < world->humansCount; i++){
        if ( Uppercase(world->humans[i]->getSurname()) == Uppercase(apellido) && Uppercase(world->humans[i]->getCountry()) == Uppercase(pais)){
            family.push_back(world->humans[i]);
        }
    }
    for (int i = 0; i < family.size(); i++){
        int temporalarray[7] = {family[i]->socialNetworkslike[0], family[i]->socialNetworkslike[1], family[i]->socialNetworkslike[2], family[i]->socialNetworkslike[3], family[i]->socialNetworkslike[4], family[i]->socialNetworkslike[5], family[i]->socialNetworkslike[6]};
        for (int j = 0; j < opcion; j++){
            if (family[i]->state != 0)
                break;
            int max = family[i]->getfavoritesocialnetwork();
            family[i]->publication(max);
            family[i]->socialNetworkslike[max] = 0;
            cont++;
        }
        for (int j = 0; j < 7; j++){
            family[i]->socialNetworkslike[j] = temporalarray[j];
        }
    }
    cout << "Se han hecho " << cont << " publicaciones" <<endl;
}

void publicationjob(HumanWorld* world){
    int cont = 0;
    cout << "Publicacion por trabajo" << endl;
    cout << "Esta publica en la red social favorita de todos los humanos de un trabajo" << endl;
    cout << "Debe escojer un N el cual es la cantidad de redes sociales en las que publicaran basado en su favoritismo" << endl;
    cout << "Debe ser un N entre 1 y 7" << endl;
    string preopcion;
    getline(cin, preopcion);
    int opcion = NumberCoversion(preopcion);
    if (opcion == -1)
        publicationfamily(world);
    if (opcion > 7){
        cout << "Debe ser un N entre 1 y 7" << endl;
        publicationfamily(world);
    }
    cout << "N escogido" << endl;
    cout << "Ingrese el trabajo" << endl;
    cout << "Se le recomienda ver el archivo de trabajos para ver los trabajos disponibles" << endl;
    string trabajo;
    getline(cin, trabajo);
    cout << "Trabajo escogido" << endl;

    vector <Human*> workers;
    for (int i = 0; i < world->humansCount; i++){
        if (Uppercase(world->humans[i]->getJob()) == Uppercase(trabajo))
            workers.push_back(world->humans[i]);
        
    }
    for (int i = 0; i < workers.size(); i++){
        int temporalarray[7] =  {workers[i]->socialNetworkslike[0], workers[i]->socialNetworkslike[1], workers[i]->socialNetworkslike[2], workers[i]->socialNetworkslike[3], workers[i]->socialNetworkslike[4], workers[i]->socialNetworkslike[5], workers[i]->socialNetworkslike[6]};
        for (int j = 0; j < opcion; j++){
            if (workers[i]->state != 0)
                break;
            int max = workers[i]->getfavoritesocialnetwork();
            workers[i]->publication(max);
            workers[i]->socialNetworkslike[max] = 0;
            cont++;
        }
        for (int j = 0; j < 7; j++){
            workers[i]->socialNetworkslike[j] = temporalarray[j];
        }
    }
    cout << "Se han hecho " << cont << " publicaciones" <<endl;
}

void publication(HumanWorld* world){
    if (world->humansCount == 0){
        cout << "No hay humanos" << endl;
        return;
    }
    cout << "Publicaciones" << endl;
    cout << "Escoja una opcion" << endl;
    cout << "1.Publicacion indivual" << endl;
    cout << "2.Publicacion por religion" << endl;
    cout << "3.Por profesion" << endl;
    cout << "4.Por familia" << endl;
    string preopcion;
    getline(cin, preopcion);
    int opcion = NumberCoversion(preopcion);
    switch (opcion){
            case 1:
            individualpublication(world);
            break;

            case 2:
            publicationreligion(world);
            break;

            case 3:
            publicationjob(world);
            break;

            case 4:
            publicationfamily(world);
            break;

            default:
            cout << "Opcion invalida" << endl;
            publication(world);
            break;
        }
}