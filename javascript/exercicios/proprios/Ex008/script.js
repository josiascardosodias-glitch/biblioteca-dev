function velocidadeCar(pesoCar, velocidadeCarKMh) {
    return (pesoCar * velocidadeCarKMh) / 100;
}

const resposta = velocidadeCar(1200, 70);
console.log(resposta);