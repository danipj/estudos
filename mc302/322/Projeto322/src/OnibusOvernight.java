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

}
