public class CartaLacaio {
	
	private int ID;
	private String nome;
	private int ataque;
	private int vidaAtual;
	private int vidaMaxima;
	private int custoMana;
	
	public CartaLacaio(int iD, String nome, int ataque, int vidaAtual, int vidaMaxima, int custoMana) {
		super();
		ID = iD;
		this.nome = nome;
		this.ataque = ataque;
		this.vidaAtual = vidaAtual;
		this.vidaMaxima = vidaMaxima;
		this.custoMana = custoMana;
	}
	
	
	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public int getAtaque() {
		return ataque;
	}

	public void setAtaque(int ataque) {
		this.ataque = ataque;
	}

	public int getVidaAtual() {
		return vidaAtual;
	}

	public void setVidaAtual(int vidaAtual) {
		this.vidaAtual = vidaAtual;
	}

	public int getVidaMaxima() {
		return vidaMaxima;
	}

	public void setVidaMaxima(int vidaMaxima) {
		this.vidaMaxima = vidaMaxima;
	}

	public int getCustoMana() {
		return custoMana;
	}

	public void setCustoMana(int custoMana) {
		this.custoMana = custoMana;
	}

	public int getID() {
		return ID;
	}

	public void setID(int ID) {
		this.ID = ID;
	}


	@Override
	public String toString() {
		String out = getNome() + " (ID: " + getID() + ")\n";
		out = out + "Ataque = " + getAtaque() + "\n";
		out = out + "Vida Atual = "+ getVidaAtual()+ "\n";
		out = out + "Vida Máxima = "+ getVidaMaxima()+ "\n";
		out = out + "Custo de Mana = " + getCustoMana()+ "\n";
		return out;
	}

	
}
