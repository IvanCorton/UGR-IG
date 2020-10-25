#include "revolucion_ply.h"

_revolucion_ply::_revolucion_ply()
{

    _file_ply File_ply;

    if(File_ply.open("/home/ivancorton/Escritorio/IG/Practicas/read_ply/cilinder.ply")){

        File_ply.read(Vertices, Triangles);
        std::cout<<"File read correctly"<<std::endl;

        unsigned int numCaras = 20;

        revolucionar(Vertices, Triangles, numCaras);

        this->calcularNormales();

    }else{

        std::cout<<"File can not be opened"<<std::endl;

    }

}
