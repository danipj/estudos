package br.unicamp.ic.mc302.documento2;

public class ExemploDocumento2 {

	public static void main(String args[]) {
		
	    Documento2 doc = new Documento2();
	    
	    doc.editar();
	    doc.imprimir();
	    
	    Telegrama2 tel = new Telegrama2();
	    
	    // operações definidas por Telegrama
	    tel.registrar();
	    tel.pagar();
	    
	    // operações definidas por Documento
	    tel.editar();
	    tel.imprimir();
	    
	    Carta2 carta = new Carta2();
	    
	    // operações definidas por Carta
	    carta.anexar();
	    
	    // operações definidas por Documento
	    carta.editar();
	    carta.imprimir();
    }   
}