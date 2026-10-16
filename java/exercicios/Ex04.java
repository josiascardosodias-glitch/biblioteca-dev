import java.util.ArrayList;

public class Ex04 {
    public static void main(String[] args) {
        ArrayList<String> alunos = new ArrayList<>();
        alunos.add("josias");
        alunos.add("joão");
        alunos.add("alice");
        alunos.add("carla");

        ArrayList<Double> notas = new ArrayList<>();
        notas.add(9.0);
        notas.add(8.9);
        notas.add(8.8);
        notas.add(9.2);

        double soma = 0.0;
        double maior = notas.get(0);
        double menor = notas.get(0);
        for (int i = 0; i < alunos.size(); i ++) {
            soma += notas.get(i);
            if (notas.get(i) > maior) {
                maior = notas.get(i);
            }
            if (notas.get(i) < menor) {
                menor = notas.get(i);
            }
            System.out.println(
                    alunos.get(i) + " - " + notas.get(i)
            );
            if (notas.get(i) >= 7) {
                System.out.println("Aprovado");
            } else if (notas.get(i) >= 5) {
                System.out.println("Recuperação");
            } else {
                System.out.println("Reprovado");
            }
        }

        double media = soma / alunos.size();

        System.out.println("Media da turma: " + media);
        System.out.println("Maior nota da turma: " + maior);
        System.out.println("Menor nota da turma: " + menor);

        alunos.remove(0);
        notas.remove(0);

        for (int i = 0; i < alunos.size(); i ++) {
            System.out.println(
                    alunos.get(i) + " - " + notas.get(i)
            );
        }

    }
}
