package br.unicamp.ic.mc302.oficina;

import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class ExemploOficina {
	public static void main(String[] args) {
		//criar 10 funcionarios sendo 1 gerente
		ArrayList<Funcionario> funcionarios = new ArrayList<Funcionario>();
		Random random = new Random();
		for (int i = 0; i < 9; i++) {
			funcionarios.add(new Funcionario(1200, (float) 0.10, random.nextInt(4), random.nextInt(4), random.nextInt(4)));
		}
		funcionarios.add(new Gerente(random.nextInt(4),random.nextInt(4),random.nextInt(4)));
		
		//programa
		@SuppressWarnings("resource")
		Scanner keyboard = new Scanner(System.in);
		
		System.out.println("Nro do funcionario ");
		int nFuncionario = keyboard.nextInt();
		if(funcionarios.get(nFuncionario-1).getClass()==Gerente.class)
			System.out.println("Funcionario é gerente");
		else
			System.out.println("Funcionario comum");
		System.out.println("Total de Tarefas 1 realizadas: "+funcionarios.get(nFuncionario-1).getTotal1());
		System.out.println("Total de Tarefas 2 realizadas: "+funcionarios.get(nFuncionario-1).getTotal2());
		System.out.println("Total de Tarefas 3 realizadas: "+funcionarios.get(nFuncionario-1).getTotal3());
		int t1 = funcionarios.get(nFuncionario-1).getTotal1()*15;
		int t2 = funcionarios.get(nFuncionario-1).getTotal2()*50;
		int t3 = funcionarios.get(nFuncionario-1).getTotal3()*40;
		float comissao = funcionarios.get(nFuncionario-1).getComissao()*(t1+t2+t3);
		System.out.println("Comissão total = "+comissao);
		System.out.println("Salario final = "+((float)funcionarios.get(nFuncionario-1).getSalario()+comissao));
	}
}
