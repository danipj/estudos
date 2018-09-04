package util;

import base.cartas.Lacaio;

public class Util {
	public static int MAX_CARDS = 30;
	
	public static void buffar(Lacaio lac, int a) {
		lac.setAtaque(lac.getAtaque()+a);
	}
	
	public static void buffar(Lacaio lac, int a, int v) {
		lac.setAtaque(lac.getAtaque()+a);
		lac.setVidaAtual(lac.getVidaAtual()+v);
	}
	
	public static void alteraNomeFortalecido(Lacaio lac) {
		lac.setNome(lac.getNome()+ " Buffed");
	}
}
