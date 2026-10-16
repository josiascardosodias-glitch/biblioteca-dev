    let num = document.getElementById('num');
    let dates = document.getElementById('database');
    let res = document.getElementById('res');
    let valores = []

function isnumber(n) {
    if (Number(n) >= 1 && Number(n) <= 100) {
        return true
    } else {
        return false
    }
}

function inlist(n, l) {
    if (l.indexOf(Number(n)) != -1) {
        return true
    } else {
        return false
    }
}

function adicionar() {
    if (isnumber(num.value) && !inlist(num.value, valores)) {
        valores.push(Number(num.value))
        let item = document.createElement('option')
        item.text = `valor ${num.value} adicionado.`
        dates.appendChild(item)
    } else {
        window.alert ('Valor incorreto ou já Existente na Lista')
    }
    num.value = ''
    num.focus()
}

function finalizar() {
    if (valores.length == 0 ) {
        window.alert('Adicione números antes de começar') 
    } else {
        let tot = valores.length
        let maior = valores[0]
        let menor = valores[0]
        let soma = 0
        let media = 0
        for(let pos in valores) {
            soma += valores[pos]
            if (valores[pos] > maior)
                maior = valores[pos]
            if (valores[pos] < menor)
                menor = valores[pos]
        }
        media = soma / tot
        res.innerHTML = ''
        res.innerHTML += `<p>Ao todo são ${tot} números cadastrados </p>`
        res.innerHTML += `<p>O maior valor informado foi ${maior}</p>`
        res.innerHTML += `<p>O menor numero informado foi ${menor}</p>`
        res.innerHTML += `<p>Se somarmo todos os valores, temos ${soma}</p>`
        res.innerHTML += `<p>A média dos valores informados foi ${media}</p>`

    }
}
