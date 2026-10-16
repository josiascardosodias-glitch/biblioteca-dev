function troco(notas) {
if (typeof notas !== 'number' || isNaN(notas)) {
    console.log('[ERRO] Valor inválido ou não encontrado');
    return; // encerra a função imediatamente, caso os valores estejam dentro dos parametros 
}

const denom = [100, 50, 20, 10, 5, 1]; // cria um array com o valor das notas em ordem decrescente
const contagem = {}; // guarda as informações dentro do array

for (const d of denom) {
    contagem[d] = Math.floor(notas / d);
    notas = notas % d;
} // A estrutura for...of faz com que os parametros se repitam até que a validação do código acabe
        // d é o valor da nota e denom é a variavel que guarda as notas 
            // match.floor descarta as decimais, guarda dentro do objeto
                // 'notas = notas % d' atualiza os valores que ainda precisam ser trocado  
console.log('Troco:', contagem);
return contagem; // retorna o objeto final
}

const resultado = troco(22051);

//  mach.floor serve para que notas decimais, ou seja, números quebrados. Não sejam devolvidas, porque o mach.floor vai arredondar elas para baixo.
// "notas = notas % d" vai fazsr com que a lógica do programa funcione corretamente. Ele até funciona sem, mas teria a chance de ocorrer erros.