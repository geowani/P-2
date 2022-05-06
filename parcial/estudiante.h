#pragma once
#include<mysql.h>
#include<iostream>
#include<string>
#include"dbconexion.h"
using namespace std;
class estudiante
{
private: string nombre, apellido,direccion,genero,correo,fecha;
	   int carnet, telefono;
	   //constructor
public:
	estudiante() {

	}
	estudiante(string nom, string ape, string dir, string g, string cor, string f, int tel, int car) {
		nombre = nom;
		apellido = ape;
		direccion = dir;
		genero = g;
		correo = cor;
		fecha = f;
		tel = telefono;
		carnet = car;
	}
	void setProveedor(string nom) { nombre = nom; }
	void setApellido(string ape) { apellido = ape; }
	void setDireccion(string direc) { direccion = direc; }
	void setGenero(string g) { genero = g; }
	void setCorreo(string cor) { correo = cor;  }
	void setFecha(string f) { fecha = f; }
	void setTelefono(int tel) { telefono = tel; }
	void setNit(int car) { carnet = car; }

	//get (mostrar)
	string getNit() { return nombre; }
	string getProveedor() { return apellido; }
	string getDireccion() { return direccion; }
	string getGenero() { return genero; }
	string getCorreo() { return correo; }
	string getFecha() { return fecha; }
	int getTelefono() { return telefono; }
	int getCarne() { return carnet; }

	void crear() {
		int q_estado;
		dbconexion cn = dbconexion();
		cn.abrir_conexion();
		if (cn.getconectar())
		{
			string t = to_string(telefono);
			string e = to_string(carnet);
			string insert = "INSERT INTO `parcial`.`estudiante`(`carnet`,`nombres`,`apellido`,`direccion`,`telefono`,`genero`,`email`,`fecha_nacimiento`) VALUES('" + e + "'"+ nombre + "'" + apellido + "' " + "' "+ direccion + "'" + t + "' "+ genero + " ' " + correo + "'" + fecha + "'); ";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getconectar(), i);
			if (!q_estado) {

				cout << "Ingreso Exitoso" << endl;
			}
			else
			{
				cout << "Error al ingresar los datos" << endl;
			}
		}
	}
	void leer() {
		int q_estado;
		dbconexion cn = dbconexion();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string consulta = "SELECT `estudiante`.`id_estudiante`,`estudiante`.`carnet`,`estudiante`.`nombres`,`estudiante`.`apellido`,`estudiante`.`direccion`,`estudiante`.`telefono`,`estudiante`.`genero`,`estudiante`.`email`,`estudiante`.`fecha_nacimiento`FROM `parcial`.`estudiante`;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1] << " , " << fila[2] << " , " << fila[3] << " , " << fila[4] << " , " << fila[5] << " , " << fila[6] << " , " << fila[7] << " , " << fila[8] << endl;
				}
			}
			else
			{
				cout << "Error al consultar los datos" << endl;
			}
		}
		else {
			cout << "----Conexion fallida----";
		}
		cn.cerrar_conexion();
	}
	void actualizar(int id) {
		int q_estado;
		dbconexion cn = dbconexion();
		cn.abrir_conexion();
		if (cn.getconectar())
		{
			string t = to_string(telefono);
			string e = to_string(carnet);
			string id_ = to_string(id);
			string insert = "UPDATE `parcial`.`estudiante`SET `carnet` = `" + e + "`, `nombres` = "+ nombre + ", `apellido` = " + apellido + ", `direccion` = " + direccion + ", `telefono` = " + t + ", `genero` = " + genero + ", `email` = " + correo + ", `fecha_nacimiento` = " + fecha + "WHERE `id_estudiante` = " + id_ + " ";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getconectar(), i);
			if (q_estado == 0) {

				cout << "Actualizado Correctamente" << endl;
			}
			else
			{
				cout << "Error al Actualizar los datos" << endl;
			}
		}
	}
	void Eliminar(int id) {
		int q_estado;
		dbconexion cn = dbconexion();
		cn.abrir_conexion();
		if (cn.getconectar())
		{
			string id_ = to_string(id);
			string insert = "DELETE FROM `parcial`.`estudiante`WHERE " + id_ + ";";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getconectar(), i);
			if (!q_estado) {

				cout << "Registro Eliminado" << endl;
			}
			else
			{
				cout << "Error al Eliminar Registro" << endl;
			}
		}
	}

};

