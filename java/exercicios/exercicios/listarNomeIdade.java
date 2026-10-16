package exercicios;

import java.awt.List;
import java.util.*;

public class listarNomeIdade {
    private Map <String, Integer> pessoas = new HashMap<>();

    public void adicionarPessoas(String nome, int idade) {
        pessoas.put(nome, idade);
    }

    public void listarPessoas() {
        if (pessoas.isEmpty()) {
            System.out.println("Nenhuma pessoa foi casdastrada");
            return;
        }
        for (Map.Entry<String,Integer> pessoa : pessoas.entrySet()) {
            System.out.println(pessoa.getKey() + " - " + pessoa.getValue());
        }
    }

    public static void main(String[] args) {
        listarNomeIdade lista = new listarNomeIdade();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("Digite um nome (ou 'sair' para encerrar o programa): ");
            String nome = scanner.nextLine();

            if (nome.equalsIgnoreCase("sair")) {
                break;
            }

            System.out.println("Digite sua idade: ");
            int idade;
            try {
                idade = Integer.parseInt(scanner.nextLine());
            } catch (NumberFormatException e) {
                System.out.println("Idade inválida");
                continue;
            }

            lista.adicionarPessoas(nome,idade);

        }

        System.out.println("\n--- Lista Pessoas ---");
        lista.listarPessoas();

        scanner.close();
    }
}