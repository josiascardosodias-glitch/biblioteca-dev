function fatorial(n) {
    let fatorial = 1 //fução abre a variavel que vai começar com o valor de 1
    for(let c = n;c > 1;c-=1) {
        fatorial *= c 
    } // c vai receber o valor da variavel e enquanto o c foi maior que 1, o c vai perder 1. ao mensmo tempo, a variavel tem seu valor multiplicado e aumentado em cada volta da estrutura de repetição
    return fatorial
}

console.log(fatorial(5))