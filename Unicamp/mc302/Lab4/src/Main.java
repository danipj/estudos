
import java.util.UUID;

import base.Baralho;
import base.cartas.Lacaio;
import base.cartas.magia.Dano;
import base.cartas.magia.DanoArea;

public class Main {

	public static void main(String[] args) {
		Baralho baralho = new Baralho();
		baralho.adicionarCarta(new Lacaio(new UUID(1, 0),"Isabela", 5, 10, 30, 30));
		baralho.adicionarCarta(new Dano(new UUID(2, 0),"Tiro", 3, 3));
		baralho.adicionarCarta(new Lacaio(new UUID(3, 0),"Thamiris", 5, 15, 40, 50));
		baralho.adicionarCarta(new DanoArea(new UUID(4, 0),"Tiros grátis", 6, 10));
		
		System.out.println(baralho);
	}

}
