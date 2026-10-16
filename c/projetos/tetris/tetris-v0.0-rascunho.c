#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ============= CONSTANTES =============
#define GRADE_LARGURA 10
#define GRADE_ALTURA 20
#define TAMANHO_BLOCO 30
#define LARGURA_JANELA (GRADE_LARGURA * TAMANHO_BLOCO + 200)
#define ALTURA_JANELA (GRADE_ALTURA * TAMANHO_BLOCO + 100)

#define VEL_QUEDA_BASE 30
#define TOTAL_FASES 10

// ============= ESTRUTURAS =============
typedef struct {
    int x, y;
    int tipo;
    int rotacao;
} Tetrominó;

typedef struct {
    int grade[GRADE_ALTURA][GRADE_LARGURA];
    int pontuacao;
    int fase;
    int linhas_eliminadas;
    Tetrominó peça_atual;
    Tetrominó proxima_peça;
    int contador_queda;
    int velocidade_queda;
    bool fim_jogo;
    int frames_emoji;
} EstadoJogo;

// ============= CORES POR FASE =============
typedef struct {
    Color fundo;
    Color grade;
    Color blocos[7];
    Color texto;
} PaletaFase;

// ============= PROTÓTIPOS =============
void inicializar_jogo(EstadoJogo *estado);
void processar_entrada(EstadoJogo *estado);
void atualizar_jogo(EstadoJogo *estado);
void desenhar_tela(EstadoJogo *estado, PaletaFase paleta);
void gerar_tetrominó(Tetrominó *t, int tipo);
bool pode_mover(EstadoJogo *estado, int dx, int dy, int rotacao);
void colocar_peça(EstadoJogo *estado);
void detectar_linhas_completas(EstadoJogo *estado);
void mudar_fase(EstadoJogo *estado);
PaletaFase obter_paleta(int fase);
void converter_numeral_romano(int num, char *str);
void desenhar_emoji_fase(int fase, int x, int y);

// ============= TETROMINÓS (7 TIPOS) =============
int tetrominós[7][4][4] = {
    // I (Cyan)
    {
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    },
    // O (Amarelo)
    {
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    },
    // T (Roxo)
    {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    },
    // S (Verde)
    {
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    },
    // Z (Vermelho)
    {
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    },
    // J (Azul)
    {
        {1, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    },
    // L (Laranja)
    {
        {0, 0, 1, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    }
};

// ============= IMPLEMENTAÇÃO =============

PaletaFase obter_paleta(int fase) {
    PaletaFase paleta;
    
    switch(fase) {
        case 1: // Neon Púrpura
            paleta.fundo = (Color){20, 10, 30, 255};
            paleta.grade = (Color){80, 40, 120, 255};
            paleta.blocos[0] = (Color){0, 255, 255, 255};
            paleta.blocos[1] = (Color){255, 255, 0, 255};
            paleta.blocos[2] = (Color){200, 50, 200, 255};
            paleta.blocos[3] = (Color){0, 255, 100, 255};
            paleta.blocos[4] = (Color){255, 50, 100, 255};
            paleta.blocos[5] = (Color){0, 150, 255, 255};
            paleta.blocos[6] = (Color){255, 150, 0, 255};
            paleta.texto = (Color){255, 100, 255, 255};
            break;
            
        case 2: // Laranja Queimado
            paleta.fundo = (Color){40, 20, 10, 255};
            paleta.grade = (Color){120, 60, 20, 255};
            paleta.blocos[0] = (Color){0, 200, 255, 255};
            paleta.blocos[1] = (Color){255, 200, 0, 255};
            paleta.blocos[2] = (Color){255, 80, 80, 255};
            paleta.blocos[3] = (Color){0, 255, 100, 255};
            paleta.blocos[4] = (Color){255, 100, 200, 255};
            paleta.blocos[5] = (Color){100, 200, 255, 255};
            paleta.blocos[6] = (Color){255, 150, 0, 255};
            paleta.texto = (Color){255, 150, 100, 255};
            break;
            
        case 3: // Verde Floresta
            paleta.fundo = (Color){10, 30, 20, 255};
            paleta.grade = (Color){40, 100, 60, 255};
            paleta.blocos[0] = (Color){0, 255, 200, 255};
            paleta.blocos[1] = (Color){200, 255, 0, 255};
            paleta.blocos[2] = (Color){100, 200, 100, 255};
            paleta.blocos[3] = (Color){0, 200, 100, 255};
            paleta.blocos[4] = (Color){255, 100, 150, 255};
            paleta.blocos[5] = (Color){100, 150, 255, 255};
            paleta.blocos[6] = (Color){200, 100, 0, 255};
            paleta.texto = (Color){100, 255, 150, 255};
            break;
            
        case 4: // Azul Profundo
            paleta.fundo = (Color){10, 20, 40, 255};
            paleta.grade = (Color){40, 80, 150, 255};
            paleta.blocos[0] = (Color){0, 255, 255, 255};
            paleta.blocos[1] = (Color){255, 200, 0, 255};
            paleta.blocos[2] = (Color){200, 100, 255, 255};
            paleta.blocos[3] = (Color){100, 255, 100, 255};
            paleta.blocos[4] = (Color){255, 100, 100, 255};
            paleta.blocos[5] = (Color){0, 200, 255, 255};
            paleta.blocos[6] = (Color){255, 150, 0, 255};
            paleta.texto = (Color){100, 200, 255, 255};
            break;
            
        case 5: // Vermelho Fogo
            paleta.fundo = (Color){40, 10, 10, 255};
            paleta.grade = (Color){150, 50, 30, 255};
            paleta.blocos[0] = (Color){0, 255, 200, 255};
            paleta.blocos[1] = (Color){255, 255, 0, 255};
            paleta.blocos[2] = (Color){255, 100, 50, 255};
            paleta.blocos[3] = (Color){0, 255, 100, 255};
            paleta.blocos[4] = (Color){255, 50, 150, 255};
            paleta.blocos[5] = (Color){50, 150, 255, 255};
            paleta.blocos[6] = (Color){255, 150, 0, 255};
            paleta.texto = (Color){255, 150, 100, 255};
            break;
            
        case 6: // Rosa Pastel
            paleta.fundo = (Color){40, 20, 35, 255};
            paleta.grade = (Color){150, 100, 130, 255};
            paleta.blocos[0] = (Color){200, 255, 200, 255};
            paleta.blocos[1] = (Color){255, 200, 200, 255};
            paleta.blocos[2] = (Color){200, 200, 255, 255};
            paleta.blocos[3] = (Color){255, 200, 255, 255};
            paleta.blocos[4] = (Color){255, 255, 200, 255};
            paleta.blocos[5] = (Color){200, 255, 255, 255};
            paleta.blocos[6] = (Color){255, 150, 200, 255};
            paleta.texto = (Color){255, 150, 200, 255};
            break;
            
        case 7: // Verde Neon
            paleta.fundo = (Color){10, 20, 10, 255};
            paleta.grade = (Color){50, 150, 50, 255};
            paleta.blocos[0] = (Color){0, 255, 200, 255};
            paleta.blocos[1] = (Color){200, 255, 0, 255};
            paleta.blocos[2] = (Color){150, 255, 50, 255};
            paleta.blocos[3] = (Color){0, 255, 100, 255};
            paleta.blocos[4] = (Color){255, 100, 200, 255};
            paleta.blocos[5] = (Color){100, 200, 255, 255};
            paleta.blocos[6] = (Color){255, 200, 0, 255};
            paleta.texto = (Color){150, 255, 100, 255};
            break;
            
        case 8: // Azul Oceano
            paleta.fundo = (Color){10, 25, 40, 255};
            paleta.grade = (Color){30, 100, 150, 255};
            paleta.blocos[0] = (Color){100, 255, 255, 255};
            paleta.blocos[1] = (Color){255, 200, 100, 255};
            paleta.blocos[2] = (Color){150, 100, 255, 255};
            paleta.blocos[3] = (Color){100, 255, 150, 255};
            paleta.blocos[4] = (Color){255, 150, 100, 255};
            paleta.blocos[5] = (Color){150, 200, 255, 255};
            paleta.blocos[6] = (Color){200, 255, 150, 255};
            paleta.texto = (Color){150, 220, 255, 255};
            break;
            
        case 9: // Roxo Místico
            paleta.fundo = (Color){30, 10, 40, 255};
            paleta.grade = (Color){100, 50, 150, 255};
            paleta.blocos[0] = (Color){200, 100, 255, 255};
            paleta.blocos[1] = (Color){255, 200, 255, 255};
            paleta.blocos[2] = (Color){200, 150, 255, 255};
            paleta.blocos[3] = (Color){100, 200, 255, 255};
            paleta.blocos[4] = (Color){255, 100, 200, 255};
            paleta.blocos[5] = (Color){150, 255, 200, 255};
            paleta.blocos[6] = (Color){255, 200, 100, 255};
            paleta.texto = (Color){200, 150, 255, 255};
            break;
            
        default: // 10 - Arco-íris
            paleta.fundo = (Color){20, 20, 20, 255};
            paleta.grade = (Color){80, 80, 80, 255};
            paleta.blocos[0] = (Color){255, 0, 0, 255};
            paleta.blocos[1] = (Color){255, 128, 0, 255};
            paleta.blocos[2] = (Color){255, 255, 0, 255};
            paleta.blocos[3] = (Color){0, 255, 0, 255};
            paleta.blocos[4] = (Color){0, 0, 255, 255};
            paleta.blocos[5] = (Color){75, 0, 130, 255};
            paleta.blocos[6] = (Color){148, 0, 211, 255};
            paleta.texto = (Color){255, 200, 255, 255};
    }
    
    return paleta;
}

void converter_numeral_romano(int num, char *str) {
    int valores[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const char *simbolos[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    strcpy(str, "");
    for (int i = 0; i < 13; i++) {
        while (num >= valores[i]) {
            strcat(str, simbolos[i]);
            num -= valores[i];
        }
    }
}

void gerar_tetrominó(Tetrominó *t, int tipo) {
    t->tipo = tipo % 7;
    t->x = 3;
    t->y = 0;
    t->rotacao = 0;
}

bool pode_mover(EstadoJogo *estado, int dx, int dy, int rotacao) {
    Tetrominó t = estado->peça_atual;
    t.x += dx;
    t.y += dy;
    t.rotacao = (t.rotacao + rotacao) % 4;
    
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (tetrominós[t.tipo][y][x]) {
                int px = t.x + x;
                int py = t.y + y;
                
                if (px < 0 || px >= GRADE_LARGURA || py >= GRADE_ALTURA) {
                    return false;
                }
                if (py >= 0 && estado->grade[py][px] != 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

void colocar_peça(EstadoJogo *estado) {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (tetrominós[estado->peça_atual.tipo][y][x]) {
                int px = estado->peça_atual.x + x;
                int py = estado->peça_atual.y + y;
                
                if (py >= 0) {
                    estado->grade[py][px] = estado->peça_atual.tipo + 1;
                }
            }
        }
    }
    
    detectar_linhas_completas(estado);
    
    estado->peça_atual = estado->proxima_peça;
    gerar_tetrominó(&estado->proxima_peça, rand() % 7);
    
    if (!pode_mover(estado, 0, 0, 0)) {
        estado->fim_jogo = true;
    }
}

void detectar_linhas_completas(EstadoJogo *estado) {
    int linhas_removidas = 0;
    
    for (int y = GRADE_ALTURA - 1; y >= 0; y--) {
        bool linha_completa = true;
        
        for (int x = 0; x < GRADE_LARGURA; x++) {
            if (estado->grade[y][x] == 0) {
                linha_completa = false;
                break;
            }
        }
        
        if (linha_completa) {
            linhas_removidas++;
            
            for (int yy = y; yy > 0; yy--) {
                for (int x = 0; x < GRADE_LARGURA; x++) {
                    estado->grade[yy][x] = estado->grade[yy - 1][x];
                }
            }
            for (int x = 0; x < GRADE_LARGURA; x++) {
                estado->grade[0][x] = 0;
            }
            y++;
        }
    }
    
    if (linhas_removidas > 0) {
        estado->linhas_eliminadas += linhas_removidas;
        
        switch(linhas_removidas) {
            case 1:
                estado->pontuacao += 10;
                break;
            case 2:
                estado->pontuacao += 20;
                break;
            case 3:
                estado->pontuacao += 30;
                break;
            case 4:
                estado->pontuacao += 40;
                break;
        }
        
        if (estado->linhas_eliminadas % 10 == 0 && estado->fase < TOTAL_FASES) {
            mudar_fase(estado);
            estado->frames_emoji = 120;
        }
    }
}

void mudar_fase(EstadoJogo *estado) {
    estado->fase++;
    estado->velocidade_queda = VEL_QUEDA_BASE - (estado->fase - 1) * 2;
    if (estado->velocidade_queda < 3) {
        estado->velocidade_queda = 3;
    }
}

void desenhar_emoji_fase(int fase, int x, int y) {
    DrawText("😊", x, y, 60, WHITE);
}

void inicializar_jogo(EstadoJogo *estado) {
    estado->fase = 1;
    estado->pontuacao = 0;
    estado->linhas_eliminadas = 0;
    estado->velocidade_queda = VEL_QUEDA_BASE;
    estado->contador_queda = 0;
    estado->fim_jogo = false;
    estado->frames_emoji = 0;
    
    for (int y = 0; y < GRADE_ALTURA; y++) {
        for (int x = 0; x < GRADE_LARGURA; x++) {
            estado->grade[y][x] = 0;
        }
    }
    
    gerar_tetrominó(&estado->peça_atual, rand() % 7);
    gerar_tetrominó(&estado->proxima_peça, rand() % 7);
}

void processar_entrada(EstadoJogo *estado) {
    if (IsKeyPressed(KEY_LEFT) && pode_mover(estado, -1, 0, 0)) {
        estado->peça_atual.x--;
    }
    if (IsKeyPressed(KEY_RIGHT) && pode_mover(estado, 1, 0, 0)) {
        estado->peça_atual.x++;
    }
    if (IsKeyPressed(KEY_DOWN) && pode_mover(estado, 0, 1, 0)) {
        estado->peça_atual.y++;
    }
    if (IsKeyPressed(KEY_SPACE) && pode_mover(estado, 0, 0, 1)) {
        estado->peça_atual.rotacao = (estado->peça_atual.rotacao + 1) % 4;
    }
    if (IsKeyPressed(KEY_R)) {
        inicializar_jogo(estado);
    }
}

void atualizar_jogo(EstadoJogo *estado) {
    if (estado->fim_jogo) return;
    
    estado->contador_queda++;
    
    if (estado->contador_queda >= estado->velocidade_queda) {
        estado->contador_queda = 0;
        
        if (pode_mover(estado, 0, 1, 0)) {
            estado->peça_atual.y++;
        } else {
            colocar_peça(estado);
        }
    }
    
    if (estado->frames_emoji > 0) {
        estado->frames_emoji--;
    }
}

void desenhar_tela(EstadoJogo *estado, PaletaFase paleta) {
    ClearBackground(paleta.fundo);
    
    int offset_x = 50;
    int offset_y = 30;
    
    // Desenhar grade
    for (int y = 0; y < GRADE_ALTURA; y++) {
        for (int x = 0; x < GRADE_LARGURA; x++) {
            int px = offset_x + x * TAMANHO_BLOCO;
            int py = offset_y + y * TAMANHO_BLOCO;
            
            DrawRectangleLines(px, py, TAMANHO_BLOCO, TAMANHO_BLOCO, paleta.grade);
            
            if (estado->grade[y][x] != 0) {
                int tipo = estado->grade[y][x] - 1;
                DrawRectangle(px + 1, py + 1, TAMANHO_BLOCO - 2, TAMANHO_BLOCO - 2, paleta.blocos[tipo]);
            }
        }
    }
    
    // Desenhar peça atual
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (tetrominós[estado->peça_atual.tipo][y][x]) {
                int px = offset_x + (estado->peça_atual.x + x) * TAMANHO_BLOCO;
                int py = offset_y + (estado->peça_atual.y + y) * TAMANHO_BLOCO;
                
                if (py >= offset_y) {
                    DrawRectangle(px + 1, py + 1, TAMANHO_BLOCO - 2, TAMANHO_BLOCO - 2, 
                                paleta.blocos[estado->peça_atual.tipo]);
                }
            }
        }
    }
    
    // Painel lateral
    int painel_x = offset_x + GRADE_LARGURA * TAMANHO_BLOCO + 30;
    int painel_y = offset_y + 20;
    
    DrawText("TETRIS", painel_x, painel_y, 28, paleta.texto);
    
    char fase_str[20];
    sprintf(fase_str, "Fase: %d/%d", estado->fase, TOTAL_FASES);
    DrawText(fase_str, painel_x, painel_y + 50, 16, paleta.texto);
    
    char romano[20];
    converter_numeral_romano(estado->pontuacao, romano);
    DrawText("Pontos:", painel_x, painel_y + 100, 14, paleta.texto);
    DrawText(romano, painel_x, painel_y + 125, 20, paleta.blocos[0]);
    
    char linhas_str[30];
    sprintf(linhas_str, "Linhas: %d", estado->linhas_eliminadas);
    DrawText(linhas_str, painel_x, painel_y + 170, 14, paleta.texto);
    
    DrawText("Proxima:", painel_x, painel_y + 220, 14, paleta.texto);
    
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (tetrominós[estado->proxima_peça.tipo][y][x]) {
                int px = painel_x + 10 + x * 20;
                int py = painel_y + 250 + y * 20;
                DrawRectangle(px, py, 18, 18, paleta.blocos[estado->proxima_peça.tipo]);
            }
        }
    }
    
    DrawText("Controles:", painel_x, painel_y + 360, 12, paleta.texto);
    DrawText("Setas: Mover", painel_x, painel_y + 380, 11, (Color){180, 180, 180, 255});
    DrawText("Espaco: Girar", painel_x, painel_y + 400, 11, (Color){180, 180, 180, 255});
    DrawText("R: Reiniciar", painel_x, painel_y + 420, 11, (Color){180, 180, 180, 255});
    
    // Emoji de fase
    if (estado->frames_emoji > 0) {
        DrawText("Fase Completa!", painel_x - 30, painel_y + 300, 16, (Color){255, 200, 100, 255});
        DrawText("😊", painel_x + 20, painel_y + 270, 50, WHITE);
    }
    
    // Tela de fim de jogo
    if (estado->fim_jogo) {
        DrawRectangle(0, 0, LARGURA_JANELA, ALTURA_JANELA, (Color){0, 0, 0, 200});
        DrawText("FIM DE JOGO!", 250, 200, 48, RED);
        
        char pontuacao_final[50];
        converter_numeral_romano(estado->pontuacao, romano);
        sprintf(pontuacao_final, "Pontuacao Final: %s", romano);
        DrawText(pontuacao_final, 200, 300, 24, WHITE);
        
        char fase_final[40];
        sprintf(fase_final, "Alcancou a Fase: %d", estado->fase);
        DrawText(fase_final, 250, 360, 20, WHITE);
        
        DrawText("Pressione R para Reiniciar", 220, 450, 20, YELLOW);
    }
}

int main(void) {
    srand((unsigned int)time(NULL));
    
    InitWindow(LARGURA_JANELA, ALTURA_JANELA, "TETRIS em C - Raylib");
    SetTargetFPS(60);
    
    EstadoJogo estado;
    inicializar_jogo(&estado);
    
    while (!WindowShouldClose()) {
        processar_entrada(&estado);
        atualizar_jogo(&estado);
        
        BeginDrawing();
        PaletaFase paleta = obter_paleta(estado.fase);
        desenhar_tela(&estado, paleta);
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
