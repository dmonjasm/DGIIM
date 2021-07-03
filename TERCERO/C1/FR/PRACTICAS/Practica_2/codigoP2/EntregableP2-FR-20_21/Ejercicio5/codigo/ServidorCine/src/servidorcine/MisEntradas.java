/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package servidorcine;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Random;

/**
 *
 * @author daniel
 */
public class MisEntradas {
    public boolean vermis_entradas(String user, PrintWriter printer){
        boolean funciona =false;
        try{
            String path="data/"+user+".txt";
            File archivo = new File(path);
            
            if(!archivo.exists()){
                System.out.println("Servidor manda 304 ERROR No tiene ninguna compra realizada\n");
                printer.println("304 ERROR No tiene ninguna compra realizada\n");
                printer.flush();  
                return funciona;
            }
            
            else{
                FileReader fr = new FileReader(archivo);
                BufferedReader br = new BufferedReader(fr);

                String linea="";
                String texto="Entradas reservadas por "+ user +":\n";

                while((linea=br.readLine()) != null){
                    if(linea != "")
                        texto +=linea + "\n";
                }

                fr.close();
                System.out.println("Servidor manda las entradas ya reservadas");
                printer.println(texto);
                printer.flush();
                funciona=true;
                return funciona;
            }
            
        }catch(IOException e){
            System.out.println("Error al consultar mis entradas actuales");
        }
        
        return funciona; 
    }
    
    public void comprar_entrada(String user, String pelicula, PrintWriter printer,BufferedReader input){
        try{
            Random referencia = new Random();
            String path_pelicula="data/"+pelicula+".txt";
            String path_usuario="data/"+user+".txt";
            File archivo_pelicula = new File(path_pelicula);
            File archivo_usuario = new File(path_usuario);
            
            if(!archivo_usuario.exists()){
                if(archivo_usuario.createNewFile()){}
                
                else{
                    System.exit(-1);
                }      
            }
            
            FileReader fr_usuario = new FileReader(archivo_usuario);
            FileReader fr_pelicula = new FileReader(archivo_pelicula);
            BufferedReader br_usuario = new BufferedReader(fr_usuario);
            BufferedReader br_pelicula = new BufferedReader(fr_pelicula);
            
            String cabecera = br_pelicula.readLine();
            String [] filas_columnas = cabecera.split("-");
            
            String texto="Filas " + filas_columnas[0] + " Columnas " + filas_columnas[1] + "\n"
                        + "Asientos ocupados:\n";
            String linea="";
            int contador=0;
            
            while((linea=br_pelicula.readLine())!=null){
                texto += linea + "\n";
                contador++;
            }
            
            if(contador==(Integer.parseInt(filas_columnas[0])*Integer.parseInt(filas_columnas[1]))){
                System.out.println("Servidor manda 303 ERROR Lo sentimos, la sala está llena hoy, elija otra película\n");
                printer.println("303 ERROR Lo sentimos, la sala está llena hoy, elija otra película\n");
                printer.flush();    
            }
            
            else{

                texto += "De los asientos restantes, ¿cual desea reservar?\n";

                printer.println(texto);
                printer.flush();

                String asiento;

                while((asiento = input.readLine()) == null){}

                int codigo=referencia.nextInt(1000000);
                String entrada_reserva= codigo + " " + pelicula + " " + asiento;
                String comprada = codigo + " " + asiento + " " + user;

                FileWriter fw_pelicula = new FileWriter(path_pelicula,true);
                FileWriter fw_usuario = new FileWriter(path_usuario,true);

                PrintWriter print_pelicula = new PrintWriter(fw_pelicula);
                PrintWriter print_usuario = new PrintWriter(fw_usuario);

                print_pelicula.println(comprada);
                print_usuario.println(entrada_reserva);

                fr_pelicula.close();
                fr_usuario.close();
                fw_pelicula.close();
                fw_usuario.close();

                System.out.println("Servidor manda 200 OK\n");
                printer.println("200 OK");
                printer.flush();
            }
            
        }catch(IOException e){
            System.out.println("Error en la compra de entradas");
        }
    }
    
    public void cancelar_entrada(String user, PrintWriter printer,BufferedReader input){
        try{
            boolean tiene=false;
            tiene=vermis_entradas(user,printer);      //Se manda al usuario para que vea las entradas que tiene reservadas
            if(tiene){
                String respuesta = input.readLine();    //Se recibe cual es la pelicula que el usuario ha decidido devolver
                String[]partes=respuesta.split(" ");
                String pelicula = partes[3];
                String path_pelicula="data/"+pelicula+".txt";
                String path_usuario="data/"+user+".txt";

                File archivo_usuario = new File(path_usuario);
                FileReader fr_usuario = new FileReader(path_usuario);
                BufferedReader br_usuario = new BufferedReader(fr_usuario);

                String excluir = partes[2] + " " + partes[3] + " " + partes[4];
                String registro_pelicula="";
                String linea="";

                while((linea=br_usuario.readLine())!=null){
                    if(!linea.equals(excluir)){
                        registro_pelicula += linea + "\n";
                    }
                }

                br_usuario.close();
                fr_usuario.close();

                archivo_usuario.delete();
                String[]insertar = registro_pelicula.split("\\r\\n|\\n|\\r");               
                
                if(!insertar[0].equals("")){
                    archivo_usuario = new File(path_pelicula);
                    archivo_usuario.createNewFile();

                    FileWriter escribir_usuario = new FileWriter(path_usuario,true);
                    PrintWriter escritor_usuario= new PrintWriter(escribir_usuario);

                     for(int i=0; i < insertar.length; i++){
                        if(!insertar[i].equals("")){
                            escritor_usuario.println(insertar[i]);
                        }
                    }

                    escritor_usuario.close();
                    escribir_usuario.close();
                }

                File archivo_pelicula = new File(path_pelicula);
                FileReader fr_pelicula = new FileReader(archivo_pelicula);
                BufferedReader br_pelicula = new BufferedReader(fr_pelicula);

                excluir = partes[2] + " " + partes[4] + " " + user;
                registro_pelicula="";
                linea="";

                while((linea=br_pelicula.readLine())!=null){
                    if(!linea.equals(excluir)){
                        registro_pelicula += linea + "\n";
                    }
                }

                insertar = registro_pelicula.split("\\r\\n|\\n|\\r");


                br_pelicula.close();
                fr_pelicula.close();

                archivo_pelicula.delete();
                archivo_pelicula = new File(path_pelicula);

                archivo_pelicula.createNewFile();

                FileWriter escribir = new FileWriter(path_pelicula,true);
                PrintWriter escritor = new PrintWriter(escribir);

                for(int i=0; i < insertar.length; i++){
                    if(!insertar[i].equals("")){
                        escritor.println(insertar[i]);
                    }
                }

                escritor.close();
                escribir.close();
                
                System.out.println("Servidor manda 200 OK");
                printer.println("200 OK");
                printer.flush();
            }
        }catch(IOException e){
            System.out.println("Error al cancelar una entrada");
        }
        
    }
}
