package base.cartas.magia;

import java.util.UUID;

import base.Carta;

public class Magia extends Carta {

	public Magia(String nome, int custoMana) {
		super(nome, custoMana);

	}
	
	public Magia(UUID id, String nome, int custoMana) {
		super(id, nome, custoMana);

	}

}
