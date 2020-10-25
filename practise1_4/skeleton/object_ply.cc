#include "object_ply.h"



_object_ply::_object_ply()
{

}

bool _object_ply::read_ply(){

    _file_ply File_ply;

    if(File_ply.open("/home/ivancorton/Escritorio/IG/Practicas/read_ply/beethoven.ply")){

        File_ply.read(Vertices, Triangles);
        std::cout<<"File read correctly"<<std::endl;

        this->calcularNormales();

        return true;
    }else{

        std::cout<<"File can not be opened"<<std::endl;
        return false;

    }
}
