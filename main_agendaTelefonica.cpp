#include <iostream>
#include <cstring>
#include "contactos.cpp"
using namespace std;
string opcion_numeros;
string opcion_correos;

struct Contacto {
    char nombre[50];
    char email[50];
    char telefonos[3][15]; // Permitir hasta 3 números de teléfono
    char direcciones[2][100]; // Permitir hasta 2 direcciones
    char notas[200];
}contacto[10], *puntero_contacto=contacto;

int contador_telefonos(int numero_contacto){
	int contador=0;
	for (int var_telefono = 0; var_telefono < 3; var_telefono++) {
			if ((puntero_contacto+numero_contacto)->telefonos[var_telefono][0] != '\0') {
                contador++;
            }
		}
	return contador;
}
int contador_direcciones(int numero_contacto){
	int contador = 0;
	for (int var_direcciones = 0; var_direcciones < 3; var_direcciones++) {
			if ((puntero_contacto+numero_contacto)->telefonos[var_direcciones][0] != '\0') {
                contador++;
            }
		}
	return contador;
}
// Función para agregar un nuevo contacto a la agenda
void agregarContacto( int& numContactos) {
	string opcion_numeros="si";
	string opcion_direccion="si";
    int num;
	num=0;
	cout << "Ingrese el nombre: ";
    cin.ignore();
    cin.getline((puntero_contacto+numContactos)->nombre, 50);

    cout << "Ingrese el email: ";
    cin.getline((puntero_contacto+numContactos)->email, 50);
	
	do{
		if (num<=2){
    	cout << "Ingrese el número de teléfono: ";
    	cin >> (puntero_contacto+numContactos)->telefonos[num] ;
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
    	cin >> (puntero_contacto+numContactos)->direcciones[num];
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
    cin.getline((puntero_contacto+numContactos)->notas, 200);

    numContactos++;
    cout << "Contacto agregado correctamente.\n";
}

// Función para buscar un contacto por nombre
bool buscarContacto(  int numContactos, const char* nombreBusqueda) {
    bool encontrado = false;
    for (int i = 0; i < numContactos; ++i) {
        if (strcmp((puntero_contacto+i)->nombre, nombreBusqueda) == 0) {
        	cout << "-------------------\n";
            cout << "Nombre: " << (puntero_contacto+i)->nombre << endl;
            cout << "Email: " << (puntero_contacto+i)->email << endl;
            cout << "Telefonos: " << (puntero_contacto+i)->telefonos[0] << " " << (puntero_contacto+i)->telefonos[1] << " " << (puntero_contacto+i)->telefonos[2] << endl;
            cout << "Direcciones: " << (puntero_contacto+i)->direcciones[0] << " " << (puntero_contacto+i)->direcciones[1] << endl;
            cout << "Notas: " << (puntero_contacto+i)->notas << endl;
            cout << "-------------------\n";
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Contacto no encontrado.\n";
    }
    return encontrado;
}
void modificarContacto( int numContactos) {
    char nombreBusqueda2[50];
    cout << "Ingrese el nombre del contacto a modificar: ";
    cin.ignore();
    cin.getline(nombreBusqueda2, 50);
    
    cout << "nombreBusqeuda2: " << nombreBusqueda2 << endl;
	bool encontrado = buscarContacto( numContactos, nombreBusqueda2);

    if (encontrado==0) {
        cout << "Contacto no encontrado.\n";
    }else{
	    for (int i = 0; i < numContactos; ++i) {
	        if (strcmp((puntero_contacto+i)->nombre, nombreBusqueda2) == 0) {
	        	
	        	int opcion;
			    do {
			        // Menú de opciones
			        cout << "Que quieres modificar?\n";
			        cout << "1. Nombre\n";
			        cout << "2. Email\n";
			        cout << "3. Numero de telefono\n";
			        cout << "4. Direccion\n";
			        cout << "5. Notas\n";
			        cout << "6. Salir\n";
			        cout << "Ingrese la opción deseada: ";
			        cin >> opcion;
					
			        switch (opcion) {
			            case 1:
			                cout << "Nombre: ";
			                cin.ignore();
	            			cin.getline((puntero_contacto+i)->nombre, 50);
			                break;
			            case 2: {
			                cout << "Email: ";
	            			cin.ignore();
	            			cin.getline((puntero_contacto+i)->email, 50);
			                break;
			            }
			            case 3:
			            	int opcion2;
			                
			                cout << "Teléfonos : "<<endl;
				            for (int j = 0; j < contador_telefonos(i); ++j) {
				                cout<<j+1<<". " << (puntero_contacto+i)->telefonos[j]<<endl;
				            }
			                cout << "Cual quieres cambiar? : ";
				            cin>> opcion2;
			                opcion2--; // Ajustar el índice para que sea base 0

							if (opcion2 >= 0 && opcion2 < contador_telefonos(i)) {
							    cout << "Escribe el número corregido: ";
							    cin.ignore(); // Limpiar el buffer del teclado
							    cin.getline((puntero_contacto + i)->telefonos[opcion2], 15);
							    cout << "Número actualizado correctamente.\n";
							} else {
							    cout << "Índice inválido. No se realizó ningún cambio.\n";
							}
			                break;
			            case 4:
			                cout << "Direcciones : "<<endl;
				            for (int j = 0; j < contador_direcciones(i); ++j) {
				                cout<<j<<". " << (puntero_contacto+i)->direcciones[j];
				            }
			                cout << "Cual quieres cambiar? : ";
				            cin>> opcion2;
				            opcion2--;
				            if (opcion2 >= 0 && opcion2 < contador_telefonos(i)) {
				                cout << "escribe la direccion corregida : ";
				                cin.ignore();
					            cin.getline((puntero_contacto+i)->direcciones[opcion2], 100);
							    cout << "Número actualizado correctamente.\n";
							} else {
							    cout << "Índice inválido. No se realizó ningún cambio.\n";
							}
			                break;  
			            case 5:
			                cout << "Notas adicionales: ";
	            			cin.ignore();
	            			cin.getline((puntero_contacto+i)->notas, 200);
			                break;
			            case 6:
			                cout << "Notas adicionales: ";
			                break;
			                
			            default:
			                cout << "Opcion invalida. Por favor, ingrese una opcion valida.\n";
			        }
	            cout << "Contacto modificado correctamente.\n";
	            break;
			    } while (opcion != 6);
	        }
	    }	
	}
}
// Función para mostrar todos los contactos en la agenda
void mostrarContactos(  int numContactos) {
    cout << "Listado de contactos:\n";
    for (int i = 0; i < numContactos; ++i) {
    	
        cout << "Nombre: " << (puntero_contacto+i)->nombre << endl;
        cout << "Email: " << (puntero_contacto+i)->email << endl;
        cout << "Teléfonos: " << (puntero_contacto+i)->telefonos[0] << " " << (puntero_contacto+i)->telefonos[1] << " " << (puntero_contacto+i)->telefonos[2] << endl;
        cout << "Direcciones: " << (puntero_contacto+i)->direcciones[0] << " " << (puntero_contacto+i)->direcciones[1] << endl;
        cout << "Notas: " << (puntero_contacto+i)->notas << endl;
        cout << "-------------------\n";
    }
}

int main() {
    // Se asume una capacidad máxima de 100 contactos
    int numContactos = 0;

    int opcion;
    string input;
    
    do {
        // Menú de opciones
        cout << "\n1. Agregar contacto\n";
        cout << "2. Buscar contacto\n";
        cout << "3. Mostrar todos los contactos\n";
        cout << "4. Modificar contactos\n";
        cout << "5. Salir\n";
        cout << "Ingrese la opción deseada: ";
        
        cin >> input;
        if (input.find_first_not_of("0123456789") == string::npos) {
    		opcion = stoi(input);

			if (opcion >= 1 && opcion <= 5) {
		        switch (opcion) {
		            case 1:
		                agregarContacto( numContactos);
		                break;
		            case 2: {
		                char nombreBusqueda[50];
		                cout << "Ingrese el nombre a buscar: ";
		                cin.ignore();
		                cin.getline(nombreBusqueda, 50);
		                buscarContacto( numContactos, nombreBusqueda);
		                break;
		            }
		            case 3:
		                mostrarContactos( numContactos);
		                break;
		            case 4:
		                modificarContacto(numContactos);
		                break;  
		            case 5:
		                cout << "Saliendo del programa.\n";
		                break;
		                
		            default:
		                cout << "Opcion invalida. Por favor, ingrese una opcion valida.\n";
		        }
		    } else {
			    cout << "Opción inválida. Por favor, ingrese un número del 1 al 5.\n";
			}
		} else {
		    cout << "Error: Ingrese un número válido del 1 al 5.\n";
		}	
    } while (opcion != 5);

    return 0;
}