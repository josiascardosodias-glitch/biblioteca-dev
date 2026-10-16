function valor(preço) {
    if (typeof preço !== 'number' && isNaN(preço)) {
        console.log('Número invalido ou não encontrado')
    }

    if (preço < 2000) {
        console.log(`Sua compra foi de ${preço.toFixed(2)}`);
    } else {
        const desconto = preço - (preço*15) / 100;
        console.log(`Sua compra teve um desconto de 15% e com isso ficou ${desconto.toFixed(2)}`);
    }
}

valor(2000);

// A função valor ira ter um valor definido por "preço"
    // É feita uma analise para saber se o valor é nulo ou se é diferente de um "número"
        // Caso o valor dentor de "preço" seja maior que 2000, É aplicado um desconto de 15%. Se o valor foi menor, ele sera mostrado na tela