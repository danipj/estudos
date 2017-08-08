
public class CartaMagia {
	private int id;
	private String nome;
	private int dano;
	private boolean area;
	private int custoMana;
	
	
	public CartaMagia(int id, String nome, int dano, boolean area, int custoMana) {
		super();
		this.id = id;
		this.nome = nome;
		this.dano = dano;
		this.area = area;
		this.custoMana = custoMana;
	}
	
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public int getDano() {
		return dano;
	}
	public void setDano(int dano) {
		this.dano = dano;
	}
	public boolean isArea() {
		return area;
	}
	public void setArea(boolean area) {
		this.area = area;
	}
	public int getCustoMana() {
		return custoMana;
	}
	public void setCustoMana(int custoMana) {
		this.custoMana = custoMana;
	}
	
	@Override
	public String toString() {
		String out = getNome() + " (ID: " + getId() + ")\n";
		out = out + "Dano = " + getDano() + "\n";
		out = out + "Area = "+ isArea()+ "\n";
		out = out + "Custo de Mana = " + getCustoMana()+ "\n";
		return out;
	}
	
}
