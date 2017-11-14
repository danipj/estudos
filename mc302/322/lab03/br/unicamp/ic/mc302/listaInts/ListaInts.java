package br.unicamp.ic.mc302.listaInts;
/*
 * Uma classe para demonstrar o uso de listas parametrizadas (ArrayList) em Java
 * concentrando no uso da estrutura de laço "for each".
 */

import java.util.ArrayList;

public class ListaInts {
    ArrayList<Integer> lista;

    // Constructor
    ListaInts() {
        lista = new ArrayList<Integer>();
    }

    // método de adição de elementos para o ArrayList
    // Outros métodos podem ser adicionados de maneira similar
    void add(Integer n) {
        lista.add(n);
    }

    // n é um elemento da lista?
    Boolean elem(Integer n) {
        for (Integer x: lista) {
            if (x.equals(n)) return true;
        }
        return false;
    }

    // Soma dos elementos da lista
    Integer sum() {
        Integer total = 0;
        for (Integer x: lista) {
            total = total + x;
        }
        return total;
    }

    // Encontra o menor elemento da lista
    // A lista precisa ter pelo menos um elemento
    Integer minimum() {
        // mantém o menor elemento encontrado na lista
        // Inicializa com o primeiro elemento da lista.
        Integer smallestSoFar = lista.get(0);
        for (Integer x: lista) {
            if (x < smallestSoFar)
                smallestSoFar = x;
        }
        return smallestSoFar;
    }

    // Uma outra versão, utilizando laços padrões.
    Integer minimum_version2() {
        Integer smallestSoFar = lista.get(0);
        for (int index = 1; index < lista.size(); index++) {
            if (lista.get(index) < smallestSoFar)
                smallestSoFar = lista.get(index);
        }
        return smallestSoFar;
    }

    // Usa o método toString da classe base para uma representação textual
    // da lista. Isto será melhor entendido quando estudarmos herança.
    public String toString() {
        return lista.toString();
    }

} // Fim da classe ListLints

