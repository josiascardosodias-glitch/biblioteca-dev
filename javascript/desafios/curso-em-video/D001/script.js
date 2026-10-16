function carregar() {
    var horario = window.document.getElementById('horas');
    var img = window.document.getElementById('imagem');
    var agora = new Date();
    var hora = agora.getHours();
    horario.innerHTML = `Agora são ${hora} horas`;
    if (hora >= 0 && hora < 12) {
        img.src = 'imagens/imagens-png/manha.png'
        document.body.style.background = '#ffe83a'
    } else if (hora >= 12 && hora < 19) {
        img.src = 'imagens/imagens-png/tarde-.png'
        document.body.style.background = '#67774b'
    } else {
        img.src = 'imagens/imagens-png/noite.png'
        document.body.style.background = '#373542'
    }
}