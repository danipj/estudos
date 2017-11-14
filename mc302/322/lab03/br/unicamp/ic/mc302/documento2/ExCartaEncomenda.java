package br.unicamp.ic.mc302.documento2;

import java.sql.Date;

public class ExCartaEncomenda {
 public static void main(String[] args) {
	CartaRegistrada cRegistrada = new CartaRegistrada(new Date(20010101), "Campinas");
	Encomenda encomenda = new Encomenda(new Date(20030909), "Indaiatuba", "Segredo");
	cRegistrada.imprimir();
	encomenda.imprimir();
 }
}
