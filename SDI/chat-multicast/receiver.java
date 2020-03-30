import java.io.*;
import java.net.*;

public class Receiver{
	public static void main(String[] args){
		DatagramPacket pacote;
		MulticastSocket socket = new MulticastSocket(8888);
		/*fazendo a bind pro multicast ser nessa porta*/
		byte[] buffer = new byte[256];

		InetAdress endereco = InetAdress.getByName("224.0.0.2");
		socket.join(endereco);
		/*Dando JOIN no grupo do multicast*/

		while(true){
			pacote = new DatagramPacket(buffer, buffer.length);
			socket.receive(pacote);
			String mensagem = new String(pacote, 0, pacote.lenght());
			System.out.println("Endereço: "+pacote.getAdress() + "conteúdo: "+ mensagem);
		}
	}
}