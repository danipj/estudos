import java.text.SimpleDateFormat;
import java.util.GregorianCalendar;

public class Viagem {
	public static final int precoLitro = 5;
	
	private String origem;
	private String destino;
	private GregorianCalendar partida;
	private Onibus onibus;
	private int distancia;
	
	public Viagem(String origem,String destino, int distancia,GregorianCalendar partida, Onibus o) {
		super();
		this.origem = origem;
		this.destino = destino;
		this.partida = partida;
		this.distancia = distancia;
		this.setOnibus(o);
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
	public int getDistancia() {
		return distancia;
	}

	public void setDistancia(int distancia) {
		this.distancia = distancia;
	}

	public void setPartida(GregorianCalendar partida){		
		this.partida = partida;
	}

	public Onibus getOnibus() {
		return onibus;
	}

	public void setOnibus(Onibus onibus) {
		this.onibus = onibus;
	}
	
	public String getOrigem() {
		return origem;
	}

	public void setOrigem(String origem) {
		this.origem = origem;
	}
	
	public String getPartidaFormatted(){
	    SimpleDateFormat fmt = new SimpleDateFormat("dd-M-yyyy H:m");
	    fmt.setCalendar(partida);
	    String dateFormatted = fmt.format(partida.getTime());
	    return dateFormatted;
	}
	
	public double calculaPreco() {
		double preco = distancia / getOnibus().getQuilometragem() * precoLitro * 1.25 ;
		if (getOnibus().getClass()==OnibusOvernight.class)
			preco += 10 + (((OnibusOvernight)getOnibus()).hasTelevisao()?10:0) + (((OnibusOvernight)getOnibus()).hasServicoDeBordo()?20:0);
		return preco;
	}
	
	public String toString(){
		String r = "Ônibus saindo de "+origem+" com destino a " + destino+" (Distância: "+distancia+"km)";
		r+="\nHorário de partida: "+getPartidaFormatted();
		r+="\nTipo de ônibus: "+(onibus.getClass()==OnibusOvernight.class?"VIP":"Comum");
		if(onibus.getClass()==OnibusOvernight.class){
			if(((OnibusOvernight)onibus).hasServicoDeBordo())
				r+="\nEquipado com serviço de bordo";
			if(((OnibusOvernight)onibus).hasTelevisao())
				r+="\nEquipado com televisão";
		}
		r+="\nPreço: "+calculaPreco();
		r+="\n"+onibus.toString();
		return r;
	}
}
