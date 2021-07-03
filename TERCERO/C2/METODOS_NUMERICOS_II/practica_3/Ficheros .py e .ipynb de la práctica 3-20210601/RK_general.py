## módulo RK4
''' Método de Runge-Kutta de cuarto orden para resolver
    el problema de valores iniciales {y}' = {F(x,{y})}, 
    donde    {y} = {y[0],y[1],...y[N-1]}.
    X,Y    = integrate(F,x0,y0,xfinal,h).
    x0,y0  = condiciones iniciales
    xfinal = valor final de x
    N      = número de subintervalos de la partición
    h      = incremento de x usado en la integración
    F      = función suplida por el usuario que devuelve el
            array F(x,y) = {y'[0],y'[1],...,y'[N-1]}.
    butcher = arreglo de Butcher
    b      = vector de números tal que b_1+b_2+...+b_m=1 donde m es el número de columnas del arreglo de Butcher
             así obtenemos un método consistente
'''
import numpy as np
def integrate(F,x0,y0,xfinal,N,butcher,b):
    aux=0
    c=[]
    
    for i in range(len(butcher)):
        for j in range(len(butcher[i])):
            aux += butcher[i][j]
        
        c.append(aux)
        aux=0
    
    
    def RK(F,xn,yn,h,c,butcher,b):
        aux=0
        K=[]
        salida=0
        
        for i in range(len(c)):
            K.append(0)
        
        for i in range(len(c)):
            for j in range(len(c)):
                aux+=butcher[i][j]*K[j]
                
            K[i]=F(xn + h*c[i], yn + h*aux)
            aux=0
            
        for i in range(len(K)):
            salida+=b[i]*K[i]
        
        return salida     
    
    X = np.linspace(x0,xfinal,N+1)
    Y = [y0]; h = (xfinal-x0)/N
    for n in range(N):
        Y.append( Y[n] + h*RK(F,X[n],Y[n],h,c,butcher,b) )
    return np.array(X),np.array(Y)
