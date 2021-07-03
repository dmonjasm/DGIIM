/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package servidorcine;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

/**
 *
 * @author daniel
 */
public class ServidorCine {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // Puerto de escucha
        int port=8989;
        // array de bytes auxiliar para recibir o enviar datos.
        byte []buffer=new byte[256];
        // Número de bytes leídos
        int bytesLeidos=0;

        try {
                // Abrimos el socket en modo pasivo, escuchando el en puerto indicado por "port"
                ServerSocket server;
                server = new ServerSocket(port);

                System.out.println("Hemos abierto pasivamente el puerto " + port);


                // Mientras ... siempre!
                do {

                        // Aceptamos una nueva conexión con accept()
                        Socket socketServicio = null;
                        socketServicio = server.accept();

                        // Creamos un objeto de la clase ProcesadorYodafy, pasándole como 
                        // argumento el nuevo socket, para que realice el procesamiento
                        // Este esquema permite que se puedan usar hebras más fácilmente.
                        Cartelera creador = new Cartelera();
                        creador.inicial();
                        ProcesadorCine procesador=new ProcesadorCine(socketServicio);
                        procesador.start();

                } while (true);

        } catch (IOException e) {
                System.err.println("Error al escuchar en el puerto "+port);
        }
        
    }
    
}
