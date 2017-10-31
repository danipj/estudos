package br.unicamp.ic.mc302.chamadaMetodos;

public class PrincipalMetodo {

	public static void main(String[] args) {
		ContaMeta conta1 = new ContaMeta();
		ContaMeta conta2 = new ContaMeta();

		conta1.creditar(10);
		conta2.creditar(15);
		conta1.creditar(25);
		conta2.creditar(5);
		conta2.creditar(10);

		System.out.println("OBJETO \"conta1\":"); // (a)
		conta1.mostrarNumMsgObjeto(); // (a)
		System.out.println("OBJETO \"conta2\":"); // (a)
		conta2.mostrarNumMsgObjeto(); // (a)
		// System.out.println("CLASSE \"ContaMeta\":"); //(b)
		// ContaMeta.mostrarNumMsgClasse(); //(b)

	}

}
