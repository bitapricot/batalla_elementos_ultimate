class Coordenada {
private:
    int primera;
    int segunda;
public:
    Coordenada(int primera, int segunda);
    int obtener_primera();
    int obtener_segunda();
    void cambiar_primera(int nueva);
    void cambiar_segunda(int nueva);
};