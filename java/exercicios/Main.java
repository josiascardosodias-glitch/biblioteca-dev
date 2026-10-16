import java.util.ArrayList; // ArrayList é uma função para poder criar arrays que não possuem definições de espaço pré definidos
public class Main { // A primeira classe sempre terá que ser public e deverá ter o mesmo nome do arquivo
    public static void main(String[] args) {
        int idade = 21;
        String nome = "josias";
        float altura = 1.84f;
        boolean bool = true;

        int[] coleçãoDeValores = {1, 5, 6, 12, 7};

        char[] letrasDoMeuNome = {'j', 'o', 's', 'i', 'a', 's'};
        System.out.println(letrasDoMeuNome.length);
        System.out.println(3);

        ArrayList<String> nomes = new ArrayList<>(); // Exemplo de ArrayList
        nomes.add("josias");
        nomes.add("carla");
        nomes.add("roberto");

        System.out.println(nomes.get(0));

        nomes.remove(0);

        System.out.println(nomes.get(0));

        for (int i = 0; i < nomes.size(); i ++) {
            System.out.println(nomes.get(i));
        }

        int cont = 0;
        while (cont < 3) {
            System.out.println("Estou repetindo");
            cont++;
        }

        double resultado = 0.0;
        int resultadoInt = (int) resultado;

        String meuString = "10";
        int meuInt = Integer.parseInt(meuString);

        if(nome.equals("josias")) {
            System.out.println("Verdadeiro");
        } else if (nome.equals("joão")) {
            System.out.println("SEu nome é Josias");
        } else {
            System.out.println("Falso");
        }

        System.out.println(coleçãoDeValores[2]);
    }
}