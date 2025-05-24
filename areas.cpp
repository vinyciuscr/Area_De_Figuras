#include <iostream>
#include <string>

using namespace std;

const float PI = 3.14;

class Ponto{
    int _x, _y;

    public:

    Ponto(int x, int y) : _x(x), _y(y){};

    int getX() const {return _x; }
    int getX() const {return _y; }

    void setX(int x){
        this->_x = x;
    }
    void setY(int y){
        this->_y = y;
    }

};

class FiguraGeometrica {

    Ponto A;

    public:
    FiguraGeometrica(int x, int y) : A(x,y){}
    virtual void Desenha();
    virtual float CalculaArea() = 0;

};

class Retangulo : public FiguraGeometrica{
    int comprimento, largura;

    public: 

    Retangulo(int x, int y, int comprimento, int largura) : FiguraGeometrica(x, y), comprimento(comprimento), largura(largura){}

    void Retangulo::Desenha(){
        FiguraGeometrica::Desenha();
        cout << "RETANGULO" << endl;
    }

    float Retangulo::CalculaArea(){
        return this->comprimento * this->largura;
    }

};

class Triangulo : public FiguraGeometrica{

    int base, altura;

    public: 

    Triangulo(int x, int y, int base, int altura) : FiguraGeometrica(x, y), base(base), altura(altura){}

    void Triangulo::Desenha(){
        FiguraGeometrica::Desenha();
        cout << "Triangulo" << endl;
    }

    float Triangulo::CalculaArea(){
        return (this->base * this->altura) / 2;
    }

};

class Circulo : public FiguraGeometrica{

    int raio;

    public: 

    Circulo(int x, int y, int raio) : FiguraGeometrica(x, y), raio(raio){}

    void Circulo::Desenha(){
        FiguraGeometrica::Desenha();
        cout << "RETANGULO" << endl;
    }

    float Circulo::CalculaArea(){
        return PI*((this->raio * this->raio));
    }

};


int main(){


    








    return 0;
}