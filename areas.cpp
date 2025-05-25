#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

//const double PI = 3.14159265358979323846;

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
    virtual ~FiguraGeometrica() = default;

};

class Retangulo : public FiguraGeometrica{
    int comprimento, largura;

    public: 

    Retangulo(int x, int y, int comprimento, int largura) : FiguraGeometrica(x, y), comprimento(comprimento), largura(largura){}

    void Desenha() override {
        cout << "RETANGULO" << endl;
    }

    float CalculaArea() override{
        return (this->comprimento) * this->largura;
    }

};

class Triangulo : public FiguraGeometrica{

    int base, altura;

    public: 

    Triangulo(int x, int y, int base, int altura) : FiguraGeometrica(x, y), base(base), altura(altura){}

    void Desenha() override{
        cout << "TRIANGULO" << endl;
    }

    float CalculaArea() override{
        return (this->base * this->altura) / 2.0;
    }

};

class Circulo : public FiguraGeometrica{

    int raio;

    public: 

    Circulo(int x, int y, int raio) : FiguraGeometrica(x, y), raio(raio){}

    void Desenha() override{
        cout << "CIRCULO" << endl;
    }

    float CalculaArea() override{
        return M_PI * (this->raio * this->raio); 
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
        figuras.clear();
            break;
        }
        else if(opc == 'R'){
            cin >> a >> b >> comprimento >> largura;
            figuras.push_back(new Retangulo(a, b, comprimento, largura));
        }
        else if(opc == 'C'){
            cin >> a >> b >>  raio;
            figuras.push_back(new Circulo(a, b, raio));
        }
        else if(opc == 'T'){
            cin >> a >> b >> base >> altura;
            figuras.push_back(new Triangulo(a, b, base, altura));
        }
        else if(opc == 'D'){
            for(FiguraGeometrica* figura : figuras){
                Ponto ponto = figura->getPontoA();
                cout << ponto.getX() << " " << ponto.getY() << " ";
                figura->Desenha();
            }
        }
        else if(opc == 'A'){
            area = 0;    
            for(FiguraGeometrica* figura : figuras){
                area += figura->CalculaArea();
            }
            cout << fixed << setprecision(2) << area<< endl;

        }
    }

    for(FiguraGeometrica* figura : figuras){
        delete figura;
    }


    return 0;
}
