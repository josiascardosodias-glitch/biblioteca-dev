function troco(notas) {

    if (typeof notas !== "number" || isNaN(notas)) {
        console.log('ERRO: Valor ivalido ou não encontrado');
        
        return
    }

    const denom = [100, 50, 20, 10, 5, 1];
    const contagem = {};

    for (const d of denom) {
        contagem[d] = Math.floor(notas / d);
        notas = notas % d;
    }

    console.log('troco', contagem);
    return
}

troco(2052)