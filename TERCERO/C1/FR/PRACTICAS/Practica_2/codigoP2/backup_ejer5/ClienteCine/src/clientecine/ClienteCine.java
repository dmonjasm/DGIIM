/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package clientecine;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

/**
 *
 * @author daniel
 */
public class ClienteCine {

    /**
     * @param args the command line arguments
     */
    
    private static String leer_todo_buffer(BufferedReader input){
            String texto="";
            String linea="";
            
            try{
                
                while(!(linea = input.readLine()).equals("")&&(linea != null)){
                    texto += linea + "\n";
                }
            }catch (IOException e){
                System.out.println("Error en la lectura de mensajes desde el socket");
            }
            
            return texto;
    }
    
    private static void seleccion_pelicula(Scanner entrada,String cartelera, PrintWriter printer,String user){
        boolean valida=false;
        System.out.println("Escriba el código de la película cuya entrada quiere comprar (el número a la derecha del código de película)");
        String pelicula;
        int codigo=0;
        
        while(!valida){
            pelicula=entrada.nextLine();
            
            switch(pelicula){
                case "0":
                    case "[0]":
                        valida=true;
                        codigo=0;
                        break;
                    case "1":
                    case "[1]":
                        valida=true;
                        codigo=1;
                        break;
                    case "2":
                    case "[2]":
                        valida=true;
                        codigo=2;
                        break;
                    case "3":
                    case "[3]":
                        valida=true;
                        codigo=3;
                        break;
                    default:
                        System.out.println("Introduzca una acción válida");
                        break;
                
            }
        }
        
        String []partes = cartelera.split("\\r\\n|\\n|\\r");
        String []pelicula_elegida= partes[codigo+1].split(" ");
        
        String mensaje = "1003 COMPRAR " + pelicula_elegida[1];
        
        printer.println(mensaje);
        
        
    }
    
    public static void seleccion_asiento(String respuesta,Scanner entrada,PrintWriter printer){
        System.out.println(respuesta);
        String []partes = respuesta.split("\\r\\n|\\n|\\r");
        String []filas_columnas = partes[0].split(" ");
        String fila_sel="";
        String columna_sel = "";
        String asiento_final="";
        boolean ocupado = true;
        
        while(ocupado){
            System.out.println("Seleccione la fila");
            fila_sel=entrada.nextLine();
            
            while(fila_sel.equals("")){
                System.out.println("La cadena vacía no es válida");
                fila_sel=entrada.nextLine();
            }
           
            while(Integer.parseInt(fila_sel) > Integer.parseInt(filas_columnas[1]) || Integer.parseInt(fila_sel) <= 0){
                System.out.println("Introduzca una fila válida");
                fila_sel=entrada.nextLine();
            }

            System.out.println("Seleccione la columna");

            columna_sel=entrada.nextLine();
            
            while(columna_sel.equals("")){
                columna_sel=entrada.nextLine();
            }

            while(Integer.parseInt(columna_sel) > Integer.parseInt(filas_columnas[3]) || Integer.parseInt(columna_sel) <= 0){
                System.out.println("Introduzca una columna válida");
                columna_sel=entrada.nextLine();

            }
            
            asiento_final=fila_sel+"-"+columna_sel;
            String []codigo_asiento;
            
            ocupado=false;
            
            for(int i=0; i < partes.length && !ocupado; i++){
                codigo_asiento=partes[i].split(" ");
                
                if((codigo_asiento[1]).equals(asiento_final)){
                    ocupado=true;
                    System.out.println("El asiento ya está ocupado");
                }
            } 
        }
        
        printer.println(asiento_final); 
        printer.flush();
    }
    
    public static void validacion_cancelar(String asientos,Scanner entrada,PrintWriter printer){
        String cancelar;
        boolean poseida=false;
        String [] division_lineas=asientos.split("\\r\\n|\\n|\\r");
        
        while(!poseida){
            cancelar= entrada.nextLine();
            
            for(int i=0; i < division_lineas.length && !poseida; i++){
                String []codigo=division_lineas[i].split(" ");

                if(codigo[0].equals(cancelar)){
                    poseida=true;
                    String mensaje = "1006 CANCELAR "+ division_lineas[i];
                    printer.println(mensaje);
                }
            }
            
            if(!poseida){
                System.out.println(asientos);
                System.out.println("Introduzca un código de entrada el cual tenga en posesión(exactamente igual a como se muestra)");
            }
        }
        
    }
    
    public static void main(String[] args) {
        String mensaje="";
        String user="";         //Cadena que almacenará el usuario introducido por el cliente
        String pass="";         //Cadena que almacenará la contraseña del usuario
        boolean valido=false;   //Contiene si la acción es válida una vez se ha identificado
        String cartelera="";
        Scanner entrada_teclado=new Scanner(System.in);
        String []partes;
        String user_registro;
        String contra_registro;
        String contra_confirm;
        boolean terminar=false;

        // Nombre del host donde se ejecuta el servidor:
        String host="localhost";
        // Puerto en el que espera el servidor:
        int port=8989;

        // Socket para la conexión TCP
        Socket socketServicio=null;
        
        boolean login_valido=false;

        try {
            // Creamos un socket que se conecte a "hist" y "port":
            /*Bloque para establecer y comprobar que se ha establecido la conexión*/
            System.out.println("##**Estableciendo conexión**##");
            socketServicio = new Socket(host, port);
            BufferedReader input = new BufferedReader(new InputStreamReader(socketServicio.getInputStream()));
            PrintWriter printer = new PrintWriter(socketServicio.getOutputStream(),true);
            String conexion=input.readLine();
            
            if(conexion.equals("201 HELLO")){
                System.out.println("##**Conexión establecida correctamente**##");
            }
            
            mensaje = leer_todo_buffer(input);
            String copia=mensaje;
            
            while(!valido&&!terminar){
                System.out.println(copia);
                mensaje=entrada_teclado.nextLine();
                
                switch(mensaje){
                    case "0":
                    case "[0]":
                        System.out.println("\nIntroduzca su usuario:");
                        user=entrada_teclado.nextLine();
                        System.out.println("\nIntroduzca su contraseña:");
                        pass=entrada_teclado.nextLine();

                        mensaje="1001 LOGIN "+user+ " PASS "+pass;
                        printer.println(mensaje); 
                        printer.flush();
                        
                        mensaje=input.readLine();
                        partes=mensaje.split(" ");
                        
                        while(!partes[0].equals("200")){
                            System.out.println("Usuario o contraseña errorneos.\nIntroduzca un usuario y contraseñas validos");
                            System.out.println("Introduzca su usuario:");
                            user=entrada_teclado.nextLine();
                            System.out.println("Introduzca su contraseña:");
                            pass=entrada_teclado.nextLine();

                            mensaje="1001 LOGIN "+user+ " PASS "+pass;

                            printer.println(mensaje);
                            printer.flush();
                            mensaje=input.readLine();

                            partes=mensaje.split(" ");
                        }
                        
                        valido=true;
                        break;
                    case "1":
                    case "[1]":
                        mensaje="1002 LOGOUT";
                        printer.println(mensaje); 
                        printer.flush();
                        
                        mensaje=input.readLine();
                        partes=mensaje.split(" ");

                        if(partes[0].equals("500")){
                            System.out.println("!Hasta luego¡");
                        }
                        valido=true;
                        terminar=true;
                        break;
                    case "2":
                    case "[2]":
                        boolean registrado=false;
                        while(!registrado){
                            System.out.println("Introduzca el nombre usuario que desea:");
                            user_registro=entrada_teclado.nextLine();

                            System.out.println("Introduzca su contraseña");
                            contra_registro=entrada_teclado.nextLine();

                            System.out.println("Confirme su contraseña:");
                            contra_confirm=entrada_teclado.nextLine();

                            while(!contra_confirm.equals(contra_registro)){
                                System.out.println("La contraseña introducida y la confirmación no coinciden");
                                System.out.println("Introduzca su contraseña");
                                contra_registro=entrada_teclado.nextLine();

                                System.out.println("Confirme su contraseña:");
                                contra_confirm=entrada_teclado.nextLine();
                            }

                            printer.println("1000 SIGNUP USER " + user_registro + " PASS " + contra_confirm);

                            mensaje=input.readLine();

                            if(mensaje.equals("200 OK")){
                                System.out.println("Usuario registrado con éxito");
                                registrado=true;
                            }

                            else{
                                System.out.println("El usuario introducido ya estaba registrado");
                            }
                        }
                        break;
                    default:
                        printer.println(mensaje);
                        printer.flush();
                        
                        mensaje=input.readLine();
                        partes=mensaje.split(" ");
                        
                        if(partes[0].equals("300")){
                            System.out.println("No disponemos de esa opción.");
                            System.out.println("Intorduzca una acción válida");
                        }
                        break;
                }
            }
            if(!terminar){
                System.out.println("\nBienvenido " + user);

                mensaje=leer_todo_buffer(input);
                cartelera=leer_todo_buffer(input);
            }
            
            String respuesta_servidor;
            String respuesta;
            valido=false;
            while(!valido&&!terminar){
                System.out.println(mensaje);  
                System.out.println(cartelera);
                respuesta = entrada_teclado.nextLine();
                switch(respuesta){
                    case "0":
                    case "[0]":
                        seleccion_pelicula(entrada_teclado,cartelera,printer,user);
                        respuesta=leer_todo_buffer(input);
                        
                        if(respuesta.equals("303 ERROR Lo sentimos, la sala está llena hoy, elija otra película\n")){
                            System.out.println("La película seleccionada está llena.");
                        }
                        
                        else{
                            seleccion_asiento(respuesta,entrada_teclado,printer);

                            respuesta=input.readLine();

                            if(respuesta.equals("200 OK"))
                                System.out.println("Entrada Comprada con Exito");
                        }
                        break;
                    case "1":
                    case "[1]":
                        printer.println("1004 CANCELAR");
                        respuesta_servidor=leer_todo_buffer(input);
                        if(respuesta_servidor.equals("304 ERROR No tiene ninguna compra realizada\n"))
                            System.out.println("No tiene ninguna entrada comprada");
                        
                        else{
                            respuesta_servidor+="\n¿Que entrada desea cancelar?(escriba el codigo a la izquierda de la película)\n";
                            System.out.println(respuesta_servidor);
                            validacion_cancelar(respuesta_servidor,entrada_teclado,printer);
                            respuesta_servidor = input.readLine();

                            if(respuesta_servidor.equals("200 OK")){
                                System.out.println("Entrada devuelta con éxito");
                            }
                        }
                        
                        break;
                    case "2":
                    case "[2]":
                        printer.println("1005 VER");
                        respuesta_servidor=leer_todo_buffer(input);
                        if(respuesta_servidor.equals("304 ERROR No tiene ninguna compra realizada\n"))
                            System.out.println("No tiene ninguna compra realizada");
                        
                        else
                            System.out.println(respuesta_servidor);
                        break;
                    case "3":
                    case "[3]":
                        printer.println("1002 LOGOUT");
                        respuesta=input.readLine();
                        
                        if(respuesta.equals("500 BYE !Hasta la proxima¡")){
                            System.out.println("¡Hasta la próxima!");
                            terminar=true;
                        }
                        break;
                    default:
                        System.out.println("Introduzca una acción válida");
                        mensaje=entrada_teclado.nextLine();
                }
            }
            
            System.out.println("Cliente termina con éxito");
            socketServicio.close();
        }catch(IOException e){
            System.out.println("Error en el cliente");
        }
    }
    
}
