/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package servidorcine;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.Socket;
import java.util.Random;
import java.io.PrintWriter;


/**
 *
 * @author daniel
 */
public class ProcesadorCine extends Thread{
    // Referencia a un socket para enviar/recibir las peticiones/respuestas
    private Socket socketServicio;
    // stream de lectura (por aquí se recibe lo que envía el cliente)
    private BufferedReader input;
    // stream de escritura (por aquí se envía los datos al cliente)
    private PrintWriter printer;
    //String que contendrá los mensajes del servidor en caracteres
    private String mensaje;
    
    private verificador verificar;
    
    private boolean verificado;
    
    private boolean valido;
    
    private Cartelera cartelera;
    
    private MisEntradas misentradas;
    
    private String currentUser;
    
    public ProcesadorCine(Socket socketServicio) {
        this.socketServicio=socketServicio;
        this.mensaje="**Bienvenido al Servicio de Compra de entrada online**\n"
                     + "¿Qué desea hacer?\n"
                     + "[0]LOGIN\n[1]LOGOUT\n[2]SIGNUP\n";             //El primer mensaje que se manda es una confirmación de conexión
        
        try{
        this.printer = new PrintWriter(socketServicio.getOutputStream(),false);
        this.input = new BufferedReader(new InputStreamReader(socketServicio.getInputStream()));
        }catch(IOException e){
            System.out.println("Error al abrir los flujos de entrada/salida");
        }
        
        this.verificar = new verificador();
        this.verificado = false;
        this.cartelera = new Cartelera();
        this.misentradas = new MisEntradas();
        this.currentUser = "";
        this.valido = false;
    }
    
    @Override
    public void run(){ 
        boolean terminar=false;
        
        try{
            printer.println("201 HELLO");
            System.out.println("Servidor manda 201 HELLO");
            printer.println(mensaje);    //Manda el mensaje de accion
            printer.flush();
            String[]partes;

            while(!valido&&!terminar){
                mensaje=input.readLine();
                System.out.println("Servidor recibe " + mensaje);
                partes=mensaje.split(" ");
                switch(partes[0]){
                    case "1001":
                        valido=true;
                        verificado=false;
                        while(!verificado){
                        verificado=verificar.hacer_login(socketServicio,printer,input, mensaje);

                        if(!verificado){
                            mensaje=input.readLine();
                            partes = mensaje.split(" ");
                        }

                        currentUser = partes[2];
                        }
                        break;

                    case "1002":
                        valido=true;
                        verificar.hacer_logout(socketServicio,printer);
                        terminar=true;
                        break;
                    case "1000":
                        verificado=false;
                        while(!verificado){
                        verificado=verificar.hacer_signup(printer,input,partes[3],partes[5]);
                        
                            if(!verificado){
                                mensaje=input.readLine();
                                partes = mensaje.split(" ");
                            }
                        }
                        break;
                    default:
                        printer.println("300 ERROR No disponemos de esa opción");
                        printer.flush();
                        break;
                }
            }
            
            mensaje="¿Que desea hacer?\n"
                    + "[0]Comprar una Entrada\n"
                    + "[1]Devolver una Entrada\n"
                    + "[2]Ver sus Entradas\n"
                    + "[3]LOGOUT\n";
            
            /*Bloque que imprimera la posibles acciones y la cartelera una vez identificado*/
            printer.println(mensaje);
            printer.flush();
            cartelera.mostrarCartelera(printer);
            verificado=false;
            
            String accion;
            
            
            while(!verificado&&!terminar){
                accion=input.readLine();
                System.out.println("Servidor recibe " + accion);
                partes=accion.split(" ");
                
                switch(partes[0]){
                    case "1003":
                        misentradas.comprar_entrada(currentUser, partes[2], printer, input);
                        break;

                    case "1004":
                        misentradas.cancelar_entrada(currentUser, printer, input);
                        break;
                    case "1005":
                        misentradas.vermis_entradas(currentUser, printer);
                        break;
                    case "1002":
                        verificar.hacer_logout(socketServicio, printer);
                        terminar=true;
                        break;

                }
            }
            
            System.out.println("Procesador terminado con éxito");
            
            
        }catch(IOException e){
            System.out.println("Error al obtener los flujos de entrada/salida");
        }
    }
}
