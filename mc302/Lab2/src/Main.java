

public class Main {

	public static void main(String[] args) {
		CartaLacaio lac1 = new CartaLacaio(1, "Frodo Bolseiro", 2, 1, 1);
		CartaLacaio lac2 = new CartaLacaio(2, "Aragorn", 5, 7, 6);
		CartaLacaio lac3 = new CartaLacaio(3, "Legolas", 8, 4, 6);

		CartaMagia mag1 = new CartaMagia(4, "You shall not pass", 4, true, 7);
		CartaMagia mag2 = new CartaMagia(5, "Telecinese", 3, false, 2);
		
		//1 - os atributos não usados pelo construtor foram iniciados com zero
		CartaLacaio lac4 = new CartaLacaio(6, "Lalala", 8);
		System.out.println(lac4);
		
		//2 
		lac1.setAtaque(lac3.getAtaque());
		System.out.println(lac1);
		
		//3 - é escrito apenas o endereço do objeto
		System.out.println(mag2);
		
		//4 - são objetos aparentemente iguais
		CartaLacaio lac5 = new CartaLacaio(lac2);
		System.out.println(lac5 + "\n"+ lac2);
		
		//5 - não é possível acessar atributos private fora da classe, para isso criamos
		//funções get e set. Seus objetivos são impedir que outras areas do programa
		//acessem esses atributos, o que pode causar conflitos
		System.out.println(mag1.nome);
		System.out.println(mag1.getNome());
		
		//6
		lac3.buffar(5);
		lac5.buffar(3, 5);
		System.out.println(lac3 + "\n"+ lac5);
	}

}
