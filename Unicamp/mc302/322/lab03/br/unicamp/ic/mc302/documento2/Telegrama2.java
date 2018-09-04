package br.unicamp.ic.mc302.documento2;

public class Telegrama2 extends Documento2 {

    private String hora;
    
    public void registrar() {
        System.out.println( "Registra o Telegrama.");
    }
    
    public void pagar() {
	    System.out.println("Paga o Telegrama.");    
    }
}