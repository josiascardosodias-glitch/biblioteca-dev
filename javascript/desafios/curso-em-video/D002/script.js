function carregar() {
    var data = new Date()
    var ano = data.getFullYear()
    var fano = document.getElementById('txtano')
    var res = document.querySelector('div#res')
    if (fano.value.length == 0 || Number(fano.value) > ano) {
        window.alert('[ERRO]: Verifique os dados inseridos e tente novamente!')
    } else{
    var idade = ano - Number(fano.value)
    var fsex = document.getElementsByName('radsex')
        var genero = ''
    var img = document.createElement('img')
    img.setAttribute('id', 'foto')
    // estilo para centralizar a imagem e definir altura
    img.style.height = '250px'
    img.style.display = 'block'
    img.style.margin = '10px auto 0'
    img.setAttribute('alt', genero)
        if (fsex[0].checked) {
            genero = 'Homem'
            if (idade > 0 && idade < 10) {
                img.setAttribute('src', 'imagens/icones/criança-h.png')
                //criança
            } else if (idade < 31) {
                img.setAttribute('src', 'imagens/icones/jovem-h.png')
                //jovem
            } else if (idade < 50) {
                img.setAttribute('src', 'imagens/icones/adulto-h.png')
                //adulto
            } else {
                img.setAttribute('src', 'imagens/icones/idoso-h.png')
                //idoso
            } 
        } else if (fsex[1].checked) {
            genero = 'Mulher'
            if (idade > 0 && idade < 10) {
                img.setAttribute('src', 'imagens/icones/criança-m.png')
                //criança
            } else if (idade < 31) {
                img.setAttribute('src', 'imagens/icones/jovem-m.png')
                //jovem
            } else if (idade < 50) {
                img.setAttribute('src', 'imagens/icones/adulto-m.png')
                //adulto
            } else {
                img.setAttribute('src', 'imagens/icones/idoso-m.png')
                //idoso
            }
        }
        res.style.textAlign = 'center'
        res.innerHTML = `Detectamos ${genero} com ${idade} anos.`
        res.appendChild(img)
    }
}
