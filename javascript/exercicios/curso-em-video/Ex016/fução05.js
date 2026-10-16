// função em forma recursiva 
function fat(n) {
    if (n == 1) {
        return 1 // se o valor de n for 1, então o fatorial de 1 é 1, por isso ira retornar 1
    } else {
        return n * fat(n-1)
    } // caso o valor de n seja maior q 1, então o valor da fatorial vai ser o fatorial daquele numero, menos o fatorial do seu antecessor ex: 5 fat(5-1=4) ou 9 fat(9-1=8)
}

console.log(fat(5))