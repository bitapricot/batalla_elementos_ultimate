#ifndef COORDENADA_H_INCLUDED
#define COORDENADA_H_INCLUDED

class Coordenada {
private:
    int primera, segunda;
public:
    /*
    Constructor base
    */
    Coordenada(): primera(0), segunda(0) {}

    Coordenada(const int primera, const int segunda);

    /*
    Constructor de copia
    Coordenada(const Coordenada& c);*/

    Coordenada operator+(Coordenada c);

    Coordenada operator=(Coordenada c);

    int obtener_primera();
    int obtener_segunda();
    void cambiar_primera(int nueva);
    void cambiar_segunda(int nueva);
    bool operator==(Coordenada c);
};
#endif // COORDENADA_H_INCLUDED