import java.net.*;

public class Speditore {
	
	public static void main (String args[]) {
		
	DatagramSocket s = new DatagramSocket();
    s.setBroadcast(true);
    DatagramPacket dp = new DatagramPacket("insert data here".getBytes(), "insert data here".length(), new InetSocketAddress("255.255.255.255", 5000));
    s.send(dp);
		
	}
}

