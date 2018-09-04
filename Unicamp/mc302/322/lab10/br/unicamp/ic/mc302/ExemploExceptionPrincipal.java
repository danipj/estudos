package br.unicamp.ic.mc302;

import br.unicamp.ic.mc302.exercicioExcecoes.*;

public class ExemploExceptionPrincipal {

	public static void main(String Arg[]) {
		ContaCor conta1 = new ContaCor("Josefina", 1000, 1, 1);
		ContaCor conta2 = new ContaCor("Serafim", 2000, 2, 2);
		System.out.println("*********************************************");
		System.out.println("********** Contas Ativas do Banco ***********");
		System.out.println("*********************************************");
		
		
		try {
			System.out.println("Conta #1 / Senha 1 / Saldo= R$" + conta1.getSaldo(1));
			System.out.println("Conta #2 / Senha 2 / Saldo= R$" + conta2.getSaldo(2));
		} catch (ContaCorExc e) { // tratador de exceção
			System.out.println("Erro: Não é possível ");
		}

		System.out.println("*********************************************");
		System.out.println("   ");
		System.out.println("--- Cliente deseja creditar R$-40 na Conta ---- ");

		try {
			conta1.creditaValor(-40); // valor inválido
		} catch (ContaCorExc e) { // tratador de exceção
			System.out.println("Erro: O valor solicitado para depósito é inválido");
		}
		System.out.println("   ");
		System.out.println("--- Cliente deseja debitar R$50000 na Conta #1 ---- ");
		try {
			conta1.debitaValor(5000, 1); // quantia a debitar é maior que saldo
		} catch (ContaCorExc e) { // tratador de exceção
			System.out.println("Erro: Saldo Insuficiente para o valor de débito solicitado");
		}

		System.out.println("   ");
		System.out
				.println("--- Cliente deseja ver o saldo da Conta#2 e fornece 9 como senha correspondente ---- ");

		// Ultimo bloco try/catch do método main().
		try {
			conta2.getSaldo(9); // senha incorreta
		}catch (SenhaInvalidaException e) {
			System.out.println("Erro: Não é possível fornecer o Saldo - Senha Incorreta");
		} catch (ContaCorExc e) { // tratador de exceção
			System.out.println("Erro: ContaCorExc");	
		}
		
		System.out.println("Fim");
		
		try {
			 conta2.mostraInformacoes(1);
			 } catch(ContaCorExc cce) {
			System.out.println("Erro: Não é possível mostrar as informações da conta.");
			}
	}
} // fim da classe ExemploExceptionPrincipal
