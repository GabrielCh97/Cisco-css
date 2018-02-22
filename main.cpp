#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <string.h>


using namespace std;

void menu_pro();
void Anadir();
void Eliminar();
void Editar();
void Ver();
void Ver_Todo();
void ingreso();
void crear();
void menu_user();
void factura();
void factura_con();

int factucon=0;
int contapro=0;
int contauser = 0;
char la[10];


//produnctos a devolver
struct informacion{
char Nombre_Producto [25];
char Fecha_ingreso[25];
int cantidad;
char precio;
}
pro_sis[50];


//estructura crear usuario
struct usuario{
	int ci;
	char nombre[20];
	int contra;
}user_new[10];

struct factura{
	int ci;
	char nombre[20];
	int telefono;
	int fecha;
	int precio;
}factu_new[10];


//titulo
int main(){ 
	system("mode con: cols=170 lines=76");
	MessageBox(0,"Welcome","HOLA",0);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout<<"\n\n\n";
	cout<<"\t\t____________________________________________________________________________\n\n";
	cout<<"\t\t############\t############\t############\t############\t############\n";
	cout<<"\t\t     ##     \t     ##	 \t##          \t##          \t##        ##\n";
	cout<<"\t\t     ##     \t     ##	 \t##          \t##          \t##        ##\n";
	cout<<"\t\t     ##     \t     ##	 \t##          \t##          \t##        ##\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	cout<<"\t\t     ##     \t     ##     \t##          \t##          \t##        ##\n";
	cout<<"\t\t     ##     \t     ##     \t############\t##          \t##        ##\n";
	cout<<"\t\t     ##     \t     ##     \t          ##\t##          \t##        ##\n";
	cout<<"\t\t     ##     \t     ##	 \t          ##\t##          \t##        ##\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout<<"\t\t     ##     \t     ##     \t          ##\t##          \t##        ##\n";
	cout<<"\t\t     ##     \t     ##     \t          ##\t##          \t##        ##\n";
	cout<<"\t\t############\t     ##     \t############\t############\t############\n\n";
	cout<<"\t\t____________________________________________________________________________\n\n";
	cout<<"\t\t\t\t\t\t Primero A \n";
	cout<<"\t\t____________________________________________________________________________\n";
	cout<<"\t\t____________________________________________________________________________\n";
	system("pause > nul");
	system("cls");
	menu_user();
	return 0;
}
//final titulo

//parte opciones
void menu_user(){
	int op=0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	cout<<"\n\n\n\n";
	cout<<"\n\t\t\t\t--_______________________________________--";
	cout<<"\n\t\t\t\t--_______________________________________--";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	cout<<"\n\t\t\t\t|||\t\t            \t\t|||";
	cout<<"\n\t\t\t\t|||\t\t 1.- ingreso\t\t|||";
	cout<<"\n\t\t\t\t|||\t\t 2.- crear  \t\t|||";
	cout<<"\n\t\t\t\t|||\t\t 3.- salir  \t\t|||";
	cout<<"\n\t\t\t\t|||\t\t            \t\t|||";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	cout<<"\n\t\t\t\t--_______________________________________--";
	cout<<"\n\t\t\t\t--_______________________________________--";
	cout<<"\n\t\t\t\t\t\t ingrese opcion:  ";
	cin>>op;
	switch(op){
		case 1:
			system("cls");
      		ingreso();
		break;
		case 2:
			system("cls");
      		crear();
		break;
		case 3:
			system("cls");
      		cout <<"gracias";
      		MessageBox(0,"Gracias","Adios",0);
		break;
		default:
			MessageBox(0,"Operacion incorrecta. Escriba nuevamente la operacion a realizar","error",0);
   			system("pause>nul");
			system("cls");
      		menu_user();
      	break;
	}
}
//parte final opciones

//login
void ingreso(){
	int i=0,u=999,us,con,j=0;
	cout << "\t\t\tIngrese la cedula :";
	cin >> us;
	i=0;
	u=999;
	while(i<=10){
		if(us==user_new[i].ci){
			u=i;
		}
		i++;
	}
	if(us==user_new[u].ci){
		cout <<"\t\t\tSeñor(a) " << user_new[u].nombre;
		j=0;
		int s=0;
		while(j<=3){
			cout << "\n\t\t\tIngrese la contraseña: "; cin>> con;
			if(con==user_new[u].contra){
				system("cls");
				menu_pro();
			}
			else{
				MessageBox(0,"***La contraseña no es correcta***","Error",0);
				s=1;
				system("pause > nul");
				system("cls");
			}
			j=j+1;
			if(j==3){
				MessageBox(0,"***A exedido sus intentos***","Error",0);
				cout << "\t\t\t A exedido sus intentos sr(a) "<< user_new[u].nombre;
				system("pause > nul");
				system("cls");
				menu_user();
			}
		}
	}
	else{
		char op;
		MessageBox(0,"Usuario no existe","Error",0);
		cout << "\t\t\tDesea crear un usuario s/n: ";
		cin >> op;
		if(op=='s'){
			system("cls");
			crear();
		}
		else{
			system("cls");
			menu_user();
		}
	}
}
//fin login

//parte inicial crear usuario
void crear(){
	int op;
		cout << "\t\t\tIngrese la informacion requerida. \n";
		cout << "\t\t\tIngrese la Cedula: ";
		cin >> user_new[contauser].ci;
		cout << "\t\t\tIngrese el Nombre: ";
		cin >> user_new[contauser].nombre;
		cout << "\t\t\tIngrese la contraseña solo numeros ";
		cin >> user_new[contauser].contra;
   {
   		ofstream archivo;
   		archivo.open("registrousuarios.txt", ios::app);
   		archivo << "Cedula Usuario: " << user_new[contauser].ci << endl;
   		archivo << "Nombre Usuario: " << user_new[contauser].nombre << endl;
   		archivo << "Contraseña Usuario: " << user_new[contauser].contra<< endl;
   		archivo.close();
   		contauser++;
   		MessageBox(0,"Usuario añadido correctamente","Error",0);
	}
	system("pause > nul");
	system("cls");
   	menu_user();
}
//parte final crear usuario

//funciones del menu pro
void menu_pro(){
	int op=0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
   cout<<"\t\t      __________________________________________________________ "<<endl;
   cout<<"\t\t                           Menu Devoluciones                     "<<endl;
   cout<<"\t\t      ---------------------------------------------------------- "<<endl;
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
   cout<<"\t\t                        1. Anadir un Producto.                   "<<endl;
   cout<<"\t\t                       2. Eliminar un Producto                   "<<endl;
   cout<<"\t\t                        3. Editar un Producto.                   "<<endl;
   cout<<"\t\t                      4. informacion de producto				   "<<endl;
   cout<<"\t\t                        5. lista de productos.                   "<<endl;
   cout<<"\t\t                        6. abrir archivo plano. 			       "<<endl;
   cout<<"\t\t                              7. Facturar.				       "<<endl;
   cout<<"\t\t                         8. Registro Facturas.			       "<<endl;
   cout<<"\t\t                          9. Salir programa.                     "<<endl;
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
   cout<<"\t\t      __________________________________________________________ "<<endl;
   cout<<"\t\t       Numero de operacion a realizar:";cin>>op;cout<<  "|"<<endl;
   cout<<"\t\t      __________________________________________________________|"<<endl;
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);

   switch(op){
   		case 1:
   			system("cls");
      		Anadir();
      	break;
      	case 2:
      		system("cls");
      		Eliminar();
      	break;
      	case 3:
      		system("cls");
      		Editar();
      	break;
      	case 4:
      		system("cls");
      		Ver();
      	break;
      	case 5:
      		system("cls");
      		Ver_Todo();
      	break;
      	case 6:
      		system("cls");
      		system("registroDevDevolucion.txt");
      		menu_pro();
      	break;
      	case 7:
      		system("cls");
      		factura();
      	break;
      	case 8:
      		factura_con();
      	break;
      	case 9:
      		exit(0);
      	break;
      	default:
      		MessageBox(0,"Operacion incorrecta. Escriba nuevamente la operacion a realizar","Error",0);
      		system("pause > nul");
   	  		system("cls");
      		menu_pro();
      	break;
    }
} //termina el main
//fin funciones del menu pro

//funciones añadir
void Anadir(){
cout << "\t\t\tEscriba la siguiente informacion del Producto.";
   cout <<endl<< "\t\t\t1. Nombre producto: ";
   cin >> pro_sis[contapro].Nombre_Producto;
   cout << "\t\t\t2. Fecha Ingreso: ";
   cin >> pro_sis[contapro].Fecha_ingreso;
   cout << "\t\t\t3. Cantidad: ";
   cin >> pro_sis[contapro].cantidad;
   cout << "\t\t\t4. Precio: ";
   cin >> pro_sis[contapro].precio;

   {
// Entrada/Salida a archivo de texto "registroDev.txt"
   ofstream archivo;
   		archivo.open("registroproductos.txt", ios::app);
   		archivo << "Nombre Producto: " << pro_sis[contapro].Nombre_Producto << endl;
   		archivo << "Fecha ingreso: " << pro_sis[contapro].Fecha_ingreso << endl;
   		archivo << "Cantidad: " << pro_sis[contapro].cantidad<< endl;
  		archivo << "Precio: "<< pro_sis[contapro].precio<< endl;
   		archivo.close();
   		// Fin de Entrada/Salida a archivo de registroDev .txt"
   		contapro++;
   		MessageBox(0,"Producto creado correctamente","Proceso",0);
   		system("pause > nul");
   		system("cls");
   		menu_pro();
   }
}
//fin funciones añadir

//funcion eliminar
void Eliminar(){
	int eli;
   	cout << "Numero de registro para eliminar: ";
   	cin >> eli;
   	eli--;
	if (eli < contapro){
   		cout <<endl<< "\t\t\t1. Producto: ";
  		cout << pro_sis[eli].Nombre_Producto;
   		cout <<endl<< "\t\t\t2. Fecha ingreso: ";
   		cout << pro_sis[eli].Fecha_ingreso;
   		cout <<endl<< "\t\t\t3. Cantidad: ";
   		cout << pro_sis[eli].cantidad;
   		cout <<endl<< "\t\t\t4. Precio: ";
   		cout << pro_sis[eli].precio;


   			cout <<endl<< "\t\t\tEliminar producto? [S/N]: ";
   			cin >> la;
   			if((strcmp(la,"s")==0)||(strcmp(la,"S")==0)){
   				pro_sis[eli]=pro_sis[contapro];
   				MessageBox(0,"Producto eliminado","Proceso",0);
   				system("pause > nul");
   				system("cls");
   				menu_pro();
   			}
   			if((strcmp(la,"n")==0)||(strcmp(la,"N")==0)){
   				MessageBox(0,"Producto no eliminado","Error",0);
   				system("pause > nul");
   				system("cls");
   				menu_pro();
   			}
   	}
   	else{
   		MessageBox(0,"No existe este registro","Error",0);
   		system("pause > nul");
   		system("cls");
   		menu_pro();
   	}
system("pause > nul");
system("cls");
menu_pro();
/* 
char nom[11];
int feini, canti, fechasa;

ifstream salida;
salida.open("registroDevDevolucion.txt", ios::in);

ifstream entrada;
entrada.open("temp.txt", ios::out);

if(salida.fail()){
	
	
	
	cout<<"hubo un error registroDevDevolucion.txt";
	getch();
	
	
}
else{
	
	char aux[20];
	
	cout <<"introduca el campo";
	cin >> aux;
	
	salida>>nom;
	
	while(!salida.eof()){
		salida>>feini;
		
		if(strcmp(aux,nom)==0){
			
			cout<<"se a eliminado";
			getch();
		}
		else{
			entrada<<nom<<feine<< endl;
		}
		
		salida>>nom;
	}
	entrada.close();
	salida.close();
	
	remove("registroDevDevolucion.txt"),
	rename("temp.txt","registroDevDevolucion.txt");
	
}*/
}
//fin funcion eliminar

//funcion editar
void Editar(){
		int campo;
   		int op;
   		cout << "\t\t\tNumero de registro a editar: ";
   		cin >> campo;
   		campo--;
   		if (campo<contapro){
   			cout <<"\t\t\tNombre"<< pro_sis[campo].Nombre_Producto << endl;
   			cout <<"\t\t\tFecha ingreso"<< pro_sis[campo].Fecha_ingreso << endl;
   			cout <<"\t\t\tcantidad"<< pro_sis[campo].cantidad << endl;
   			cout <<"\t\t\tPrecio"<< pro_sis[campo].precio << endl;
   			
   			cout <<"\t\t\tElija que desea editar"<<endl;
   			cout << "\t\t\t1. Nombre producto: " << endl;
   			cout << "\t\t\t2. Fecha de ingreso: " << endl;
   			cout << "\t\t\t3. Cantidad: " << endl;
   			cout << "\t\t\t4. Precio: " << endl;
   			cout << "\t\t\t8. Todo. " << endl;
   			cout << "\t\t\t9. Nada. " << endl;
   			cout << "\t\t\tInformacion a editar: " << endl;
   			cin >> op;
   			switch (op){
   				case 1:
   					cout <<endl<< "\t\t\t1. Nombre producto: ";
   					cin >> pro_sis[campo].Nombre_Producto ;
   				break;
   				case 2:
   					cout <<endl<< "\t\t\t2. Fecha ingreso: ";
   					cin >> pro_sis[campo].Fecha_ingreso;
   				break;
   				case 3:
   					cout <<endl<< "\t\t\t3. Cantidad: ";
   					cin >> pro_sis[campo].cantidad ;
   				break;
   				case 4:
   					cout <<endl<< "\t\t\t4. Precio: ";
   					cin >> pro_sis[campo].precio;
   				break;
   				case 8:
   					cout <<endl<< "\t\t\t1. Nombre Producto: ";
   					cin >> pro_sis[campo].Nombre_Producto ;
   					cout <<endl<< "\t\t\t2. Fecha ingreso: ";
   					cin >> pro_sis[campo].Fecha_ingreso ;
   					cout <<endl<< "\t\t\t3. Cantidad: ";
   					cin >> pro_sis[campo].cantidad ;
   					cout <<endl<< "\t\t\t4. Precio: ";
   					cin >> pro_sis[campo].precio;
   				break;
   				case 9:
   					menu_pro();
   				break;
   				default:
   					MessageBox(0,"Ingrese una opcion valida.","Error",0);
   					system("cls");
   					Editar();
   				break;
   			}
   			menu_pro();
   			system("pause > nul");
   			system("cls");
  		}
   		else{
   			MessageBox(0,"Numero de registro no existe","Proceso",0);
  	 		system("pause > nul");
   			system("cls");
   			menu_pro();
   		}
   		system("pause > nul");
   		system("cls");
   		menu_pro();
}
//fin funcion editar

//funcion ver
void Ver(){
	int ver;
	cout << "Numero de registro a ver: ";
	cin >> ver;
	ver--;
	if (ver < contapro){
		cout <<endl<< "\t\t\t1. Nombre producto: ";
		cout << pro_sis[ver].Nombre_Producto << endl; 
		cout << "\t\t\t2. Fecha ingreso: ";
		cout << pro_sis[ver].Fecha_ingreso << endl;
		cout << "\t\t\t3. Cantidad: ";
		cout << pro_sis[ver].cantidad << endl;
		cout << "\t\t\t4. Precio: ";
		cout << pro_sis[ver].precio << endl;
		system("pause > nul");
   		system("cls");
		menu_pro();
   }
   else{
   		MessageBox(0,"Numero de registro noexiste","Error",0);
   		system("pause > nul");
   		system("cls");
		menu_pro();
   }
}
//fin funcion ver

//funcion ver todo
void Ver_Todo(){
	
   int verTodo;
   for (verTodo = 0; verTodo < contapro; verTodo++){
   		cout << "\t\t\t1. Nombre producto: ";
  		cout << pro_sis[verTodo].Nombre_Producto <<endl;
   		cout << "\t\t\t2. Fecha de ingreso: ";
   		cout << pro_sis[verTodo].Fecha_ingreso <<endl;
   		cout << "\t\t\t3. Cantidad: ";
   		cout << pro_sis[verTodo].cantidad << endl;
   		cout << "\t\t\t4. Precio:  ";
   		cout << pro_sis[verTodo].precio  <<endl;

   }
    system("pause > nul");
	system("cls");
    menu_pro();
}
//funcion ver todo

void factura(){
	int i=0,n,campo,acu=0,can;
	cout <<"\t\t\tnumero factura "<< factucon<<endl;
	cout <<"\t\t\tIngrese la cedula; "; cin >> factu_new[factucon].ci;
	cout <<"\t\t\tIngrese el nombre; "; cin >> factu_new[factucon].nombre;
	cout <<"\t\t\tIngrese el telefono; "; cin >> factu_new[factucon].telefono;
	cout <<"\t\t\tIngrese la fecha; "; cin >> factu_new[factucon].fecha;
	cout <<"cuantos productos desea comprar: "; cin >> n;
	for(i=1;i<=n;i++){
		cout << "\t\t\tNumero del producto: ";
   		cin >> campo;
   		campo--;
   		if (campo<contapro){
   			cout <<"\t\t\tNombre "<< pro_sis[campo].Nombre_Producto << endl;
   			cout <<"\t\t\tPrecio "<< pro_sis[campo].precio << endl;
   			cout <<"\t\t\tingrese la cantidad de este producto que decea : ";cin>>can;
  				if(pro_sis[campo].cantidad >= can){
  					pro_sis[campo].cantidad=pro_sis[campo].cantidad-can;
  					acu=acu+(pro_sis[campo].precio*can);
				}
   				else{
   					MessageBox(0,"No hay suficiente stock","Proceso",0);
   					system("cls");
   					i--;
		   		}
		}
  		else{
  			MessageBox(0,"Registro no existe","Proceso",0);
  	 		i--;
  	 		cout <<"\t\t\tDesea crear un producto S/N"; cin >> la;
  	 		if((strcmp(la,"s")==0)||(strcmp(la,"S")==0)){
  	 			system("cls");
  	 			Anadir();
			}
		}
	}
	cout <<endl<< "total a pagar: "<< acu;
	factu_new[factucon].precio=acu;
	
	
	{
   ofstream archivo;
   archivo.open("facturacion.txt", ios::app);
   archivo << "\t\t\tCedula; " << factu_new[factucon].ci << endl;
   archivo << "\t\t\tNombre: " << factu_new[factucon].nombre << endl;
   archivo << "\t\t\tTelefono: " << factu_new[factucon].telefono<< endl;
   archivo << "\t\t\tFecha: " << factu_new[factucon].fecha<< endl;
   archivo << "\t\t\ttotal a pagar: "<< factu_new[factucon].precio<< endl;
   archivo.close();
   factucon++;
   MessageBox(0,"factura creado correctamente","Proceso",0);
   }
system("pause > nul");
system("cls");
menu_pro();
}


void factura_con(){	int ver;
	cout << "Numero de registro a ver: ";
	cin >> ver;
	ver--;
	if (ver < factucon){
		cout <<endl<< "\t\t\t1. Nombre producto: ";
		cout << factu_new[ver].ci << endl; 
		cout << "\t\t\t2. nombre: ";
		cout << factu_new[ver].nombre << endl;
		cout << "\t\t\t3. telefono: ";
		cout << factu_new[ver].telefono << endl;
		cout << "\t\t\t4. fecha: ";
		cout << factu_new[ver].fecha << endl;
		cout << "\t\t\t5. total a pagar: ";
		cout << factu_new[ver].precio << endl;
		system("pause > nul");
   		system("cls");
		menu_pro();
   }
   else{
   		MessageBox(0,"Numero de factura no existe","Error",0);
   		system("pause > nul");
   		system("cls");
		menu_pro();
   }
}
