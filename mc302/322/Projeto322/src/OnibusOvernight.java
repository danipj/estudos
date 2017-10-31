import java.util.GregorianCalendar;

public class OnibusOvernight extends Onibus{

	public OnibusOvernight(String destino, GregorianCalendar partida) {
		super(destino, partida);
		this.totalLugares = 20;
	}

}
