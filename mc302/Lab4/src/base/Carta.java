package base;

import java.util.UUID;

public class Carta {
	
	private UUID id;
	private String nome;
	private int custoMana;
	
	public Carta(UUID id, String nome, int custoMana) {
		this.id = id;
		this.nome = nome;
		this.custoMana = custoMana;
	}
	
	public Carta(String nome, int custoMana) {
		this.nome = nome;
		this.custoMana = custoMana;
	}
	
	public UUID getId() {
		return id;
	}


	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public int getCustoMana() {
		return custoMana;
	}

	public void setCustoMana(int custoMana) {
		this.custoMana = custoMana;
	}
	
	public void usar(Carta alvo){
		
	}
	
	public String toString() {
		String out = getNome() + " (ID: " + getId() + ")\n";
		out = out + "Custo de Mana = " + getCustoMana()+ "\n";
		return out;
	}

}
