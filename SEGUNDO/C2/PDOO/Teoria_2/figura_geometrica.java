package unPaquete;

import Java.utils.ArrayList;

class FiguraGeometrica{
    float area() {return 0.0f; }
}

class Circulo extends FiguraGeometrica {
    private float radio;

    float area(){
        return Math.PI * radio * radio;
    }
}

class Rectangulo extends FiguraGeometrica {
    private float lado1;
    private float lado2;
    float area(){
        return lado1*lado2;
    }
}

ArrayList<FiguraGeometrica> coleccionDeFiguras = new ArrayList<>();
coleccionDeFiguras.add (new Circulo (radio));
coleccionDeFiguras.add (new Rectangulo(lado1,lado2));

float suma = 0.0f;

for(FiguraGeometrica unaFigura : coleccionDeFiguras){
    suma += unaFigura.area();
}