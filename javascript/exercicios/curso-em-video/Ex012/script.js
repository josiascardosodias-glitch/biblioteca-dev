// Exercício a
/*var idade = 68
if (idade < 16) {
    console.log(`Você tem ${idade} anos, por isso você não pode votar.`)
} else {
    if (idade >- 16 && idade < 18 || idade > 65) {
        console.log(`Você tem ${idade}, por isso seu voto é opcional`)
    } else {
        console.log(`Você tem ${idade}, por isso seu voto é obrigatório!`)
    }
}*/

// Exercício b
/*
// A função date() serve para adicionar algo do mundo real ao seu programa.
var agora = new Date()
// Aqui você vai dar o valor da função 'hora' como o valor de 'agora' pegando a informação sobre as horas que estão no relógio do servidor
var hora = agora.getHours()
console.log(`Agora são exatamente ${hora} horas`)
if (hora <= 12) {
    console.log('Bom dia!')
} else if (hora <= 19) {
    console.log('Boa tarde!')
} else {
    console.log('Boa noite!')
}
*/

// Exercício c
var hoje = new Date()
var diasem = hoje.getDay()
switch(diasem) {
    case 0:
        console.log('domingo')
        break
    case 1:
        console.log('segunda')
        break
    case 2:
        console.log('terça')
        break
    case 3:
        console.log('quarta')
        break
    case 4:
        console.log('quinta')
        break
    case 5:
        console.log('sexta')
        break
    case 6:
        console.log('sábado')
        break
    default: {
        console.log('[ERRO] Dia invalido')
    }
}