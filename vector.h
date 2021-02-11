//
// Created by camila on 28/10/20.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H
typedef int Dato; // tipo generico, si quiero char lo cambio aca y listo
const int NULO = 0; // depende del tipo de datos que guarde, xej, si guardo char
                    // podria ser el NULO = "" o NULO = "-" etc
class Vector{

private:
    // atributos
    int largo = 0; // longitud del vector
    Dato* datos = 0; // vector

public:
    /* constructor con parametro de longitud
     * PRE: l > 0
     * POS: crea un vector con longitud l y los valores en nulo */
    Vector(int l);


    /* constructor por defecto
     * PRE: -
     * POS: crea un vector con largo = 0, sin datos */
    Vector() = default;

    Vector(const Vector& v); // constructor de copia


    /*
     * destructor
     * PRE: -
     * POS: libera la memoria
     */
    ~Vector();


    /*
     * PRE: 0 <= pos < 1
     * POS: coloca a d en el vector en la posicion pos. La primera pos es la 0
     */
    void asignar(Dato d, int pos);

    /*
    * PRE: 0 <= pos < 1
    * POS: devuelve el dato
    */
    Dato obtener(int pos);

    /*
    * PRE: -
    * POS: devuelve la longitud del vector
    */
    int obtener_longitud();

    /*
     * PRE: nl > 0 y nl != largo
     * POS: si nl > largo entonces deja los valores cargados y completa con nulos
     *      si nl < largo trunca manteniendo los valores cargados
     */
    void redimensionar(int nl);

private:
    /*
     * PRE: 0 <= desde <= hasta < largo
     */
    void anular(int desde, int hasta);

    /*
     * PRE: 0 <= desde <= hasta < largo
     * POS: copia los datos de vec en datos desde d hasta h
     */
    void copiar(Dato * vec, int d, int h);


};




#endif //VECTOR_VECTOR_H
