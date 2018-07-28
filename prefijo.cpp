#include <iostream>
#include <fstream>
// las otras 2 en Debian 9 no hacen falta , en Debian 8 si
//#include <string>
//#include <iomanip>
//#include <cstdlib>
// compilado con :
// g++ -O prefijo.cpp -o prefijo
using namespace std;

//
// esta funcion es para jugar con encontrar caracteres 
// podria ser una expresion regular
// la idea es que si tiene un espacio lle agregue comillas asi la shell toma todo como una linea
//
string sanear_espacios(string cadena){
	std::size_t encontrado;
	encontrado = cadena.find_first_of(" ");
	return ( encontrado != std::string::npos) ?	"\""+cadena +"\"":	cadena;
}

int main(int argc, char *argv[])
{ 	ifstream inFile;
	string lineFromFile;
    string origen;
	string cadena;
	
	int error=0;
	switch (argc)
	{
		case 1:
		case 2:	
			error =1;
			break;
		case 3:
			cadena=argv[1];
			origen=argv[2];
			if(!origen.compare("-t") || !origen.compare("--t") ) {
				// Aca se llama a si mismo con el listado del directorio donde esta parado
        // usa bash queda como ejercicio tomar la lista de archivos desde c++
				system(("ls -d -1 $PWD/*.* | prefijo \""+ cadena +"\" -i").c_str() );
				// me puedo evitar usar sanear con el comando  "ls -b -d -1" 
			}else 
				if(!origen.compare("-i")){
					while( getline(std::cin,lineFromFile) ){
						std::cout << cadena <<" " << sanear_espacios(lineFromFile) << std::endl;
					}
				}
				else{ 
					error=1;
				}
			break;
		default:
			error=1;
			break;
	}
	if(error){		
		  std::cout << "  =================================================================" << std::endl;
	    std::cout << "    Prefijo by ANDRUS74" << std::endl;
		  std::cout << "  =================================================================" << std::endl;
			std::cout << std::endl << "  Uso:";
			std::cout << std::endl;
			std::cout << "  prefijo cadena [-t]"<< std::endl;
			std::cout << std::endl;
		    std::cout << "  prefijo cadena [--t]"<< std::endl;			
			std::cout << "     Genera una lista con cadena delante de cada archivo "<< std::endl;
			std::cout << "     en el directorio actual "<< std::endl;
			std::cout << std::endl;
			std::cout << "  prefijo cadena [-i]"<< std::endl;
			std::cout << "     Interactivo, lee directo de la entrada estandard "<< std::endl;			
			std::cout << "     puede ser la salida de un comando, por ejm: "<< std::endl;		
      std::cout << "             cat archivo | prefijo cadena -i "<< std::endl;		
			std::cout << std::endl;
			std::cout << "  Utilidad para agregar la cadena al inicio de la cadena recibida" << std::endl;
			std::cout << std::endl;
			std::cout << "  =================================================================" << std::endl;
			std::cout << "  Ingresaste : (" << (argc-1) << ") parametros"<< std::endl;
			int i;
    		for(i=0;i<argc;i++){
        		std::cout <<"  "<< argv[i];
    		}
			std::cout << "  =================================================================" << std::endl;
			std::cout <<std::endl;
			return EXIT_FAILURE;
	}else{	
		return EXIT_SUCCESS; 
	}
}
