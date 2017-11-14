<<<<<<< HEAD
public class OnibusOvernight extends Onibus{
	private boolean servicoDeBordo;
	private boolean televisao;
	
	public OnibusOvernight( int km, boolean sb, boolean tv) {
		super(km);
		setServicoDeBordo(sb);
		setTelevisao(tv);
		this.totalLugares = 20;
	}
	public boolean hasTelevisao() {
		return televisao;
	}
	public void setTelevisao(boolean televisao) {
		this.televisao = televisao;
	}
	public boolean hasServicoDeBordo() {
		return servicoDeBordo;
	}
	public void setServicoDeBordo(boolean servicoDeBordo) {
		this.servicoDeBordo = servicoDeBordo;
	}
=======
import java.util.GregorianCalendar;

public class OnibusOvernight extends Onibus{

	public OnibusOvernight(String destino, GregorianCalendar partida) {
		super(destino, partida);
		this.totalLugares = 20;
	}
>>>>>>> 255c5b41d88d652e2336f88a6412b8eab764dda3

}
