package br.unicamp.ic.mc302.conta;
public class ExemploConta {

    public static void main(String args[]) {

        Conta c1 = new Conta(100);
        double a=c1.saldo;
        c1.calcula( );

        ContaDePoup c2 = new ContaDePoup(100);
        double b = c2.saldo; 
        double i = c2.getIndice();
        c2.calcula( );
        c2.credita(10);
    }
}


