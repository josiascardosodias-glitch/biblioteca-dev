public class Ex02 {
    public static void main(String[] args) {
        double[] notas = {7.5, 8.0, 5.5, 9.0, 6.0};

        double soma = 0.0;
        for(int i = 0; i < notas.length; i ++) {
            System.out.println(notas[i]);
            soma += notas[i];
        }

        double media = soma / notas.length;

        if (media >= 7) {
            System.out.println("Aprovado");
        }
        else if (media >= 5) {
            System.out.println("Recuperação");
        } else {
            System.out.println("Reprovado");
        }
    }
}