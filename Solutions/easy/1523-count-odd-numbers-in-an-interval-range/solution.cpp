//Coisas interessantes:
//Se o intervalo começa com um par e termina num par,
//o tamanho será ímpar e vai ser portanto even skewed
//
//Se o intervalo começa em impar e termina em impar, 
//o mesmo acontece.
//
//Já se o intervalo começa em par e termina em impar 
//ou vice-versa, o tamanho será par, então é só dividir o tamanho
//Em outras palavras se end - start + 1 for par é só dividir isso por 2

class Solution {
public:
    int countOdds(int low, int high) {
        return 
                (high - low + 1) % 2 == 0 ? (high - low + 1)/2 :
                high & 1 && low & 1 ? (high - low + 1)/2 + 1 :
                (high - low + 1)/2;
    }
};