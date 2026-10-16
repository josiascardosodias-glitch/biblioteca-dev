function verificar() {
    let ini = document.getElementById("txti")
    let fim = document.getElementById("txtf")
    let pas = document.getElementById("txtp")
    
    if (ini.value.length == 0 || fim.value.length == 0 || pas.value.length == 0) {
        window.alert("Erro: Valor incopleto")
    } else {
        res.innerHTML = 'contando:'
        let i = Number(ini.value)
        let f = Number(fim.value)
        let p = Number(pas.value)
        //caso o passo tenha valor nulo
        if (p == 0)
            window.alert('Erro: passo invalido, considerando passo como 1')
        p = 1
        //contagem decrescente
        if (i < f) {
            for(let c = i; c <= f; c += p) {
            res.innerHTML += ` ${c} \u{1F449}`
        }
        //contagem regressiva
        } else {
            for(let c = i; c >= f; c -= p) {
            res.innerHTML += ` ${c} \u{1F449}`
            }
        }
        res.innerHTML += `\u{1F3C1}`
        
    }
}