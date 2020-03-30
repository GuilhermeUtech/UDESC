import java.io.*;
import java.net.*;

public class Sender{
	final int PORT = 8888;
	socket = new DatagramSocket(); /*Socket usado para enviar socket.send()*/
	String mensagem;
	int contador = -1;
	byte[] buffer;
	public static void main(String[] args){
		while(true){
			contador++;
			mensagem = "Mensagem: BLABLA " + contador;
			/*transformar a mensagem em bytes*/
			buffer = mensagem.getBytes();
			/*representação de endereço ip com InetAdress, o endereço
			IP que eu coloquei foi por causa do tutorial, não sei o que 
			tem que por ali ainda*/
			InetAddres enderecoIP =  InetAddres.getByName("224.0.0.2");
			DatagramSocket pacoteSaida = new DatagramSocket(buffer, buffer.length, endereço, PORT);
			/*Datagrama criado com o conteúdo em bytes da saida, o tamanho do conteúdo, o endereço ip e a porta*/
			socket.send(pacoteSaida);
			System.out.println("Conteúdo saida: " mensagem);
		}
	}
}