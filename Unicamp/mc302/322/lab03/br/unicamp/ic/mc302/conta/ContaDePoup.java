package br.unicamp.ic.mc302.conta;

class ContaDePoup extends Conta {
    private double indice; // indice de rendimento
    public ContaDePoup(double sal) { super(sal); }
    public double calcula( ){  // calcula e deposita o rendimento
        double i = getIndice()*saldo; 
        saldo=saldo+i;
        return i;
    }
    public void retira(double v) { saldo = saldo - v; }
	public double getIndice() {
		return indice;
	}
	public void setIndice(double indice) {
		this.indice = indice;
	}
} // fim da classe ContaDePoup

