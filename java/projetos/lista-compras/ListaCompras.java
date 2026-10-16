package crud_compras;

import java.util.ArrayList;
import java.util.List;

public class ListaCompras {
    private List<String> produtos;

    public ListaCompras() {
        this.produtos = new ArrayList<>();
    }

    public void adicionar(String produto) {
        produtos.add(produto);
    }

    public void remover(String produto) {
        produtos.remove(produto);
    }

    public List<String> listar() {
        return produtos;
    }

    public void marcarComprado(String produto) {
        int index = produtos.indexOf(produto);
        if (index != -1) {
            produtos.set(index, produto + " - comprado");
        }
    }

    public int total() {
        return produtos.size();
    }

    public static void main(String[] args) {
        ListaCompras lista = new ListaCompras();
        lista.adicionar("Arroz");
        lista.adicionar("Feijão");
        lista.adicionar("Leite");
        lista.marcarComprado("Arroz");
        lista.remover("Leite");

        for (String produto : lista.listar()) {
            System.out.println(produto);
        }

        System.out.println("Total: " + lista.total());
    }
}
