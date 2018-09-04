package br.unicamp.ic.mc302.conta;

class Conta {
    public double saldo; 
    public Conta (double sal) {saldo = sal;}
    public void credita(double valor) {saldo+= valor;}
    public double getSaldo ( ) {return saldo;}
	public void calcula() {
		// TODO Auto-generated method stub
		
	}
}
