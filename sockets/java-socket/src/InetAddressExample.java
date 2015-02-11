import java.net.InetAddress;
import java.net.UnknownHostException;

public class InetAddressExample {

	public static void main(String[] args) {
		try {
			InetAddress inetAddress = InetAddress.getLocalHost();
			System.out.println(inetAddress.getHostAddress()+" && "+inetAddress.getHostName());
		} catch (UnknownHostException e) {

			e.printStackTrace();
		}
	}

}
