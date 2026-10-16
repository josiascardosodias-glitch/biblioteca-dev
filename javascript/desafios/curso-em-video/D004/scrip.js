function checar() {
    let txtn = document.getElementById("num")
    let res = document.getElementById("seltab")

    if (txtn.value.length == 0) {
        window.alert('ERRO: Valor incompleto')
    } else {

        let n = Number(txtn.value)
        let c = 1
        res.innerHTML = ''
        while (c <= 10) {
            let item = document.createElement('option')
            item.text = `${n} x ${c} = ${n*c}`
            res.appendChild(item)
            c++
        }
    }
}