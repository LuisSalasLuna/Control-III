#include <iostream>

using namespace std;

class Polygon{
private:
    int width,height;
public:
    Polygon() : width(0), height(0){}
    Polygon(int a, int b): width(a), height(b){}
    Polygon(const Polygon &A) : width(A.width), height(A.height){}
    int area (void){return 0;}
    void PrintD();
    void printArea(){
    cout<< this-> area()<<"\n";
    }
};
    void Polygon::PrintD(){   //Profundizar clase informal
    cout<< width<<endl;
    cout<< height<<endl;}
class ArrayPolygons{
    private:
        Polygon *ptr;
        int tam;
        void RedimensionarPriv();
    public:
        ArrayPolygons();
        ArrayPolygons(Polygon[], int);
        ArrayPolygons(const ArrayPolygons&);
        ~ArrayPolygons();
        void Mostrar();
        void InsertFinal(Polygon);
        void InsertarPos(Polygon,int);
        void Eliminar();
};
ArrayPolygons::ArrayPolygons(){
    tam = 0;
    ptr= new Polygon[tam];
}
ArrayPolygons::ArrayPolygons(Polygon arr[], int tama ){  //mejorar
    tam = tama;
    ptr= new Polygon[tama];
    int x = 0;
    for(int a = 0; a < tam ; a++)
        *(ptr+a) = arr[a];
    cout<< "Constructor invoked"<< endl;
}
ArrayPolygons::ArrayPolygons(const ArrayPolygons& A){
    tam = A.tam;
    ptr = new Polygon[A.tam];
    for(int i = 0 ; i < tam ; ++i)
        ptr[i]=A.ptr[i];
    cout<< "Constructor invoked"<< endl;
}
ArrayPolygons::~ArrayPolygons(){
    delete[] ptr;
    cout<< "Destructor invoked"<< endl;
}
void ArrayPolygons::RedimensionarPriv(){
    tam = tam+1;
    Polygon *Narr= new Polygon[tam];
    Polygon *ptr2 = ptr;
    for(int i = 0;i < tam-1;i++){
        Narr[i]=*(ptr+i);
    }
    ptr = Narr;
    Narr = ptr2;
    delete[] Narr;
}
void ArrayPolygons::InsertFinal(Polygon A){
    RedimensionarPriv();
    *(ptr+tam-1) = A;
}
void ArrayPolygons::InsertarPos(Polygon A,int pos){
    tam = tam+1;
    Polygon *Narr= new Polygon[tam];
    Polygon *ptr2 = ptr;
    int x = 0;
    for(int i = 0;i < tam;i++){
        if(i != pos){
            Narr[i]=*(ptr+x);
            x++;
        }
        else{Narr[i]= A;}
    }
    ptr = Narr;
    Narr = ptr2;
    delete[] Narr;
}
void ArrayPolygons::Eliminar(){ //decoherence
    tam = tam-1;
    Polygon *Narr= new Polygon[tam];
    Polygon *ptr2 = ptr;
    for(int i = 0;i < tam;i++){
            Narr[i]=*(ptr+i);
        }
    ptr = Narr;
    Narr = ptr2;
    delete[] Narr;
}
void ArrayPolygons::Mostrar(){
    for(int i =0 ; i<tam ; i++){
        (ptr+i)->PrintD();

    }
}
int main(){
 Polygon A(8,9);
 Polygon B = A;
 Polygon arr[]={A,B};
 ArrayPolygons C(arr,2);
 C.Mostrar();
 cout<<"Insertar Final"<< endl;
 Polygon E(5,5);
 C.InsertFinal(E);
 C.Mostrar();
 cout<<"Eliminar"<< endl;
 C.Eliminar();
 C.Mostrar();
 cout<< "Insertar cualquier posicion"<<endl;
 Polygon T(4,7);
 C.InsertarPos(T,1);
 C.Mostrar();
 cout<< "Constructor copia"<<endl;
 if(true){
    ArrayPolygons D = C;
    D.Mostrar();
}
C.Mostrar();

return 0;
}

