#include <iostream>
#include <fstream>
#include <string>
//#include <iomanip>
//#include <cstdlib>
// compilado con :
// g++ -O prefijo.cpp -o prefijo
// Esta fue la primer prueba con la consola
using namespace std;
int main(int argc, char *argv[])
{ 	string cadena;
	int error=0;
    std::size_t encontrado;
    cadena=(argc>1)? argv[1]:"";
    // es el primer parametro un flag?
    encontrado=cadena.find_first_of("-");
    if(encontrado != std::string::npos){
        // esta mal los flag deberian ir despues de la cadena // porque se me ocurrio forzarlo asi nomas
        std::cout << "  El comando no acepta ningun flag como parametro "<< std::endl;
        error=1;
    }
    else
    encontrado=cadena.find_first_of(" ");
    if(encontrado != std::string::npos){
        std::cout << "  El comando no acepta cadenas con espacios "<< std::endl;
        error=1;
    }
    else
    if(argc>2){
        std::cout << "  El comando no acepta mas de 1 parametro "<< std::endl;
        error=1;
    }
    else{
        error=system( ( "dir -p -d -1 $PWD/*"+ cadena +"*").c_str() );
    }
	return error?EXIT_FAILURE:EXIT_SUCCESS; 
}
