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
public class verificador {
    public void hacer_logout(Socket socket, PrintWriter output){
        String mensaje="500 BYE !Hasta la proxima¡";
        
        try{
            output.println(mensaje);
            output.flush();
            
            socket.close();
            
        }catch(IOException e){
            System.out.println("Error al hacer logout");
        }
        
    }
    
    public boolean hacer_login(Socket socket, PrintWriter output, BufferedReader input, String identidad){
        boolean encontrado=false;
        try{
        File archivo = new File("data/usuarios.txt");
        FileReader fr= new FileReader(archivo);
        BufferedReader br = new BufferedReader(fr);
      
        String []partes = identidad.split(" ");
        String usuario=br.readLine();
        String contra=br.readLine();
        
        while(!encontrado && usuario!=null){
            if(partes[2].equals(usuario)){
                if(partes[4].equals(contra)){
                    System.out.println("Servidor manda 200 OK");
                    output.println("200 OK");
                    output.flush();
                    encontrado=true;
                }
            }
            
            usuario = br.readLine();
            contra= br.readLine();
        }
        
        if(!encontrado){
            System.out.println("Servidor manda 301 ERROR Usuario o password no existen");
            output.println("301 ERROR Usuario o password no existen");
            output.flush();
        }
     
        fr.close();
        
        }catch(IOException e){
            System.out.println("Error al verificar el login");
        }
        
        return encontrado;
    }
    
    public boolean hacer_signup(PrintWriter printer, BufferedReader input,String user, String contra){
        boolean ya_registrado=false;
        try{
        String usuario_registrado;
        
        File archivo = new File("data/usuarios.txt");
        FileReader fr= new FileReader(archivo);
        BufferedReader br = new BufferedReader(fr);
        
        while((usuario_registrado=br.readLine())!= null&&!ya_registrado){
            if(usuario_registrado.equals(user)){
                ya_registrado=true;
            }
            
            usuario_registrado=br.readLine();
        }
        
        if(ya_registrado){
            System.out.println("Servidor manda 305 ERROR");
            printer.println("305 ERROR Usuario ya registrado");
            printer.flush();
            
            return false;
        }
        
        else{
            br.close();
            fr.close();

            FileWriter escribir = new FileWriter("data/usuarios.txt",true);
            PrintWriter escritor = new PrintWriter(escribir);

            escritor.println(user);
            escritor.println(contra);

            escritor.close();
            escribir.close();
            
            ya_registrado=true;
            
            System.out.println("Servidor manda 200 OK");
            printer.println("200 OK");
            printer.flush();
            return ya_registrado;
        }

        }catch(IOException e){
            System.out.println("Error al verificar el signup");
        } 
        
        return ya_registrado;
    }
}
