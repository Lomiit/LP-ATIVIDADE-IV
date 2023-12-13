#include <stdio.h>

struct {
    char nome[50];
    char dataNascimento[10];
    float nota1;
    float nota2;
    float media;
} Aluno;

float calcularMedia(Aluno aluno) {
    aluno.media = (aluno.nota1 + aluno.nota2) / 2;
    return aluno.media;
}

char* verificarAprovacao(Aluno aluno) {
    if (aluno.media >= 7.0) {
        return "Aprovado";
    } else {
        return "Reprovado";
    }
}

int main() {
    Aluno alunos[5];

    for (int i = 0; i < 5; i++) {
        printf("Média do aluno %s: %.2f\n", alunos[i].nome, calcularMedia(alunos[i]));
        printf("O aluno está %s\n", verificarAprovacao(alunos[i]));
    }

    return 0;
}

