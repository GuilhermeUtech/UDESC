import java.io.*;
import java.net.*;

public class Server{
	public static void main(String[] args){
		DatagramSocket socketAberto = null;
		byte[] buffer = new byte[256];
		while(true){
			socketAberto = new DatagramSocket(buffer, buffer.length);
			/*
			DatagramSocket representa um socket para enviar e receber datagramas.
			*/
		}
	}
}