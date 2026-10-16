# 📚 Biblioteca Dev

Minha biblioteca pessoal de estudos em programação. Aqui eu guardo tudo o que aprendo ao longo da carreira (exercícios, desafios, projetos e materiais da faculdade), organizado por linguagem, para consultar, relembrar e acompanhar a minha evolução.

> Sou estudante de **Sistemas de Informação** e este repositório cresce junto comigo.

---

## 🗂️ Estrutura

O conteúdo é organizado **por linguagem/tecnologia** e, dentro de cada uma, **por tipo de conteúdo**:

```
biblioteca-dev/
├── python/
│   ├── bibliotecas/      módulos reutilizáveis
│   └── exercicios/       exercícios de lógica por tema
├── java/
│   ├── exercicios/       fundamentos da linguagem
│   └── projetos/         pequenos sistemas
├── c/
│   ├── exercicios/       vetores, matrizes e funções (faculdade)
│   └── projetos/         jogos e programas maiores
├── javascript/
│   ├── exercicios/       curso-em-video/ e proprios/
│   ├── desafios/         curso-em-video/
│   └── prints/           capturas de tela dos resultados
└── html-css/
    ├── exercicios/       curso-em-video/
    ├── desafios/         curso-em-video/modulo-1/
    └── prints/
```

| Tipo de pasta | O que guarda |
|---|---|
| `exercicios/` | Exercícios curtos para praticar um conceito |
| `desafios/` | Problemas maiores propostos em cursos |
| `projetos/` | Programas completos ou em evolução, um por pasta |
| `bibliotecas/` | Código reutilizável em outros projetos |
| `faculdade/` | Atividades da faculdade que não se encaixam nas outras |
| `anotacoes/` | Resumos e anotações em Markdown |
| `prints/` | Imagens de resultados |

---

## 🐍 Python

**Bibliotecas** (`python/bibliotecas/biblioteca-uteis/`)
- `Estilo.py`: linhas, cabeçalhos e formatação de moeda (R$, US$, €)
- `Cálculos.py`: aumentar, diminuir, multiplicar e dividir valores
- `Dados.py`: leitura segura de inteiros, floats e textos

**Exercícios** (`python/exercicios/`)
- `games/`: adivinhação, dados, jokenpô, cara ou coroa, par ou ímpar
- `matematicos/`: troco, Fibonacci, matriz, tabuada, aposentadoria
- `analisadores/`: triângulo, ano bissexto, palíndromo
- `cadastros/`: alistamento militar, boletim, peso, menus
- `geradores/`: palavras, PA, Mega Sena
- `codigos-simples/`: temporizador e outros

## ☕ Java

- `java/exercicios/`: condicionais, arrays, `ArrayList`, laços e for-each
- `java/projetos/lista-compras/`: CRUD simples de lista de compras

## ⚙️ C

- `c/exercicios/`: matrizes, vetores e funções feitos na faculdade
- `c/projetos/tetris/`: jogo Tetris com [raylib](https://www.raylib.com/), versões `v0.0` (rascunho) até `v0.2`

## 🟨 JavaScript

- `javascript/exercicios/curso-em-video/`: exercícios do curso do Curso em Vídeo
- `javascript/exercicios/proprios/`: exercícios feitos por conta própria
- `javascript/desafios/curso-em-video/`: desafios do curso

## 🎨 HTML & CSS

- `html-css/exercicios/curso-em-video/`: exercícios do Curso em Vídeo
- `html-css/desafios/curso-em-video/modulo-1/`: desafios do módulo 1

---

## ▶️ Como executar

| Linguagem | Comando |
|---|---|
| Python | `python3 "arquivo.py"` |
| Java | `javac Arquivo.java && java Arquivo` |
| C | `gcc arquivo.c -o arquivo && ./arquivo` |
| C + raylib (Tetris) | `gcc tetris-v0.2.c -o tetris -lraylib -lm && ./tetris` |
| JavaScript | `node script.js` ou abrir o `index.html` no navegador |
| HTML/CSS | abrir o `index.html` no navegador |

---

## ➕ Como adicionar conteúdo

1. Escolha a pasta da linguagem (ou crie uma nova, ex.: `go/`, `sql/`).
2. Coloque o conteúdo no tipo certo (`exercicios/`, `desafios/`, `projetos/`...).
3. Use nomes em `kebab-case`, sem acentos nem espaços (ex.: `calculadora-imc`).
4. Atualize este README na seção da linguagem.

As regras completas de padronização estão em [`CLAUDE.md`](CLAUDE.md).

---

## 📄 Licença

[MIT](LICENSE) © Josias Cardoso Dias
