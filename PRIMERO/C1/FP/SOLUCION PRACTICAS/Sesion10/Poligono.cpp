#include <iostream>
#include <cmath>

using namespace std;

struct TipoPunto{
	double abscisa;
	double ordenada;
};

struct TipoPoligono{
	TipoPunto puntos[100];
	int num_puntos;
};

/*Se inicia una funcion que calcule la distancia entre abcisas de dos puntos */
double DistanciaAbscisa (TipoPunto punto1, TipoPunto punto2){
	double distancia_abscisas;
	
	distancia_abscisas = punto1.abscisa - punto2.abscisa;
	
	return distancia_abscisas;
}

/*Se inicia una funcion que calcule la distancia entre ordenadas de dos puntos */
double DistanciaOrdenada (TipoPunto punto1, TipoPunto punto2){
	double distancia_ordenadas;
	
	distancia_ordenadas = punto1.ordenada - punto2.ordenada;
	
	return distancia_ordenadas;
}

/*Se inicia una funcion que calcule el area de un triangulo formado por tres puntos dados por el usuario */
double AreaTriangulo ( TipoPunto punto1, TipoPunto punto2, TipoPunto punto3){
	double distancia1, distancia1_abscisa, distancia1_ordenada;
	double distancia2, distancia2_abscisa, distancia2_ordenada;
	double distancia3, distancia3_abscisa, distancia3_ordenada;
	double F, area;
	double paso_medio;
	
	/*Se calcula la distancia de abcisas y ordenadas y el modulo de la distancia tomando los puntos dos a dos */
	distancia1_abscisa = DistanciaAbscisa(punto1, punto2);
	distancia1_ordenada = DistanciaOrdenada(punto1, punto2);								
	distancia1 = sqrt(pow(distancia1_abscisa,2) + pow(distancia1_ordenada, 2));
	
	distancia2_abscisa = DistanciaAbscisa(punto2, punto3);
	distancia2_ordenada = DistanciaOrdenada(punto2, punto3);
	distancia2 = sqrt(pow(distancia2_abscisa,2) + pow(distancia2_ordenada, 2));
	
	distancia3_abscisa = DistanciaAbscisa(punto3, punto1);
	distancia3_ordenada = DistanciaOrdenada(punto3, punto1);
	distancia3 = sqrt(pow(distancia3_abscisa,2) + pow(distancia3_ordenada, 2));
	
	/*Se calcula F mediante el algoritmo dado */
	F = (distancia1 + distancia2 + distancia3) / 2;
	
	paso_medio = F * (F - distancia1) * (F - distancia2) * (F - distancia3);
	
	area = sqrt(paso_medio);
	
	return area;
}

int main() {
	TipoPoligono figura;
	double area_poligono;
	
	cout << "Introduzca el numero de puntos del poligono: ";
	cin >> figura.num_puntos;
	
	/*Se toman los puntos del poligono con sus respectivas abscisas y ordenadas */
	cout << "\nIntroduzca las coordenadas de cada punto (puntos consecutivos)(abscisa / ordenada): ";
	for(int i = 0; i < figura.num_puntos; i++){
		cin >> figura.puntos[i].abscisa >> figura.puntos[i].ordenada;
	}
	
	/*Se calcula el area del poligono sumando el area de los triangulos en los que se divide el poligono */
	for(int i = 0; i + 2< figura.num_puntos; i++){
		area_poligono += AreaTriangulo(figura.puntos[0],figura.puntos[i + 1], figura.puntos[i + 2]);
	}
	
	cout << "\nEl area del poligono es: " << area_poligono << "\n";
	
	system("pause");
}	
