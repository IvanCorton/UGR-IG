#include "revolucion.h"

/*
 * perfil: numero de elementos que tiene el perfil sin contar las tapas
 * n_caras: numero de caras de la figura a generar
*/
void revolucion::rotacionVertices(vector<_vertex3f>& Vertices, unsigned long perfil, unsigned long n_caras){
    float D_PI = 2 * 3.14159;
    float rotacion = D_PI/n_caras;
    float modulo = 0;
    for (unsigned long i=1;i < n_caras;++i){
        for (unsigned long j = 0; j < perfil; ++j) {
            modulo = Vertices[j]._0;
            Vertices[(i*perfil)+j] = _vertex3f(modulo*cos(rotacion*i),Vertices[j]._1,modulo*sin(rotacion*i));
        }
    }
}

void revolucion::triangulosCentrales(vector<_vertex3ui> &Triangles, unsigned long n_caras, unsigned long perfil, unsigned long totalVertices, unsigned long &prim){
    for (unsigned long i=0;i<perfil-1;++i){
        for (unsigned long j=0;j<n_caras;++j, prim +=2){
            // Para las caras pares
            Triangles[prim] = _vertex3ui((((j+1)*perfil)+i)%totalVertices, (j*perfil)+i, (j*perfil)+i+1);
            // Para las caras impares
            Triangles[prim+1] = _vertex3ui((j*perfil)+i+1, (((j+1)*perfil)+i+1)%totalVertices, (((j+1)*perfil)+i)%totalVertices);
        }
    }

}
/*
 * n_caras: numero de caras de la figura a generar
 * perfil: numero de elementos que tiene el perfil sin contar las tapas
 * tieneTapaSup: booleano activo si la figura tiene tapa superior
 * tieneTapaInf: booleano para la tapa inferior
 * totalVertices: numero total de vertices de la figura
*/

void revolucion::triangulosInferiores(vector<_vertex3ui>& Triangles, unsigned long n_caras, unsigned long perfil, unsigned long totalVertices, unsigned long &start, unsigned long n_tapas){
    for (unsigned long i=0;i < n_caras;++i) {
        Triangles[start+i] = _vertex3ui((i*perfil)%(totalVertices-n_tapas), ((i+1)*perfil)%(totalVertices-n_tapas), totalVertices-n_tapas);
    }
}

void revolucion::triangulosSuperiores(vector<_vertex3ui> &Triangles, unsigned long n_caras, unsigned long perfil, unsigned long totalVertices, unsigned long &start, unsigned long n_tapas){
    for (unsigned long i=0;i < n_caras;++i) {
        Triangles[start+i] = _vertex3ui(((perfil-1)+((i+1)*perfil))%(totalVertices-n_tapas), (perfil-1)+(i*perfil)%(totalVertices-n_tapas), totalVertices-1);
    }
}

/*
 * n_caras: numero de caras de la figura a generar
*/
void revolucion::revolucionar(vector<_vertex3f>& Vertices, vector<_vertex3ui>& Triangles, unsigned long n_caras){
    //Variables iniciales
    const unsigned long MIN_PARTE_CENTRAL = 2;
    unsigned long perfil = Vertices.size();
    unsigned long n_tapas = 0;
    unsigned long start = 0;
    bool tieneTapaSup = false;
    bool tieneTapaInf = false;
    bool tieneParteCentral = true;
    _vertex3f tapaSup;
    _vertex3f tapaInf;

    //Comprobacion de las tapas y parte central de la figura
    //Comprobacion de las tapas. Segun el sentido proporcionado, se comprueba si hay tapas y se extraen del vector para evitar repetir puntos

        //Comprobacion de tapa inferior
        if(Vertices[perfil-1]._0 == 0 && Vertices[perfil-1]._2 == 0){
            tieneTapaInf = true;
            tapaInf = Vertices[perfil-1];
            Vertices.resize(Vertices.size()-1);
            perfil = Vertices.size();
            ++n_tapas;
        }else if(Vertices[perfil-2]._0 == 0 && Vertices[perfil-2]._2 == 0){
            tieneTapaInf = true;
            tapaInf = Vertices[perfil-2];
            Vertices[perfil-2]=Vertices[perfil-1];
            Vertices.resize(Vertices.size()-1);
            perfil = Vertices.size();
            ++n_tapas;
        }

        //Comprobacion de la tapa superior
        if(Vertices[perfil-1]._0 == 0 && Vertices[perfil-1]._2 == 0){
            tieneTapaSup = true;
            tapaSup = Vertices[perfil-1];
            Vertices.resize(Vertices.size()-1);
            perfil = Vertices.size();
            ++n_tapas;
        }

    //Comprobacion de la parte central. Si el numero restante de elementos es mayor a 2 existe una parte central
    if(perfil < MIN_PARTE_CENTRAL)
        tieneParteCentral = false;

    //Se redimensionan el tamaño de los vectores de vertices y el de triangulos
    Vertices.resize((perfil*n_caras)+n_tapas);
    Triangles.resize(((perfil-1)*n_caras*2) + (n_caras*n_tapas));

    //Se añaden los vertices rotados al vector de vertices
    rotacionVertices(Vertices, perfil, n_caras);

    //Generacion de triangulos de la parte central
    if(tieneParteCentral){
        triangulosCentrales(Triangles, n_caras, perfil, perfil*n_caras, start);
    }

    //Se añaden al final los vertices de la tapa superior e inferior y se generar los triangulos de las tapas

    if(tieneTapaSup && tieneTapaInf){
        Vertices[Vertices.size()-2] = tapaSup;
        triangulosSuperiores(Triangles, n_caras, perfil, Vertices.size(), start, n_tapas);
        Vertices[Vertices.size()-1] = tapaInf;
        start += n_caras;
        triangulosInferiores(Triangles, n_caras, perfil, Vertices.size(), start, n_tapas);
    }else if(tieneTapaSup){
        Vertices[Vertices.size()-1] = tapaSup;
        triangulosSuperiores(Triangles, n_caras, perfil, Vertices.size(), start, n_tapas);
    }else if(tieneTapaInf){
        Vertices[Vertices.size()-1] = tapaInf;
        triangulosInferiores(Triangles, n_caras, perfil, Vertices.size(), start, n_tapas);
    }

}
