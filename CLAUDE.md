# CLAUDE.md

Biblioteca pessoal de estudos de programação do Josias, estudante de Sistemas de Informação. Ela guarda exercícios, desafios, projetos e materiais da faculdade para consulta futura. Não é um software único: cada arquivo ou pasta de projeto roda sozinho.

Todo texto (README, commits, anotações, comentários novos) é escrito em **português do Brasil**.

## Estrutura

A organização é sempre `<linguagem>/<tipo>/<conteúdo>`.

- **Linguagem**: `python/`, `java/`, `c/`, `javascript/`, `html-css/`. Uma linguagem nova ganha uma pasta nova na raiz, com o nome em minúsculo (ex.: `go/`, `sql/`, `typescript/`).
- **Tipo**: use apenas estes nomes:
  - `exercicios/`: exercícios curtos de um conceito
  - `desafios/`: problemas maiores propostos em cursos
  - `projetos/`: programas completos ou em evolução, **um por subpasta**
  - `bibliotecas/`: código reutilizável
  - `faculdade/`: atividades da faculdade que não se encaixam nas anteriores
  - `anotacoes/`: resumos em Markdown
  - `prints/`: capturas de tela de resultados
- **Origem**: conteúdo de curso fica em uma subpasta com o nome do curso (ex.: `exercicios/curso-em-video/`). Conteúdo feito por conta própria fica em `exercicios/proprios/` quando houver conteúdo de curso no mesmo tipo.

Não crie pastas vazias nem pastas de tipo que ainda não têm conteúdo.

## Nomes

- Pastas e arquivos **novos**: `kebab-case`, sem acentos e sem espaços (ex.: `calculadora-imc.py`, `lista-compras/`).
- Exceções exigidas pela linguagem:
  - Java: o arquivo tem o nome da classe em `PascalCase` (`ListaCompras.java`), e as pastas de pacote têm o nome do `package`.
  - Python: módulos que são importados usam `snake_case`.
- Sequências numeradas usam 3 dígitos: `Ex001`, `D001`.
- Versões de um mesmo projeto: `nome-vX.Y.ext` (ex.: `tetris-v0.2.c`).
- **Não renomeie arquivos antigos** dentro de pastas de exercício/desafio de HTML, CSS ou JS. Os arquivos referenciam imagens e mídias por caminho relativo e o renomeio quebra os links. Se for preciso, atualize as referências junto e confira.

## Ao adicionar conteúdo

1. Coloque no caminho `<linguagem>/<tipo>/...` correto.
2. Atualize a seção da linguagem no `README.md`, e a árvore de estrutura dele se criar uma linguagem ou um tipo novo.
3. Um projeto em `projetos/` pode ter o próprio `README.md` explicando o que faz e como rodar.
4. Não versione:
   - binários e saídas de compilação (`*.class`, `out/`, `output/`, executáveis de C)
   - configurações de editor (`.vscode/`, `.idea/`, `*.iml`, `*.code-workspace`)
   - dependências (`node_modules/`, `venv/`)

   Isso já está no `.gitignore`.
5. Arquivos grandes: o GitHub recusa arquivos acima de 100 MB e avisa acima de 50 MB. Evite mídia pesada. Se precisar, comprima antes.

## Commits

- Mensagem em português, no imperativo, com prefixo do tipo:
  - `feat:` conteúdo novo
  - `fix:` correção
  - `docs:` README/CLAUDE.md
  - `refactor:` reorganização
  - `chore:` configuração
- Inclua a linguagem quando ajudar: `feat(python): adiciona calculadora de IMC`.
- Um commit por assunto. Não misture reorganização com conteúdo novo.
- Branch principal: `main`. Remote: `https://github.com/josiascardosodias-glitch/biblioteca-dev`.

## Execução (para testar antes de commitar)

- Python: `python3 arquivo.py`
- Java: `javac Arquivo.java && java Arquivo`
- C: `gcc arquivo.c -o /tmp/a && /tmp/a`. O Tetris precisa de `-lraylib -lm`.
- JS: `node script.js` ou abrir o `index.html`
- Saídas de compilação vão para fora do repositório ou ficam ignoradas pelo `.gitignore`.
