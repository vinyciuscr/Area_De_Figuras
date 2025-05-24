#include <iostream>
#include <string>
#include <vector>

using namespace std;

const float PI = 3.14;

class Ponto{
    int _x, _y;

    public:

    Ponto(int x, int y) : _x(x), _y(y){};

    int getX() const {return _x; }
    int getY() const {return _y; }

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
    Ponto getPontoA() {return A; }
    virtual void Desenha() = 0;
    virtual float CalculaArea() = 0;

};

class Retangulo : public FiguraGeometrica{
    int comprimento, largura;

    public: 

    Retangulo(int x, int y, int comprimento, int largura) : FiguraGeometrica(x, y), comprimento(comprimento), largura(largura){}

    void Desenha() override {
        cout << "RETANGULO" << endl;
    }

    float CalculaArea() override{
        return this->comprimento * this->largura;
    }

};

class Triangulo : public FiguraGeometrica{

    int base, altura;

    public: 

    Triangulo(int x, int y, int base, int altura) : FiguraGeometrica(x, y), base(base), altura(altura){}

    void Desenha() override{
        cout << "Triangulo" << endl;
    }

    float CalculaArea() override{
        return (this->base * this->altura) / 2;
    }

};

class Circulo : public FiguraGeometrica{

    int raio;

    public: 

    Circulo(int x, int y, int raio) : FiguraGeometrica(x, y), raio(raio){}

    void Desenha() override{
        cout << "RETANGULO" << endl;
    }

    float CalculaArea() override{
        return PI*((this->raio * this->raio));
    }

};


int main(){


    vector <FiguraGeometrica*> figuras;

    char opc;
    int largura, comprimento, base, altura, raio;
    int a, b;
    float area = 0;

    while(1){
    
    cin >> opc;
        
        if(opc == 'E'){
        
        for(FiguraGeometrica* figura : figuras){
            delete figura;
        }
            break;
        }
        else if(opc == 'R'){
            cin >> a >> b >> comprimento >> largura;
            figuras.push_back(new Retangulo(a, b, comprimento, largura));
        }
        else if(opc == 'C'){
            cin >> a >> b >>  raio;
            Circulo circulo(a, b, raio);
            figuras.push_back(new Circulo(a, b, raio));
        }
        else if(opc == 'T'){
            cin >> a, b, base, altura;
            Triangulo triangulo(a, b, base, altura);
            figuras.push_back(new Triangulo(a, b, base, altura));
        }
        else if(opc == 'D'){
            for(FiguraGeometrica* figura : figuras){
                Ponto ponto = figura->getPontoA();
                cout << ponto.getX() << ponto.getY();
                figura->Desenha();
            }
        }
        else if(opc == 'A'){
            for(FiguraGeometrica* figura : figuras){
                area += figura->CalculaArea();
            }
            cout << area << endl;
        }
    }

    for(FiguraGeometrica* figura : figuras){
        delete figura;
    }


    return 0;
}