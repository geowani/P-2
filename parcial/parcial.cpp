#include<iostream>
#include<mysql.h>
#include"dbconexion.h"
#include"estudiante.h"
using namespace std;
int main()
{
    int op;
    cout << "________Menu______" << endl;
    cout << "1. Mostrar registros de tablas" << endl;
    cout << "2. Insertar nuevos registros" << endl;
    cout << "3. Modificar registros" << endl;
    cout << "4. Eliminar registros" << endl;
    cout << "Opcion: ";
    cin >> op;
    if (op == 1) {
        estudiante e = estudiante();
        e.leer();
    }
    if (op == 2) {
    	system("cls");
        string nombre, apellido, direccion, genero, fecha, correo;
        int telefono, id, carne;
        cout << "Ingrese el nombre" << endl;
        cin >> nombre;
        cout << "Ingrese el Apellido" << endl;
        cin >> apellido;
        cout << "Ingrese la Direccion" << endl;
        cin >> direccion;
        cout << "Ingrese el Correo" << endl;
        cin >> correo;
        cout << "Ingrese el Telefono" << endl;
        cin >> telefono;
        cout << "Ingrese el carne" << endl;
        cin >> carne;
        cout << "Ingrese el Genero ( M = Mascululino, F= Femenino) " << endl;
        cin >> genero;
        cout << "Ingrese Fecha de Nacimiento" << endl;
        cin >> fecha;
        estudiante e = estudiante(nombre, apellido, direccion, genero, correo, fecha, telefono, carne);
        e.crear();
        system("PAUSE");
    }
    if (op == 3) {
    	system("cls");
        string nombre, apellido, direccion, genero, fecha, correo;
        int telefono, id, carne;
        cout << "Ingrese el id que desea modificar" << endl;
        cin >> id;
        cout << "Ingrese el nombre" << endl;
        cin >> nombre;
        cout << "Ingrese el Apellido" << endl;
        cin >> apellido;
        cout << "Ingrese la Direccion" << endl;
        cin >> direccion;
        cout << "Ingrese el Correo" << endl;
        cin >> correo;
        cout << "Ingrese el Telefono" << endl;
        cin >> telefono;
        cout << "Ingrese el carne" << endl;
        cin >> carne;
        cout << "Ingrese el Genero ( M = Mascululino, F= Femenino) " << endl;
        cin >> genero;
        cout << "Ingrese Fecha de Nacimiento" << endl;
        cin >> fecha;
        estudiante e = estudiante(nombre, apellido, direccion, genero, correo, fecha, telefono, carne);
        e.actualizar(id);
        system("PAUSE");
    }
    if (op == 4) {
    	system("cls");
        string nombre, apellido, direccion, genero, fecha, correo;
        int telefono, id, carne;
        cout << "Ingrese el id que desea modificar" << endl;
        cin >> id;
        estudiante e = estudiante();
        e.Eliminar(id);
        system("PAUSE");
    }
}
