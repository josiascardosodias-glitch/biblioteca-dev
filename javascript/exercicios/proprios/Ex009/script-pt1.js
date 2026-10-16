function calcularPâr(a=0, b=0, c=0) {
    return (a + c) / b;
}

let resposta = calcularPâr(7, 2, 5);
if (resposta % 2 === 0) {
    console.log(resposta);
}
else {
    console.log(`A soma dos números foi de ${resposta}, o valor não é par`);
}