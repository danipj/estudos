

public class Main {

	public static void main(String[] args) {
		CartaLacaio lacaio = new CartaLacaio(1, "Lacraia", 100, 100, 100, 10);
		
		//Como Magias são outra classe, iniciando outra contagem de IDs
		CartaMagia magia = new CartaMagia(1, "Arremesso", 5, true, 5);
		
		System.out.println(lacaio + "\n" + magia);

	}

}
