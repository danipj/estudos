import java.text.SimpleDateFormat;
import java.util.GregorianCalendar;

public class Onibus {
	private String destino;
	private GregorianCalendar partida;
	private int[] lugares;
	protected int totalLugares;
	
	
	public Onibus(String destino, GregorianCalendar partida) {
		super();
		this.destino = destino;
		this.partida = partida;
		this.totalLugares = 40;
		lugares = new int[totalLugares];
		//marca todos os lugares como vagos
		for(int i=0;i<totalLugares;i++)
			lugares[i] = 0; 
	}
	public String getDestino() {
		return destino;
	}
	public void setDestino(String destino) {
		this.destino = destino;
	}
	public GregorianCalendar getPartida() {
		return partida;
	}
	public void setPartida(GregorianCalendar partida) {
		this.partida = partida;
	}
	
	public boolean estaVago(char poltrona, int fileira){
		if(fileira>totalLugares/4)
			return false;
		poltrona = Character.toUpperCase(poltrona);
		switch(poltrona){
		case 'A':
			if(lugares[(fileira-1)*4]==0)
				return true;
			return false;
		case 'B':
			if(lugares[fileira*4-3]==0)
				return true;
			return false;
		case 'C':
			if(lugares[fileira*4-2]==0)
				return true;
			return false;
		case 'D':
			if(lugares[fileira*4-1]==0)
				return true;
			return false;
		}
		return false;
	}
	
	public void reservar(char poltrona, int fileira){
		poltrona = Character.toUpperCase(poltrona);
		switch(poltrona){
		case 'A':
			lugares[(fileira-1)*4]=1;
			break;
		case 'B':
			lugares[fileira*4-3]=1;
			break;
		case 'C':
			lugares[fileira*4-2]=1;
			break;
		case 'D':
			lugares[fileira*4-1]=1;
			break;
		}
	}
	
	public int totalVagos(){
		int vagos= 0;
		for(int i=0;i<totalLugares;i++)
			if(lugares[i]==0)
				vagos++;
		return vagos;
	}
		
	public boolean estaCheio(){
		if(totalVagos()==0)
			return true;
		return false;
	}
	
	public String getPartidaFormatted(){
	    SimpleDateFormat fmt = new SimpleDateFormat("dd-M-yyyy H:m");
	    fmt.setCalendar(partida);
	    String dateFormatted = fmt.format(partida.getTime());
	    return dateFormatted;
	}
	
	public String toString(){
		String r = "Ônibus com destino a " + destino;
		r+="\nHorário de partida: "+getPartidaFormatted();
		r+="\nPoltronas:";
		r+="\n- A B - C D";
		for(int i=1;i<=totalLugares/4;i++)
			r+="\n"+i+" "+lugares[(i-1)*4]+" "+lugares[i*4-3]+" - "+lugares[i*4-2]+" "+lugares[i*4-1];
		return r;
	}
}
