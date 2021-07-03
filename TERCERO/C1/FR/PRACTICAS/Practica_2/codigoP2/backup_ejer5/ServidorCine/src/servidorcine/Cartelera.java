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
import java.io.FileWriter;

/**
 *
 * @author daniel
 */
public class Cartelera{
    public void inicial(){
        try{
        File archivo = new File("data/cartelera.txt");
        FileReader fr= new FileReader(archivo);
        BufferedReader br = new BufferedReader(fr);
        boolean creado=true;
        String linea;
        
        while(creado){
            if((linea = br.readLine()) == null){
                creado=false;
            }
            
            else{
                String []pelicula=linea.split(" "); //pelicula[1] es el nombre de la película
                String path = "data/"+pelicula[1] + ".txt";
                
                File archivo_pelicula = new File(path);
                
                if(!archivo_pelicula.exists()){
                    if(archivo_pelicula.createNewFile()){
                        System.out.println("Se ha creado el archivo correctamente");
                        
                        FileWriter escrib_pel = new FileWriter(path);
                        PrintWriter escritor = new PrintWriter(escrib_pel);

                        escritor.println("12-20");
                        escritor.close();
                        escrib_pel.close();  
                    }
                    
                    else{
                        System.out.println("Error al crear el archivo");
                        System.exit(-1);
                    }
                }                
            }
        }
        }catch(IOException e){
            System.out.println("Error al iniciar los archivos peliculas");
        }
        
    }
    public void mostrarCartelera(PrintWriter printer){
        try{
        File archivo = new File("data/cartelera.txt");
        FileReader fr= new FileReader(archivo);
        BufferedReader br = new BufferedReader(fr);
        
        String linea="";
        String texto="La Cartelera Actual es:\n";
        
        while((linea = br.readLine())!= null){
                    texto += linea + "\n";
        }
        
        printer.println(texto);
        printer.flush();
        
        }catch(IOException e){
            System.out.println("Error al consultar la cartelera");
        }
    }
}
