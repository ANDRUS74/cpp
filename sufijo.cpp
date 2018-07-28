#include <iostream>
#include <fstream>
// las otras 2 en Debian 9 no hacen falta , en Debian 8 si
//#include <string>
//#include <iomanip>
// compilado con :
// g++ -O sufijo.cpp -o sufijo
using namespace std;

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
            cadena=argv[1];
			while( getline(std::cin,lineFromFile) ){
				std::cout << (lineFromFile) <<" " << cadena << std::endl;
			}
			break;
		default:
			error=1;
			break;
	}
	if(error){		
		    std::cout << "  =================================================================" << std::endl;
	        std::cout << "    sufijo by ANDRUS74" << std::endl;
		    std::cout << "  =================================================================" << std::endl;
			std::cout << std::endl;
            std::cout << "  Uso:";
			std::cout << std::endl;
			std::cout << "  sufijo cadena "<< std::endl;
			std::cout << "     Lee directo de la entrada estandard "<< std::endl;			
			std::cout << "     debe ser la salida de un comando por ejm: "<< std::endl;		
            std::cout << "             ./prefijo cp -t | ./sufijo /dir/ "<< std::endl;		
			std::cout << std::endl;
			std::cout << "  Utilidad para agregar la cadena al final de cada linea recibida" << std::endl;
			std::cout << std::endl;
			std::cout << "  =================================================================" << std::endl;
			std::cout << "  Ingresaste : (" << (argc-1) << ") parametros"<< std::endl;
			int i;
    		for(i=0;i<argc;i++){
        		std::cout <<"  "<< argv[i];
    		}
			std::cout <<std::endl;
			std::cout <<std::endl;
			std::cout << "  =================================================================" << std::endl;
			std::cout <<std::endl;
			return EXIT_FAILURE;
	}else{	
		return EXIT_SUCCESS; 
	}
}
