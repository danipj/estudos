public class Onibus {
	
	private int[] lugares;
	protected int totalLugares;
	private int quilometragem;
	
	
	public Onibus(int km) {
		super();
		this.totalLugares = 40;
		this.setQuilometragem(km);
		lugares = new int[totalLugares];
		//marca todos os lugares como vagos
		for(int i=0;i<totalLugares;i++)
			lugares[i] = 0; 
	}
	
	
	public boolean estaVago(char poltrona, int fileira) throws LugarException{
		if(fileira>totalLugares/4){
			throw new LugarException("Fileira não existe");
		}
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
		default:
			throw new LugarException("Poltrona não existe");
		}
	}
	
	public void reservar(char poltrona, int fileira) throws LugarException{
		if(fileira>totalLugares/4){
			throw new LugarException("Fileira não existe");
		}
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
		default:
			throw new LugarException("Poltrona não existe");
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
	
	public int getQuilometragem() {
		return quilometragem;
	}
	
	public void setQuilometragem(int quilometragem) {
		this.quilometragem = quilometragem;
	}
	
	public String toString(){
		String r;
		r="Poltronas:";
		r+="\n- A B - C D";
		for(int i=1;i<=totalLugares/4;i++)
			r+="\n"+i+" "+lugares[(i-1)*4]+" "+lugares[i*4-3]+" - "+lugares[i*4-2]+" "+lugares[i*4-1];
		return r;
	}
	
}
