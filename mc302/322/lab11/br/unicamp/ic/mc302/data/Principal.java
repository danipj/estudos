package br.unicamp.ic.mc302.data;

import java.util.Date;

public class Principal {

	public static void main(String Arg[]) {
		Date hoje = new Date();
		System.out.println(DateBR.extenso(hoje));
		System.out.println(DateBR.ddmmaa(hoje));
	}
}
