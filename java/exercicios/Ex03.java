import java.util.ArrayList;

public class Ex03 {
    public static void main(String[] args) {
        ArrayList<String> compras = new ArrayList<>();
        compras.add("bola");
        compras.add("camisetas");
        compras.add("panelas");
        compras.add("calçado");
        compras.add("alface");

        for (int i = 0; i < compras.size(); i ++) {
            System.out.println(compras.get(i));
        }

        compras.remove(0);

        for (String item : compras) {
            System.out.println(item); // for-each: é uma forma mais lispa e atualizada de utilizar uma estrutura for
        }

        if (compras.size() < 3) {
            System.out.println("lista pequena");
        } else {
            System.out.println("lista grande");
        }
    }

}
