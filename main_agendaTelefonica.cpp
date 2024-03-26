#include <iostream>
#include <cstring>

using namespace std;
string opcion_numeros;
string opcion_correos;

struct Contacto {
    char nombre[50];
    char email[50];
    char telefonos[3][15]; // Permitir hasta 3 números de teléfono
    char direcciones[2][100]; // Permitir hasta 2 direcciones
    char notas[200];
};

// Función para agregar un nuevo contacto a la agenda
void agregarContacto(Contacto* agenda, int& numContactos) {
	string opcion_numeros="si";
	string opcion_direccion="si";
    int num;
	num=0;
	cout << "Ingrese el nombre: ";
    cin.ignore();
    cin.getline(agenda[numContactos].nombre, 50);

    cout << "Ingrese el email: ";
    cin.getline(agenda[numContactos].email, 50);
	
	do{
		if (num<=2){
    	cout << "Ingrese el número de teléfono: ";
    	cin >> agenda[numContactos].telefonos[num] ;
    	cout << "¿desea agregar otro numero?(si/no): ";
    	cin >> opcion_numeros;
    	num++;
		}else{
    		cout << "Lo lamento superaste el limite de numeros disponibles";
			opcion_numeros="no";
		}	
	}while(opcion_numeros != "no");
	num=0;
	do{
		if (num<=1){
		cout << "Ingrese la direccion: ";
    	cin >> agenda[numContactos].direcciones[num];
    	cout << "¿desea agregar otra direccion?(si/no): ";
    	cin >> opcion_direccion;
    	num++;	
		}else{
    		cout << "Lo lamento superaste el limite de direcciones disponibles";
			opcion_direccion="no";
		}
    		
	}while(opcion_direccion != "no");


    cout << "Ingrese notas adicionales: ";
    cin.ignore();
    cin.getline(agenda[numContactos].notas, 200);

    numContactos++;
    cout << "Contacto agregado correctamente.\n";
}

// Función para buscar un contacto por nombre
bool buscarContacto(const Contacto* agenda, int numContactos, const char* nombreBusqueda) {
    bool encontrado = false;
    for (int i = 0; i < numContactos; ++i) {
        if (strcmp(agenda[i].nombre, nombreBusqueda) == 0) {
            cout << "Nombre: " << agenda[i].nombre << endl;
            cout << "Email: " << agenda[i].email << endl;
            cout << "Telefonos: " << agenda[i].telefonos[0] << ", " << agenda[i].telefonos[1] << ", " << agenda[i].telefonos[2] << endl;
            cout << "Direcciones: " << agenda[i].direcciones[0] << ", " << agenda[i].direcciones[1] << endl;
            cout << "Notas: " << agenda[i].notas << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Contacto no encontrado.\n";
    }
    return encontrado;
}
void modificarContacto(Contacto* agenda, int numContactos) {
    char nombreBusqueda2[50];
    cout << "Ingrese el nombre del contacto a modificar: ";
    cin.ignore();
    cin.getline(nombreBusqueda2, 50);
    
    cout << "nombreBusqeuda2: " << nombreBusqueda2 << endl;
	bool encontrado = buscarContacto(agenda, numContactos, nombreBusqueda2);

    if (encontrado==0) {
        cout << "Contacto no encontrado.\n";
    }else{
	    for (int i = 0; i < numContactos; ++i) {
	        if (strcmp(agenda[i].nombre, nombreBusqueda2) == 0) {
	            cout << "Contacto encontrado. Ingrese los nuevos datos:\n";
	            cout << "Nombre: ";
	            cin.getline(agenda[i].nombre, 50);
	
	            cout << "Email: ";
	            cin.getline(agenda[i].email, 50);
	
	            cout << "Teléfonos (hasta 3 separados por espacio): ";
	            for (int j = 0; j < 3; ++j) {
	                cin >> agenda[i].telefonos[j];
	            }
	
	            cout << "Direcciones (hasta 2 separadas por espacio): ";
	            for (int j = 0; j < 2; ++j) {
	                cin >> agenda[i].direcciones[j];
	            }
	
	            cout << "Notas adicionales: ";
	            cin.ignore();
	            cin.getline(agenda[i].notas, 200);
	
	            cout << "Contacto modificado correctamente.\n";
	            break;
	        }
	    }	
	}
}
// Función para mostrar todos los contactos en la agenda
void mostrarContactos(const Contacto* agenda, int numContactos) {
    cout << "Listado de contactos:\n";
    for (int i = 0; i < numContactos; ++i) {
        cout << "Nombre: " << agenda[i].nombre << endl;
        cout << "Email: " << agenda[i].email << endl;
        cout << "Teléfonos: " << agenda[i].telefonos[0] << ", " << agenda[i].telefonos[1] << ", " << agenda[i].telefonos[2] << endl;
        cout << "Direcciones: " << agenda[i].direcciones[0] << ", " << agenda[i].direcciones[1] << endl;
        cout << "Notas: " << agenda[i].notas << endl;
        cout << "-------------------\n";
    }
}

int main() {
    Contacto* agenda = new Contacto[100]; // Se asume una capacidad máxima de 100 contactos
    int numContactos = 0;

    int opcion;
    do {
        // Menú de opciones
        cout << "\n1. Agregar contacto\n";
        cout << "2. Buscar contacto\n";
        cout << "3. Mostrar todos los contactos\n";
        cout << "4. Modificar contactos\n";
        cout << "5. Salir\n";
        cout << "Ingrese la opción deseada: ";
        
        cin >> opcion;
		
        switch (opcion) {
            case 1:
                agregarContacto(agenda, numContactos);
                break;
            case 2: {
                char nombreBusqueda[50];
                cout << "Ingrese el nombre a buscar: ";
                cin.ignore();
                cin.getline(nombreBusqueda, 50);
                buscarContacto(agenda, numContactos, nombreBusqueda);
                break;
            }
            case 3:
                mostrarContactos(agenda, numContactos);
                break;
            case 4:
                modificarContacto(agenda,numContactos);
                break;  
            case 5:
                cout << "Saliendo del programa.\n";
                break;
                
            default:
                cout << "Opcion invalida. Por favor, ingrese una opcion valida.\n";
        }
    } while (opcion != 5);

    delete[] agenda; // Liberar memoria dinámica
    return 0;
}