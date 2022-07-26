#include<stdio.h>

typedef struct {
    int num;
    int den;
} fracao;

fracao soma(fracao, fracao);
fracao subtracao(fracao, fracao);
fracao multiplicacao(fracao, fracao);
fracao divisao(fracao, fracao);

fracao soma(fracao um, fracao dois){
    fracao resultado;
    resultado.num = ((um.num * dois.den) + (dois.num * um.den));
    resultado.den = (um.den * dois.den);
    
    return resultado;
}

fracao subtracao(fracao um, fracao dois){
    fracao resultado;
    resultado.num = ((um.num * dois.den) - (dois.num * um.den));
    resultado.den = (um.den * dois.den);
    
    return resultado;
}

fracao multiplicacao(fracao um, fracao dois){
    fracao resultado;
    resultado.num = (um.num * dois.num);
    resultado.den = (um.den * dois.den);
    
    return resultado;
}

fracao divisao(fracao um, fracao dois){
    fracao resultado;
    resultado.num = (um.num * dois.den);
    resultado.den = (dois.num * um.den);
    
    return resultado;
}

int mdc(fracao resultado_s){
    int resto;

    do {
        resto = resultado_s.num % resultado_s.den;
        resultado_s.num = resultado_s.den;
        resultado_s.den = resto;
    } while (resto != 0);

    return resultado_s.num;
}

fracao simplifica(fracao resultado_s){
    int divide;
    divide = mdc(resultado_s);

    resultado_s.num /= divide;
    resultado_s.den /= divide;

    if(resultado_s.den < 0){
        resultado_s.den *= -1;
        resultado_s.num *= -1;
        }

    return resultado_s;
}


int main(){
    int n;
    fracao f1, f2, resultado, resultado_s;
    char operacao, b1, b2;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d %c %d %c %d %c %d", &f1.num, &b1, &f1.den, &operacao, &f2.num, &b2, &f2.den);

        if(operacao == '+') resultado = soma(f1, f2);
        else if(operacao == '-') resultado = subtracao(f1, f2);
        else if(operacao == '*') resultado = multiplicacao(f1, f2);
        else if(operacao == '/') resultado = divisao(f1, f2);

        resultado_s = simplifica(resultado);

        printf("%d/%d = %d/%d\n", resultado.num, resultado.den, resultado_s.num, resultado_s.den);
    }

    return 0;
}

