function valor(preço){

    if (preço < 1500) {
        console.log(`O valor de sua compra foi de ${preço}, obrigado por comprar conosco! volte sempre!`)
    } else { 
        const desconto = preço - (15*preço) / 100
        console.log(`O valor de sua compra foi de ${desconto}, obrigado por comprar conosco! volte sempre!`)
    }
}

valor(300)